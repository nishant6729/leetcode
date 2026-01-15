# Write your MySQL query statement below
Select a.customer_id,Count(*) as count_no_trans
from visits a
Left JOIN Transactions b
ON a.visit_id=b.visit_id
where b.transaction_id is NULL
Group BY customer_id

