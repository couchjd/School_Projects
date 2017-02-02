/**
 * FileIO.h
 * Contains classes to facilitate reading and writing to files.
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.1 (09.18.2014)
 **/
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/**
 * Capital class
 *
 *  A class for recording the position of capital letters in the messages
 * to be encrypted and decrypted.
 **/
class Capital
{
  /**
   * Class member variables
   *   int x -- holds the vector index of each string containing a capital letter.
   *   int y -- holds the string index of each capital letter within the vector.
   **/
 private:
  int x;
  int y;

 public:

  /**
   * Constructor for Capital class
   * Sets x and y values for created Capital object
   *
   * @param int xIn
   * @param int yIn
   **/
  Capital(int xIn, int yIn);

  /**
   * Accessor for int x
   *
   * @return x
   **/

  int getX();
  /**
   * Accessor for int y
   *
   * @return y
   **/
  int getY();		
};

/**
 * FileIO class
 *
 * A class with static methods for reading and
 * writing files.
 **/
class FileIO
{
 public:
  /**
   * Vector of Capital objects
   * Records the location of capital characters in the
   * string being read.
   **/
  static vector<Capital> caps;
  
  /**
   * Reads the contents of a file (specified by fileName), 
   * converts it to lowercase characters,
   * stores the location of any capital characters in a vector of
   * Capital objects, and places into a vector &returned.
   *
   * @param string fileName
   * @param vector<string> &returned
   **/
  static void readFile(string fileName, vector<string> &returned);

  /**
   * Reads the contents of a vector, replaces any uppercase characters,
   * and writes the elements to a text file specified by fileName.
   *
   * @param string fileName
   * @param vector<string> &returned
   **/
  static void writeFile(string fileName, vector<string> &returned);
};

