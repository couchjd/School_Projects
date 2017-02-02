/**
 * class Circle represents a circle and can calculate the circumference and the area.
 * 
 * @author Rick Cassoni
 * @version v1.0
 * @since 2012-01-03
 */

public class Circle
{
    // instance variables 
    private double radius;
    private static final double PI = 3.14159;

    /**
     * Default Constructor for objects of class Circle
     * 
     * sets default radius to 5 
     */
    public Circle()
    {
        radius = 5;
    }

    /**
     * Constructor for objects of class Circle
     * 
     * @param rad   the circle's radius
     */
    public Circle(double rad)
    {
        radius = rad;
    }

    /**
     * Computes the circle's circumference
     * 
     * @return the circumference of the circle 
     */
    public double calcCirc()
    {
       return 2*PI*radius;
    }
    
    /**
     * Computes the circle's area
     * 
     * @return the area of the circle 
     */
    public double calcArea()
    {
       return PI*radius*radius;
    }
    
    /* 
	* Getter Method
	* @return radius
	*/
    public double getRadius ()
    {
       return radius;  //
    }

    /* 
	* Setter Method
	* @param inRad
	*/
    public void setRadius (double inRad)
    {
       radius = inRad;  //
    }
}

