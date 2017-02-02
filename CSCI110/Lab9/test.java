import java.util.*;
/**
 * Write a description of class test here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class test
{
   public static void main(String[] args)
   {
       try
       {
           Rational testing = new Rational();
           testing.doRational();
       }
       catch(InputMismatchException e)
       {
           System.out.println("Input mismatch exception.");
       }
       catch(DivideByZeroException e)
       {
           System.out.println(e.getMessage());
       }
    }
}
