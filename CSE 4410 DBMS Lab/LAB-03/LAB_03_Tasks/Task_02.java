import java.sql.*;
import java.util.Scanner;

public class Task_02
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the day of the week:");
        String day = scanner.nextLine();
        System.out.println("Enter the starting hour:");
        int startHour = scanner.nextInt();
        System.out.println("Enter the ending hour:");
        int endHour = scanner.nextInt();


        String Username = "cse4409";
        String Password = "cse4409";
        String URL = "jdbc:oracle:thin:@localhost:1521:xe";

        String t1 = "SELECT i.name " + "FROM instructor i, teaches t, section s, time_slot ts " +
                "WHERE i.ID = t.ID AND " +
                "t.course_id = s.course_id AND t.sec_id = s.sec_id AND t.semester = s.semester AND t.year = s.year AND "
                +
                "s.time_slot_id = ts.time_slot_id AND ts.day = ? AND ts.start_hr >= ? AND ts.end_hr <= ?";




        try
        {
            Class.forName("oracle.jdbc.driver.OracleDriver");
            Connection connection = DriverManager.getConnection(URL, Username, Password);
            PreparedStatement pstmt = connection.prepareStatement(t1);
            pstmt.setString(1, day);
            pstmt.setInt(2, startHour);
            pstmt.setInt(3, endHour);

            ResultSet rs = pstmt.executeQuery();
            while (rs.next())
            {
                System.out.println(rs.getString("name"));
            }
            connection.close();
        }
        catch (SQLException e)
        {
            System.out.println("Connection Failed : \n");
            e.printStackTrace();
        }
        catch (ClassNotFoundException e)
        {
            System.out.println("Driver Not Found : " + e.getMessage());
        }
    }
}
