import java.util.Scanner;
/**
 * Adds two integers and prints the sum.
 * 
 * @author Jeff Couch 
 * @version v1.0
 */
public class AddThreeNumbers
{
    public static void main(String[] args)
    {
        //input variables
        int n1, n2, n3;
        
        System.out.println("Hello out there.");
        System.out.println("I will add three numbers for you.");
        System.out.println("Enter three whole numbers on a line:");
        
        //Gets input from user
        Scanner keyboard = new Scanner(System.in);
        n1 = keyboard.nextInt();
        n2 = keyboard.nextInt();
        n3 = keyboard.nextInt();
        
        System.out.println("The sum of those three number is: ");
        System.out.println(n1+n2+n3);
    }
}