set serveroutput on;


--1) 
Begin
DBMS_OUTPUT.PUT_LINE('My set is : Alpha');
End;
/



--2)
Select Act_firstname, Act_lastname
From Actor
Where Act_id in 
(
    Select Act_id
    From Casts c , movie m
    Where C.Mov_id = m.Mov_id
    And m.Mov_title = c.Role
);


--3) 
SELECT GEN_TITLE
FROM GENRES
WHERE GEN_ID IN 
(
    SELECT GEN_ID
    FROM MTYPE
    WHERE MOV_ID IN 
    (
        SELECT MOV_ID
        FROM CASTS
        WHERE ACT_ID IN 
        (
            SELECT ACT_ID
            FROM ACTOR
            WHERE ACT_GENDER = 'M'
        )
        GROUP BY MOV_ID
        HAVING COUNT(ACT_ID) > 
        (
            SELECT COUNT(*)
            FROM CASTS
            WHERE MOV_ID = MOV_ID
        ) / 2
    )
);



--4) 
CREATE OR REPLACE PROCEDURE movie_Time (movie_title VARCHAR2)
IS
    movie_duration NUMBER;
    ans_duration NUMBER:= 0;
    ans_hour NUMBER;
    ans_minute NUMBER;
BEGIN
    SELECT m.mov_time INTO movie_duration
    FROM MOVIE m
    WHERE m.mov_title = movie_title;

    while(movie_duration > 0)
    loop
        if(movie_duration>=70)
        then
           movie_duration := movie_duration - 70;
           ans_duration := ans_duration + 70;
        else
              ans_duration := ans_duration + movie_duration;
              movie_duration := movie_duration - movie_duration;
        end if;
        if(movie_duration > 30)
        then
            ans_duration := ans_duration + 15;
        end if;
       
    end loop;

    ans_hour := TRUNC(ans_duration / 60);
    ans_minute := ans_duration - (ans_hour * 60);

    DBMS_OUTPUT.PUT_LINE('Movie Duration: ' || ans_hour || ' hour ' || ans_minute || ' minute');

END;
/

--Call the procedure
DECLARE
    title VARCHAR2(100);
BEGIN
    title:= '&title';
    movie_Time(title);
END;
/



--5)

-- Check if the user has rated any movie of the genre
Create or replace function has_rated (user_id number, Gen_id number)
return number
is
    rate number;
begin
    select count(*) into rate
    from Rating r, Movie m, REVIEWER u, MTYPE t
    where r.mov_id = m.mov_id
    and r.rev_id = u.rev_id
    and u.Rev_id = user_id
    and m.mov_id = t.mov_id
    and t.gen_id = Gen_id;
    return rate;
end;
/



-- Find the average rating of the genre
Create or replace function avg_rating (Gen_id number)
return number
is
    avg_rate number;
begin
    select avg(r.rev_stars) into avg_rate
    from Rating r, MTYPE t
    where r.mov_id = t.mov_id
    and t.gen_id = Gen_id;
    return avg_rate;
end;
/


-- Find the average rating of the genre by the user
Create or replace function avg_rating_user (user_id number, Gen_id number)
return number
is
    avg_rate number;
begin
    select avg(r.rev_stars) into avg_rate
    from Rating r, Movie m, REVIEWER u, MTYPE t
    where r.mov_id = m.mov_id
    and r.rev_id = u.rev_id
    and u.Rev_id = user_id
    and m.mov_id = t.mov_id
    and t.gen_id = Gen_id;
    return avg_rate;
end;
/



-- Trigger ans
Create or replace Trigger verify_review After insert on Rating
For each row
DECLARE
    Gen_id number;
    Rev_id number;
Begin
    select t.gen_id, r.rev_id into Gen_id, Rev_id
    from Rating r, MTYPE t
    where r.mov_id = t.mov_id
    and r.rev_id = :new.rev_id;

    if(has_rated(Rev_id, Gen_id) = 0)
    then
        DBMS_OUTPUT.PUT_LINE('You have not rated any movie of this genre');
        DBMS_OUTPUT.PUT_LINE('Average rating of this genre is: ' || avg_rating(Gen_id));

    else
        DBMS_OUTPUT.PUT_LINE('You have rated a movie of this genre');
        DBMS_OUTPUT.PUT_LINE('Your average rating of this genre is: ' || avg_rating_user(Rev_id, Gen_id));

    end if;
End;
/










--6) 
-- Function to get the SM.
Create or replace function same_movie_reviewer (rev_id number)
return number
is
    ans number;
    star number;
    total_star number:=0;
    total number:=0;
    Crusor c1 is
    select r.rev_id, r.mov_id
    from Rating r
    where r.mov_id in 
    (
        select mov_id
        from Rating
        where rev_id = rev_id
    )
    group by r.rev_id

begin
    for i in c1
    loop
        select rev_stars into star from Rating where rev_id = i.rev_id and mov_id = i.mov_id;
        total_star := total_star + star;
        total := total + 1;
    end loop;
    
    ans := total_star / total;
    return ans;
end;
/



Create or replace function same_genre_reviewer (rev_id number, gen_id number)
return number
is
    rev number;
begin
    select r.rev_id into rev
    from Rating r, MTYPE t
    where r.mov_id = t.mov_id
    and t.gen_id = gen_id
    and r.rev_id in 
    (
        select rev_id
        from Rating
        where rev_id = rev_id
    )
    group by r.rev_id
    order by count(*) desc;

    return rev;
end;