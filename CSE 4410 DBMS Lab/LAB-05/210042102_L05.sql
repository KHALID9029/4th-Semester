--1.
Declare
    dept_name department.dept_name%type;
    budget department.budget%type;

    Cursor c1 is
        Select dept_name, budget
        From department
        Where budget > 99999;

    Cursor c2 is
        Select count(*) as num
        From department
        Where budget <= 99999;

Begin
    For i in c2
    Loop
        dbms_output.put_line('Number of departments that did not get affected: ');
        dbms_output.put_line(i.num);
    End Loop;

    For i in c1
    Loop
        Update department
        Set budget = budget * 0.9
        Where dept_name = i.dept_name;

        dbms_output.put_line('Department: ' || i.dept_name || ' Budget: ' || i.budget);
    End Loop;

End;
/


--2.
Declare 
    day time_slot.day%type;
    start_hr time_slot.start_hr%type;
    end_hr time_slot.end_hr%type;

    Cursor T_Schedule (day time_slot.day%type, start_hr time_slot.start_hr%type, end_hr time_slot.end_hr%type)
    is
        SELECT i.name FROM instructor i, teaches t, section s, time_slot ts
        WHERE i.ID = t.ID 
        AND t.course_id = s.course_id 
        AND t.sec_id = s.sec_id 
        AND t.semester = s.semester 
        AND t.year = s.year 
        AND s.time_slot_id = ts.time_slot_id 
        AND ts.day = day 
        AND ts.start_hr >= start_hr 
        AND ts.end_hr <= end_hr;

Begin
    day := '&day';
    start_hr := '&start_hr';
    end_hr := '&end_hr';

    For i in T_Schedule(day, start_hr, end_hr)
    Loop
        dbms_output.put_line(i.name);
    End Loop;

End;
/



--3.
Declare
    n number;
    count number:= 0;
    Cursor c1(n number) is
    Select *
    From 
    (
        Select s.ID, s.name, s.dept_name, count(*) as num
        From student s, takes t
        Where s.ID = t.ID
        Group by s.ID, s.name, s.dept_name
        Order by num desc
    )
    Where ROWNUM <= n;


Begin
    n := &n;

    For i in c1(n)
    Loop
        dbms_output.put_line('ID: ' || i.ID || ' Name: ' || i.name || ' Department: ' || i.dept_name || ' Number of courses: ' || i.num); 
    End Loop;

End;
/




--4.
Declare
    max_ID student.ID%type;
    dept_name department.dept_name%type;

    Cursor c1 is
        Select dept_name
        From student
        Group by dept_name
        Having count(*) = (Select min(count(*)) From student Group by dept_name);

    Cursor c2 is
        Select max(ID) as max_ID
        From student;

Begin
    For i in c2
    Loop
        max_ID := i.max_ID;
    End Loop;

    For i in c1
    Loop
        dept_name := i.dept_name;
    End Loop;

    Insert into student
    Values (max_ID + 1, 'Jane Doe', dept_name, 0);

End;
/





--5.
Declare
    ID student.ID%type;
    name student.name%type;
    dept_name student.dept_name%type;
    i_ID instructor.ID%type;
    i_name instructor.name%type;
    num number;

    Cursor c1 is
        Select s.ID, s.name, s.dept_name
        From student s
        Where s.ID not in (Select s_ID From advisor);

    Cursor c2(dept_name student.dept_name%type) is
        Select i.ID, i.name, count(*) as num
        From instructor i, advisor a, student s
        Where i.ID = a.i_ID
        And a.s_ID = s.ID
        And s.dept_name = dept_name
        Group by i.ID, i.name
        Order by num;

Begin
    For i in c1
    Loop
        ID := i.ID;
        name := i.name;
        dept_name := i.dept_name;

        For j in c2(dept_name)
        Loop
            i_ID := j.ID;
            i_name := j.name;
            num := j.num;
            Exit;
        End Loop;

        Insert into advisor
        Values (ID, i_ID);

        dbms_output.put_line('Student: ' || name || ' Advisor: ' || i_name || ' Number of students advised: ' || num);
    End Loop;

End;
/