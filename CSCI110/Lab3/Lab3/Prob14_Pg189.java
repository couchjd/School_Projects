import java.util.*;
/**
 * Prompts user to input a selection and then displays their choice using a switch statement and an enumeration.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 2014-29-01
 */
public class Prob14_Pg189
{
    public enum Choice {a, b, c, d, e, x}
    public static void main(String[] args)
    {
        char inputChar;
        boolean choose = false;
        Choice userChoice;        
        Scanner input = new Scanner(System.in);

        do
        {
            choose = false;
            System.out.println("a. Open");
            System.out.println("b. Save");
            System.out.println("c. Save as");
            System.out.println("d. Print");
            System.out.println("e. Quit");
            System.out.print("Enter your selection: ");

            userChoice = Choice.valueOf(input.next().toLowerCase());

            switch(userChoice)
            {
                case a: System.out.println("You have chosen a. Open.");
                    break;
                case b: System.out.println("You have chosen b. Save.");
                    break;
                case c: System.out.println("You have chosen c. Save as.");
                    break;
                case d: System.out.println("You have chosen d. Print.");
                    break;
                case e: System.out.println("You have chosen e. Quit.");
                    break;
                default: System.out.println("Invalid choice!");
                    choose = true;
            }
        }while(choose == true);
    }
}
