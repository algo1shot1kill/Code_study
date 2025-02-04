WITH av AS
(
select car_id, sum(if('2022-10-16' between start_date and end_date, 1, 0)) as avblt from CAR_RENTAL_COMPANY_RENTAL_HISTORY group by 1
)
select car_id, if(avblt = 0, '대여 가능','대여중') AS AVAILABILITY
from av
ORDER BY car_id desc