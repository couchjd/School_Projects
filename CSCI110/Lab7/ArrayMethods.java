import java.util.*;
/**
 * A class demonstrating array operations.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 04.10.2014
 * 
 */
public class ArrayMethods
{
    private int[] a = {7, 8, 8, 3, 4, 9, 8, 7};
    /**
     * returns a count of array elements
     * 
     * @return count of array elements
     */    
    public int count()
    {
        int count = 0;
        for(int x : a)
        {
            count++;
        }
        return count;
    }
    /**
     * returns a sum of all array elements
     * 
     * @return sum of array elements
     */    
    public int sum()
    {
        int sum = 0;
        for(int x : a)
        {
            sum += x;
        }
        return sum;
    }
    /**
     * returns the average of array elements
     * 
     * @return sum/count
     */    
    public double average()
    {
        return (double)sum()/count();
    }
    /**
     * returns the index of the last instance of key
     * 
     * @param key
     * @return index of last instance of key
     */    
    public int findLast(int key)
    {
        int last = -1;
        int count = 0;
        for(int x : a)
        {
            if(x == key)
                last = count;
            count++;
        }
        return last;
    }
    /**
     * returns the highest value in the array
     * 
     * @return highest value in array
     */    
    public int findMax()
    {
        int max = a[0];
        for(int x : a)
        {
            if(x > max)
                max = x;
        }
        return max;
    }
    /**
     * returns the lowest value in the array
     * 
     * @return lowest value in array
     */    
    public int findMin()
    {
        int min = a[0];
        for(int x : a)
        {
            if(x < min)
                min = x;
        }
        return min;
    }
    /**
     * returns the index of the first instance of the maximum value in the array
     * 
     * @return index of highest value in array
     */    
    public int findIndexOfMax()
    {
        int index = 0;
        int count = 0;
        for(int x : a)
        {
            if(x == findMax())
            {
                index = count;
                break;
            }
            count++;
        }
        return index;
    }
    /**
     * returns the range of values in the array
     * 
     * @return range of array values
     */    
    public int range()
    {
        return findMax() - findMin();
    }
    /**
     * returns an array of the indices of each instance of key in the original array
     * 
     * @param key
     * @return array of indices of each instance of key
     */    
    public int[] findAll(int key)
    {
        int arrSize = 0;
        int count = 0;
        int index = 0;
        
        for(int x : a)
        {
            if(x == key)
            {    
                arrSize++;
            }
        }
        int[] retArray = new int[arrSize];
        for(int y : a)
        {
            if(y == key)
            {    
                retArray[index] = count;
                index++;
            }
            count++;
        }
        return retArray;
    }
    /**
     * prints each element of the array
     * @param a
     */    
    public void print(int[] a)
    {
        System.out.print("{");
        int i;
        // print elements before the last, separated by commas
        for (i = 0; i < a.length - 1; ++i)
            System.out.print(a[i] + ", ");
        // print last element.  Careful here to handle length 0
        if (a.length > 0)
            System.out.print(a[i]);
        System.out.println("}");
    }
    /**
     * getter for array int[] a
     * 
     * @return array a
     */
    public int[] getArray()
    {
        int[] temp = new int[a.length];
        for(int x = 0; x <= a.length; x++)
            temp[x] = a[x];
        return temp;
    }
    /**
     * returns a copy of array a
     * 
     * @return copy of array a
     */    
    public int[] copyArray()
    {
        return Arrays.copyOf(a, a.length);
    }
    /**
     * sorts elements of array from lowest to highest
     * 
     * @param inArray
     * @return array sorted from lowest to highest
     */    
    public int[] sortArray(int[] inArray)
    {
        int temp = 0;
        boolean flag = true;
        while(flag)
        {
            flag = false;
            for(int x = 0; x < inArray.length-1; x++)
            {
                if(inArray[x] > inArray[x+1])
                {
                    temp = inArray[x];
                    inArray[x] = inArray[x+1];
                    inArray[x+1] = temp;
                    flag = true;
                }
            }
        }
        return inArray;
    }
    /**
     * reverses the order of array elements
     * 
     * @param inArray
     * @return array with elements in reverse order
     */    
    public int[] reverse(int[] inArray)
    {
        int temp = 0;
        for(int x = 0; x < inArray.length/2; x++)
        {
            temp = inArray[x];
            inArray[x] = inArray[(inArray.length-1)-x];
            inArray[(inArray.length-1)-x] = temp;
        }
        return inArray;
    }
    /**
     * generates a 5x5 integer array, fills it with values
     * (each row contains the values {1, 2, 3, 4, 5}),
     * and prints the array.
     * 
     */
    public void genFiveByFiveRows()
    {
        int[][] array = new int[5][5];
        for(int x = 0; x < 5; x++)
        {
            for(int y = 0; y < 5; y++)
            {
                array[x][y] = x + 1;
            }
        }
        System.out.println("  A B C D E");
        for(int x = 0; x < 5; x++)
        {
            System.out.print(x+1 + " ");
            for(int y = 0; y < 5; y++)
            {
                System.out.print(array[x][y] + " ");
            }
            System.out.println();
        }        
    }
    /**
     * generates a 5x5 char array, fills it with values
     * (each row contains the values {'A', 'B', 'C', 'D', 'E'}),
     * and prints the array.
     * 
     */
    public void genFiveByFiveCols()
    {
        char[][] array = new char[5][5];
        for(int x = 0; x < 5; x++)
        {
            for(int y = 0; y < 5; y++)
            {
                array[x][y] = (char)(y + 65);
            }
        }
        System.out.println("  A B C D E");
        for(int x = 0; x < 5; x++)
        {
            System.out.print(x+1 + " ");
            for(int y = 0; y < 5; y++)
            {
                System.out.print(array[x][y] + " ");
            }
            System.out.println();
        }        
    }
}
