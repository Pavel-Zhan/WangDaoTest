//Singleton mode

#include <iostream>

using std::cout;
using std::endl;

class Singleton
{

public:
    static Singleton* getInstance()
    {
        if(nullptr == _pInstance)
        {
            _pInstance = new Singleton();
        }
        return _pInstance;
    }

    static void destory()
    {
        if(_pInstance)
            delete _pInstance;
    }

private:
    Singleton() {cout <<"Singleton" <<endl;}
    ~Singleton() {cout <<"~Singleton" <<endl;}

private:
    static Singleton * _pInstance;
};

Singleton* Singleton::_pInstance = nullptr;


int main()
{
    Singleton* ps1 = Singleton::getInstance();
    Singleton* ps2 = Singleton::getInstance();
    
    Singleton::destory();
    return 0;
}
	
