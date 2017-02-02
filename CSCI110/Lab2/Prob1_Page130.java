    import java.util.Scanner;
/**
 * Prints the average of three numbers input by user.
 * 
 * @author Jeff Couch 
 * @version v1.0
 * @since 2014-01-21
 */
public class Prob1_Page130
{
    public static void main(String[] args)
    {
        //input variables
        int n1, n2, n3;
        
        System.out.println("Hello out there.");
        System.out.println("I will average three numbers for you.");
        System.out.println("Enter three whole numbers on a line:");
        
        //Gets input from user
        Scanner keyboard = new Scanner(System.in);
        n1 = keyboard.nextInt();
        n2 = keyboard.nextInt();
        n3 = keyboard.nextInt();
        
        System.out.printf("The average of those three number is: %1.10f", ((float)(n1+n2+n3)/3));
        //System.out.println((double)(n1+n2+n3)/3);
    }
}
