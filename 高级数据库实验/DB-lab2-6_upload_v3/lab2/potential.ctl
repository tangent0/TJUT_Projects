LOAD DATA
INFILE 'potential.dat'
INTO TABLE potential
FIELDS TERMINATED BY ','
(part_number,supplier_id,product_number)
