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

  node (int no)
  {
    data = no;
    next = nullptr;
  }
};

typedef node NODE;
typedef node * PNODE;

class SinglyCLL
{
  private:
  PNODE first;
  PNODE last ;
  int iCount ;

  public:
  SinglyCLL()
  {
    first = nullptr;
    last = nullptr;
    iCount = 0;
  }
  void InsertFirst(int no)
  {
    PNODE newn = new NODE(no);
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
  void InsertLast(int no)
  {
    PNODE newn = new NODE(no);
    
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
  void InsertAtPos(int no,int pos)
  {
    PNODE newn = new NODE(no);
    PNODE temp = nullptr;
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
    PNODE temp = nullptr;
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
    PNODE temp = nullptr;
    PNODE target = nullptr;
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
    PNODE temp = first;
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
  SinglyCLL scobj;
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