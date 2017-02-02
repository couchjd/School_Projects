import java.util.*;
/**
 * A class for modeling and comparing temperatures of C and F types.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com) 
 * @version v1.0
 * @since 03.31.2014
 * 
 */
public class Temperature
{
    private double tempNum;
    private char tempUnit;
    
    /**
     * Default constructor
     */
    public Temperature()
    {
        tempNum = 0.0;
        tempUnit = 'C';
    }
    /**
     * Constructor
     * @param inputNum
     * @param inputUnit
     */
    public Temperature(double inputNum, char inputUnit)
    {
        tempNum = inputNum;
        tempUnit = inputUnit;
    }
    /**
     * Constructor
     * @param inputNum
     */
    public Temperature(double inputNum)
    {
        tempNum = inputNum;
        tempUnit = 'C';
    }
    /**
     * Constructor
     * @param inputUnit
     */
    public Temperature(char inputUnit)
    {
        tempNum = 0.0;
        tempUnit = inputUnit;
    }
    
    /**
     * returns temp in Fahrenheit
     * @return temperature in Fahrenheit
     */
    public double getFahr()
    {
        if(tempUnit == 'C')
        {
            return ((9*(tempNum)/5)+32);
        }
        else
            return tempNum;
    }
   /**
    * returns temp in Celsius
    * @return temperature in Celsius
    */
    public double getCels()
    {
        if(tempUnit == 'F')
        {
            return (5*(tempNum-32))/9;
        }
        else
            return tempNum;
    }        
    /**
     * tests if two Temperature objects are equal and returns true if they are
     * @param testObj
     */
    public boolean equals(Temperature testObj)
    {
        if(this.getCels() == testObj.getCels())
            return true;
        else
            return false;
    }
    /**
     * tests if a Temperature object is greater than another Temperature object that is passed to the method
     * @param testObj
     */
    public boolean isGreaterTemp(Temperature testObj)
    {
        if(this.getCels() > testObj.getCels())
            return true;
        else
            return false;
    }
    /**
     * tests if a Temperature object is less than another Temperature object that is passed to the method
     * @param testObj
     */
    public boolean isLessTemp(Temperature testObj)
    {
        if(this.getCels() < testObj.getCels())
            return true;
        else
            return false;
    }
    /**
     * only sets the numeric portion of a Temperature object
     * @param inputTemp
     */
    public void setTempObj(double inputTemp)
    {
        tempNum = inputTemp;
    }
    /**
     * only sets the unit portion of a Temperature object
     * @param inputUnit
     */
    public void setTempObj(char inputUnit)
    {
        tempUnit = inputUnit;
    }
    /**
     * sets temperature and unit of a Temperature object
     * @param inputTemp
     * @param inputUnit
     */
    public void setTempObj(double inputTemp, char inputUnit)
    {
        tempNum = inputTemp;
        tempUnit = inputUnit;
    }
}
