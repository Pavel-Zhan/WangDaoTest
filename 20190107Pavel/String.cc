#include<iostream>
#include<stdio.h>
#include<string.h>
#include"String.h"

using std::cout;
using std::endl;

String::String()
:_pstr(new char[1]())
{
   strcpy(_pstr,"");
   cout << "Default Costructor" << endl;
}

String::String(const char *pstr)
:_pstr(new char[strlen(pstr)+1]())
{
   strcpy(_pstr,pstr);	
   cout << "Construcor" <<endl;
}

String::String(const String& rhs)
:_pstr(new char[strlen(rhs._pstr)+1]())
{
   strcpy(_pstr,rhs._pstr);
   cout<< "Copy Constructor" <<endl;
}

String& String::operator=(const String& rhs)
{
   size_t len = strlen(this->_pstr);
   if(len>strlen(rhs._pstr))
	   strcpy(this->_pstr,rhs._pstr);
   else{
   	delete[] this->_pstr;
	this->_pstr = new char[strlen(rhs._pstr)+1]();
	strcpy(this->_pstr,rhs._pstr);
   }
}

String::~String()
{
	delete[] _pstr;
	cout << "~String();" <<endl;
}
	
void String::print() const
{
	cout << "_pstr = " << _pstr << endl;
}


int main(void)
{
	String str1;
	str1.print();

	String str2 = "Hello,world";
	String str3("wangdo");

	str2.print();
	str3.print();

	String str4 = str3;
	str4.print();
	
	str4 = str2;
	str4.print();

	return 0;
}	
                                               
