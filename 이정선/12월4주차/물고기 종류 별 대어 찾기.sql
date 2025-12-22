select I.ID, N.FISH_NAME, A.LENGTH
from FISH_INFO I 
join FISH_NAME_INFO N 
    on I.FISH_TYPE = N.FISH_TYPE 
join (
    select FISH_TYPE, max(LENGTH) as LENGTH
    from FISH_INFO
    group by FISH_TYPE
) A 
    on A.FISH_TYPE = I.FISH_TYPE and A.LENGTH = I.LENGTH
order by I.ID ASC;
