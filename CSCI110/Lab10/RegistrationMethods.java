import java.io.PrintWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * A number of methods for creating and manipulating car registration records
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 05.07.2014
 */
public class RegistrationMethods implements RegistrationMethodsInterface
{
    public static final int ARRAY_SIZE = 25;
    public static final int REG_MONTH = 4;
    public static final int REG_YEAR = 2013;    

    private File inputFile;
    private File outputFile;

    /**
     * Method that generates and returns an array for vehicles whose
     * registration will expire in three months or less. The state of Looney
     * Tunes sends a reminder three months out to the car owner.
     *
     * @param inArray
     * @return CarOwner[] array based on above
     */
    public CarOwner[] flagAlmostDueOwners(CarOwner[] inArray)
    {
        int arrSize = 0;
        CarOwner[] newArray;
        for(CarOwner x : inArray)
        {
            if(((getDate() - x.getDate()) >= 10) && ((getDate() - x.getDate()) < 13) && (x.getDate() != 0))
            {    
                arrSize++;
            }

        }        

        newArray = new CarOwner[arrSize];
        int y = 0;

        for(int x = 0; x < inArray.length; x++)
        {
            if(((getDate() - inArray[x].getDate()) >= 10) && ((getDate() - inArray[x].getDate()) < 13) && (inArray[x].getDate() != 0))
            {
                newArray[y] = inArray[x];
                y++;
            }
        } 
        return newArray;
    }

    /**
     * Method that generates and returns an array for vehicles whose
     * registration have expired defined as registration is over 12 months old
     * based on current REG_MONTH and REG_YEAR.
     *
     * @param inArray
     * @return CarOwner[] array based on above
     */
    public CarOwner[] flagDinqOwners(CarOwner[] inArray)
    {
        int arrSize = 0;
        CarOwner[] newArray;
        for(CarOwner x : inArray)
        {
            if(((getDate() - x.getDate()) > 12) && (x.getDate() != 0))
            {    
                arrSize++;
            }

        }        

        newArray = new CarOwner[arrSize];
        int y = 0;

        for(int x = 0; x < inArray.length; x++)
        {
            if(((getDate() - inArray[x].getDate()) > 12) && (inArray[x].getDate() != 0))
            {
                newArray[y] = inArray[x];
                y++;
            }
        } 
        return newArray;
    }

    /**
     * Prints out array passed in based on toString() along with passed in
     * message
     *
     * @param inArray CarOwner[] array passed in
     * @param inMsg Message specific to the array being printed
     */
    public void printArrayToFile(CarOwner[] inArray, String inMsg)
    {
        PrintWriter output = null;
        try
        {
            output = new PrintWriter(new FileOutputStream(outputFile, true));
        }
        catch(FileNotFoundException e)
        {
            System.out.println("File not found.");
        }
        output.println(inMsg);
        output.println();
        output.println("Name\t\tLicense\t\tLast Renewal Date");

        for(CarOwner x : inArray)
        {
            if(x.getMonth() != 0)
                output.println(x);
        }
        output.println();
        output.close();
    }

    /**
     * Takes a csv file input, parses out each record and creates a CarOwner
     * object and then puts into a CarOwner[] array that is passed into the
     * method
     *
     * @param inArray
     */
    public void processText2Array(CarOwner[] inArray)
    {
        Scanner fileIn = null;
        try
        {
            fileIn = new Scanner(inputFile);
        }
        catch(FileNotFoundException e)
        {
            System.out.println("File not found.");
            System.exit(0);
        }
        String line = fileIn.nextLine();
        int count = 0;

        while(fileIn.hasNextLine())
        {
            line = fileIn.nextLine();
            String[] ary = line.split(",");

            String lastName = ary[0];
            String firstName = ary[1];
            String license = ary[2];
            int month = Integer.parseInt(ary[3]);
            int year = Integer.parseInt(ary[4]);

            inArray[count] = new CarOwner(firstName, lastName, license, month, year);
            count++;
        }
        fileIn.close();
    }

    /**
     * Prints messages to user to request input file name and then output 
     * file name and saves to instance vars inputFile and outputFile.  
     */
    public void setFileNames()
    {
        Scanner input = new Scanner(System.in);
        String temp = null;

        System.out.print("Enter input file name (DEFAULT => ./registration.csv): ");
        temp = input.nextLine();
        if(temp.isEmpty())
        {    
            inputFile = getFileName("registration.csv");
        } 
        else
        {
            inputFile = getFileName(temp);
        }
        System.out.print("Enter output file name (DEFAULT => ./output.txt): ");
        temp = input.nextLine();
        if(temp.isEmpty())
        {
            outputFile = getFileName("output.txt");
        }
        else
        {
            outputFile = getFileName(temp);
        }

    }

    /**
     * Helper function to provide File objects to iostreams
     * 
     * @return new File object
     */
    private File getFileName(String fileNameIn)
    {
        return new File(fileNameIn);
    }
    /**
     * Helper function to calculate absolute registration date in months
     * 
     * @return (REG_YEAR * 12) + REG_MONTH
     */
    private int getDate()
    {
        return((REG_YEAR*12)+REG_MONTH);
    }
}
