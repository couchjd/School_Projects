package leapYear;


/**
 * Driver class to test for leap years
 * 
 * @author Rick Cassoni
 * @version v1.0
 * @since 2/1/2012
 */
public class LeapYearDriver
{
    public static void main (String args[])
    {
        TestLeapYear year2012 = new TestLeapYear (2012);
        TestLeapYear year2000 = new TestLeapYear (2000);
        TestLeapYear year1900 = new TestLeapYear (1900);
        
        System.out.println ("Is year 2012 a leap year? " + year2012.testLeapYear());//should be true
        System.out.println ("Is year 2000 a leap year? " + year2000.testLeapYear()); //should be ture
        System.out.println ("Is year 1900 a leap year? " + year1900.testLeapYear()); //should be false
        
    }
}
