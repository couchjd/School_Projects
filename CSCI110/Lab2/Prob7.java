import java.util.Scanner;
/**
 * Demonstrates string manipulation.
 * 
 * @author Jeff Couch 
 * @version v1.0
 * @since 2014-01-21
 */
public class Prob7
{
    public static void main(String[] args)
    {
        String inputString, newString;
        Scanner input = new Scanner(System.in);

        System.out.println("Enter a line of text: ");
        inputString = input.nextLine().trim();

        try
        {
            newString = inputString.substring(0, inputString.indexOf("like"))
                + "LOVE" + (inputString.substring(inputString.indexOf("like")+4));

            System.out.println("I have rephrased " + inputString);
            System.out.println("with String methods to read: " + newString);
            System.out.println("The output is " + inputString.length() + " chars long.");
        }

        catch(StringIndexOutOfBoundsException e)
        {
            System.out.println(inputString);
        }

    }
}