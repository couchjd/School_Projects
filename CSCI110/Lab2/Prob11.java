import java.util.*;
/**
 * Reads a binary input value and outputs its decimal value.
 * 
 * @author Jeff Couch 
 * @version v1.0
 * @since 2014-01-21
 */
public class Prob11
{
    public static void main(String[] args)
    {
        String inputString;
        ArrayList<Integer> digit = new ArrayList();
        Scanner input = new Scanner(System.in);

        System.out.print("Input a 4-bit binary number: ");
        inputString = input.nextLine();

        for(int x = 0; x < inputString.length(); x++)
            digit.add(x, Character.digit(inputString.charAt(x), 10));

        int total = digit.get(0)*8 + digit.get(1)*4 + digit.get(2)*2 + digit.get(3)*1;

        System.out.println(total);
    }
}
