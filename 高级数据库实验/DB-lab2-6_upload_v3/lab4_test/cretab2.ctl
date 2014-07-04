Load Data
INFILE 'cretab2.dat'
INTO TABLE part2
FIELDS TERMINATED BY ','
(part_number, part_name, status)
