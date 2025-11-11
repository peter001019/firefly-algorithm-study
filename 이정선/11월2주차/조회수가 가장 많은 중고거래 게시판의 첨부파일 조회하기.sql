-- 코드를 입력하세요
SELECT concat('/home/grep/src/', b.BOARD_ID, '/', b.FILE_ID, b.FILE_NAME, b.FILE_EXT) as FILE_PATH
from (
    select VIEWS, BOARD_ID
    from USED_GOODS_BOARD
    order by VIEWS DESC limit 1
) a, USED_GOODS_FILE b
where a.BOARD_ID = b.BOARD_ID
order by FILE_ID DESC;
