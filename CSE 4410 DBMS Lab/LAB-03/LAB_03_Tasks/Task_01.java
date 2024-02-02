import java.sql.*;

public class Task_01
{
    public static void main(String[] args)
    {
        String sqlQuery = "Select dept_name,budget from department";
        String name;
        int amount ;
        int count=0;

        String Username = "cse4409";
        String Password = "cse4409";
        String URL = "jdbc:oracle:thin:@localhost:1521:xe";

        try
        {
            Class . forName ("oracle.jdbc.driver.OracleDriver");
            Connection connection = DriverManager.getConnection(URL, Username, Password);
            System . out . println (" Connection to database successful ");
            Statement statement = connection . createStatement ();


            ResultSet result = statement . executeQuery ( sqlQuery);

            while(result.next())
            {
                name= result.getString("dept_name");
                amount = result.getInt("budget");
                System.out.println("Department Name: "+name+" Budget: "+amount);
                if(amount<=99999)
                {
                    count++;
                }
                else
                {
                    int increase=amount*10/100;
                    amount=amount+increase;

                    String sqlQuery2 = "UPDATE department SET budget = "+amount+" WHERE dept_name = '"+name+"'";
                    Statement updatestatement = connection.createStatement();
                    updatestatement.executeUpdate(sqlQuery2);
                    System.out.println("New Budget of "+name+" is "+amount);
                    updatestatement.close();
                }
            }

            System.out.println("Number of departments unaffected: "+count);

            connection . close ();
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
