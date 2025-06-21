# Write your MySQL query statement below
with minTable as (Select product_id,min(year) as first_year from Sales group by product_id)
select m.product_id,m.first_year,s.quantity,s.price from minTable m join Sales s on m.product_id=s.product_id and m.first_year=s.year
;