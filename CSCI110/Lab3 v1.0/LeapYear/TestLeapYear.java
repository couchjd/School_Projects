package leapYear;

/**
 * Class TestLeapYear tests to see if a year is a leap year
 * 
 * @author Rick Cassoni 
 * @version v1.0
 * @since 2/1/2012
 */
public class TestLeapYear
{
    // instance variables - replace the example below with your own
    private int year;
    boolean isLeapYear = false;

    /**
     * Constructor for objects of class TestLeapYear
     */
    public TestLeapYear(int inputYear)
    {
        // initialise instance variables
        year = inputYear;
    }

    /**
     * method to check if a leap year
     * 
     * @return     true or false 
     */
    public boolean testLeapYear()
    {
        if ((year%400==0)||((year%4==0)&&(year%100!=0)))
            isLeapYear=true;
        return isLeapYear;
    }
}
