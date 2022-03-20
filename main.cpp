#include "String.h"

    #define     COLOR_BLACK   "\u001b[30m"
    #define     COLOR_RED   "\u001b[31m"
    #define     COLOR_GREEN "\u001b[32m"
    #define     COLOR_YELLOW   "\u001b[33m"
    #define     COLOR_BLUE   "\u001b[34m"
    #define     COLOR_MAGENTA   "\u001b[35m"
    #define     COLOR_CYAN   "\u001b[36m"
    #define     COLOR_WHITE   "\u001b[37m"


ostream& operator<< (ostream &out, String &s) {
  for(int i=0; i<s.size; i++) {
    out << s.str[i];
  }

  return out;
}


int main() {
  String s;
  String s2('a');
  String s3("Hallo");
  String s4(s3);

  cout << COLOR_GREEN <<  endl << "******* Constructors ********" << COLOR_WHITE << endl;

  cout << "empty constructor  : '" << s << "'"  << endl;
  cout << "char constructor   : '" << s2 << "'"  << endl;
  cout << "string constructor : '" << s3 << "'"  << endl;
  cout << "copy constructor   : '" << s4 << "'" << endl << endl;
  
  /*cout <<  COLOR_GREEN << endl << "******* move Constructor ********" << COLOR_WHITE << endl;
  cout << COLOR_YELLOW << "source            : '"  << s3 << "'" << COLOR_WHITE  <<  endl;  
  String s5 = std::move(s3); 
  cout << "move constructor  : '" << s5 << "'" << endl;
  cout << "empty source      : '" << s3 << "'" << endl ; 
  
  cout << COLOR_GREEN <<  endl << "******* index ********" << COLOR_WHITE << endl;
  cout << "index 0 : '"  << s5[0] << "'" << endl;
  cout << "index 1 : '"  << s5[1] << "'" << endl;
  cout << "index 2 : '"  << s5[2] << "'" << endl;
  cout << "index 3 : '"  << s5[3] << "'" << endl << endl;
  cout << "index 99 : '"  << s5[99] << "'" << endl;
  
  
  cout << COLOR_GREEN <<  endl << "******* = operator ********" << COLOR_WHITE << endl;
  
   s2 = s5;
  cout <<  COLOR_YELLOW << "source       : '"  << s2 << "'" << COLOR_WHITE <<  endl;
  s2 = s2;
  cout << "copy self    : '"  << s2 << "'" << endl << endl;
  
  
  cout <<  COLOR_YELLOW << "source       : '"  << s5 << "'" << COLOR_WHITE <<  endl;
  s3 = std::move(s5);
  cout << "move         : '"  << s3 << "'" <<  endl;
  cout << "empty source : '"  << s5 << "'" << endl << endl;


  cout << COLOR_GREEN <<  endl << "******* =+ operator ********" << COLOR_WHITE << endl;    
  cout <<  COLOR_YELLOW << "source            : '" << s3 << "'" << COLOR_WHITE << endl;
  s4 += s3;
  cout << "different sources : '" << s4 << "'" << endl << endl;
  s4 += s4;
  cout << "same source       : '" << s4 << "'" << endl << endl;*/


}


