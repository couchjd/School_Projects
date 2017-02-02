import java.util.Scanner;
/**
 * Adds two numbers.
 * 
 * @since 1-15-2014
 * @author Jeff Couch, couchjeffrey@yahoo.com
 * @version v1.0
 */
public class AddTwoNumbers
{
    public static void main(String[] args)
    {
        //input variables
        int n1, n2;

        System.out.println("Hello out there.");
        System.out.println("I will add two numbers for you.");
        System.out.println("Enter two whole numbers on a line: ");

        //Gets input from the user
        Scanner keyboard = new Scanner(System.in);
        n1 = keyboard.nextInt();
        n2 = keyboard.nextInt();

        System.out.println("The sum of those two numbers is: ");
        System.out.println(n1+n2);
    }
}