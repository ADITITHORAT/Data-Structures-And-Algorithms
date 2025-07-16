#include<iostream>
using namespace std;


class node 
{
  public:
  int data;
  node * next;
  
  node()
  {
    data = 0;
    next = nullptr;
  }
  node(int no)
  {
    data = no;
    next = nullptr;
  }
};

class stack
{
  private:

  node * first;
  int iCount ;
  public:
  stack();
  void Push(int);
  int Pop();
  void Display();
  int Count();
};

stack :: stack()
{
  this -> first = nullptr;
  iCount = 0;
}

int stack ::Count()
{
  return this -> iCount;
}

void stack :: Display()
{
  node * temp = this -> first;
  while(temp != nullptr)
  {
    cout<<"| "<<temp->data<<" |"<<endl;
    temp = temp->next;
  }
}

void stack :: Push(int no)
{
  node * newn = new node(no);
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

int stack :: Pop()
{
  node * temp = this -> first;
  int iValue = 0;
  if(this -> first == nullptr)
  {
    cout<<"Stack is empty"<<endl;
    return -1;
  }
  else 
  {
    iValue = temp->data;
    this -> first = this -> first -> next;
    this -> iCount--;
    delete temp;
    return iValue;
  }
}
int main()
{
  stack sobj;
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