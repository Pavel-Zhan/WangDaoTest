 ///
 /// @file    onlyHeapObject2.cc
 /// @author  Pavel(1786447581@qq.com)
 /// @date    2019-01-10 03:59:59
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
 
class Student
{

public:

	Student(int id,const char * name)
	:_id(id)
	,_name(new char[strlen(name)+1]())
	{
		strcpy(_name,name);
		cout << "Student();" <<endl;
	}

	void print() const
	{
		cout << "_id" << _id << endl;
		cout << "_name" << _name << endl;
	}

	void* operator new(size_t size)
	{
		void* pret = malloc(size);
		cout << "void * operator new(size_t size)" << endl;
		return pret;
	}

	void operator delete(void* pret)
	{
		free (pret);
		cout << "void operator delete(void* pret)" <<endl;
	}

	void destory()
	{
		delete this;
	}
	
private:

	~Student()
	{
		delete[] _name;
		cout << "~Student();" <<endl;
	}

private:
	int _id;
	char* _name;
};



int main(void)
{
	Student* pstu1 = new Student(100,"Pavel");
	//Student pstu1(100,"Pavel");
	pstu1->print();
	//Student* pstu2 = new Student(100,"Levap");
	//pstu2->print();


	//delete[] pstu1;
	//delete pstu1;
	pstu1->destory();
	return 0;
}
