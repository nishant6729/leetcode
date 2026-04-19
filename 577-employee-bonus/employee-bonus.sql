# Write your MySQL query statement below
Select e.name,b.bonus from employee e
LEFT join Bonus b 
ON e.empId=b.empId
where b.bonus is NULL or b.bonus<1000