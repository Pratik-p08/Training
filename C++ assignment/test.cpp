#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<sstream>
using namespace std;
vector<string> printWords(string str)
{
    // word variable to store word
    string word;
 
    // making a string stream
    stringstream iss(str);
    vector<string>result;
 
    // Read and print each word.
    while (iss >> word)
       result.push_back(word);
    return result;
}

string removeSpaces(string &str)
{
    // n is length of the original string
    int n = str.length();
 
    // i points to next position to be filled in
    // output string/ j points to next character
    // in the original string
    int i = 0, j = -1;
 
    // flag that sets to true is space is found
    bool spaceFound = false;
 
    // Handles leading spaces
    while (++j < n && str[j] == ' ');
 
    // read all characters of original string
    while (j < n)
    {
        // if current characters is non-space
        if (str[j] != ' ')
        {
            // remove preceding spaces before dot,
            // comma & question mark
            if ((str[j] == '.' || str[j] == ',' ||
                 str[j] == '?') && i - 1 >= 0 &&
                 str[i - 1] == ' ')
                str[i - 1] = str[j++];
 
            else
                // copy current character at index i
                // and increment both i and j
                str[i++] = str[j++];
 
            // set space flag to false when any
            // non-space character is found
            spaceFound = false;
        }
        // if current character is a space
        else if (str[j++] == ' ')
        {
            // If space is encountered for the first
            // time after a word, put one space in the
            // output and set space flag to true
            if (!spaceFound)
            {
                str[i++] = ' ';
                spaceFound = true;
            }
        }
    }
 
    // Remove trailing spaces
    if (i <= 1)
        str.erase(str.begin() + i, str.end());
    else
        str.erase(str.begin() + i - 1, str.end());
    return str;
}
 
int main()
{


// Create a text string, which is used to output the text file
string myText;
vector<string> vect;
vector<string> results;
vector<vector<string>> withWords;
// Read from the text file
ifstream MyReadFile("input/sample_input.in");

// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
   vect.push_back(myText);
  // Output the text from the file
  cout<<myText<<endl;
}

 for(int i=0;i<vect.size();i++)
 {
  string temp=removeSpaces(vect[i]);
  results.push_back(temp);
 }
for(int i=0;i<results.size();i++)
 {
  cout<<results[i]<<endl;
 }

for (int i=0;i<results.size();i++)
{
  withWords.push_back(printWords(results[i]));
}

for (int i=0;i<withWords.size();i++)
{
  for(int j=0;j<withWords[i].size();j++)
  {
    cout<<withWords[i][j]<<endl;
  }
}



for (int i=0;i<withWords.size();i++)
{
  cout<<withWords[i][1]<<" "<<withWords[i][0]<<","<<endl;
  cout<<withWords[i][4]<<" "<<withWords[i][5]<<","<<endl;
  cout<<withWords[i][6]<<","<<withWords[i][7]<<","<<withWords[i][8]<<endl;
  cout<<endl;
}

for (int i=0;i<withWords.size();i++)
{
  cout<<withWords[i][1]<<" "<<withWords[i][0]<<" ";
  cout<<withWords[i][4]<<" "<<withWords[i][5]<<" ";
  cout<<withWords[i][6]<<","<<withWords[i][7]<<" "<<withWords[i][8]<<endl;
  cout<<endl;
}

for (int i=0;i<withWords.size();i++)
{
  cout<<'"'<<withWords[i][1]<<" "<<withWords[i][0]<<'"'<<",";
  cout<<'"'<<withWords[i][4]<<" "<<withWords[i][5]<<'"'<<","<<endl;
  cout<<'"'<<withWords[i][6]<<","<<withWords[i][7]<<" "<<withWords[i][8]<<'"'<<endl;
  cout<<endl;
}





// Close the file
MyReadFile.close();

}
     