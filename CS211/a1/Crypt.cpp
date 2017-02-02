/**
 * Crypt.cpp
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu
 * @version 1.1 (09.18.2014)
 **/
#include "Crypt.h"

/**
 * Reads cryptogram from text file and returns it as a string.
 *
 * @param string fileName
 * @return string
 */
string getKey(string fileName);

//Unencrypted representation of the alphabet to be used for encrypting and
//decrypting with cryptogram methods.
string alphabet = "abcdefghijklmnopqrstuvwxyz";

void Crypt::encrypt(const vector<string> &unencrypted, vector<string> &encrypted, int rotation)
{
  encrypted.clear();
  string tempString;
  
  //Ensure that rotation amount is less than the length of the entire alphabet.
  if(rotation > 26)
    rotation = rotation % 26;
  
  //Iterate over each string in the vector.
  for(int x = 0; x < unencrypted.size(); x++)
  {
    tempString.clear();
    //Iterate over each character in the current string.
    for(int y = 0; y < unencrypted[x].size(); y++)
    {
      //Check if current character is a valid lowercase character, encrypt it, and
      //append it to the temporary string.
      if((unencrypted[x][y] + rotation) > 96 && unencrypted[x][y] + rotation < 123)
      {
	tempString += char(unencrypted[x][y] + rotation);
      }
      else if(unencrypted[x][y] + rotation > 122 && unencrypted[x][y] + rotation < 149)
      {
	tempString += ((unencrypted[x][y] + rotation) - 26);
      }
      else
      {
	tempString += unencrypted[x][y];
      }
    }
    //Push encrypted string into vector.
    encrypted.push_back(tempString);
  }
}

void Crypt::encrypt(const vector<string> &unencrypted, vector<string> &encrypted)
{
  string cryptogram = getKey("crypto.txt");
  string tempString;
  encrypted.clear();
  
  //Iterate over each string in the vector.
  for(int x = 0; x < unencrypted.size(); x++)
  {
    tempString.clear();
    //Iterate over each charater of the current string.
    for(int y = 0; y < unencrypted[x].size(); y++)
    {
      //Check if current character is a valid lowercase character.
      //If it is, encrypt it and append it to the temporary string.
      if(unencrypted[x][y] < 96 || unencrypted[x][y] > 122)
	tempString += unencrypted[x][y];
      else
      {
	//Find the correct replacement character from the cryptogram
	//and replace the current character with it.
	tempString += cryptogram[alphabet.find(unencrypted[x][y])];
      }
    }
    //Push encrypted string into the vector.
    encrypted.push_back(tempString);
  }
}

void Crypt::decrypt(const vector<string> &encrypted, vector<string> &unencrypted, int rotation)
{
  unencrypted.clear();
  string tempString ;

  //Check if rotation is greater than the size of the entire alphabet.
  if(rotation > 26)
    rotation = rotation % 26;
  
  //Iterate over each element in the vector.
  for(int x = 0; x < encrypted.size(); x++)
  {
    tempString.clear();
    //Iterate over character in the current element.
    for(int y = 0; y < encrypted[x].size(); y++)
    {
      //Check if current character is a valid lowercase character.
      //If it is, decrypt it and append it to the temporary string.
      if((encrypted[x][y] - rotation) > 96 && encrypted[x][y] - rotation < 123)
      {
	tempString += char(encrypted[x][y] - rotation);
      }
      else if(encrypted[x][y] - rotation < 96 && encrypted[x][y] - rotation > 71)
      {
	tempString += ((encrypted[x][y] - rotation) + 26);
      }
      else
      {
	tempString += encrypted[x][y];
      }
    }
    //Push decrypted string into vector.
    unencrypted.push_back(tempString);
  }
}

void Crypt::decrypt(const vector<string> &encrypted, vector<string> &unencrypted)
{
  string cryptogram = getKey("crypto.txt");
  string tempString;
  unencrypted.clear();

  //Iterate over each element of the vector.
  for(int x = 0; x < encrypted.size(); x++)
  {
    tempString.clear();
    //Iterate over each character of the current element.
    for(int y = 0; y < encrypted[x].size(); y++)
    {
      //Check if current character is a valid lowercase character.
      //If it is, decrypt it and append it to the temporary string.
      if(encrypted[x][y] < 96 || encrypted[x][y] > 122)
	tempString += encrypted[x][y];
      else
      {
	//Find the correct replacement character from the cryptogram.
	//Replace the encrypted character with the corresponding
	//character from the normal alphabet.
	tempString += alphabet[cryptogram.find(encrypted[x][y])];
      }
    }
    //Push decrypted string into the vector.
    unencrypted.push_back(tempString);
  }
}

string getKey(string fileName)
{
  string cryptogram;
  fstream fin;
  fin.open(fileName.c_str());
  
  fin >> cryptogram;
  return cryptogram;
}
