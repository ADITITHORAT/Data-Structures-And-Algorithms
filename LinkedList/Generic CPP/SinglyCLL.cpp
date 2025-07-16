#include<iostream>
using namespace std;

template<class T>
class node
{
  public:
  T data;
  node <T>* next;

  node()
  {
    this->data = data;
    next = nullptr;
  }

  node (T no)
  {
    data = no;
    next = nullptr;
  }
};


template<class T>
class SinglyCLL
{
  private:
  node<T>* first;
  node<T>* last ;
  int iCount ;

  public:
  SinglyCLL()
  {
    first = nullptr;
    last = nullptr;
    iCount = 0;
  }
  void InsertFirst(T no)
  {
    node<T>* newn = new node<T>(no);
    if(first == nullptr && last == nullptr)
    {
      first = newn;
      last = newn;
      last -> next = newn;
    }
    else
    {
      newn ->next = first;
      first = newn;
      last -> next = first;
    }
    iCount++;
  }
  void InsertLast(T no)
  {
    node<T>* newn = new node<T>(no);
    
    if(first == nullptr && last == nullptr)
    {
      first = newn;
      last = newn;
      last -> next = first;
    }
    else
    {
      last -> next = newn;
      last = newn;
      last -> next = first;
      
    }
    iCount++;
  }
  void InsertAtPos(T no,int pos)
  {
    node<T>* newn = new node<T>(no);
    node<T>* temp = nullptr;
    if(pos < 1 || pos > iCount+1)
    {
      cout<<"Invalid position "<<endl;
      return ;
    }
     if (pos == 1)
    {
      InsertFirst(no);
    }
    else if (pos == iCount+1)
    {
      InsertLast(no);
    }
    else
    {
      temp = first;
      for(int iCnt = 1; iCnt < pos -1 ;iCnt ++)
      {
        temp = temp -> next;
      }
      newn -> next = temp -> next;
      temp ->next = newn;
      iCount++;
    }
  }
  void DeleteFirst()
  {
    if(first == nullptr && last == nullptr)
    {
      return;
    }
    else if (first == last)
    {
      delete first ;
      first = nullptr;
      last = nullptr;
    }
    else 
    {
      first = last -> next ->next ;
      delete last -> next;
      last -> next = first;
    }
    iCount--;
  }
  void DeleteLast()
  {
    node<T>* temp = nullptr;
    if(first == nullptr && last == nullptr)
    {
      return;
    }
    else if ( first == last)
    {
      delete first;
      first = nullptr;
      last = nullptr;
    }
    else
    {
      temp = first;
      while(temp -> next  != last)
      {
        temp = temp ->next;
      }
      delete last;
      last = temp ;
      last -> next = temp;
    }
    iCount--;
  }
  void DeleteAtPos(int pos)
  {
    node<T>* temp = nullptr;
    node<T>* target = nullptr;
    if(pos < 1 || pos > iCount+1)
    {
      cout<<"Invalid position "<<endl;
      return ;
    }
     if (pos == 1)
    {
      DeleteFirst();
    }
    else if (pos == iCount+1)
    {
      DeleteLast();
    }
    else
    {
      temp = first;
      for(int iCnt = 1 ; iCnt < pos -1;iCnt++)
      {
        temp = temp->next;
      }
      target = temp -> next;
      temp ->next = target -> next;
      delete target;
      iCount--;
      
    }
  }
  void Display()
  {
    node<T>* temp = first;
    if(first == nullptr && last == nullptr)
    {
      return;
    }
    for(int iCnt = 1 ; iCnt <= iCount ; iCnt++)
    {
      cout<<"| "<<temp->data<<" | -> ";
      temp = temp->next;
    }
    cout<<endl;
    
    
  }
  int count()
  {
    return iCount;
  }
};

int main()
{
  SinglyCLL<int> scobj;
  int iRet = 0;
  scobj.InsertFirst(11);
  scobj.InsertFirst(21);
  scobj.InsertFirst(51);
  scobj.Display();
  iRet = scobj.count();
  cout<<"Number of elements are : "<<iRet<<endl;
  scobj.InsertLast(11);
  scobj.InsertLast(21);
  scobj.InsertLast(51);
  scobj.Display();
  iRet = scobj.count();
  cout<<"Number of elements are : "<<iRet<<endl;

  // scobj.DeleteFirst();
  // scobj.Display();
  // iRet = scobj.count();
  // cout<<"Number of elements are : "<<iRet<<endl;
  // scobj.DeleteLast();
  // scobj.Display();
  // iRet = scobj.count();
  // cout<<"Number of elements are : "<<iRet<<endl;
  scobj.InsertAtPos(51,5);
  scobj.Display();
  iRet = scobj.count();
  cout<<"Number of elements are : "<<iRet<<endl;
  scobj.DeleteAtPos(5);
  scobj.Display();
  iRet = scobj.count();
  cout<<"Number of elements are : "<<iRet<<endl;
  return 0;
}