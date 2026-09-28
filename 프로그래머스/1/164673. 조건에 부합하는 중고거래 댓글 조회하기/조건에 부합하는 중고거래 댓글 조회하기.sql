select
    b.TITLE,
    b.BOARD_ID,
    r.REPLY_ID,
    r.WRITER_ID,
    r.CONTENTS,
    date_format(r.CREATED_DATE, '%Y-%m-%d') as CREATED_DATE
from USED_GOODS_BOARD b
join USED_GOODS_REPLY r on b.BOARD_ID = r.BOARD_ID
where b.CREATED_DATE >= '2022-10-01' 
  and b.CREATED_DATE < '2022-11-01'
order by r.CREATED_DATE asc, b.TITLE asc;