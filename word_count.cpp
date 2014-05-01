#include <iostream> //cin, cout
#include <fstream> //ifstream, open, is_open, close, getline, 
#include <cctype> //isalnum, isspace, isupper, tolower
using namespace std;

//prototype functions
char check_case(char);
void clean_word(string*);

int main() {
  string str_filename;
  ifstream file_in;
  cout << "Enter the filename to read. ";
  cin >> str_filename;
  file_in.open(str_filename.c_str()); //default file test_read.in
  
  if (file_in==NULL)  {
    perror ("Error opening file");
  } else {
    string line_in; //stores each line of the file
    string word("");
    char achar; //current char
    char pause;
    int num_words(0); //counts total number of words
    int num_lines(0);

    while(getline(file_in,line_in)) { //file_in line to line_in
      num_lines++;
      word = "";  //make sure word resets
      cout << endl << line_in << endl;  //print line read in
      for(int i=0; i<line_in.size(); i++) { //cycle through line
        achar = line_in[i];
        if (isspace((int)achar)) {  //achar is space or end line
//          cout << word << endl;
          clean_word(&word);
          cout << word;
          //to nodes
            num_words++;  //FOR LATER: check nodes for same word
          word = "";  //reset word
          cout << "\t\tThere are " << num_words << " words now." << endl << endl;
        } else {  //achar not space
          achar = check_case(achar);
          word += achar;
//          cout << word << " didn't find space" << endl;
        }
      } //for line_in
      if (word.size()>0) {  //reached end of line, if word has size, need to record
//        cout << word << " last word of line" << endl;
//        cout << word << endl;
        clean_word(&word);
        cout << word;
        //to nodes
          num_words++;  //FOR LATER: check nodes for same word
        word = "";  //reset word
      }
      cout << "\t\tThere are " << num_words << " words after " << num_lines << " lines." << endl << endl;
//      cin.get(pause);
//      cout << "\tHIT ENTER TO CONTINUE" << endl << endl;
    } //while getline
    cout << endl;
    file_in.close();
  }
  return 0;
}

char check_case(char a) {
  if (isupper((int)a)) 
    a = (char)tolower((int)a);
  return a;
}

void clean_word(string* b) {
  string::reverse_iterator rit = b->rbegin(); //start from end of word
  int range2delete = 0;
  while (!isalnum((int)(*rit))) { //while char is not alphanumeric
    range2delete++;
//    cout << "\tCHECKING END VALUES OF WORD " << *rit << endl;
    ++rit;
  }
//  cout << "\tWORD BEFORE " << range2delete << " DELETIONS " << *b << endl;
  b->erase(b->end()-range2delete,b->end());
//  cout << "\tWORD AFTER ANY DELETION " << *b << endl;
}
