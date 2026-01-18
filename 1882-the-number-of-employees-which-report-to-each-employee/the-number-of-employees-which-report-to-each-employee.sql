# Write your MySQL query statement below
Select e1.employee_id,e1.name,Count(*) as reports_count,Round(Avg(e2.age)) as average_age
from employees e1
JOIN employees e2
ON e1.employee_id=e2.reports_to
Group BY employee_id
Order by employee_id