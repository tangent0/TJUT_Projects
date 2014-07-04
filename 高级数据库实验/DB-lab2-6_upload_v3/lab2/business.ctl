LOAD DATA
INFILE 'business.dat'
INTO TABLE business
FIELDS TERMINATED BY ','
(po_number,supplier_id)
