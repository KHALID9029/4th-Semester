-- 1. 
Select name From instructor Where dept_name = 'Biology';


--2. 
Select course_id, title From course Where course_id In 
(Select course_id From takes Where ID = '73492');

--3. 
Select name, dept_name From student Where ID In
(Select ID From takes Where course_id In
(Select course_id From course Where dept_name = 'Comp. Sci.'));

--4. 
Select name From student Where ID In
(Select ID From takes Where course_id = 'CS-101' And semester = 'Spring' And year = 2018);

--5.
SELECT s.name
FROM student s
WHERE s.ID IN 
(
    SELECT ID FROM takes t
    WHERE t.course_id LIKE 'CS%'
    GROUP BY t.ID
    HAVING COUNT(*) = 
    (
        SELECT MAX(course_count)
        FROM 
        (
            SELECT COUNT(*) as course_count
            FROM takes tt
            WHERE tt.course_id LIKE 'CS%'
            GROUP BY tt.ID
        )
    )
);

--6. 
SELECT s.name 
FROM student s
WHERE s.ID IN 
(
    SELECT t.ID FROM takes t
    WHERE t.course_id IN 
    (
        SELECT course_id FROM teaches
        GROUP BY course_id
        HAVING COUNT(DISTINCT ID) >= 3
    )
);

--7. 
SELECT c.title, s.sec_id
FROM course c, section s
WHERE c.course_id = s.course_id
AND s.course_id IN 
(
    SELECT t.course_id
    FROM takes t
    GROUP BY t.course_id
    HAVING COUNT(*) = 
    (
        SELECT MIN(enrollment_count)
        FROM 
        (
            SELECT COUNT(*) as enrollment_count
            FROM takes tt
            GROUP BY tt.course_id
            Having COUNT(*) > 0
        )
    )
);

--8. 
SELECT i.name, i.dept_name, COUNT(a.s_ID) as student_count
FROM instructor i LEFT JOIN advisor a
ON i.ID = a.i_ID
GROUP BY i.ID, i.name, i.dept_name;

--9. 
SELECT s.name, s.dept_name
FROM student s
WHERE s.ID IN 
(
    SELECT ID FROM takes t
    GROUP BY t.ID
    HAVING COUNT(*) > 
    (
        SELECT AVG(course_count)
        FROM 
        (
            SELECT COUNT(*) as course_count
            FROM takes tt
            GROUP BY tt.ID
        )
    )
);

--10. 
INSERT INTO student
(SELECT i.ID, i.name, i.dept_name, 0
FROM instructor i where i.id<>'76543');

--11. 
DELETE FROM student
WHERE ID IN 
(
    SELECT ID FROM instructor where id<>'76543'
);

--12. 
UPDATE student
SET tot_cred = 
(
    SELECT SUM(credits)
    FROM course c, takes t
    WHERE c.course_id = t.course_id
    AND t.ID = student.ID
    GROUP BY t.ID
)
WHERE ID IN 
(
    SELECT ID FROM takes
);

--13. 
UPDATE instructor
SET salary = CASE 
    WHEN (SELECT COUNT(*) * 10000 FROM teaches t WHERE t.instructor_ID = instructor.ID GROUP BY t.instructor_ID) < 29000
    THEN 29000
    ELSE (SELECT COUNT(*) * 10000 FROM teaches t WHERE t.instructor_ID = instructor.ID GROUP BY t.instructor_ID)
END
WHERE ID IN (SELECT instructor_ID FROM teaches);


--14.
Create table grade_point
(
    grade varchar(2) primary key,
    point numeric(2,0) not null
);

INSERT INTO grade_point VALUES ('A', 10);
INSERT INTO grade_point VALUES ('B', 8);
INSERT INTO grade_point VALUES ('C', 6);
INSERT INTO grade_point VALUES ('D', 4);
INSERT INTO grade_point VALUES ('F', 0);

SELECT s.ID, s.name, s.dept_name, SUM(g.point * c.credits) / SUM(c.credits) as CPI
FROM student s, takes t, course c, grade_point g
WHERE s.ID = t.ID
AND t.course_id = c.course_id
AND t.grade = g.grade
GROUP BY s.ID, s.name, s.dept_name;