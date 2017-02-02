import java.util.*;
/**
 * Interface for Rational class
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 05.07.2014
 */
public interface RationalInterface
{
    /**
     * Prompts user for a numerator and a denominator, checks if the
     * values are valid and prints the result of the division.
     * 
     * @throws InputMismatchException
     * @throws DivideByZeroException
     */
    public void doRational() throws InputMismatchException, DivideByZeroException;
    /**
     * Checks for valid user input values.
     * 
     * @throws InputMismatchException
     */
    public int setUserInput() throws InputMismatchException;
    /**
     * Allows user another try at entering valid input values
     * 
     * @param e
     * @throws InputMismatchException
     */
    public void handleInputMismatchException(InputMismatchException e);
    /**
     * Performs division of numerator by denominator if denominator is not zero.
     * Otherwise, throws an DivideByZeroException
     * 
     * @throws DivideByZeroException
     */
    public double calcRational() throws DivideByZeroException;
}
