import java.util.*;
/**
 * Driver for demonstrating Rational objects
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 05.07.2014
 */
public class RationalDemo
{
    public static void main(String[] args)
    {
        Rational rat1 = new Rational();
        try
        {
            rat1.doRational();
        }
        catch(InputMismatchException e)
        {
            rat1.handleInputMismatchException(e);
        }
        catch(DivideByZeroException e)
        {
            System.out.println(e.getMessage());
        }
        finally
        {
            System.out.println("Thank you for playing.");
        }
    }    
}
