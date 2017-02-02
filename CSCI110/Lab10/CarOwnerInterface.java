/**
 * Interface for CarOwner class
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 05.07.2014
 */
public interface CarOwnerInterface extends Comparable
{
    /**
     * Setter for license
     * 
     * @param inLicense
     */
    public void setLicense(String inLicense);
    /**
     * Getter for license
     * 
     * @return license
     */    
    public String getLicense();
    /**
     * Setter for month
     * 
     * @param inMonth
     */    
    public void setMonth(int inMonth);
    /**
     * Getter for month
     * 
     * @return month
     */    
    public int getMonth();
    /**
     * Setter for year
     * 
     * @param inYear
     */    
    public void setYear(int inYear);
    /**
     * Getter for year
     * 
     * @return year
     */    
    public int getYear();
    /**
     * Compares two CarOwner objects based on registration date.
     * 
     * @return  -1 if calling object registration date < registration date of object being compared
     *           1 if calling object registration date > registration date of object being compared
     *          0 if calling object registration date == registration date of object being compared
     */    
    public int compareTo(Object o);
    /**
     * Provides a string representation of CarOwner object
     * 
     * @return string representation of CarOwner object
     */    
    public String toString();
}
