
/**
 * A class for modeling generic Citizen objects
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 05.07.2014
 */
public class Citizen implements CitizenInterface
{
    private String firstName;
    private String lastName;
    
    /**
     * Default constructor
     */
    public Citizen()
    {
        firstName = null;
        lastName = null;
    }
    /**
     * Constructor that sets firstName and lastName
     * 
     * @param inFirst
     * @param inLast
     */
    public Citizen(String inFirst, String inLast)
    {
        firstName = inFirst;
        lastName = inLast;
    }
    /**
     * Setter for firstName
     * 
     * @param inFirst
     */    
    public void setFirstName(String inFirst)
    {
        firstName = inFirst;
    }
    /**
     * Getter for firstName
     * 
     * @return firstName
     */
    public String getFirstName()
    {
        return firstName;
    }
    /**
     * Setter for lastName
     * 
     * @param inLast
     */
    public void setLastName(String inLast)
    {
        lastName = inLast;
    }
    /**
     * Getter for lastName
     * 
     * @return lastName
     */
    public String getLastName()
    {
        return lastName;
    }
    /**
     * Provides a string representation of a Citizen object
     * 
     * @return string containing firstName and lastName
     */
    public String toString()
    {
        return(firstName + " " + lastName);
    }
}
