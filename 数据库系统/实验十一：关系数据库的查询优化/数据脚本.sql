--创建表testtab01
CREATE TABLE testtab01(id int primary key, note text);

--为表testtab01插入测试数据：
INSERT INTO testtab01 select generate_series(1,10000), generate_series(1,10000); 
 --generate_series(start,stop)为序列号生产函数;

----创建表testtab02
CREATE TABLE testtab02(id int primary key, note text);

--为表testtab02插入测试数据：
INSERT INTO testtab02 select generate_series(1,9102), generate_series(1,9102);  

----创建表testtab03
CREATE TABLE testtab03(id int primary key, note text);

--为表testtab03插入测试数据：
INSERT INTO testtab03 select generate_series(1,10000000), generate_series(1,10000000);  
