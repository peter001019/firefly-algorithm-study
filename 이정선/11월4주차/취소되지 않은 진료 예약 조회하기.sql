-- 코드를 입력하세요
SELECT DA.APNT_NO, P.PT_NAME, P.PT_NO, DA.MCDP_CD, DA.DR_NAME, DA.APNT_YMD
from (
    select A.APNT_NO, A.MCDP_CD, D.DR_NAME, A.APNT_YMD, A.PT_NO
    from DOCTOR D join APPOINTMENT A on D.DR_ID = A.MDDR_ID
    where DATE(A.APNT_YMD) = '2022-04-13' and A.MCDP_CD = "CS" and A.APNT_CNCL_YN = 'N'
) DA join PATIENT P on DA.PT_NO = P.PT_NO
order by DA.APNT_YMD asc;
