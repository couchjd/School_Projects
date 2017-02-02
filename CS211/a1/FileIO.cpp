/**
 * FileIO.cpp
 * 
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.1 (09.18.2014)
 **/

#include "FileIO.h"

//Vector for recording the location of capital letters.
vector<Capital> FileIO::caps;

void FileIO::readFile(string fileName, vector<string> &returned)
{
  fstream fin;
  fin.open(fileName.c_str());
  string tempString = "";

  //Initialize the returned and Capital vectors.
  returned.clear();
  caps.clear();
  
  //Reads in each string from the file and pushes it
  //into the return vector.
  while(fin)
  {
    fin >> tempString;

    returned.push_back(tempString);
		
    if(fin.eof())
      break;
  }

  //Checks for uppercase characters, records their position,
  //and replaces them with lowercase characters.
  for(int x = 0; x < returned.size(); x++)
  {
    for(int y = 0; y < returned[x].size(); y++)
    {
      if(returned[x][y] > 64 && returned[x][y] < 91)
      {
	caps.push_back(Capital(x, y));
	returned[x][y] = tolower(returned[x][y]);
      }
    }
  }
}

void FileIO::writeFile(string fileName, vector<string> &toWrite)
{
  fstream fout;

  //Opens stream to file. If file does not exist, it is created.
  fout.open(fileName.c_str(), fstream::out);

  //Replaces all uppercase characters in vector.  
  for(int x = 0; x < caps.size(); x++)
  {
      toWrite[caps[x].getX()][caps[x].getY()] = 
	toupper(toWrite[caps[x].getX()][caps[x].getY()]);
  }

  //Writes contents of vector to file.
  for(int x = 0; x < toWrite.size(); x++)
  {
    if(x == toWrite.size()-1)
      fout << toWrite[x];
    else
      fout << toWrite[x] << " ";
  }
}

Capital::Capital(int xIn, int yIn)
{
  x = xIn;
  y = yIn;
}
int Capital::getX(){return x;}
int Capital::getY(){return y;}
