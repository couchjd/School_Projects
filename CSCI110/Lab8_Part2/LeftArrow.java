
/**
 * A class for drawing left-facing arrows
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 04.21.2014
 */
public class LeftArrow extends BasicShape implements ArrowInterface
{
    private int tail;
    private int width;
    
    /**
     * Default constructor
     * 
     */
    public LeftArrow()
    {
        setXAdj(0);
        setYAdj(0);
        setTail(5);
        setWidth(5);
    }
    /**
     * Constructor
     * 
     * @param newXAdj
     * @param newYAdj
     * @param newTail
     * @param newWidth
     */
    public LeftArrow(int newXAdj, int newYAdj, int newTail, int newWidth)
    {
        setXAdj(newXAdj);
        setYAdj(newYAdj);
        setTail(newTail);
        setWidth(newWidth);
    }
    /**
     * Helper function for drawing '*' characters.
     * 
     */
    private void drawArrow()
    {
        drawFiller((getWidth()/2));
        System.out.print('*');
    }
    /**
     * Helper function--draws leading '*', spaces, and trailing '*'
     * 
     * @param end
     */
    private void drawArrow(int end)
    {
        drawFiller(((getWidth()/2))-end);
        System.out.print('*');
        drawFiller(end-1);
        System.out.print('*');
    }
    /**
     * Helper function for drawing ' ' characters
     * 
     */
    private void drawFiller()
    {
        System.out.print(' ');
    }
    /**
     * Helper function--draws filler between initial and terminal '*' on arrows.
     * 
     * @param end
     */
    private void drawFiller(int end)
    {
        for(int x = 0; x < end; x++)
        {
            System.out.print(' ');
        }
    }
    /**
     * Helper function to draw the tail of an arrow
     * 
     * @param tailIn
     */
    private void drawTail(int tailIn)
    {
        for(int x = 0; x < tailIn; x++)
            System.out.print('*');
    }
    /**
     * Helper function to draw any needed spaces in an arrow
     * 
     * @param spaces
     */
    private void drawSpaces(int spaces)
    {
        for(int x = 0; x < spaces; x++)
            System.out.print(' ');
    }
    /**
     * Setter for tail
     * 
     * @param newTail
     */
    public void setTail(int newTail)
    {
        tail = newTail;
    }
    /**
     * Getter for tail
     * 
     * @return tail
     */
    public int getTail()
    {
        return tail;
    }
    /**
     * Setter for width
     * 
     * @param newWidth
     */
    public void setWidth(int newWidth)
    {
        width = newWidth;
    }
    /**
     * Getter for width
     * 
     * @return width
     */
    public int getWidth()
    {
        return width;
    }
    /**
     * Sets tail and width of LeftArrow objects
     * 
     * @param newTail
     * @param newWidth
     */    
    public void setArrowDim(int newTail, int newWidth)
    {
        tail = newTail;
        width = newWidth;
    }    
    /**
     * Draws the arrow
     * 
     *  
     */
    public void drawShape()
    {
        for(int line = 0; line <= width/2; line++)
        {
            drawSpaces(getXAdj());
            if(line == 0)
            {
                drawArrow();
            }
            else
            {
                drawArrow(line);
            }
            if(line == width/2)
            {
                drawTail(tail);
            }
            System.out.println();
        }
        for(int line = (width/2)-1; line >= 0; line--)
        {
            drawSpaces(getXAdj());
            if(line == 0)
            {
                drawArrow();
            }
            else
            {
                drawArrow(line);
            }
            System.out.println();
        }

    }
}