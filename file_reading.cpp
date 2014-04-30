#include <iostream> //cin, cout
#include <fstream> //ifstream, open, is_open, close, getline, 
#include <cctype> //isalnum, isspace
using namespace std;

//for eventual use in a word frequency project...some ideas for word checks
//read line         Adam David Scott, Ph.D.
//check alnum       11110111110111110011010
//check white space 00001000001000000100000

int main() {
  string str_filename;
  cout << "Enter the filename to read. ";
  cin >> str_filename;
  //convert string to char array, needed for ifstream open
  char ch_filename[str_filename.size()];
  for (int i=0; i<str_filename.size(); i++) { ch_filename[i] = str_filename[i]; }
  
  ifstream file_in; //default ifstream open mode is ios::in
  file_in.open(ch_filename);
  
  if (file_in==NULL)  {
    perror ("Error opening file");
  } else {
    string line_in;
    bool done = false;
    int num_lines = 0;
    while(getline(file_in,line_in)) { //file_in line to line_in
//
//word checks in here
//
      num_lines++;
      cout << line_in << endl;
    }
    cout << endl;
    if (file_in.eof())  { 
      cout << "End of file (eof) was reached after reading " << num_lines << " lines.\n"; 
      file_in.clear();
      cout << "To read again, you should reset eof state and the get position.\n";
      if (file_in.eof())  {
        cout << "Did not reset eof properly.\n";
      } else {
        cout << "The eof state reset properly.\n";
      }
    }
    cout << "The get position now needs to be reset.\n";
    streampos begin = ios::beg;
    file_in.seekg(begin);  //Set get position to beginning of file
    if (file_in.tellg()==begin) { cout << "The get position has been reset. Read now! AGAIN!\n\n"; }
    while(getline(file_in,line_in)) { cout << line_in << endl;  }
    file_in.close();
  }
  return 0;
}
