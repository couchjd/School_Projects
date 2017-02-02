import java.util.Arrays;
/**
 * Driver for demonstrating CarOwner objects and methods.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 05.07.2014
 */
public class RegistrationDemo
{
    public static void main(String[] args)
    {
        RegistrationMethods reg1 = new RegistrationMethods();

        CarOwner[] ltState = new CarOwner[RegistrationMethods.ARRAY_SIZE];
        for(int x = 0; x < RegistrationMethods.ARRAY_SIZE; x++)
        {
            ltState[x] = new CarOwner();
        }

        reg1.setFileNames();
        reg1.processText2Array(ltState);
        reg1.printArrayToFile(ltState, "Initial Set of Car Owners - Unsorted");
        CarOwner[] ltStateCopy = Arrays.copyOf(ltState, ltState.length);
        Arrays.sort(ltStateCopy);
        reg1.printArrayToFile(ltStateCopy, "Sorted list based on Registration Date");
        CarOwner[] dinqOwners = reg1.flagDinqOwners(ltStateCopy);
        reg1.printArrayToFile(dinqOwners, "Owners with expired registration");
        CarOwner[] almostDue = reg1.flagAlmostDueOwners(ltStateCopy);
        reg1.printArrayToFile(almostDue, "Owners with registration expiring in three months or less.");
    }
}