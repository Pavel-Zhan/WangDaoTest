// stack

#include<iostream>

using std::cout;
using std::endl;

class Stack1
{

public:
    void initStack(); //initializing Stack
    void push(int x); // in the stack 
    void pop(); //out of the stack
    int top(); // read the top of stack
    bool empty(); // empty or not
    bool full();// full or not
    Stack1(); //  constructor
    Stack1(int max_Size);
    ~Stack1(); //  destructor

private:
    int * _data;
    int _top;
    int _maxSize;
};

void Stack1::initStack()
{
    _data = new int(_maxSize);
    _top = -1;
}

Stack1::Stack1()
{
    _maxSize = 10;
    initStack();
    cout << "Dafault Constructor" << endl;
}

Stack1::Stack1(int max_Size)
{
    _maxSize = max_Size;
    initStack();
    cout << "Customed Constructor" << endl;
}

Stack1::~Stack1()
{
    delete _data;
    cout << "Destructor" <<endl;
}

    
void Stack1::push(int x)
{
    _data[++_top] = x;    
}

void Stack1::pop() //out of the stack
{
    if(-1 == _top)
    {
        cout << "There is no element in this fucking stack!" << endl;
    }
    else
    {
        _top -= 1; 
    }
}

int Stack1::top() // read the top of stack
{
    if(-1 == _top)
    {
        cout << "There is no element in this fucking stack!" << endl;
    }
    else
    {
        cout <<"The top element is:" << _data[_top] << endl;    
        return _data[_top];
    }
}

bool Stack1::empty() // empty or not
{
    return (-1 == _top)?1:0;    
}

bool Stack1::full()// full or not
{
    return (_top>=_maxSize)?1:0;
}


int main()
{
    Stack1 stack2;
    stack2.push(10);
    stack2.push(12);
    stack2.push(14);
    stack2.top();
    stack2.pop();
    stack2.top();

    return 0;
}
