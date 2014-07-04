LOAD DATA
INFILE 'part.dat'
INTO TABLE part
FIELDS TERMINATED BY ','
(part_number, part_name, qty_stock, qty_minimum, qty_ordered, unit, unit_price)
