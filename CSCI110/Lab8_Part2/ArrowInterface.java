/**
 * An ArrowInterface that extends BasicInterface with Arrow-specific methods.
 * 
 * @author Jeff Couch (couchjeffrey@yahoo.com)
 * @version v1.0
 * @since 04.21.2014
 */
public interface ArrowInterface extends BasicInterface
{
    /**
     * Sets tail and width dimensions for Arrow objects
     * 
     * @param newTail
     * @param newWidth
     */
    public void setArrowDim(int newTail, int newWidth);
}
