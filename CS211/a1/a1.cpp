#include "FileIO.h"
#include "Crypt.h"
#include <iostream>

using namespace std;

int main()
{
  vector<string> original;
  vector<string> encrypted;
  vector<string> decrypted;

  int rotation;
  bool flag;
  char run;
  char again = 'n';

  do
  {  
    int cryptType;
    flag = 1;

    do
    {
           cout << "=================================================\n"
	   << "1. Rotation\n" 
	   << "2. Cryptogram\n"
	   << "=================================================\n"
	   << "Choose encryption type: ";
      cin >> cryptType;

      switch(cryptType)
      {
      case 1:
	cout << "Input rotation amount: ";
	cin >> rotation;
	
	FileIO::readFile("original.txt", original);
	Crypt::encrypt(original, encrypted, rotation);
	FileIO::writeFile("encrypt01.txt", encrypted);
	FileIO::readFile("encrypt01.txt", encrypted);
	Crypt::decrypt(encrypted, decrypted, rotation);	
	FileIO::writeFile("decrypt01.txt", decrypted);
	break;
      
      case 2:
	FileIO::readFile("original.txt", original);
	Crypt::encrypt(original, encrypted);
	FileIO::writeFile("encrypt02.txt", encrypted);
	FileIO::readFile("encrypt02.txt", encrypted);
	Crypt::decrypt(encrypted, decrypted);
	FileIO::writeFile("decrypt02.txt", decrypted);
	break;
      
      default:
	cout << "Invalid entry!\n";
	flag = 0;
	break;
      }
    }while(flag == 0);
    cout << "Encrypt another (y/n)? ";
    cin >> again;
  }while(again == 'y');
  return 0;
}
