import java.util.Scanner;
/**
 * Floating point operations
 * 
 * @author Jeff Couch 
 * @version v1.0
 * @since 2014-01-21
 */
public class Prob1_Page127
{
    public static void main(String[] args)
    {
        float x, y;
        Scanner input = new Scanner(System.in);
        System.out.print("Input a floating-point value: ");
        x = input.nextFloat();
        y = 1.0f/x;
        System.out.println("x = " + x + "\ny = " + y + "\nx * y = " + (x*y));
        System.out.println((x*y) + " - 1 = " + ((x*y)-1));
    }
}
