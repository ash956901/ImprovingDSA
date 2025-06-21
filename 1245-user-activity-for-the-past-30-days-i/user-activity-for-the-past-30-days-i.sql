# Write your MySQL query statement below
-- SELECT activity_date as day,count(distinct(user_id)) as active_users from Activity group by activity_date having DATEDIFF(activity_date,"2019-07-27")<=30; 
SELECT 
    activity_date AS day,
    COUNT(DISTINCT user_id) AS active_users
FROM 
    Activity
WHERE 
    DATEDIFF('2019-07-27', activity_date) BETWEEN 0 AND 29
GROUP BY 
    activity_date
ORDER BY 
    activity_date;
