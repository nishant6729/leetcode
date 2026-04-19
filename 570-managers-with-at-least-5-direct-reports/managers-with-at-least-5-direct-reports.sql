# Write your MySQL query statement below
Select e1.name as name from employee e1
JOin employee e2 ON e1.id=e2.managerId
Group by e1.id
Having Count(e1.id)>=5
