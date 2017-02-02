import java.util.*;
/**
 * Write a description of class Prob6_Pg251 here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Prob6_Pg251
{
    public static void main(String[] args)
    {
        double average = 0;
        int sum = 0, aCount = 0, bCount = 0, cCount = 0, 
            dCount = 0, fCount = 0, totalCount = 0, next = 0;
        Scanner input = new Scanner(System.in);
        
        System.out.println("Input scores: ");
        next = input.nextInt();
        while(next >= 0)
        {
            if(next >= 90)
                aCount++;
            else if(next >= 80)
                bCount++;
            else if(next >= 70)
                cCount++;
            else if(next >= 60)
                dCount++;
            else
                fCount++;
            
            sum += next;
            totalCount++;
            next = input.nextInt();
        }


        
        if(totalCount < 1)
        {
            System.out.println("No valid scores entered.  Could not compute average.");
        }
        else
        {
            average = (double)sum/totalCount;
            System.out.printf("A's: %d\nB's: %d\nC's: %d\nD's: %d\nF's: %d\nTotal scores entered: %d\nAverage test score: %.1f",
                aCount, bCount, cCount, dCount, fCount, totalCount, average);
        }
    }
}
