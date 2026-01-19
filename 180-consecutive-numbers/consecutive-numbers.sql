# Write your MySQL query statement below
Select distinct l1.num as ConsecutiveNums 
from logs l1
Join logs l2 ON l1.id=l2.id-1
Join logs l3 ON l2.id=l3.id-1
where l1.num=l2.num and l2.num=l3.num
