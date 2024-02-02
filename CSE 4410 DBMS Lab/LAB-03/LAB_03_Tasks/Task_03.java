import java.sql.*;
import java.util.Scanner;

public class Task_03
{
    public static void main(String[] args)
    {
        String Username = "cse4409";
        String Password = "cse4409";
        String URL = "jdbc:oracle:thin:@localhost:1521:xe";

        String sql="select ID, name, dept_name, count(course_id) as numCourses " +
        "from student natural join takes " +
        "group by ID, name, dept_name " +
        "order by numCourses desc";

        System.out.println("Enter Number of students to be displayed:");
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        try
        {
            Class . forName ("oracle.jdbc.driver.OracleDriver");
            Connection connection = DriverManager.getConnection(URL, Username, Password);
            System . out . println (" Connection to database successful ");

            Statement statement = connection . createStatement ();
            ResultSet result = statement . executeQuery ( sql);

            while(result.next() && n>0)
            {
                System.out.println(result.getString("ID")+" "+result.getString("name")+" "+result.getString("dept_name")+" "+result.getString("numCourses"));
                n--;
            }
        }

        catch ( SQLException e)
        {
            System . out . println (" Error while connecting to database . Exception code : " + e);
        }

        catch ( ClassNotFoundException e)
        {
            System . out . println (" Failed to register driver . Exception code : " + e);
        }
        System . out . println (" Thank You !");
    }
}