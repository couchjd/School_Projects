#ifndef DICTIONARY_H
#define DICTIONARY_H

/**
 * dictionary.h
 * class Dictionary
 * 
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.0 (10.20.2014)
 **/
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Dictionary{
 private:
  const int maxWordsInDict;
  const int maxWordsPerFile;
  int totalWordsInDict;
  int numOfWordsInFile[26];
  static bool failure;
  static bool success;

  /**
   * Formats and returns name of file to be opened.
   *
   * @param string word -- first character is used to create file name.
   * @return string -- returns name of file created from first character of word.
   **/
  string fileName(const string& word);

  /**
   * Checks to see if dictionary or current file are at maximum capacity.
   *
   * @param string filename -- name of file to check.
   * @return bool Dictionary::success if dictionary or current file is full.
   * @return bool Dictionary::failure if dictionary or current file in not full. 
   **/
  bool isFull(string& filename);

 public:

  /**
   * Default constructor
   *
   **/
  Dictionary();

  /**
   * Constructor
   *
   * @param int dictMaxWords -- maximum number of words that can be input into dictionary
   * @param int fileMaxWords -- maximum number of words that can be in any file of dictionary.
   **/
  Dictionary(int dictMaxWords, int fileMaxWords);

  /**
   * Default destructor
   *
   **/
  ~Dictionary();

  /**
   * Adds passed word to dictionary. 
   *
   * @param string word -- word to be added to dictionary.
   * @return bool Dictionary::success if word is successfully added to dictionary.
   * @return bool Dictionary::failure if word cannot be added to dictionary.
   **/
  bool AddAWord(string word);

  /**
   * Removes passed word from dictionary. 
   *
   * @param string word -- word to be removed from dictionary.
   * @return bool Dictionary::success if word is successfully removed from dictionary.
   * @return bool Dictionary::failure if word cannot be removed from dictionary.
   **/
  bool DeleteAWord(string word);

  /**
   * Searches for a word within the dictionary. 
   *
   * @param string word -- word to be searched for.
   * @return bool Dictionary::success if word is found in dictionary.
   * @return bool Dictionary::failure if word cannot be found in dictionary.
   **/
  bool SearchForWord(string word);

  /**
   * Prints all words in specified file of dictionary.
   *
   * @param string filename -- name of file to be printed 
   **/
  bool PrintAFileInDict(string& filename);

  /**
   * Checks file passed in against all entries in dictionary.
   *
   * @param string filename -- name of file to be checked.
   * @return boolean Dictionary::failure if file cannot be opened.
   * @return boolean Dictionary::success if file can be opened.
   **/
  bool SpellChecking(string filename);

  /**
   * Opens a file and attempts to add all words in the file to the dictionary.
   *
   * @param string filename -- name of file to read words from.
   * @return boolean Dictionary::failure if file cannot be opened.
   * @return boolean Dictionary::success if file can be opened.
   **/
  bool InsertWordsIntoDict(string& filename);

  /**
   * Reads transaction file, parses the contents, and calls relevant methods
   * with the proper values.
   **/
  void ProcessTransactionFile();

  /**
   * Helper function to convert words to lower case.
   *
   * @param string word -- word to be converted.
   * @return string word -- lowercase represen
   **/
  string to_lower(const string& word);
};

#endif
