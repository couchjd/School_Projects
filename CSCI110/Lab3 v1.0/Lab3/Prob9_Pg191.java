import java.util.*;
/**
 * Gets a date from the user and then checks to see if the date is valid.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 2014-29-01
 */

public class Prob9_Pg191
{
    public static void main(String[] args)
    {
        String dateInput, temp;
        int day, month, year;
        Scanner input = new Scanner(System.in);
        boolean isValidMonth = true, isValidDay = true, isLeapYear = false;

        System.out.print("Input a date (format MM/DD/YYYY): ");        
        dateInput = input.nextLine();

        month = Integer.parseInt(dateInput.substring(0, dateInput.indexOf("/")));
        temp = dateInput.substring(dateInput.indexOf("/")+1);

        day = Integer.parseInt(temp.substring(0, temp.indexOf("/")));
        year = Integer.parseInt(temp.substring(temp.indexOf("/")+1));

        if(month >= 1 && month <= 12)
        {
            isValidMonth = true;
        }
        else
        {
            isValidMonth = false;
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
            }
            else
            {
                isValidDay = false;
            }
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            if(day >= 1 && day <= 30)
            {
                isValidDay = true;
            }
            else
            {
                isValidDay = false;
            }
        }
        else
        {    
            if(isLeapYear)
            {
                if(day >= 1 && day <= 29)
                {
                    isValidDay = true;
                }
                else
                {
                    isValidDay = false;
                }
            }
            else
            {
                if(day >= 1 && day <= 28)
                {
                    isValidDay = true;
                }
                else
                {
                    isValidDay = false;
                }
            }
        }

        if(isValidMonth && isValidDay)
        {
            System.out.println(month + "/" + day + "/" + year + 
                    " is a valid date!");    
        }
        else if(isValidMonth && !isValidDay)
        {
            System.out.println(month + "/" + day + "/" + year +
                    " is not a valid date!");
            System.out.println(day + " is not a valid day in month " +
                    month + ".");
        }
        else
        {
            System.out.println(month + "/" + day + "/" + year +
                    " is not a valid date!");
            System.out.println(month + " is not a valid month.");
        }
    }
}