import java.util.*;
/**
 * Driver for demonstrating Temperature objects.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 04.02.2014
 */
public class TempDriver
{
    public static void main(String[] args)
    {
        Temperature t1 = new Temperature();
        Temperature t2 = new Temperature('F');
        t2.setTempObj(32.0);
        Temperature t3 = new Temperature(100.0);
        Temperature t4 = new Temperature(-40.0);
        Temperature t5 = new Temperature(-40.0);
        t5.setTempObj('F');
        Temperature t6 = new Temperature(212.0, 'F');    
        Temperature t7 = new Temperature(40.0, 'F');
        Temperature t8 = new Temperature(40.0, 'C');
        Temperature t9 = new Temperature(23.456, 'F');
        Temperature t10 = new Temperature(34.567, 'C');
        
        System.out.println("Does 0C equal 32F: " + t1.equals(t2));
        System.out.println("Does -40C equal -40F: " + t5.equals(t4));
        System.out.println("Does 212F equal 100C: " + t6.equals(t3));
        System.out.println("Is -40C greater than -40F: " + t5.isGreaterTemp(t4));
        System.out.println("Is -40F less than -40C: " + t4.isLessTemp(t5));
        System.out.println("Does 40F equal 40C: " + t7.equals(t8));
        System.out.println("Is 40F greater than 40C: " + t7.isGreaterTemp(t8));
        System.out.println("Is 40F less than 40C: " + t7.isLessTemp(t8));
        
        System.out.printf("t9 (23.456F) in F is: %.1f\n", t9.getFahr());
        System.out.printf("t9 (23.456F) in C is: %.1f\n", t9.getCels());
        System.out.printf("t10 (34.567C) in F is: %.1f\n", t10.getFahr());
        System.out.printf("t10 (34.567C) in C is: %.1f\n", t10.getCels());
    }
}