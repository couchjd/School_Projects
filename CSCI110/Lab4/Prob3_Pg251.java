import java.util.*;

/**
 * Write a description of class Prob3_Pg251 here.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com) 
 * @version v1.0
 * @since 02-13-14
 */
public class Prob3_Pg251
{
    public static void main(String[] args)
    {
        String runAgain = "";
        char tempUnits, convertedUnits = ' ';
        double tempInitial = 0.0, tempConverted = 0.0;
        Scanner input = new Scanner(System.in);
        boolean unitsValid = false;
        do
        {
            System.out.println("Input a temperature followed by units (F or C): ");
            tempInitial = input.nextDouble();
            tempUnits = input.next().toLowerCase().charAt(0);
            
            while(unitsValid == false)
            {
                unitsValid = true;
                if(tempUnits == 'c')
                {
                    convertedUnits = 'F';
                    tempConverted = ((9*(tempInitial)/5)+32);
                }
                else if(tempUnits == 'f')
                {
                    convertedUnits = 'C';
                    tempConverted = (5*(tempInitial-32))/9;
                }
                else
                {
                    unitsValid = false;
                    System.out.print("Invalid units! Input C or F: ");
                    tempUnits = input.next().toLowerCase().charAt(0);
                }
            }
            System.out.printf("%.2f %c equals %.2f %c\n", tempInitial, tempUnits, tempConverted, convertedUnits);
            System.out.print("Run again? ");
            runAgain = input.next().toLowerCase();
        }while(runAgain.equals("y"));

    }
}