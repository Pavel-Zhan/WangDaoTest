//queue 

#include <iostream>

using std::cout;
using std::endl;

class Queue
{
public:
    void initQueue();
    void push(int x);
    void pop();
    int front();
    int back();
    bool empty();
    bool full();
    Queue();
    Queue(int Max_size);
    ~Queue();
private:
    int *_data;
    int _top;
    int _maxSize;
};

void Queue::initQueue()
{  
    _top = -1;
    _data = new int(_maxSize);
}

void Queue::push(int x)
{
    if(_maxSize == _top+1)
    {
        cout << "It is full!" <<endl;
    }
    else
    {
        for(int i=_top;i>=0;i--)
        {
            _data[i+1] = _data[i];
        }
        _data[0] = x;
        _top += 1;
    }
}

void Queue::pop()
{
    if(-1 == _top)
    {
        cout << "There is no element in this fucking Queue!" <<endl;
    }
    else
    {
        _top -= 1;
    }
}

int Queue::front()
{
    if(-1 == _top)
    {
        cout << "There is no element in this fucking Queue!" << endl;
    }
    else
    {
        cout << "The top of this Queue is:"<< _data[_top] <<endl;
        return _data[_top];
    }
}

int Queue::back()
{
    if(-1 == _top)
    {
        cout << "There is no element in this fucking Queue!" <<endl; 
    }
    else
    {
         cout << "The rail of the Queue is:"<< _data[0] << endl;        
         return _data[0];
    }
}

bool Queue::empty()
{
    return (-1 == _top)?1:0;
}

bool Queue::full()
{
    return (_top >= _maxSize)?1:0;
}

Queue::Queue()
{
    _maxSize = 10;
    initQueue();
}

Queue::Queue(int Max_size)
{
    _maxSize = Max_size;
    initQueue();
}

Queue::~Queue()
{
    delete _data;
}

int main()
{
    Queue queue1;
    queue1.push(10);
    queue1.push(12);
    queue1.push(14);
    queue1.front();
    queue1.pop();
    queue1.front();
    return 0;
}
