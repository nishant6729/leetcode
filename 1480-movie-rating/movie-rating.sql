# Write your MySQL query statement below
(
    Select u.name as results
    from movierating mr
    JOIN users u 
    ON mr.user_id=u.user_id
    Group by u.user_id,u.name
    Order by Count(*) DESC,u.name ASC
    LIMIT 1
)
UNION ALL

(
    Select m.title as results
    from movierating mr
    JOIN movies m
    ON m.movie_id=mr.movie_id
    where mr.created_at  between '2020-02-01' and '2020-02-29'
    Group by mr.movie_id,m.title
    Order by AVG(mr.rating) DESC,title asc
    LIMIT 1
);