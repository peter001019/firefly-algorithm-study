-- 코드를 입력하세요
# 한명이 여러 개의 상품을 구매한 경우가 있으므로 distinct를 추가해야 함
SELECT YEAR(OS.SALES_DATE) as YEAR, MONTH(OS.SALES_DATE) as MONTH, UI.GENDER, count(distinct UI.USER_ID) as USERS
from USER_INFO UI join ONLINE_SALE OS on UI.USER_ID = OS.USER_ID
where UI.GENDER is not NULL
group by YEAR(OS.SALES_DATE), MONTH(OS.SALES_DATE), UI.GENDER
order by YEAR(OS.SALES_DATE) asc, MONTH(OS.SALES_DATE) asc, UI.GENDER asc;
