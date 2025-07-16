#include<iostream>
using namespace std;

template <class T>
class node 
{
  public:
  T data;
  node <T>* next;
  
  node()
  {
    this -> data = data;
    next = nullptr;
  }
  node(T no)
  {
    data = no;
    next = nullptr;
  }
};


template <class T>
class stack
{
  private:

  node <T>* first;
  int iCount ;
  public:
  stack();
  void Push(int);
  T Pop();
  void Display();
  int Count();
};

template <class T>
stack<T> :: stack()
{
  this -> first = nullptr;
  iCount = 0;
}

template <class T>
int stack<T> ::Count()
{
  return this -> iCount;
}
template <class T>
void stack<T> :: Display()
{
  node<T> * temp = this -> first;
  while(temp != nullptr)
  {
    cout<<"| "<<temp->data<<" |"<<endl;
    temp = temp->next;
  }
}
template <class T>
void stack<T> :: Push(int no)
{
  node<T> * newn = new node<T>(no);
  if(this -> first == nullptr)
  {
    this -> first = newn;
  }
  else 
  {
    newn->next = this -> first;
    this -> first = newn;
  }
  this -> iCount ++;
}
template <class T>
T stack<T> :: Pop()
{
  T iValue ;
  node<T> * temp = this -> first;
  if(this -> first == nullptr)
  {
    cout<<"Stack is empty"<<endl;
    return -1;
  }
  else 
  {
    iValue = temp -> data;
    this -> first = this -> first -> next;
    this -> iCount--;
    delete temp;
    return iValue;
  }
}
int main()
{
  stack<int> sobj;
  int iRet = 0,icnt = 0;
  sobj.Push(11);
  sobj.Push(21);
  sobj.Push(31);
  sobj.Display();
  icnt = sobj.Count();
  cout<<"Elements in the stack are : "<<icnt<< endl;
  iRet = sobj.Pop();
  sobj.Display();
  cout<<"Poped : "<<iRet<<endl;
  icnt = sobj.Count();
  cout<<"Elements in the stack are : "<<icnt<< endl;
  return 0;
}