import java.util.*;
/**
 * A class modeling motor boat operation.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com) 
 * @version v1.0
 * @since 03.26.14
 * 
 */
public class MotorBoat
{
    private double fuelCap;
    private double fuelAmount;
    private double maxSpeed;
    private double curSpeed;
    private double efficiency;
    private double distance;
    private double fuelBurned;
    private double opTime;
        
    /**
    * Changes the speed the boat is traveling.
    * 
    * @param newSpeed
    */
    public void changeSpeed(double newSpeed)
    {
        curSpeed = newSpeed;
    }
    /**
    * Changes amount of fuel in boat.
    * 
    * @param addGas
    */    
    public void refuelBoat(double addGas)
    {
        fuelAmount += addGas;
    }
    /**
    * Specifies the amount of time the boat has been operating.
    * 
    * @param newOpTime
    */    
    public void operateBoat(double newOpTime)
    {
        opTime = newOpTime;
    }
    /**
    * Returns the amount of fuel the boat has remaining.
    * 
    * @return   the amount of fuel remaining
    */    
    public double fuelLeft()
    {
        return fuelAmount - (efficiency * Math.pow(curSpeed, 2) * opTime);
    }
    /**
    * Returns the distance the boat has traveled.
    * 
    * @return   distance traveled
    */    
    public double distTravel()
    {
        distance += curSpeed * opTime;
        return distance; 
    }
    /**
    * Class constructor specifying fuel capacity, fuel amount, max speed, current speed, efficiency, 
    * and distance traveled.
    * 
    * @param fuelCapIn      fuel capacity of boat
    * @param fuelAmountIn   current fuel level of boat
    * @param maxSpeedIn     boat max speed
    * @param curSpeedIn     boat current speed
    * @param efficiencyIn   boat efficiency
    * @param distanceIn     distance traveled
    */
    public MotorBoat(double fuelCapIn, double fuelAmountIn, double maxSpeedIn, double curSpeedIn,
                     double efficiencyIn, double distanceIn)
    {
        fuelCap = fuelCapIn;
        fuelAmount = fuelAmountIn;
        maxSpeed = maxSpeedIn;
        curSpeed = curSpeedIn;
        efficiency = efficiencyIn;
        distance = distanceIn;
    }
    /**
     * Default class constructor.
     * Sets all instance variables to 0.0.
     */
    
    public MotorBoat()
    {
        fuelCap = 0.0;
        fuelAmount = 0.0;
        maxSpeed = 0.0;
        curSpeed = 0.0;
        efficiency = 0.0;
        distance = 0.0;
    }
    
}
