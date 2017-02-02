import java.util.Scanner;
/**
 * Prints each digit of a four-digit number on different lines.
 * 
 * @author Jeff Couch 
 * @version v1.0
 * @since 2014-01-21
 */
public class Prob5
{
    public static void main(String[] args)
    {
        String inputString;
        Scanner input = new Scanner(System.in);
        System.out.print("Input a four-digit integer: ");
        inputString = input.next();
        for(int x = 0; x < inputString.length(); x++)
        {
            System.out.println(inputString.charAt(x));
        }    
    }
}
