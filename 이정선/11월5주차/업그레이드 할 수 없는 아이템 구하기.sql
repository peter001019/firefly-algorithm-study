-- 코드를 작성해주세요
select a.ITEM_ID, a.ITEM_NAME, a.RARITY
from ITEM_INFO a
where a.ITEM_ID not in ( 
    select distinct PARENT_ITEM_ID
    from ITEM_TREE
    where PARENT_ITEM_ID IS NOT NULL
)
order by a.ITEM_ID DESC;
