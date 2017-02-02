
/**
 * An exception for handling division by zero
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 05.07.2014
 */
public class DivideByZeroException extends Exception
{
    /**
     * Default constructor
     */
    public DivideByZeroException()
    {
        super("Divide by zero error.");
    }
    /**
     * Constructor
     * 
     * @param message
     */
    public DivideByZeroException(String message)
    {
        super(message);
    }
}
