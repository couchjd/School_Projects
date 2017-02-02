import java.text.*;
/**
 * A class modeling Adjunct Employees
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com) 
 * @version v1.0
 * @since 04.17.14
 */
public class Adjunct extends Employee
{
    private int hrs;
    private double hrRate;
    /**
     * Default constructor
     * 
     */
    public Adjunct()
    {
        super();
        hrs = 0;
        hrRate = 0.0;
    }
    /**
     * Constructor
     * 
     * @param initialName
     * @param hireDateIn
     * @param idNumIn
     * @param hrsIn
     * @param hrRateIn
     */
    public Adjunct(String initialName, int hireDateIn, String idNumIn, int hrsIn, double hrRateIn)
    {
        super(initialName, hireDateIn, idNumIn);
        hrs = hrsIn;
        hrRate = hrRateIn;
    }
    /**
     * Calculates and returns salary based on hrRate and hrs.
     * 
     * @return hrs*hrRate
     */
    public double getSalary()
    {
        return hrs * hrRate;
    }
    /**
     * Getter for hrs
     * 
     * @return hrs
     */
    public int getHrs()
    {
        return hrs;
    }
    /**
     * Getter for hrRate
     * 
     * @return hrRate
     */
    public double hrRate()
    {
        return hrRate;
    }
    /**
     * Setter for hrs
     * 
     * @param hrsIn
     */
    public void setHrs(int hrsIn)
    {
        hrs = hrsIn;
    }
    /**
     * Setter for hrRate
     * 
     * @param hrRateIn
     */
    public void setHrRate(double hrRateIn)
    {
        hrRate = hrRateIn;
    }
    /**
     * Provides a String representation of Adjunct objects
     * 
     * @return String representatino of object
     */
    public String toString()
    {
        NumberFormat currency = NumberFormat.getCurrencyInstance();
        return (super.toString() + "\nHours: " + hrs + " Hourly Rate: " +
                currency.format(hrRate) + " Monthly Salary: " + currency.format(getSalary()));
    }
}

