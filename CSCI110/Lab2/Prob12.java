import java.util.Scanner;
/**
 * Calculates storage capacity of a well based on user-defined values for radius and depth.
 * 
 * @author Jeff Couch 
 * @version v1.0
 * @since 2014-01-22
 */
public class Prob12
{
    public static final double PI = 3.14159;
    public static final double CUBIC_FOOT = 7.48;

    public static double calcGallons(double radius, double depth)
    {
        return (PI*(Math.pow(radius, 2))*depth)*CUBIC_FOOT;
    }

    public static void main(String[] args) 
    {
        double radius, depth, volume;
        Scanner input = new Scanner(System.in);
        
        System.out.print("Input radius of well (in inches): ");
        radius = input.nextDouble()/12;
        
        System.out.print("Input depth of well (in feet): ");
        depth = input.nextDouble();
        volume = calcGallons(radius, depth);
        
        System.out.printf("That is %1.2f gallons.\n", volume);
        if(volume >= 250)
            System.out.print("A holding tank is not required.");
        else
            System.out.print("A holding tank IS required.");
    }
}
