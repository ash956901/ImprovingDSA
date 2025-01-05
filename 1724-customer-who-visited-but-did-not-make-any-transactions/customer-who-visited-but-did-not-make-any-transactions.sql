# Write your MySQL query statement below
select v.customer_id,count(*) as count_no_trans from Visits v where v.visit_id not in ( select v.visit_id from Visits v join Transactions t
 on t.visit_id=v.visit_id) group by v.customer_id;