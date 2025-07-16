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
    this ->data = data;
    this ->next = nullptr;
  }

  node(T no)
  {
    this ->data = no;
    this ->next = nullptr;
  }
};


template <class T>
class QueueX
{
  private:
  int iCount;
  node<T> * first;

  public:
  QueueX()
  {
    this ->iCount = 0;
    this ->first = nullptr;
  }

  void Enqueue(T no)
  {
    node<T>* newn = new node<T>(no);
    node<T> * temp = first;
    if(first == nullptr)
    {
      first = newn;
    }
    else
    {
      while(temp ->next != nullptr)
      {
        temp = temp ->next;
      }
      temp -> next = newn;

    }
    iCount++;
  }

  int Dequeue()
  {
    node<T> * temp = first;
    if(first == nullptr)
    {
      cout<<"Queue is empty"<<endl;
      return  -1;
    }
    else
    {
      first = first ->next;
      iCount--;
      return  temp ->data;
    }
  }

  void Display()
  {
    node<T> * temp = first;
    while(temp != nullptr)
    {
      cout<<"| "<<temp ->data <<" | - ";
      temp = temp ->next;
    }
    cout<<endl;
    
  }

  int Count()
  {
    return  iCount;
  }
};

int main()
{
  QueueX<int> qobj ;
  qobj.Enqueue(11);
  qobj.Enqueue(21);
  qobj.Enqueue(31);
  qobj.Display();
  int iRet = qobj.Dequeue();
  cout<<"Dequed: "<<iRet<<endl;
  qobj.Display();
  return 0;
}
