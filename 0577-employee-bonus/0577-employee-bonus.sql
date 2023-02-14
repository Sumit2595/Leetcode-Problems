# Write your MySQL query statement below
select name,bonus from (select name,bonus from Employee e left join Bonus b on e.empId=b.empId) 
as c where c.bonus<1000 or c.bonus is null;