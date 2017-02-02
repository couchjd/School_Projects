import java.util.Scanner;
/**
 * Adds two integers and prints the sum.
 * 
 * @author Jeff Couch 
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
        System.out.println("Enter two whole numbers on a line:");
        
        //Gets input from user
        Scanner keyboard = new Scanner(System.in);
        n1 = keyboard.nextInt();
        n2 = keyboard.nextInt();
        
        System.out.println("The sum of those two number is: ");
        System.out.println(n1+n2);
    }
}
