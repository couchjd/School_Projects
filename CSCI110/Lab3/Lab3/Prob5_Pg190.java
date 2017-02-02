import java.util.*;
/**
 * Prompts user to input a selection and then displays their choice.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 2014-29-01
 */
public class Prob5_Pg190
{

    public static void main(String[] args)
    {
        String inputTemp = "", tempSubstring, tempUnits = "";
        double tempInitial, tempConverted = 0.0;
        Scanner input = new Scanner(System.in);
        boolean flag = true;
        
        while(flag == true)
        {
            flag = false;
            System.out.println("Input a temperature followed by units (F or C):");
            inputTemp = input.nextLine();
            if(inputTemp.contains("f") || inputTemp.contains("F"))
            {
                tempUnits = "C";
                tempSubstring = inputTemp.substring(0, inputTemp.toLowerCase().indexOf("f"));
                tempInitial = Double.parseDouble(tempSubstring);
                tempConverted = (5*(tempInitial-32))/9;
            }
            else if(inputTemp.contains("c") || inputTemp.contains("C"))
            {
                tempUnits = "F";
                tempSubstring = inputTemp.substring(0, inputTemp.toLowerCase().indexOf("c"));
                tempInitial = Double.parseDouble(tempSubstring);
                tempConverted = ((9*(tempInitial)/5)+32);
            }
            else
            {
                System.out.println("Invalid input!");
                flag = true;
            }
        }
        
        System.out.printf("%s equals %.2f%s", inputTemp, tempConverted, tempUnits);    
    }
}
