--1)
Create sequence biology_seq start with 1 increment by 1;
Create sequence comp_sci_seq start with 1 increment by 1;
Create sequence elec_eng_seq start with 1 increment by 1;
Create sequence finance_seq start with 1 increment by 1;
Create sequence history_seq start with 1 increment by 1;
Create sequence music_seq start with 1 increment by 1;
Create sequence physics_seq start with 1 increment by 1;

CREATE OR REPLACE FUNCTION generate_student_id(dept_name IN VARCHAR)
RETURN VARCHAR
AS
    student_id VARCHAR(50);
    student_count NUMBER;
BEGIN
    IF dept_name = 'Biology' THEN

        SELECT biology_seq.nextval INTO student_count FROM dual;
        student_id := '1' || LPAD(student_count, 4, '0');
    
    ELSIF dept_name = 'Comp. Sci.' THEN
        
        SELECT comp_sci_seq.nextval INTO student_count FROM dual;    
        student_id := '2' || LPAD(student_count, 4, '0');
    
    ELSIF dept_name = 'Elec. Eng.' THEN

        SELECT elec_eng_seq.nextval INTO student_count FROM dual;
        student_id := '3' || LPAD(student_count, 4, '0');
    
    ELSIF dept_name = 'Finance' THEN

        SELECT finance_seq.nextval INTO student_count FROM dual;
        student_id := '4' || LPAD(student_count, 4, '0');
    
    ELSIF dept_name = 'History' THEN

        SELECT history_seq.nextval INTO student_count FROM dual;
        student_id := '5' || LPAD(student_count, 4, '0');
    
    ELSIF dept_name = 'Music' THEN

        SELECT music_seq.nextval INTO student_count FROM dual;
        student_id := '6' || LPAD(student_count, 4, '0');
    
    ELSIF dept_name = 'Physics' THEN

        SELECT physics_seq.nextval INTO student_count FROM dual;
        student_id := '7' || LPAD(student_count, 4, '0');
    
    ELSE
       RAISE_APPLICATION_ERROR(-20001, 'Invalid department name');
       
    END IF;
    RETURN student_id;
END;
/






--2)
DECLARE
    CURSOR student_cursor IS
        SELECT ID, dept_name FROM student ORDER BY dept_name, name;
    
    NAME student.NAME%TYPE;
    dept_name student.dept_name%TYPE;
    student_id VARCHAR(50);
BEGIN
    FOR REC IN student_cursor LOOP
        student_id := generate_student_id(REC.dept_name);
        UPDATE student S SET ID = student_id 
        WHERE
            S.ID = REC.ID AND
            S.dept_name = REC.dept_name;
    END LOOP;
END;
/






--3)
CREATE OR REPLACE TRIGGER student_insert_trigger
BEFORE INSERT ON student
FOR EACH ROW
BEGIN
    :new.ID := generate_student_id(:new.dept_name);
END;
/



--4)
CREATE OR REPLACE TRIGGER update_tot_cred_trigger
AFTER INSERT ON takes
FOR EACH ROW
BEGIN
    UPDATE student S
    SET S.tot_cred = S.tot_cred + (SELECT C.credits FROM course C WHERE C.course_id = :new.course_id)
    WHERE S.ID = :new.ID;
END;
/