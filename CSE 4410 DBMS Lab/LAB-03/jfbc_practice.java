import java.sql.*;
class jdbc_practice
{
    public static void main(String args[])
    {
        try {
// step1 load the driver class
            Class.forName("oracle.jdbc.driver.OracleDriver");
// step2 create the connection object
            Connection con = DriverManager.getConnection(

                    "jdbc:oracle:thin:@localhost:1521:xe", "cse4409", "cse4409");

// step3 create the statement object
            Statement stmt = con.createStatement();
// step4 execute query
// drop table
            System.out.println("Drop table...");
            String sql = "DROP TABLE REGISTRATION";
            stmt.executeUpdate(sql);
// create table
            String sql1 = "CREATE TABLE REGISTRATION " +

                    "(id INTEGER not NULL, " +
                    " first VARCHAR(255), " +
                    " last VARCHAR(255), " +
                    " age INTEGER, " +
                    " PRIMARY KEY ( id ))";
            stmt.executeUpdate(sql1);
// insert table
            System.out.println("Inserting records into the table...");
            String sql2 = "INSERT INTO Registration VALUES (100, 'Zara', 'Ali',

            18)";

            stmt.executeUpdate(sql2);
            sql2 = "INSERT INTO Registration VALUES (101, 'Mahnaz', 'Fatma', 25)";
            stmt.executeUpdate(sql2);
// select table
            System.out.println("Selecting records from the table...");
            String QUERY = "SELECT id, first, last, age FROM Registration";
            ResultSet rs = stmt.executeQuery(QUERY);
            while (rs.next()) {
// Display values
                System.out.print("ID: " + rs.getInt("id"));
                System.out.print(", Age: " + rs.getInt("age"));
                System.out.print(", First: " + rs.getString("first"));
                System.out.println(", Last: " + rs.getString("last"));
            }
            rs.close();
// update table
            System.out.println("Updating records from the table...");
            String sql3 = "UPDATE Registration " +

                    "SET age = 30 WHERE id in (100, 101)";

            stmt.executeUpdate(sql3);
// delete table
            System.out.println("deleting records from the table...");
            String sql4 = "DELETE FROM Registration " +

                    "WHERE id = 101";
            stmt.executeUpdate(sql4);
// step5 close the connection object
            con.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}