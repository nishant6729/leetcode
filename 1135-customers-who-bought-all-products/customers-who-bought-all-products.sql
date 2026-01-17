# Write your MySQL query statement below
Select customer_id 
from customer
Group by customer_id
having count(distinct product_key) in(
    Select count(*) from product
)