# Write your MySQL query statement below
SELECT teacher_id,COUNT(DISTINCT(subject_id)) as cnt from Teacher group by teacher_id