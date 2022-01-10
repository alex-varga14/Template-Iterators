//  mystring2.cpp
// ENSF 480 - Fall 2021 - Lab 3, Ex B and C

#include "mystring2.h"
#include <string.h>
#include <iostream>
using namespace std;

StringClass::StringClass()
{ 
  charsM = new char[1]; 
  charsM[0] = '\0';
  lengthM = 0;
}

StringClass::StringClass(const char *s)
  : lengthM(strlen(s))
{
  charsM = new char[lengthM + 1];
  strcpy(charsM, s);
}

StringClass::StringClass(int n)
  : lengthM(0), charsM(new char[n])
{
  charsM[0] = '\0';
}

StringClass::StringClass(const StringClass& source):
  lengthM(source.lengthM), charsM(new char[source.lengthM+1])
{
  strcpy (charsM, source.charsM);
}

StringClass::~StringClass()
{
  delete [] charsM;
}

int StringClass::length() const
{
  return lengthM;
}

char StringClass::get_char(int pos) const
{
  if(pos < 0 && pos >= length()){
    cerr << "\nERROR: get_char: the position is out of boundary." ;
  }

  return charsM[pos];
}

const char * StringClass::c_str() const
{
  return charsM;
}

void StringClass::set_char(int pos, char c)
{
  if(pos < 0 && pos >= length()){
    cerr << "\nset_char: the position is out of boundary."
	 << " Nothing was changed.";
    return;
  } 

  if (c != '\0'){
    cerr << "\nset_char: char c is empty."
	 << " Nothing was changed.";
    return;
  }

  charsM[pos] = c;
}

StringClass& StringClass::operator =(const StringClass& S)
{
  if(this == &S)
    return *this;
  delete [] charsM;
  lengthM = (int) strlen(S.charsM);
  charsM = new char [lengthM+1];
  strcpy(charsM,S.charsM);
  return *this;
}

ostream& operator << (ostream& os, const StringClass & s){
	os << s.c_str();
	return os;
}

StringClass& StringClass::append(const StringClass& other)
{
  char *tmp = new char [lengthM + other.lengthM + 1];
  lengthM+=other.lengthM;
  strcpy(tmp, charsM);
  strcat(tmp, other.charsM);
  delete []charsM;
  charsM = tmp;

  return *this;
}

 void StringClass::set_str(char* s)
{
    delete []charsM;
    lengthM = (int) strlen(s);
    charsM=new char[lengthM+1];

    strcpy(charsM, s);
}
