 ///
 /// @file    Dictionary.cc
 /// @author  Pavel(1786447581@qq.com)
 /// @date    2019-01-10 04:08:23
 ///
 
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::map;

class Dictionary
{

public:
	
	void read(const std::string & filename);
	void store(const std::string & filename);
	bool isEng(string w);
private:

	map<string,int> mymap; 
};

bool Dictionary::isEng(string w)
{
	return ((w[0]>='a'&&w[0]<='z')||(w[0]>='A'&&w[0]<='Z'));
}

void Dictionary::read(const std::string & filename)
{
	ifstream ifs(filename);
	if(!ifs)
	{
		cout << "ifstream open" << filename << "error" << endl;
		return;
	}
	string word;
	while(ifs >> word)
	{

		if(isEng(word)&& mymap.find(word) == mymap.end())
		{
			mymap[word] = 1;
		}
		else if (isEng(word))
		{
			mymap[word]++;
		}
		
//		if(0 == _words.size())
//		{	_words.push_back(word);
//			_numbers.push_back(1);
//		}
//		else
//		{
//			for(int i=1; i<= _words.size();i++)
//			{
//				if(word == _words[i])
//				{
//					_numbers[i] += 1;
//				}
//			}
//			if(!iFlag)
//			{
//			_words.push_back(word);
//			_numbers.push_back(1);
//			}
//		}
	}
	ifs.close();
}

void Dictionary::store(const std::string & filename)
{ 
	ofstream ofs(filename);
	if(!ofs)
	{
		cout << "ofstream open files error!" << endl;
	}
	map<string,int>::iterator it;

	for (it = mymap.begin(); it != mymap.end();it++)
	{		
		ofs << it->first << " " << it->second << endl;
	}
//	for(int i=1; i <= _words.size();i++ )
//	{
//		ofs << _words[i] << " " << _numbers[i] << endl;
//	}
	ofs.close();
}

int main(void)
{
	Dictionary dict;
	dict.read("TheHolyBible.txt");
	dict.store("Dictionary.txt");
	return 0;
}

