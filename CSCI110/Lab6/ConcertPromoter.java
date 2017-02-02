import java.util.*;
/**
 * Concert ticket sales class.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com) 
 * @version v1.0
 * @since 03.07.2014
 */
public class ConcertPromoter 
{
    private String              bandName;
    private int                 capacity;
    private int                 tixSold;
    private double              phonePrice;
    private double              dayOfPrice; 
    private static double       totalSales;
    private boolean             concertToday;
        
    Scanner input = new Scanner(System.in);
     /**
     *Sets bandName.
     * 
     * @param   newBandName
     */
    public void setBandName(String newBandName)
    {
        bandName = newBandName;
    }
     /**
     *Sets phone sale price.
     * 
     * @param   newPhonePrice
     */
    public void setPhonePrice(double newPhonePrice)
    {
        phonePrice = newPhonePrice;
    }
     /**
     *Sets day-of sale price.
     * 
     * @param   newDayOfPrice
     */    
    public void setDayOfPrice(double newDayOfPrice)
    {
        dayOfPrice = newDayOfPrice;
    }
     /**
     *Sets venue capacity.
     * 
     * @param   newCapacity
     */    
    public void setCapacity(int newCapacity)
    {
        capacity = newCapacity;
    }
     /**
     *Sets day of event.
     * 
     * @param   newStatus
     */    
    public void dayOfShow(boolean newStatus)
    {
        concertToday = newStatus;
    }
     /**
     *Gets number of tickets sold and calculates sales based on dayOfPrice or phonePrice
     * 
     * @param   tixOrder
     */
    public void sellTix(int tixOrder)
    {
        tixSold += tixOrder;
        if(concertToday)
        {
            totalSales += (tixOrder * dayOfPrice);
        }
        else
        {
            totalSales += (tixOrder * phonePrice);
        }
    }
     /**
     *Returns number of tickets sold.
     * 
     * @return tixSold
     */
    public int getTixSold()
    {
        return tixSold;
    }
     /**
     *Returns number of tickets remaining.
     * 
     * @return capacity - tixSold
     */
    public int getTixRmng()
    {
        return capacity - tixSold;
    }
     /**
     *Returns total sales amount.
     * 
     * @return totalSales
     */
    public double getTotalSales()
    {
        return totalSales;
    }
     /**
     *Returns venue capacity.
     * 
     * @return capacity
     */
    public int getCapacity()
    {
        return capacity;
    }
     /**
     *Returns name of band.
     * 
     * @return bandName
     */
    public String getBandName()
    {
        return bandName;
    }
}