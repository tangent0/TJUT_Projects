LOAD DATA
INFILE 'product.dat'
INTO TABLE product
FIELDS TERMINATED BY ','
(product_number, supplier_number, product_name, product_unit, supplier_unit_price)
