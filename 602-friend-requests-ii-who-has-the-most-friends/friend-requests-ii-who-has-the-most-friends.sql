# Write your MySQL query statement below
Select id,Count(*) as num
from(
    Select requester_id as id from RequestAccepted
    UNION ALL 
    Select accepter_id  as id from RequestAccepted 

)t
Group by id
Order by num DESC
LIMIT 1