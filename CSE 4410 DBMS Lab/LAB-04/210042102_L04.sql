SET SERVEROUTPUT ON;

-- PRINT YOUR NAME
Begin
DBMS_OUTPUT.PUT_LINE('KHALID HASAN ADOR');
End;
/

--ID
DECLARE
ID VARCHAR2(10);
Begin
ID:='&ID';
DBMS_OUTPUT.PUT_LINE('ID LENGTH: '||LENGTH(ID));
End;
/



--1)
DECLARE
    i_name instructor.name%TYPE;
    i_id instructor.ID%TYPE;
    i_dept instructor.dept_name%TYPE;
    i_salary instructor.salary%TYPE;
    i_total_credits NUMBER;
    i_total_salary NUMBER;
    
    
    CURSOR c_instructor IS
        SELECT i.name, i.ID, i.dept_name, i.salary, SUM(c.credits) AS total_credits
        FROM instructor i
        LEFT JOIN teaches t ON i.ID = t.ID
        LEFT JOIN course c ON t.course_id = c.course_id
        GROUP BY i.name, i.ID, i.dept_name, i.salary;

BEGIN
    FOR i_rec IN c_instructor LOOP
        i_name := i_rec.name;
        i_id := i_rec.ID;
        i_dept := i_rec.dept_name;
        i_salary := i_rec.salary;
        i_total_credits := i_rec.total_credits;
        i_total_salary := i_total_credits * 9000;
        
        
        IF i_total_salary = i_salary THEN
            DBMS_OUTPUT.PUT_LINE('Instructor ' || i_name || ' salary remains unchanged.');
        ELSE
            UPDATE instructor
            SET salary = 
            case 
            when i_total_salary<29001 then i_salary
            else i_total_salary end
            WHERE ID = i_id;
            DBMS_OUTPUT.PUT_LINE('Instructor ' || i_name || ' salary updated to ' || i_total_salary);
        END IF;
    END LOOP;
END;
/


--2)
DECLARE
cursor c_course is
select c.title, s.name
from course c
left join prereq p on c.course_id = p.course_id
left join takes t on p.prereq_id = t.course_id
left join student s on t.ID = s.ID
where t.grade is not null
group by c.title, s.name;

BEGIN
    FOR REC IN c_course LOOP
        DBMS_OUTPUT.PUT_LINE('Course Title: ' || rec.title || ' Student Name: ' || rec.name);
    END LOOP;
END;
/





--3)
DECLARE
    name VARCHAR2(100);
    
    CURSOR ROUTINE IS
        SELECT s.name, c.course_id, c.title, ts.day, ts.start_hr, ts.start_min, ts.end_hr, ts.end_min, sec.building, sec.room_number
        FROM student s
        LEFT JOIN takes t ON s.ID = t.ID
        LEFT JOIN section sec ON t.course_id = sec.course_id
        LEFT JOIN time_slot ts ON sec.time_slot_id = ts.time_slot_id
        LEFT JOIN course c ON sec.course_id = c.course_id
        WHERE s.name = name
        ORDER BY ts.day, ts.start_hr, ts.start_min;

BEGIN
    
    name := '&name'; 

    FOR RE IN ROUTINE LOOP
        DBMS_OUTPUT.PUT_LINE('Student Name: ' || RE.name );
        DBMS_OUTPUT.PUT_LINE('Course ID: ' || RE.course_id );
        DBMS_OUTPUT.PUT_LINE('Course Title: ' || RE.title );
        DBMS_OUTPUT.PUT_LINE('Day: ' || RE.day );
        DBMS_OUTPUT.PUT_LINE('Start Time: ' || RE.start_hr || ':' || RE.start_min );
        DBMS_OUTPUT.PUT_LINE('End Time: ' || RE.end_hr || ':' || RE.end_min );
        DBMS_OUTPUT.PUT_LINE('Building: ' || RE.building);
        DBMS_OUTPUT.PUT_LINE('Room Number: ' || RE.room_number);
    END LOOP;
END;
/




