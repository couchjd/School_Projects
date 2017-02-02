import java.util.*;
/**
 * Prompts user to input a selection and then displays their choice using a mulit-branch if-else statement.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 2014-29-01
 */
public class Prob15_Pg189
{
    public static void main(String[] args)
    {
        char inputChar;
        boolean choose = false;

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

            inputChar = input.next().toLowerCase().charAt(0);

            if(inputChar == 'a')
            {    
                System.out.println("You have chosen a. Open.");
            }
            else if(inputChar == 'b')
            {
                System.out.println("You have chosen b. Save.");
            }
            else if(inputChar == 'c')
            {
                System.out.println("You have chosen c. Save as.");
            }
            else if(inputChar == 'd')
            {
                System.out.println("You have chosen d. Print.");
            }
            else if(inputChar == 'e')
            {
                System.out.println("You have chosen e. Quit.");
            }
            else
            {
                System.out.println("Invalid choice.");
                choose = true;
            }

        }while(choose == true);
    }
}
