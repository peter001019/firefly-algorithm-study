-- 코드를 입력하세요
SELECT I.ANIMAL_ID, O.NAME
from ANIMAL_INS I right outer join ANIMAL_OUTS O on I.ANIMAL_ID = O.ANIMAL_ID
order by (O.DATETIME - I.DATETIME) desc
limit 2;
