 ///
 /// @file    Dictionary.cc
 /// @author  Pavel(1786447581@qq.com)
 /// @date    2019-01-10 04:08:23
 ///
 
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

class Dictionary
{

public:
	
	void read(const std::string & filename);
	void store(const std::string & filename);

private:

	vector<string> _words;
	vector<int> _numbers;
};

void Dictionary::read(const std::string & filename)
{
	ifstream ifs(filename);
	if(!ifs)
	{
		cout << "ifstream open" << filename << "error" << endl;
		return;
	}
	int iFlag = 0;
	string word;
	while(ifs >> word)
	{
		iFlag = 0;
		if(0 == _words.size())
		{	_words.push_back(word);
			_numbers.push_back(1);
		}
		else
		{
			for(int i=1; i<= _words.size();i++)
			{
				if(word == _words[i])
				{
					_numbers[i] += 1;
					iFlag = 1;
				}
			}
			if(!iFlag)
			{
			_words.push_back(word);
			_numbers.push_back(1);
			}
		}

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
	for(int i=1; i <= _words.size();i++ )
	{
		ofs << _words[i] << " " << _numbers[i] << endl;
	}
	ofs.close();
}

int main(void)
{
	Dictionary dict;
	dict.read("TheHolyBible.txt");
	dict.store("dictionary.txt");
	return 0;
}

