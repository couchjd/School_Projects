/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package test;
import java.util.*;
/**
 *
 * @author jeff
 */
public class Test 
{
    public static void main(String[] args)
    {
        //StudentRecord student1 = new StudentRecord();
        //student1.writeOutput();
        
        Scanner input = new Scanner(System.in);
        boolean run = true;
        while(run == true)
        {
            run = false;
            ConcertPromoter newConcert = new ConcertPromoter();
            while(newConcert.getTixRmng() > 0)
            {
                newConcert.mainMenu();
                switch(newConcert.getMenuChoice())
                {
                    case 1: 
                        System.out.print("Input number of tickets purchased: ");
                        newConcert.sellTix(input.nextInt());
                        break;
                    case 2:
                        newConcert.dayOfShow(true);
                        System.out.print("Input number of tickets purchased: ");
                        newConcert.sellTix(input.nextInt());
                        break;
                    case 3:
                        System.out.print("Input new capacity: ");
                        newConcert.setCapacity();
                        break;
                    case 4:
                        System.out.print("Input phone price: ");
                        newConcert.setPhonePrice();
                        break;
                    case 5:
                        System.out.print("Input day-of price: ");
                        newConcert.setDayOfPrice();
                        break;
                    case 6:
                        System.out.print("Input band name: ");
                        newConcert.setBandName();
                        break;
                }
            }
            System.out.printf("%d tickets have been sold.\n", newConcert.getTixSold());
            System.out.printf("Total sales: $%.2f\n", newConcert.getTotalSales());
            System.out.println("New concert? ");
            char choice = input.next().toLowerCase().charAt(0);
            if(choice == 'y')
                run = true;
        }
    }
}
