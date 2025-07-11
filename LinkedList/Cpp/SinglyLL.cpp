#include<iostream>
using namespace std;

class node
{
  public:
  int data;
  node * next;
  node(int no)
  {
    data = no;
    next = nullptr;
  }

  node ()
  {
    data = 0;
    next = nullptr;
  }
};
typedef node NODE;
typedef node * PNODE;


class SinglyLL
{
    private:
    int iCount = 0;
    PNODE first = nullptr;

    public:

    void Display()
    {
      PNODE temp = first;
      while(temp != nullptr)
      {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
      }
      cout<<"NULL"<<endl;
    }


    void InsertFirst(int no)
    {
      PNODE newn = new NODE(no);
      
      if(first == nullptr)
      {
        first = newn;
      }
      else
      {
        newn -> next = first;
        first = newn;
      }
      iCount++;
    }


    void InsertLast(int no)
    {
      PNODE newn = new NODE(no);
      PNODE temp = nullptr;
      if(first == nullptr)
      {
        first = newn;
      }
      else 
      {
        temp = first;
        while(temp -> next != nullptr)
        {
          temp = temp -> next;
        }
        temp -> next = newn;
        newn -> next = nullptr; 
      }
      iCount++;
    }


    void InsertAtPos(int no,int pos)
    {
      PNODE newn = new NODE(no);
      PNODE temp = nullptr;
      int iCnt = 0;
      if((pos < 1) || (pos > iCount +1))
      {
        cout<<"Invalid Position"<<endl;
        return;
      }

      if(pos == 1)
      {
        InsertFirst(no);
      }
      else if (pos == iCount + 1)
      {
        InsertLast(no);
      }
      else
      {
        temp = first;
        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
          temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
        iCount++;
      }
    }
    


    void DeleteFirst()
    {
      PNODE temp = nullptr;
      if(first == nullptr)
      {
        return;
      }
      else
      {
        temp = first;
        first = first -> next;
        delete temp;
      }
      iCount--;
    }
    void DeleteLast()
    {
      PNODE temp = nullptr;
      PNODE target = nullptr;
      if(first == nullptr)
      {
        return;
      }
      else if (first -> next == nullptr)
      {
        first  = nullptr;
        delete first;
      }
      else 
      {
        temp = first;
        while (temp -> next -> next != nullptr)
        {
          temp = temp->next;
        }
        temp -> next = target;
        temp -> next = nullptr;
        delete target;
      }
      iCount--;
    }


    void DeleteAtPos(int pos)
    {
      PNODE temp = nullptr;
      PNODE target = nullptr;
      int iCnt = 0;
      if((pos < 1) || (pos > iCount))
      {
        cout<<"Invalid Position"<<endl;
        return;
      }
      if(pos == 1)
      {
        DeleteFirst();
      }
      else if (pos == iCount)
      {
        DeleteLast();
      }
      else 
      {
        temp = first;
        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
          temp = temp -> next;
        }
        target = temp -> next;
        temp -> next = temp -> next-> next;
        delete target;
        iCount--;
      }

    }
    int Count()
    {
      return iCount;
    }
};
int main()
{
  SinglyLL sobj;
  int iRet = 0;
  sobj.InsertFirst(12);
  sobj.InsertFirst(11);
  sobj.Display();
  iRet = sobj.Count();
  cout<<"Number of Elements are : "<<iRet<<endl;
  sobj.InsertLast(13);
  sobj.InsertLast(14);
  sobj.InsertLast(16);
  sobj.InsertLast(17);
  sobj.Display();
  iRet = sobj.Count();
  cout<<"Number of Elements are : "<<iRet<<endl;

  // sobj.DeleteFirst();
  // sobj.Display();
  // iRet = sobj.Count();
  // cout<<"Number of Elements are : "<<iRet<<endl;  
  // sobj.DeleteLast();
  // sobj.Display();
  // iRet = sobj.Count();
  // cout<<"Number of Elements are : "<<iRet<<endl;  

  sobj.InsertAtPos(15,5);
  sobj.Display();
  iRet = sobj.Count();
  cout<<"Number of Elements are : "<<iRet<<endl;
  sobj.DeleteAtPos(5);
  sobj.Display();
  iRet = sobj.Count();
  cout<<"Number of Elements are : "<<iRet<<endl;
  return 0;

}