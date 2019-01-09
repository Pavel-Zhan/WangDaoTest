//DoubleLinkedList
#include<iostream>

using std::cout;
using std::endl;

class Node
{
public:
    int data;
    Node *pre;
    Node *next;
};

class List
{
public:
    List();
    ~List();
    void push_back(int value);
    void push_front(int vale);
    void pop_back();
    void pop_front();
    void insert(Node* ,int value);
    void erase(Node*);
    void display() const;
    Node* find(const Node*);

private:
    Node* _head;
    Node* _tail;
    int _size;
};；


List::List()
{
    _head = NULL;
    _tail = NULL;
    _size = 0;
    cout << "default Constructor" << endl;
}

List::~List()
{
    Node* temp = _head;
    while(_head != _tail)
    {
        _head = _head->next;
        delete temp;
        temp = _head;
    }
}

void List::push_back(int value)
{
    if(NULL == _head)
    {
        _head = new Node();
        _head->data = value;
        _size++;
        _tail = _head;
    }
    else
    {
        _tail->pre = new Node();
        _tail->pre->data = value;
        _tail->pre->next = _tail;
        _tail = _tail->pre;
        _size++;
    }
}

void List::push_front(int vale)
{
    if(NULL == _head)
    {
        _head = new Node();
        _head->data = value;
        _size++;
        _tail = _head; 
    }
    else
    {
        _head->next = new Node();
        _head->next->data = value;
        _head->next->pre = _head;
        _head = _head->next;
        _size++;
    }
}

void List::pop_back()
{
    if(NULL == _head)
    {
        cout << "There is no element in this DoubleLinkedList !" <<endl;
    }
    else if(_tail == _head)
    {
        Node * temp = _head;
        delete *temp;
        _tail = NULL;
        _head = NULL;
    }
    else
    {
        Node* temp = _tail;
        _tail = _tail->next;
        delete temp;
    }
}

void List::pop_front()
{

    if(NULL == _head)
    {
        cout << "There is no element in this DoubleLinkedList !" <<endl;
    }
    else if(_tail == _head)
    {
        Node * temp = _head;
        delete *temp;
        _tail = NULL;
        _head = NULL;
    }
    else
    {
        Node* temp = _head;
        _head = _head->pre;
        delete temp;
    }
}

Node* List::find(const Node* node)
{
    Node* temp;
    int flag = 0;
    temp = _head;
    if(NULL == head)
    {
        cout << "It is empty!" <<endl;
    }
    else
    {
        while(node->data != temp->data)
        {
            if(_tail == temp)
            {
                cout << "There is no suitable data!" <<endl;
                flag = 1;
                break;
            }
            else
            {
                temp = temp->pre;
            }
        }
        if(0 == flag)
        {
            return temp;
        }
        else
        {
            return NULL;
        }
    }
}

void List::insert(Node* temp,int value)
{
    if(NULL == find(temp))
    {
        cout<< "There is no suitable data!" <<endl;
    }
    else
    {
        Node* p = new Node();
        p->pre = temp->pre;
        p->next = temp;
        temp->pre = p;
        p->data = value;
    }
}

void List::erase(Node*)
{
    if(NULL == find(temp))
    {
        cout<< "There is no suitable data!" <<endl;
    }
    else
    {
        Node* p = temp;
        p->next->pre = p->pre;
        p->pre->next = p->next;
        delete p;
    }
}

void List::display() const
{
    Node* temp;
    temp = _head;
    if(NULL == temp)
    {
        cout << "It is empty!" << endl;
    }
    else
    {
        while(temp!=_tail->next)
        {
            cout << temp->data <<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}


int main()
{

    return 0;
}

