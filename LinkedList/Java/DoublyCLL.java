

class node
{
  public int data;
  public node next;
  public node prev;
  
  public node()
  {
    data = 0;
    next = null;
    prev = null;
  }

  public node(int no)
  {
    data = no;
    next = null;
    prev = null;
  }
}


class DCLL
{
  private int iCount;
  private node first;
  private node last;

  public DCLL()
  {
    iCount = 0;
    first = null;
    last = null;
  }


  void Display()
  {
    node temp = first;
    do
    {
      System.out.print("| "+temp.data+" |<=>");
      temp = temp.next;
    }while(temp != first);
    System.out.println(" null");
  }
  void InsertFirst(int no)
  {
    node newn = new node(no);
    if(first == null && last == null)
    {
      first = newn;
      last = newn;
      
    }
    else 
    {
      newn.next = first;
      first=newn;
    }
    last.next = first;
    first.prev = last;
    iCount++;
  }

  void InsertLast(int no)
  {
    node newn = new node(no);
    if(first == null && last == null)
    {
      first = newn;
      last = newn;
    }
    else
    {
      last.next = newn ;
      last = newn;
    }
    last.next = first;
    first.prev = last;
    iCount++;
  }

  void InsertAtPos(int no,int pos)
  {
    node newn = new  node(no);
    node temp = null;
    if(pos < 1 || pos > iCount+1)
    {
      System.out.println("Invalid Position");
      return;
    }

    if(pos == 1)
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
      for(int iCnt = 1 ;iCnt<pos-1;iCnt++)
      {
        temp = temp.next;
      }
      newn.next = temp.next;
      newn.prev = temp;
      temp.next = newn;
      temp.next.prev = newn;
    }
  }

  public void DeleteFirst()
  {
    if(first == null && last == null)
    {
      return;
    }
    else if (first == last)
    {
      first = null;
      last = null;
    }
    else
    {
      first = first.next;
    }
    last.next=first;
    first.prev=last;
    iCount--;
  }

  public void DeleteLast()
  {
    if(first == null && last == null)
    {
      return;
    }
    else if ( first == last)
    {
      first = null;
      last = null;
    }
    else 
    {
      last = last.prev;
    }
    last.next = first;
    first.prev = last;
    iCount--;
  }

  public void DeleteAtPos(int pos)
  {
    node temp = null;
    if(pos < 1 ||pos > iCount)
    {
      System.out.println("Invalid Position");
      return;
    }
    if(pos == 1)
    {
      DeleteFirst();
    }
    else if(pos == iCount)
    {
      DeleteLast();
    }
    else
    {
      temp = first;
      for(int iCnt = 1;iCnt<pos -1;iCnt++)
      {
        temp = temp.next;
      }
      temp.next = temp.next.next;
      temp.next.prev = temp;
      iCount--;
    }
  }
}

public class DoublyCLL {
  public static void main(String A[]) {
      DCLL dcobj = new DCLL();
      dcobj.InsertFirst(21);
      dcobj.InsertFirst(31);
      dcobj.InsertFirst(42);
      dcobj.Display();

      dcobj.InsertLast(55);
      dcobj.InsertLast(88);
      dcobj.InsertLast(11);
      dcobj.Display();
      dcobj.InsertAtPos(78, 3);
      dcobj.Display();
      dcobj.DeleteFirst();
      dcobj.Display();
      dcobj.DeleteAtPos(3);
      dcobj.Display();
  }
}
