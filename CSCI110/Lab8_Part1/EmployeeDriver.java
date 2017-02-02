
/**
 * Driver for Employee class
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com) 
 * @version v1.0
 * @since 04.21.2014
 */
public class EmployeeDriver
{
    public static void main(String[] args)
    {
        FullTime fred = new FullTime("Flintstone, Fred", 2005, "BR-1", 65000.12);
        Adjunct barney = new Adjunct("Rubble, Barney", 2006, "BR-2", 320, 48.55);
        FullTime wilma = new FullTime();
        wilma.setName("Flintstone, Wilma");
        wilma.setIdNum("BR-3");
        wilma.setHireDate(2009);
        wilma.setSalary(48123.25);
        Employee betty = new Employee("Rubble, Betty", 2011, "BR-4");
        FullTime wilma2 = new FullTime("Slate, Wilma", 2009, "BR-3", 48123.25);
        Person[] staff = {fred, barney, wilma, betty, wilma2};
        for(Person x : staff)
        {
            System.out.println(x);
            System.out.println("---------------------------");
        }
        System.out.println("\nHR knows that they only have 4 employess at BRU, " + 
                            "but 5 employess are in the DB.  They see two Wilmas " + 
                            "and decide to run \na report to see if they are the same.\n");
        System.out.println("Are wilma and wilma2 the same person? " + wilma.equals(wilma2) + "\n");
        System.out.println("Seeing the mistake, HR updates the wilma record, " +
                            "deletes the wilma2 record, and runs a new report: \n");
        wilma.setName("Slate, Wilma");
        for(int x = 0; x < 4; x++)
        {
            System.out.println(staff[x]);
            System.out.println("---------------------------");
        }
    }
}
