import java.util.Scanner;
/**
 * Converts a Farenheit temperature to Celsius.
 * 
 * @author Jeff Couch 
 * @version v1.0
 * @since 2014-01-21
 */
public class Prob6
{
    public static void main(String[] args)
    {
        double degF, degC;
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a temperature in degrees Farenheit: ");
        degF = input.nextDouble();
        degC = (5*(degF-32))/9;
        System.out.printf("%.0f degrees Farenheit is %3.1f degrees Celsius.\n"
        , degF, degC);
    }
}
