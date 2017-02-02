import java.util.*;
/**
 * Class for student records.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com) 
 * @version v1.0
 * @since 03.07.2014
 */
public class StudentRecord 
{
    private int quiz1, quiz2, midTermExam, finalExam;
    private double totalScore;
    private char finalGrade;
     /**
     *Constructor calls readInput() method.
     * 
     */
    public StudentRecord()
    {
        readInput();
    }
    
     /**
     *Gets quiz and exam scores for student.
     * 
     */
    public void readInput()
    {
        //get Q1, Q2, MT, & Final Exam Scores
        Scanner input = new Scanner(System.in);
        System.out.print("Input quiz 1 score: ");
        quiz1 = input.nextInt();
        while((quiz1 < 0) || (quiz1 > 10))
        {
            System.out.println("Quiz score must be between 1 and 10.");
            System.out.print("Input quiz 1 score: ");
            quiz1 = input.nextInt();
        }
        System.out.print("Input quiz 2 score: ");
        quiz2 = input.nextInt();
        while((quiz2 < 0) || (quiz2 > 10))
        {
            System.out.println("Quiz score must be between 1 and 10.");
            System.out.print("Input quiz 2 score: ");
            quiz2 = input.nextInt();
        }
        System.out.print("Input midterm exam score: ");
        midTermExam = input.nextInt();
        while((midTermExam < 0) || (midTermExam > 100))
        {
            System.out.println("Exam score must be between 1 and 100.");
            System.out.print("Input midterm exam score: ");
            midTermExam = input.nextInt();
        }
        System.out.print("Input final exam score: ");
        finalExam = input.nextInt();
        while((finalExam < 0) || (finalExam > 100))
        {
            System.out.println("Exam score must be between 1 and 100.");
            System.out.print("Input final exam score: ");
            finalExam = input.nextInt();
        }
    }
     /**
     *Prints scores and final grades.
     * 
     */
    public void writeOutput()
    {
        //print Q1, Q2, MT, & Final Exam Scores
        numericGrade();
        letterGrade();
        System.out.println("Quiz 1: " + quiz1);
        System.out.println("Quiz 2: " + quiz2);
        System.out.println("Midterm Exam: " + midTermExam);
        System.out.println("Final Exam: " + finalExam);        
        System.out.println("Total Score: " + totalScore);
        System.out.println("Letter Grade: " + finalGrade);
    }
     /**
     *Calculates final grade.
     * 
     */
    private void numericGrade()
    {
        totalScore = ((double)midTermExam*.25)+((double)finalExam*.5)+
                (((double)(quiz1+quiz2)/20)*25);
    }
     /**
     *Determines letter grade.
     * 
     */
    private void letterGrade()
    {
        if(totalScore >= 90)
            finalGrade = 'A';
        else if(totalScore >= 80)
            finalGrade = 'B';
        else if(totalScore >= 70)
            finalGrade = 'C';
        else if(totalScore >= 60)
            finalGrade = 'D';
        else
            finalGrade = 'F';
    }
     /**
     *Sets quiz 1 score.
     * 
     * @param   newQ1
     */
    public void setQ1(int newQ1)
    {
        quiz1 = newQ1;
    }
     /**
     *Returns quiz 1 score.
     * 
     * @return   quiz1;
     */
    public int getQ1()
    {
        return quiz1;
    }
     /**
     *Sets quiz 2 score.
     * 
     * @param   newQ2
     */
    public void setQ2(int newQ2)
    {
        quiz2 = newQ2;
    }
     /**
     *Returns quiz 2 score.
     * 
     * @return   quiz2;
     */
    public int getQ2()
    {
        return quiz2;
    }
     /**
     *Sets midterm exam score.
     * 
     * @param   newMT
     */
    public void setMidTerm(int newMT)
    {
        midTermExam = newMT;
    }
     /**
     *Returns midterm exam score.
     * 
     * @return   midTermExam;
     */
    public int getMidTerm()
    {
        return midTermExam;
    }
     /**
     *Sets final exam score.
     * 
     * @param   newFinal
     */
    public void setFinalExam(int newFinal)
    {
        finalExam = newFinal;
    }
     /**
     *Returns final exam score.
     * 
     * @return   finalExam;
     */
    public int getFinalExam()
    {
        return finalExam;
    }    
}
