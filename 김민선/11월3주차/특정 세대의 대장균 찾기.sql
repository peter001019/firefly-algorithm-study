-- 코드를 작성해주세요  sql 이 길어도 예쁘게 쓰는 법을 연습해야겠다
select e3.id from ECOLI_DATA e3
where e3.parent_id in(
select e2.id from ECOLI_DATA e2 where e2.parent_id in (select e1.id from ECOLI_DATA e1 where e1.parent_id is NULL)
)
order by e3.id asc;