import java.text.*;

/**
 * A class modeling full time employees
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com) 
 * @version v1.0
 * @since 04.17.2014
 */
public class FullTime extends Employee
{
    private double salary;
    /**
     * Default constructor
     * 
     */
    public FullTime()
    {
        super();
        salary = 0.0;
    }
    /**
     * Constructor
     * 
     * @param initialName
     * @param hireDateIn
     * @param idNumIn
     * @param salaryIn
     */
    public FullTime(String initialName, int hireDateIn, String idNumIn, double salaryIn)
    {
        super(initialName, hireDateIn, idNumIn);
        salary = salaryIn;
    }
    /**
     * Getter for salary
     * 
     * @return salary
     */
    public double getSalary()
    {
        return salary;
    }
    /**
     * Setter for salary
     * 
     * @param salaryIn
     */
    public void setSalary(double salaryIn)
    {
        salary = salaryIn;
    }
    /**
     * Provides a String representation of a FullTime object.
     * 
     * @return String representation of object
     */
    public String toString()
    {
        NumberFormat currency = NumberFormat.getCurrencyInstance();
        return (super.toString() + "\nYearly Salary: " + currency.format(salary) + 
                " Monthly Pay: " + currency.format(salary/12.0));
    }
}
