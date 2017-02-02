/**
 * Employee class with hire date and idNum
 * 
 * @author Jeff Couch
 * @version v1.0
 * @since 04.16.2014
 * 
 */
public class Employee extends Person
{
    public static final int CURRENT_YEAR = 2012;
    private int hireDate;
    private String idNum;
    
    /**
     * Default constructor. 
     */
    public Employee()
    {
        super();
        hireDate = 0;
        idNum = "";
    }
    /**
     * Constructor.
     * 
     * @param hireDateIn
     * @param idNumIn
     */
    public Employee(int hireDateIn, String idNumIn)
    {
        super();
        hireDate = hireDateIn;
        idNum = idNumIn;
    }
    /**
     * Constructor.
     * 
     * @param initialName
     * @param hireDateIn
     * @param idNumIn
     */
    public Employee(String initialName, int hireDateIn, String idNumIn)
    {
        super(initialName);
        hireDate = hireDateIn;
        idNum = idNumIn;
    }
    /**
     * Checks if the idNum of two Employee objects are the same.
     * 
     * @param employeeIn
     * @return true if this.idNum is the same as employeeIn.idNum
     */
    public boolean equals(Object o)
    {
        if((o != null) && (o instanceof Employee))
        {
            Employee empIn = (Employee) o;
            if(empIn.idNum.equals(idNum))
            {
                return true;
            }
            else
            {
                return false;    
            }
        }
        return false;
    }
    /**
     * Calculates and returns the number of years of service.
     * 
     * @return years of service
     */
    public int getServiceYears()
    {
        return CURRENT_YEAR - hireDate;
    }
    /**
     * Getter for hireDate
     * 
     * @return hire date
     */
    public int getHireDate()
    {
        return hireDate;
    }
    /**
     * Getter for idNum
     * 
     * @return id number
     */
    public String getIdNum()
    {
        return idNum;
    }
    /**
     * Setter for hireDate
     * 
     * @param hireDateIn
     */
    public void setHireDate(int hireDateIn)
    {
        hireDate = hireDateIn;
    }
    /**
     * setter for idNum
     * 
     * @param idNumIn
     */
    public void setIdNum(String idNumIn)
    {
        idNum = idNumIn;
    }
    /**
     * Provides a String representation of an Employee object
     * 
     * @return String representation of Employee object
     */
    public String toString()
    {
        return("Name: " + getName() + "\nID Num: " + idNum + "\nYear Hired: " + hireDate +
                ", Years of Service: " + getServiceYears());
    }
}
