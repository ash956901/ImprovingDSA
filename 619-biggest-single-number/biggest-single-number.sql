# Write your MySQL query statement below
with onetable as (select  num from MyNumbers group by num having count(*)=1)
select 
    case 
    when count(*)>0 then max(num)
    else NULL
    END as num
from onetable;
;