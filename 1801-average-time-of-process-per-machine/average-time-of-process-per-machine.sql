# Write your MySQL query statement below
Select e.machine_id,Round(AVG(e.time_taken),3) as processing_time  from (Select a1.machine_id,a1.process_id,(a2.timestamp-a1.timestamp)as time_taken
from Activity a1 
JOIN Activity a2
ON a1.machine_id=a2.machine_id and a1.process_id=a2.process_id
and a1.activity_type='start' and a2.activity_type='end') as e
Group by machine_id
