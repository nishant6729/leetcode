# Write your MySQL query statement below
Select customer_id,Count(*) as count_no_trans from Visits 
where visit_id not in (Select distinct visit_id from transactions)
Group by customer_id;