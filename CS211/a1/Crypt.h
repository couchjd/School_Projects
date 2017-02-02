/**
 * Crypt.h
 * class Crypt
 * Provides methods for encrypting and decrypting the contents of a vector of strings.
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu
 * @version 1.1 (09.18.2014)
 **/
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Crypt
{
 public:
  /**
   * Static method for encrypting a vector of strings by rotation.
   *
   * @param const vector<string> &unencrypted -- the vector to be encrypted
   * @param vector<string> &encrypted -- the contents of the vector are placed here
   *                                     once they are encrypted.
   * @param int rotation -- the amount each character should be rotated for encryption
   **/
  static void encrypt(const vector<string> &unencrypted, vector<string> &encrypted, int rotation);

  /**
   * Static method for encrypting a vector of strings by cryptogram.
   *
   * @param const vector<string> &unencrypted -- the vector to be encrypted
   * @param vector<string> &encrypted -- the contents of the vector are placed here
   **/
  static void encrypt(const vector<string> &unencrypted, vector<string> &encrypted);

  /**
   * Static method for decrypting a vector of strings by rotation.
   *
   * @param const vector<string> &unencrypted -- the contents of the encrypted vector are placed
   *                                             here once they have been decrypted.
   * @param vector<string> &encrypted -- the vector to be decrypted.
   * @param int rotation -- the amount each character should be rotated for decryption
   **/
   static void decrypt(const vector<string> &encrypted, vector<string> &unencrypted, int rotation);

  /**
   * Static method for decrypting a vector of strings by cryptogram.
   *
   * @param const vector<string> &unencrypted -- the contents of the encrypted vector are placed
   *                                             here once they have been decrypted.
   * @param vector<string> &encrypted -- the vector to be decrypted.
   **/
  static void decrypt(const vector<string> &encrypted, vector<string> &unencrypted);
};
