--1) Find the top N students based on the number of courses they are enrolled in. You should take N as input and print the ID, name, department name, and the number of courses taken by the student. If N is larger than the total number of students, print the information for all the students.
select ID, name, dept_name, count(course_id) as numCourses
from student natural join takes
group by ID, name, dept_name
order by numCourses desc;


--2) Find the department name with lowest number of students
select dept_name
from student
group by dept_name
having count(ID) = 
(
    select min(numStudents)
    from 
    (
        select count(ID) as numStudents
        from student
        group by dept_name
    )
);


--3) Select the highest id value among existing students
select max(ID)
from student;

--4) Select the students with no advisor
select ID, name, dept_name
from student
where ID not in (select s_ID from advisor);

--5) select the advisor with least number of students he advised in a certain department
select i_ID, count(s_ID) as numStudents
from advisor natural join student
where dept_name = 'Comp. Sci.'
group by i_ID
having count(s_ID) = 
(
    select min(numStudents)
    from 
    (
        select count(s_ID) as numStudents
        from advisor natural join student
        where dept_name = 'Comp. Sci.'
        group by i_ID
    )
);