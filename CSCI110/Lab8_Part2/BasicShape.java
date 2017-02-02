/**
 * Abstract BasicShape class for other Shapes to inherit from.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 04.21.2014
 */
public abstract class BasicShape implements BasicInterface
{
    private int xAdj;
    private int yAdj;
    
    /**
     * Setter for x-axis adjustment
     * 
     * @param newXAdj
     */
    public void setXAdj(int newXAdj)
    {
        xAdj = newXAdj;
    }
    /**
     * Getter for x-axis adjustment
     * 
     * @return xAdj
     */
    public int getXAdj()
    {
        return xAdj;
    }
    /**
     * Setter for y-axis adjustment
     * 
     * @param newYAdj
     */
    public void setYAdj(int newYAdj)
    {
        yAdj = newYAdj;
    }
    /**
     * Getter for y-axis adjustment
     * 
     * @return yAdj
     */
    public int getYAdj()
    {
        return yAdj;
    }
    /**
     * Draws shape, adjusted for y-axis adjustment
     * 
     * 
     */    
    public void drawShapeOn()
    {
        for(int y = 0; y < getYAdj(); y++)
        {
            System.out.println();
        }
        drawShape();
    }
    /**
     * Performs drawing operations 
     * 
     */
    public abstract void drawShape();
}
