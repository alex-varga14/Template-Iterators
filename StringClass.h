#include <iostream>
using namespace std;

#ifndef STRINGCLASS_H
#define STRINGCLASS_H

class StringClass {
	template <class T>
	friend class Vector;
 public:
  StringClass();

  StringClass(int n); 

  StringClass(const char *s); 
 
  ~StringClass(); // destructor

  StringClass(const StringClass& source); // copy constructor

  StringClass& operator =(const StringClass& rhs); // assignment operator

  int length() const;

  char get_char(int pos) const;

  const char * c_str() const;

  void set_char(int pos, char c);
  
  StringClass& append(const StringClass& other);

  void set_str(char* s);
  
  private:

  int lengthM; // the string length - number of characters excluding \0
  char* charsM; // a pointer to the beginning of an array of characters, allocated dynamically.
  void memory_check(char* s);
};

ostream& operator << (ostream& os, const StringClass& s); //operator
#endif











