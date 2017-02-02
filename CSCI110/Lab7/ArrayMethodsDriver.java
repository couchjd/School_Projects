import java.util.*;
/**
 * Driver for ArrayMethods class
 * 
 * @author Jeff Couch
 * @version v1.0
 * @since 04.11.2014
 */
public class ArrayMethodsDriver
{
    public static void main(String[] args)
    {
        //part 1
        ArrayMethods arrayDemo = new ArrayMethods();
        System.out.println("The number of elements in int[] a is: " + arrayDemo.count());
        System.out.println("The sum of elements in int[] a is: " + arrayDemo.sum());
        System.out.println("The average of elements in int[] a is: " + arrayDemo.average());
        System.out.println("The last index of 8 is: " + arrayDemo.findLast(8));
        System.out.println("The last index of 2 is: " + arrayDemo.findLast(2));
        System.out.println("The max number in int[] a is: " + arrayDemo.findMax());
        System.out.println("The index of the max number in int[] a is: " + arrayDemo.findIndexOfMax());
        System.out.println("The range between the largest and smallest number of int[] a is: " + arrayDemo.range());
        System.out.println("Create and print a new array with the indices of int[] a when 8 occurs: ");
        int[] newArray = arrayDemo.findAll(8);
        arrayDemo.print(newArray);

        //part 2
        int[] copyOfA = arrayDemo.copyArray();
        System.out.println("Array a and copyOfA are equal? " + Arrays.equals(arrayDemo.getArray(), copyOfA));
        arrayDemo.sortArray(copyOfA);
        System.out.println("Sorted int[] copyOfA: ");
        arrayDemo.print(copyOfA);
        System.out.println("Array a and copyOfA are equal? " + Arrays.equals(arrayDemo.getArray(), copyOfA));
        int[] anotherCopyOfA = arrayDemo.copyArray();
        System.out.println("Print out of anotherCopyOfA: ");
        arrayDemo.print(anotherCopyOfA);
        Arrays.sort(anotherCopyOfA);
        System.out.println("Print out of anotherCopyOfA after sorting: ");
        arrayDemo.print(anotherCopyOfA);
        System.out.println("Array copyOfA and anotherCopyOfA are equal after anotherCopyOfA is sorted? " 
                            + Arrays.equals(copyOfA, anotherCopyOfA));
        arrayDemo.reverse(anotherCopyOfA);
        System.out.println("Print out of anotherCopyOfA after being reversed: ");
        arrayDemo.print(anotherCopyOfA);
        System.out.println("\nPrinting out Five x Five Rows");
        arrayDemo.genFiveByFiveRows();
        System.out.println("\nPrinting out Five x Five Cols");
        arrayDemo.genFiveByFiveCols();
    }
}
