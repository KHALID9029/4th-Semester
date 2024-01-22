--1. Create two tablespaces tbs1 and tbs2.
CREATE TABLESPACE tbs1 DATAFILE 'tbs1_data.dbf' SIZE 1M EXTENT MANAGEMENT LOCAL AUTOALLOCATE;
CREATE TABLESPACE tbs2 DATAFILE 'tbs2_data.dbf' SIZE 1M EXTENT MANAGEMENT LOCAL AUTOALLOCATE;


--2. Set quota for a single user on both tablespaces.
CREATE USER u1 IDENTIFIED BY 123 DEFAULT TABLESPACE tbs1;
ALTER USER u1 QUOTA 1M ON tbs1;
ALTER USER u1 QUOTA 1M ON tbs2;


--3. Create two tables student(name, ID, fk[dept_ID]) and department(ID, name) in tbs1.
CREATE TABLE DEPARTMENT
(
    DEPT_ID NUMBER, 
    DEPT_NAME VARCHAR2(20),
    CONSTRAINT DEPT_ID_PK PRIMARY KEY (DEPT_ID)
) TABLESPACE tbs1;

CREATE TABLE student
(
    name VARCHAR2(20), 
    ID NUMBER, 
    DEPT_ID NUMBER,
    CONSTRAINT ID_PK PRIMARY KEY (ID),
    CONSTRAINT DEPT_ID_FK FOREIGN KEY (DEPT_ID) REFERENCES DEPARTMENT(DEPT_ID)
) TABLESPACE tbs1;




--4. Create another table course(course_code, name, credit, fk[offered_by_dept_ID]) in tbs2.
CREATE TABLE course
(
    course_code NUMBER, 
    name VARCHAR2(20), 
    credit NUMBER, 
    offered_by_dept_ID NUMBER,
    CONSTRAINT course_code_PK PRIMARY KEY (course_code),
    CONSTRAINT offered_by_dept_ID_FK FOREIGN KEY (offered_by_dept_ID) REFERENCES DEPARTMENT(DEPT_ID)
) TABLESPACE tbs2;



--5. Insert a large amount of data in the student table and course table.
INSERT INTO DEPARTMENT VALUES (1, 'CSE');

INSERT INTO student VALUES ('A', 1, 1);
INSERT INTO student VALUES ('B', 2, 1);
INSERT INTO student VALUES ('C', 3, 1);
INSERT INTO student VALUES ('D', 4, 1);
INSERT INTO student VALUES ('E', 5, 1);

INSERT INTO course VALUES (1, 'CSE 101', 3, 1);
INSERT INTO course VALUES (2, 'CSE 102', 3, 1);
INSERT INTO course VALUES (3, 'CSE 103', 3, 1);
INSERT INTO course VALUES (4, 'CSE 104', 3, 1);
INSERT INTO course VALUES (5, 'CSE 105', 3, 1);

COMMIT;


--6. List the title and the name of the offering department of each course.
SELECT course.name, DEPARTMENT.DEPT_NAME
FROM course, DEPARTMENT
WHERE course.offered_by_dept_ID = DEPARTMENT.DEPT_ID;


--7. Check the free space of the tablespaces.
SELECT TABLESPACE_NAME, BYTES/1024/1024 MB
FROM DBA_FREE_SPACE
WHERE TABLESPACE_NAME = 'tbs1';

SELECT TABLESPACE_NAME, BYTES/1024/1024 MB
FROM DBA_FREE_SPACE
WHERE TABLESPACE_NAME = 'tbs2';


--8. Extend tbs1 by adding extra data files.
ALTER TABLESPACE tbs1 
ADD DATAFILE 'tbs1_data2.dbf' SIZE 1M;



--9. Extend tbs2 by resizing data files.
ALTER DATABASE DATAFILE 'tbs2_data.dbf' RESIZE 2M;



--10. Check the size of the tablespaces.
SELECT TABLESPACE_NAME, BYTES/1024/1024 MB
FROM DBA_DATA_FILES
WHERE TABLESPACE_NAME = 'tbs1';

SELECT TABLESPACE_NAME, BYTES/1024/1024 MB
FROM DBA_DATA_FILES
WHERE TABLESPACE_NAME = 'tbs2';



--11. Set tbs1 to offline and show that the data cannot be accessed.
ALTER TABLESPACE tbs1 OFFLINE;
SELECT * FROM student;



--12. Delete tablespace tbs1 including the data files.
DROP TABLESPACE tbs1 INCLUDING CONTENTS AND DATAFILES CASCADE CONSTRAINTS;



--13. Delete tablespace tbs2 excluding the data files.
DROP TABLESPACE tbs2 INCLUDING CONTENTS;