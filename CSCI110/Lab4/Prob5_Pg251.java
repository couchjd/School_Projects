import java.util.*;
/**
 * Reads in a series of positive integers and prints the min, max, and 
 *  average of the integers.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com) 
 * @version v1.0
 * @since 2
 */
public class Prob5_Pg251
{
    public static void main(String[] args)
    {
        int max, min, next, sum = 0, count = 0;
        double average;
        Scanner input = new Scanner(System.in);
        
        System.out.println("Input positive integer values: ");
        next = max = min = input.nextInt();
                
        while(next >= 0)
        {
            sum += next;
            if(next > max)
                max = next;
            if(next < min)
                min = next;
            next = input.nextInt();
            count++;
        }
        if(count < 1)
        {
            System.out.print("No positive values entered.  Could not compute average.");
        }
        else
        {
            average = (double)sum/count;
            System.out.println("Max is: " + max + "\nMin is: " + min + "\nAverage is: " + average);
        }

    }
}