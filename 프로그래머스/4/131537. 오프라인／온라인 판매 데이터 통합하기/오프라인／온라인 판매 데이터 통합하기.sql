select 
    date_format(SALES_DATE, '%Y-%m-%d') as SALES_DATE,
    PRODUCT_ID,
    USER_ID,
    SALES_AMOUNT
from ONLINE_SALE
where SALES_DATE >= '2022-03-01' and SALES_DATE < '2022-04-01'

union all

select
    date_format(SALES_DATE, '%Y-%m-%d') as SALES_DATE,
    PRODUCT_ID,
    null as USER_ID,
    SALES_AMOUNT
from OFFLINE_SALE 
where SALES_DATE >= '2022-03-01' and SALES_DATE < '2022-04-01'

order by 
    SALES_DATE asc,
    PRODUCT_ID asc,
    USER_ID asc;