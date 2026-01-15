# Write your MySQL query statement below
Select w1.id 
from weather w1
JOIN weather w2
ON w1.recordDate=DATE_ADD(w2.recordDate,INTERVAL 1 Day)
where w1.temperature>w2.temperature
