# Write your MySQL query statement below
Select v.customer_id,Count(*) as 'count_no_trans'
from Visits v
LEft JOin Transactions t
ON v.visit_id=t.visit_id
where t.transaction_id is NULL
Group BY v.customer_id