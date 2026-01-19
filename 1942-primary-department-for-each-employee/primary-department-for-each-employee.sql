# Write your MySQL query statement below
Select employee_id,department_id
from employee
where primary_flag='Y' or employee_id in (
    Select employee_id from employee
    Group by employee_id
    having count(department_id)=1
)
