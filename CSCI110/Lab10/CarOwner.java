/**
 * A class which models car owner records
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 05.07.2014
 */
public class CarOwner extends Citizen implements CarOwnerInterface
{
    private String license;
    private int month;
    private int year;
    /**
     * Default constructor
     * 
     */
    public CarOwner()
    {
        super();
        license = "Not Assigned";
        month = 0;
        year = 0;
    }
    /**
     * Constructor that sets firstName, lastName, license, month, and year
     * 
     * @param inFirst
     * @param inLast
     * @param inLicense
     * @param inMonth
     * @param inYear
     */
    public CarOwner(String inFirst, String inLast, String inLicense, int inMonth, int inYear)
    {
        super(inFirst, inLast);
        license = inLicense;
        month = inMonth;
        year = inYear;
    }
    /**
     * Setter for license
     * 
     * @param inLicense
     */
    public void setLicense(String inLicense)
    {
        license = inLicense;
    }
    /**
     * Getter for license
     * 
     * @return license
     */
    public String getLicense()
    {
        return license;
    }
    /**
     * Setter for month
     * 
     * @param inMonth
     */
    public void setMonth(int inMonth)
    {
        month = inMonth;
    }
    /**
     * Getter for month
     * 
     * @return month
     */
    public int getMonth()
    {
        return month;
    }    
    /**
     * Setter for year
     * 
     * @param inYear
     */
    public void setYear(int inYear)
    {
        year = inYear;
    }
    /**
     * Getter for year
     * 
     * @return year
     */
    public int getYear()
    {
        return year;
    }
    /**
     * Helper method for determining absolute month of
     * vehicle registration
     * 
     * @return (year * 12) + month
     */
    public int getDate()
    {
        return((year*12)+month);
    }
    /**
     * Compares two CarOwner objects based on registration date.
     * 
     * @return -1 if calling object registration date < registration date of object being compared
     * @return 1 if calling object registration date > registration date of object being compared
     * @return 0 if calling object registration date == registration date of object being compared
     */
    public int compareTo(Object o)
    {
        if((o != null) && (o instanceof CarOwner))
        {
            CarOwner carOwnerIn = (CarOwner) o;
            if(carOwnerIn.getDate() > getDate())
            {
                return -1;
            }
            else if(carOwnerIn.getDate() < getDate())
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return -1;
    }
    /**
     * Provides a string representation of CarOwner object
     * 
     * @return string representation of CarOwner object
     */
    public String toString()
    {
        return(super.toString() + "\t" + license + "\t\t" + month + "/" + year);
    }
}
