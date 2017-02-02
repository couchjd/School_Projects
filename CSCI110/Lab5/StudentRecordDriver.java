/**
 * Driver for StudentRecord class testing.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com) 
 * @version v1.0
 * @since 03.07.2014
 */
public class StudentRecordDriver
{
    public static void main(String[] args)
    {
        StudentRecord coder1 = new StudentRecord();
        System.out.println("Coder 1 record: ");
        coder1.writeOutput();
        StudentRecord coder2 = new StudentRecord();
        System.out.println("Coder 2 record: ");
        coder2.writeOutput();
        System.out.println("Coder 2 had a regrade on the final. Setting Coder 2 final exam score to 93.");
        coder2.setFinalExam(93);
        System.out.println("Coder 2 updated record: ");
        coder2.writeOutput();
    }
}
