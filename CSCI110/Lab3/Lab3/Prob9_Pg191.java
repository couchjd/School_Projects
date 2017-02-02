import java.util.*;
/**
 * Gets a date from the user and then checks to see if the date is valid.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.1
 * @since 2014-29-01
 */

public class Prob9_Pg191
{
    public static void main(String[] args)
    {
        String yearStr;
        int day, month, year;
        Scanner input = new Scanner(System.in);
        boolean isValidMonth = true, isValidDay = true, isLeapYear = false;

        System.out.print("Input a date (format MM/DD/YYYY): ");        
        input.useDelimiter("/");
        
        month = input.nextInt();
        day = input.nextInt();
        yearStr = input.nextLine();
        year = Integer.parseInt(yearStr.substring(1));

        if(month >= 1 && month <= 12)
        {
            isValidMonth = true;
        }
        else
        {
            isValidMonth = false;
            System.out.println(month + "/" + day + "/" + year +
                    " is not a valid date!");
            System.out.println("Valid months are between 1 and 12.");
        }

        if(year%4 == 0)
        {
            if((!(year%100 == 0)) || year%400 == 0)
            {
                isLeapYear = true;
            }
        }
        else
        {
            isLeapYear = false;
        }

        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
                || month == 10 || month == 12)
        {
            if(day >= 1 && day <= 31)
            {
                isValidDay = true;
                System.out.println(month + "/" + day + "/" + year + 
                    " is a valid date!"); 
            }
            else
            {
                isValidDay = false;
                System.out.println(month + "/" + day + "/" + year +
                    " is not a valid date!");
                System.out.println("Valid days are between 1 and 31.");
            }
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            if(day >= 1 && day <= 30)
            {
                isValidDay = true;
                System.out.println(month + "/" + day + "/" + year + 
                    " is a valid date!");                 
            }
            else
            {
                isValidDay = false;
                System.out.println(month + "/" + day + "/" + year +
                    " is not a valid date!");
                System.out.println("Valid days are between 1 and 30.");
            }
        }
        else
        {    
            if(isLeapYear)
            {
                if(day >= 1 && day <= 29)
                {
                    isValidDay = true;
                    System.out.println(month + "/" + day + "/" + year + 
                        " is a valid date!"); 
                }
                else
                {
                    isValidDay = false;
                    System.out.println(month + "/" + day + "/" + year +
                        " is not a valid date!");
                    System.out.println("Valid days are between 1 and 29.");
                }
            }
            else
            {
                if(day >= 1 && day <= 28)
                {
                    isValidDay = true;
                    System.out.println(month + "/" + day + "/" + year + 
                        " is a valid date!"); 
                }
                else
                {
                    isValidDay = false;
                    System.out.println(month + "/" + day + "/" + year +
                        " is not a valid date!");
                    System.out.println("Valid days are between 1 and 28.");
                }
            }
        }        
    }
}