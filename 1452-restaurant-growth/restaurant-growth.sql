# Write your MySQL query statement below
With daily as(
    Select visited_on,Sum(amount) as amount from customer
    Group by visited_on
),
Windowed as(
    Select visited_on,Sum(amount) over (Order by visited_on Rows between 6 preceding and current ROW) as total_amount,
    Round(Avg(amount) over(Order by visited_on Rows between 6 preceding and current ROW),2) as avg_amount
    from daily
)

Select visited_on,total_amount as amount,avg_amount as average_amount
from windowed 
where visited_on>=(
    Select min(visited_on)+Interval 6 day from customer
)
order by visited_on