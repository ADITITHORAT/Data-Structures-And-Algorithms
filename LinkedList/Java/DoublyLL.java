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

class DLL
{
  private int iCount ;
  private node first;

    public DLL() 
    {
      iCount = 0;
      first = null;
    }
    

    public void Display()
    {
      node temp = first;
      while(temp != null)
      {
        System.out.print("| "+temp.data+" | <=> ");
        temp = temp.next;
      }
      System.out.println(" null");
    }

    public int Count()
    {
      return iCount;
    }
    public void InsertFirst(int no)
    {
      node newn = new  node(no);
      if(first == null)
      {
        first = newn;
      }
      else
      {
        newn.next = first;
        first = newn;

      }
      iCount++;
    }

    public void InsertLast(int no)
    {
      node newn = new node(no);
      node temp = null;
      if(first == null)
      {
        first = newn;
      }
      else
      {
        temp = first;
        while(temp.next != null)
        {
          temp = temp.next;
        }
        temp.next = newn;
        newn.prev = temp;
      }
      iCount++;
    }

    public void InsertAtPos(int no,int pos)
    {
      node newn = new node(no);
      node temp = null;
      if(pos < 1 || pos > iCount+1)
      {
        System.out.println("Invalid position");
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
      for(int iCnt = 1;iCnt < pos -1;iCnt++)
      {
        temp = temp.next;
      }
      newn.next=temp.next;
      newn.prev = temp;
      temp.next = newn;
      temp.next.prev = newn;
      }
    }

    public void DeleteFirst()
    {
      if(first == null)
      {
        return;
      }
      else
      {
        first = first.next;
        first.prev = null;
      }
    }

    public void DeleteLast()
    {
      node temp = null;
      if(first == null)
      {
        return;
      }
      else
      {
        temp = first;
        while(temp.next.next != null)
        {
          temp = temp.next;
        }
        temp.next = temp.next.next;
        
      }
    }

    public void DeleteAtPos(int pos)
    {
      node temp = null;
      if(pos < 1 || pos > iCount)
      {
        System.out.println("Invalid Position");
        return;
      }

      if(pos == 1)
      {
        DeleteFirst();
      }
      else if ( pos == iCount)
      {
        DeleteLast();
      }
      else
      {
        temp = first;
        for(int iCnt = 1; iCnt < pos -1 ;iCnt ++)
        {
          temp = temp.next;
        }
        temp.next = temp.next.next;
      }
    }
  
}

public class DoublyLL {
  public static void main(String A[]) {
      DLL dobj = new DLL();
      dobj.InsertFirst(21);
      dobj.Display();
      dobj.InsertLast(221);
      dobj.InsertFirst(21);
      dobj.Display();
      dobj.InsertLast(221);
      dobj.Display();
      dobj.InsertAtPos(334, 2);
      // dobj.Display();
      // dobj.DeleteFirst();
      // dobj.Display();
      // dobj.DeleteLast();
      dobj.DeleteAtPos(2);
      dobj.Display();
  }
}
