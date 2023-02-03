# Write your MySQL query statement below
select sell_date,
count(sell_date) as num_sold,
GROUP_CONCAT(distinct product ORDER BY product) as products 
from (select distinct sell_date,product from Activities) as Activities group by sell_date;