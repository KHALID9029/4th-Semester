import java.sql.*;

public class Task_01
{
    public static void main(String[] args)
    {
        String sqlQuery = "Update department set budget=budget*0.9 where budget>99999";
        String sql2 = "Select count(*) from department where budget<=99999";
        String name;
        int amount ;
        int count=0;

        try
        {
            // 1) load the driver class
            Class . forName ("oracle.jdbc.driver.OracleDriver");

            // 2) create the connection object
            Connection con = DriverManager. getConnection ("jdbc:oracle:thin:@localhost:1521:xe", "cse4409", "cse4409");
            System . out . println (" Connection to database successful ");

            // 3) Create the Statement object
            Statement statement = con . createStatement ();

            // 4) Execute the query
            ResultSet result = statement . executeQuery ( sql2);

            while(result.next())
            {
                System.out.println("Number of unaffected departments = "+result.getInt(1));
            }

            statement.executeUpdate(sqlQuery);


            // 5) Close the connection object
            con . close ();
            statement . close ();

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
