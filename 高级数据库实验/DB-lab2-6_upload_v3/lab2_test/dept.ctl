LOAD DATA
INFILE 'dept.dat'
INTO TABLE dept
FIELDS TERMINATED BY ','
(deptno,dname,loc)