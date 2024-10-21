import boto3
import paramiko
import time
import os
from io import StringIO

# AWS Configuration
region = 'ap-south-1'  # Change to your region
key_file = '/home/ec2-user/key.pem'  # Path to your .pem file
bucket_name = 'de-poc-1234'  # Your S3 bucket name
script_key = 'myscript.py'  # Path in S3 where your script is stored

# EC2 Configuration
ami_id = 'ami-xxxxx53'  # Replace with your AMI ID
instance_type = 't2.micro'
key_name = 'poc-example'  # Your EC2 key pair name
security_group_id = 'sg-xxxxxxx58090d82b'  # Your security group ID

# Create an EC2 client
ec2_client = boto3.client('ec2', region_name=region)

# Launch the EC2 instance
response = ec2_client.run_instances(
    ImageId=ami_id,
    InstanceType=instance_type,
    KeyName=key_name,
    SecurityGroupIds=[security_group_id],
    SubnetId="subnet-xxxxxxxfa",
    MinCount=1,
    MaxCount=1
)

instance_id = response['Instances'][0]['InstanceId']
print(f'Launching EC2 instance: {instance_id}')

# Wait for the instance to be running
ec2_client.get_waiter('instance_running').wait(InstanceIds=[instance_id])
print(f'EC2 instance {instance_id} is now running.')

# Get the public IP of the instance
instance_info = ec2_client.describe_instances(InstanceIds=[instance_id])
instance_ip = instance_info['Reservations'][0]['Instances'][0]['PrivateIpAddress']
print(f'Instance public IP: {instance_ip}')

# Create an SSH client
ssh = paramiko.SSHClient()
ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())

# Wait for the instance to be ready for SSH
time.sleep(30)  # Adjust as necessary based on instance startup time

try:
    # Load the private key
    f=open(key_file,'r')
    s=f.read()
    keyfile = StringIO(s)
    key = paramiko.RSAKey.from_private_key(keyfile)

    # Connect to the instance
    ssh.connect(hostname=instance_ip, username='ec2-user', pkey=key)

    # Download the script from S3
    s3 = boto3.client('s3')
    local_script_path = '/tmp/your-script.py'
    s3.download_file(bucket_name, script_key, local_script_path)
    print('Downloaded script from S3.')

    # Transfer the script to the instance
    sftp = ssh.open_sftp()
    remote_script_path = '/home/ec2-user/your-script.py'
    sftp.put(local_script_path, remote_script_path)
    sftp.close()
    print('Uploaded script to EC2 instance.')

    # Execute the script
    command = f'python3 {remote_script_path}'
    stdin, stdout, stderr = ssh.exec_command(command)

    # Print the output
    print(stdout.read().decode())
    print(stderr.read().decode())

finally:
    ssh.close()
    print(f'Closed SSH connection to {instance_ip}.')
