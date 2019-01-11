 ///
 /// @file    onlyStackObject2.cc
 /// @author  Pavel(1786447581@qq.com)
 /// @date    2019-01-10 03:35:33
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;


class Student
{

public:

	Student(int d,const char* name)
	:_d(d)
	,_name(new char[strlen(name)+1]())
	{
		strcpy(_name,name);
		cout << "Student()" << endl;
	}

	~Student()
	{
		delete[] _name;
		cout << "~Student()" <<endl;
	}

	void print() const
	{
		cout << "_d = " <<endl;
		cout << "_name = " << _name <<endl;
	}

private:

	void* operator new(size_t size)
	{
		void * pret = malloc(size);
		cout << "void* operator new(size_t size)" << endl;
		return pret;
	}
	
	void operator delete(void* pret)
	{
		free (pret);
		cout << "void operator delete(void* pret)" <<endl;
	}

private:
	int _d;
	char *_name;
};


int main(void)
{
	Student s1(100,"Pavel");

	return 0;
}
