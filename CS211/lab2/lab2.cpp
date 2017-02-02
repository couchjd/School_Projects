#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void processLine(string action, string value, int index, vector<string> &V);
void processString(string lineIn, string &action, string &value, int &index);

int main()
{
  string temp;
  string action;
  string value;
  int index;

  vector<string> V;
  fstream inFile;
  
  inFile.open("data.txt");
  if(!inFile)
    cout << "File not found.";
  else
  {
    while(inFile)
    {
      if(inFile.eof())
	break;
      getline(inFile, temp, '\n');
      processString(temp, action, value, index);
      processLine(action, value, index, V);
    }
  }
  inFile.close();
}

void processString(string lineIn, string &action, string &value, int &index)
{
  string temp;
  action = lineIn.substr(0, lineIn.find('\t'));
  temp = lineIn.substr(lineIn.find('\t')+1, string::npos);

  if(action == "Insert")
  {
    value = temp.substr(0, temp.find('\t'));
    index = atoi(temp.substr(temp.find('\t')+1, string::npos).c_str());
  }
  else if(action == "Delete")
  {
    value = "";
    index = atoi(temp.substr(temp.find('\t')+1, string::npos).c_str());
  }
  else if(action == "Print")
  {
    value = "";
    index = 0;
  }
}

void processLine(string action, string value, int index, vector<string> &V)
{
  if(action == "Insert")
  {
    if(index < V.size() && index >= 0)
      V.insert(V.begin()+index, value);
    else if(index == V.size())
      V.push_back(value);
    else
      cout << "Cannot insert value: \"" << value << "\" at index: [" << index << "]. Index is out of range." << endl;
  }
  else if(action == "Delete")
  {
    if(index <= V.size()-1)
      V.erase(V.begin()+index);
    else
      cout << "Cannot delete value at index: [" << index << "]. Index is out of range." << endl;
  }
  else if(action == "Print")
  {
    cout << "Index\tValue" << endl;
    cout << "---------------" << endl;
    for(int x = 0; x < V.size(); x++)
      cout << x << '\t' << V[x] << endl;
  }
  else
    cout << "Command not found.";
}
