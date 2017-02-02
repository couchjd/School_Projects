import java.util.Scanner;
/**
 * Prints each digit of a four-digit number on different lines.
 * 
 * @author Jeff Couch 
 * @version v1.0
 * @since 2014-01-21
 */
public class Prob4
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int inputInt, printInt;
        System.out.print("Input a four-digit integer: ");
        inputInt = input.nextInt();

        printInt = inputInt/1000;
        inputInt = inputInt%1000;
        System.out.println(printInt);
        printInt = inputInt/100;
        inputInt = inputInt%100;
        System.out.println(printInt);
        printInt = inputInt/10;
        inputInt = inputInt%10;
        System.out.println(printInt);
        printInt = inputInt/1;
        System.out.println(printInt);
    }
}
