import java.sql.*;

public class Task_05
{
    public static void main(String[] args)
    {
        String Username = "cse4409";
        String Password = "cse4409";
        String URL = "jdbc:oracle:thin:@localhost:1521:xe";

        int id;
        String name;
        String dept_name;

        String sql1="select ID, name, dept_name from student where ID not in (select s_ID from advisor)";


        try
        {
            Class . forName ("oracle.jdbc.driver.OracleDriver");
            Connection connection = DriverManager.getConnection(URL, Username, Password);
            System . out . println (" Connection to database successful ");

            Statement statement = connection . createStatement ();
            ResultSet result = statement . executeQuery ( sql1);
            while(result.next())
            {
                System.out.println(result.getString("ID")+" "+result.getString("name")+" "+result.getString("dept_name"));
                id=result.getInt("ID");
                name=result.getString("name");
                dept_name=result.getString("dept_name");


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