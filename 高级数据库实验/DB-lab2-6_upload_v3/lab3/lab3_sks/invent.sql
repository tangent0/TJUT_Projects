select part_name, qty_stock
from ora00176.part;

select sum(qty_stock) "total number of parts"
from ora00176.part;
