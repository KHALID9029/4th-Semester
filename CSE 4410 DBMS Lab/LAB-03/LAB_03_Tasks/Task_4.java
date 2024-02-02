import java.sql.*;

public class Task_4
{
    public static void main(String[] args)
    {
        String Username = "cse4409";
        String Password = "cse4409";
        String URL = "jdbc:oracle:thin:@localhost:1521:xe";

        String dept_name="";
        int Id=0;

        String sql1="select dept_name" +
                "        from student" +
                "        group by dept_name" +
                "        having count(ID) =" +
                "            (" +
                "                    select min(numStudents)" +
                "        from" +
                "                (" +
                "                        select count(ID) as numStudents" +
                "                        from student" +
                "                        group by dept_name" +
                "                )" +
                ")";

        String sql2="select max(ID) from student";

        try
        {
            Class . forName ("oracle.jdbc.driver.OracleDriver");
            Connection connection = DriverManager.getConnection(URL, Username, Password);
            System . out . println (" Connection to database successful ");

            Statement statement = connection . createStatement ();
            ResultSet result = statement . executeQuery ( sql1);
            while(result.next())
            {
                dept_name=result.getString("dept_name");
            }

            result = statement . executeQuery ( sql2);
            while(result.next())
            {
                Id = result.getInt("ID");
            }
            String sql3="insert into student values ("+(Id+1)+",'Jane Doe','"+dept_name+"',0)";
            statement.executeUpdate(sql3);
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