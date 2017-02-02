import java.util.InputMismatchException;
import java.util.Scanner;

/**
 * Class for performing division operations
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 05.07.2014
 */
public class Rational implements RationalInterface 
{
    private int numerator;
    private int denom;
    private double result;
    /**
     * Prompts user for a numerator and a denominator, checks if the
     * values are valid and prints the result of the division.
     * 
     * @throws InputMismatchException
     * @throws DivideByZeroException
     */    
    public void doRational() throws InputMismatchException, DivideByZeroException
    {
        Scanner input = new Scanner(System.in);
        char run;
        
        do
        {
            run = 'n';
            System.out.print("Please enter numerator: ");
            numerator = setUserInput();
            System.out.print("Please enter denominator: ");
            denom = setUserInput();
            result = calcRational();
            System.out.println("Result is " + result);
            System.out.print("Calculate another? ");
            run = input.next().toLowerCase().charAt(0);
        }while(run == 'y');        
    }
    /**
     * Checks for valid user input values.
     * 
     * @return value if value is valid it is returned to the caller
     * @throws InputMismatchException
     */    
    public int setUserInput() throws InputMismatchException
    {
        Scanner input = new Scanner(System.in);
        int value;
        try
        {    
            value = input.nextInt();
        }
        catch(InputMismatchException e)
        {
            throw new InputMismatchException("Input mismatch!");
        }
        return value;
    }
    /**
     * Allows user another try at entering valid input values
     * 
     * @param e
     * @throws InputMismatchException
     */
    public void handleInputMismatchException(InputMismatchException e)
    {
        System.out.println(e.getMessage());
        System.out.println("Please input non-zero integers: ");
        try
        {
            doRational();
        }
        catch(InputMismatchException e2)
        {
            System.out.println(e2.getMessage());
        }
        catch(DivideByZeroException e3)
        {
            System.out.println(e3.getMessage());
        }
    }
    /**
     * Performs division of numerator by denominator if denominator is not zero.
     * Otherwise, throws an DivideByZeroException
     * 
     * @return quotient of numerator/denominator
     * @throws DivideByZeroException
     */
    public double calcRational() throws DivideByZeroException
    {
        if(denom == 0)
            throw new DivideByZeroException();
        else
            return((double)numerator/denom);
    }
}
