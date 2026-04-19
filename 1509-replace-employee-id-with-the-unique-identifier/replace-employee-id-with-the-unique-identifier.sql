# Write your MySQL query statement below
Select b.unique_id,a.name
from Employees  a Left JOIN
EmployeeUNI b ON a.id=b.id