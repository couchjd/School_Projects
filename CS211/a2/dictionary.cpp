/**
 * dictionary.cpp
 * Implementation of Dictionary Class methods
 *
 * @author Jeff Couch (couch009@cougars.csusm.edu)
 * @version 1.0 (10.20.2014)
 **/

#include "dictionary.h"

bool Dictionary::failure = false;
bool Dictionary::success = true;

Dictionary::Dictionary() : maxWordsInDict(10000), maxWordsPerFile(1000){
  totalWordsInDict = 0;
  for(int x = 0; x < 26; x++){ //initialize word count of all files to 0
    numOfWordsInFile[x] = 0;
  }
}

Dictionary::Dictionary(int dictMaxWords, int fileMaxWords) : maxWordsInDict(dictMaxWords), maxWordsPerFile(fileMaxWords){
  totalWordsInDict = 0;
  for(int x = 0; x < 26; x++){ //initialize word count of all files to 0
    numOfWordsInFile[x] = 0;
  }
}

Dictionary::~Dictionary(){
}

string Dictionary::to_lower(const string& word){
  string tempString = word;
  for(int x = 0; x < word.length(); x++)
    //convert each character in word to lowercase.
    tempString[x] = tolower(word[x]);
  return tempString;
}

bool Dictionary::AddAWord(string word){
  ofstream fout;
  string file = fileName(word);
  word = to_lower(word);

  //check if file or dictionary is full
  if(isFull(file))
    return(failure);

  fout.open(file.c_str(), fstream::app);

  if(!SearchForWord(word)){
    //output word to file
    fout << word << " ";
    //increment word counts
    numOfWordsInFile[toupper(file[0]-65)]++;
    totalWordsInDict++;
    return(success);
  }
  fout.close();
  return(failure);
}

bool Dictionary::DeleteAWord(string word){
  vector<string> wordsVect;
  bool wordFound = false;
  word = to_lower(word);
  string nextWord;
  ifstream fin;
  ofstream fout;
  string file = fileName(word);

  fin.open(file.c_str());
  fin >> nextWord;

  while(fin){
    if(fin.eof())
      break;
    wordsVect.push_back(to_lower(nextWord));
    fin >> nextWord;
  }
  fin.close();

  for(int x = 0; x < wordsVect.size(); x++){
    //check if word exists in file
    if(wordsVect[x] == word){
      cout << "ERASING: " << wordsVect[x] << endl;
      //erase word from vector
      wordsVect.erase(wordsVect.begin() + x);
      //decrement word counts
      numOfWordsInFile[toupper(fileName(word)[0]-65)]--;
      totalWordsInDict--;
      wordFound = true;
    }
  }
  //open file and discard previous contents
  fout.open(file.c_str(), ofstream::trunc);
  //write vector to file
  for(int x = 0; x < wordsVect.size(); x++){
    if(x == wordsVect.size())
      fout << wordsVect[x];
    else
      fout << wordsVect[x] << " ";
  }
  
  fout.close();

  if(wordFound == true)
    return(success);
  else
    return(failure);
}

bool Dictionary::SearchForWord(string word){
  string tempWord;
  ifstream fin;
  word = to_lower(word);
  string file = fileName(word);

  fin.open(file.c_str());

  fin >> tempWord;

  while(fin){
    if(fin.eof()){
      break;
    }
    if(to_lower(tempWord) == word){
      return success;
    }
    fin >> tempWord;
  }
  fin.close();
  return failure;
}

bool Dictionary::PrintAFileInDict(string& filename){
  string tempWord;
  ifstream fin;
  int count = 0;

  fin.open(filename.c_str());
  cout << "Contents of file: " << filename << endl;
  fin >> tempWord;
  if(!fin.is_open())
    return failure;
  while(fin){
    if(fin.eof())
      break;
    if(count >= 5){
      count = 0;
      cout << endl;
    }
    cout << tempWord << " ";
    count++;
    fin >> tempWord;
  }
  cout << endl;
  return success;
}

bool Dictionary::InsertWordsIntoDict(string& filename){
  ifstream fin;
  string tempWord;

  fin.open(filename.c_str());
  if(fin.is_open()){
    fin >> tempWord;
    while(fin){
      if(fin.eof())
	break;
      AddAWord(to_lower(tempWord));
      fin >> tempWord;
    }
    return success;
  }
  else
    return failure;
}

bool Dictionary::SpellChecking(string filename){
  ifstream fin;
  string tempWord;

  fin.open(filename.c_str());
  if(!fin.is_open())
    return failure;

  fin >> tempWord;
  while(fin){
    if(fin.eof())
      break;
    //check if word is in dictionary
    if(!SearchForWord(to_lower(tempWord)))
      cout << "Not found in dictionary: " << to_lower(tempWord) << endl;
    fin >> tempWord;
  }
  return success;
}

void Dictionary::ProcessTransactionFile(){
  ifstream fin;
  string full, action, value;
  fin.open("transaction.txt");
  getline(fin, full);  

  while(fin){
    //tokenize full string and call appropriate function,
    //passing value to that function
    action = full.substr(0, full.find(' '));
    value = full.substr(full.find(' ')+1);

    cout << "\n### " << action << " " << value << " ###" << endl;

    if(action == "AddW"){
      if(AddAWord(value))
	cout << "Added word: " << value << endl;
      else
	cout << "Could not add: " << value << endl;
    }
    else if(action == "DeleteW"){
      if(DeleteAWord(value))
	cout << "Deleted word:  " << value << endl;
      else
	cout << "Could not delete: " << value << endl;
    }
    else if(action == "SearchW"){
      if(SearchForWord(value))
	cout << "Found: " << value << endl;
      else
	cout << "Could not find: " << value << endl;
    }
    else if(action == "InsertF"){
      if(InsertWordsIntoDict(value))
	cout << value << " added successfully." << endl;
      else
	cout << "Could not open file: " << value << endl;
    }
    else if(action == "PrintF"){
      if(PrintAFileInDict(value))
	cout << "Printing: " << value << endl;
      else
	cout << "Could not open: " << value << endl;
    }
    else if(action == "SpellCheck"){
      if(SpellChecking(value))
	cout << "Checked: " << value << endl;
      else
	cout << "Could not open: " << value << endl;
    }
    else
      cout << "\nInvalid Action!" << endl;

    getline(fin, full);
  }
}

string Dictionary::fileName(const string &word){
  string fName = "#.txt";
  fName[0] = toupper(word[0]);
  return fName;
}

bool Dictionary::isFull(string &filename){
  if(numOfWordsInFile[toupper(filename[0])-'A'] >= maxWordsPerFile){
    cout << "File [" << filename << "] is full!" << endl;
    return success;
  }
  if(totalWordsInDict >= maxWordsInDict){
    cout << "Dictionary is full!" << endl;
    return success;
  }
  return failure;
}
