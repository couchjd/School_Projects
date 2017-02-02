
/**
 * Interface for Citizen class
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 05.07.2014
 */
public interface CitizenInterface
{
    /**
     * Setter for firstName
     * 
     * @param inFirst
     */
    public void setFirstName(String inFirst);
    /**
     * Getter for firstName
     * 
     * @return firstName
     */    
    public String getFirstName();
    /**
     * Setter for lastName
     * 
     * @param inLast
     */    
    public void setLastName(String inLast);
    /**
     * Getter for lastName
     * 
     * @return lastName
     */    
    public String getLastName();
    /**
     * Provides a string representation of a Citizen object
     * 
     * @return string containing firstName and lastName
     */    
    public String toString();
}