--4)
DECLARE
    CURSOR c_instructor IS
        SELECT i.ID, i.name, i.dept_name
        FROM instructor i
        LEFT JOIN advisor a ON i.ID = a.i_ID
        WHERE a.i_ID IS NULL
        ORDER BY i.dept_name;
        
    CURSOR c_student IS
        SELECT s.ID, s.name, s.dept_name, s.tot_cred
        FROM student s
        LEFT JOIN advisor a ON s.ID = a.s_ID
        WHERE a.s_ID IS NULL
        ORDER BY s.dept_name, s.tot_cred;
        
    instructor_id instructor.ID%TYPE;
    instructor_name instructor.name%TYPE;
    instructor_dept instructor.dept_name%TYPE;

    student_id student.ID%TYPE;
    student_name student.name%TYPE;
    student_dept student.dept_name%TYPE;
    student_tot_cred student.tot_cred%TYPE;

BEGIN
    FOR i_rec IN c_instructor LOOP
        instructor_id := i_rec.ID;
        instructor_name := i_rec.name;
        instructor_dept := i_rec.dept_name;
        
        FOR s_rec IN c_student LOOP
            student_id := s_rec.ID;
            student_name := s_rec.name;
            student_dept := s_rec.dept_name;
            student_tot_cred := s_rec.tot_cred;
            
            IF instructor_dept = student_dept THEN
                INSERT INTO advisor VALUES (student_id, instructor_id);
                DBMS_OUTPUT.PUT_LINE('Student ' || student_name || ' assigned to Instructor ' || instructor_name);
                EXIT;
            END IF;
        END LOOP;
    END LOOP;
    
    FOR i_rec IN c_instructor LOOP
        instructor_id := i_rec.ID;
        instructor_name := i_rec.name;
        instructor_dept := i_rec.dept_name;
        
        
        DBMS_OUTPUT.PUT_LINE('Instructor ' || instructor_name || ' still does not have any students assigned to them.');
        
    END LOOP;
END;
/




--5)Insert a new instructor named ‘John Doe’ in the INSTRUCTOR table. The instructor should be enrolled in the department having the highest number of students. The ID of the instructor will be (X − 1), where X is the lowest ID value among the existing instructors. The salary of the instructor should be the average among all the instructors of the same department. Finally, print the information of the instructor.
DECLARE
    instructor_id instructor.ID%TYPE;
    instructor_name instructor.name%TYPE;
    instructor_dept instructor.dept_name%TYPE;
    instructor_salary instructor.salary%TYPE;
    instructor_avg_salary NUMBER;
    instructor_new_id instructor.ID%TYPE;
    instructor_new_salary instructor.salary%TYPE;
    
    CURSOR c_instructor IS
        SELECT i.ID, i.name, i.dept_name, i.salary
        FROM instructor i
        LEFT JOIN student s ON i.dept_name = s.dept_name
        GROUP BY i.ID, i.name, i.dept_name, i.salary
        ORDER BY COUNT(s.ID) DESC;
        
    CURSOR c_instructor_salary IS
        SELECT i.salary
        FROM instructor i
        WHERE i.dept_name = instructor_dept;

BEGIN
    OPEN c_instructor;
    FETCH c_instructor INTO instructor_id, instructor_name, instructor_dept, instructor_salary;
    CLOSE c_instructor;
    
    SELECT MIN(ID) - 1 INTO instructor_new_id FROM instructor;
    
    SELECT AVG(salary) INTO instructor_avg_salary
    FROM instructor
    WHERE dept_name = instructor_dept;
    
    INSERT INTO instructor VALUES (instructor_new_id, 'John Doe', instructor_dept, instructor_avg_salary);
    
    DBMS_OUTPUT.PUT_LINE('Instructor ID: ' || instructor_new_id);
    DBMS_OUTPUT.PUT_LINE('Instructor Name: John Doe');
    DBMS_OUTPUT.PUT_LINE('Instructor Department: ' || instructor_dept);
    DBMS_OUTPUT.PUT_LINE('Instructor Salary: ' || instructor_avg_salary);
END;
/