/**
 * Interface for shape objects to implement.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com) 
 * @version v1.0
 * @since 04.21.14
 */
public interface BasicInterface
{
    /**
     * Setter for x-axis adjustment
     * 
     * @param newXAdj
     */
    public void setXAdj(int newXAdj);
    /**
     * Getter for x-axis adjustment
     * 
     * @return xAdj
     */
    public int getXAdj();
    /**
     * Setter for y-axis adjustment
     * 
     * @param newYAdj
     */
    public void setYAdj(int newYAdj);
    /**
     * Getter for y-axis adjustment
     * 
     * @return yAdj
     */
    public int getYAdj();
    /**
     * Draws the shape, adjusted for y-axis adjustment
     * 
     */
    public void drawShapeOn();
    /**
     * Performs drawing operations
     * 
     */
    public void drawShape();
}
