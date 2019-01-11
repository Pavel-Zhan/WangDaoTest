#ifndef _String_H
#define _String_H


class String
{
public:
	String();
	String(const char*pstr);
	String(const String& rhs);
	String&operator=(const String & rhs);
	~String();
	void print() const;
private:
	char * _pstr;	
};


#endif
