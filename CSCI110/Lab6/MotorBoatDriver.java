/** MotorBoatDriver is a test / driver class that uses the MotorBoat class
 * to perform boat operations
 *
 * @author Rick Cassoni, rcassoni@palomar.edu
 * @version v1.0
 * @since 2/18/2012
 * 
 */
public class MotorBoatDriver {

    public static void main(String[] args) {
        MotorBoat skiBoat = new MotorBoat (50.0, 20.0, 30.0, 15.0, 0.1, 5.0);
        
        System.out.println("Time to slow down the ski boat to get some gas\n"
                + "to go water skiing\n");
        skiBoat.changeSpeed(0.0);
        System.out.println("Lets top off the tank with more 30 gallons\n");
        skiBoat.refuelBoat(30.0);
        System.out.println("Lets crank it up - Weee!\n");
        skiBoat.changeSpeed(15.0);
        System.out.println("After 1.5 hrs of skiing, I am ready to head back\n");
        skiBoat.operateBoat(1.5);
        System.out.println("How much fuel do we have left?\n"
                + "I don't know, let me check");
        System.out.println("We have " + skiBoat.fuelLeft() + " gallons left\n");
        System.out.println("Wow, how far did we go today?\n"
                + "Looks like we went " + skiBoat.distTravel() + "nm\n");
        
        System.out.println("Great day of skiing, better get the bass boat\n"
                + "so we are not eating PB&J for dinner\n");
        
        MotorBoat bassBoat = new MotorBoat (10.0, 4.0, 5.0, 3.0, 0.8, 1.0);
        System.out.println("Time to slow down the bass boat to get some gas\n"
                + "to go fishing\n");
        bassBoat.changeSpeed(0.0);
        System.out.println("Lets get 5 gallons");
        bassBoat.refuelBoat(5.0);
        System.out.println("Lets get the poles out and trawl - a bite!\n");
        bassBoat.changeSpeed(2.0);
        System.out.println("Wow didn't think it was going to take 2 hrs\n"
                + "to catch dinner, lets head back\n");
        bassBoat.operateBoat(2.0);
        System.out.println("How much fuel do we have left?\n"
                + "I don't know, let me check\n");
        System.out.printf("We have %.1f gallons left",bassBoat.fuelLeft());
        System.out.println("\nWe barely made it back\n");
        System.out.println("Wow, how far did we go today?\n"
                + "Looks like we went " + bassBoat.distTravel() + "nm");
        
    } //end main
} //end class