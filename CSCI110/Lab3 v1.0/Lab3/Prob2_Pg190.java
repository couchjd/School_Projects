import java.util.*;
/**
 * Gets three integers from the user, sorts the values from lowest to highest, and displays the results on the screen.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 2014-29-01
 */
public class Prob2_Pg190
{
    public static void main(String[] args)
    {
        int num[]={0,0,0}, first, second, third, temp;
        boolean flag = true;
        
        Scanner input = new Scanner(System.in);
        
        for(int x = 0; x < 3; x++) //get 3 integers from the user
        {
            System.out.print("Input positive integer (" + (x+1) + "): ");
            num[x] = input.nextInt();
        }
        
        while(flag)
        {
            flag = false;
            for(int x = 0; x < num.length-1; x++)
            {
                if(num[x] > num[x+1]) //compares adjacent elements
                {
                    temp = num[x];      //
                    num[x] = num[x+1];  //swaps elements if element x is greater than element x+1
                    num[x+1] = temp;    //
                    flag = true;
                }
            }
        }
        System.out.printf("Min = %d\tMid = %d\tMax = %d", num[0], num[1], num[2]);
    }
}
