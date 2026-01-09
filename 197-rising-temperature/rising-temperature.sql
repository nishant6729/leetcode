# Write your MySQL query statement below
# Jab bhi same table ke rows me checkup krna ho toh table ko do table me todo or self join kro 
Select today.id
from weather today
JOIN weather yesterday
ON today.recordDate=DATE_ADD(yesterday.recordDate,INTERVAL 1 DAY)
where today.temperature>yesterday.temperature