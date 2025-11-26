-- 코드를 입력하세요
SELECT c.CAR_ID, 
    case
        when c.CAR_ID in(
            select d.CAR_ID
            from CAR_RENTAL_COMPANY_RENTAL_HISTORY d
            where d.START_DATE <= '2022-10-16' and '2022-10-16' <= d.END_DATE
            group by d.CAR_ID
        )
        THEN '대여중'
        ELSE '대여 가능'
    end as AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY c
group by c.CAR_ID
order by c.CAR_ID desc;