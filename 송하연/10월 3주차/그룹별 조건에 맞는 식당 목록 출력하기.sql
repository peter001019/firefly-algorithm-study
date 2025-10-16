select m.MEMBER_NAME, r.REVIEW_TEXT, DATE_FORMAT(r.REVIEW_DATE, '%Y-%m-%d') AS REVIEW_DATE
from MEMBER_PROFILE as m
join REST_REVIEW as r on m.MEMBER_ID=r.MEMBER_ID
where r.MEMBER_ID in ( # 반환값이 2개 이상, 비교는 in 쓰기
    select MEMBER_ID
    from REST_REVIEW
    group by MEMBER_ID
    having count(*) = (
        select count(*) as cnt
        from REST_REVIEW
        group by MEMBER_ID
        order by cnt desc
        limit 1
    )
)
order by r.REVIEW_DATE asc, r.REVIEW_TEXT asc
