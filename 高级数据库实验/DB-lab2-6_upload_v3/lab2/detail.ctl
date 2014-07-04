LOAD DATA
INFILE 'detail.dat'
INTO TABLE detail
FIELDS TERMINATED BY ','
(po_number, product_number, qty_ordered, qty_received)
