class node<T>
{
  
  public T data;
  public node<T>  next;

  public node()
  {
    this.data=data;
    next = null;
  }
  public node (T no)
  {
    data = no;
    next = null;
  }
}
class SLL<T>
{
  private int iCount ;
  private node<T> first;

    public SLL() 
    {
      first = null;
      iCount = 0;
    }
  
    public void InsertFirst(T no)
    {
      node<T> newn = new node<>(no);

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

    public void InsertLast(T no)
    {
      node<T> newn = new node<>(no);
      node<T> temp = null;
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
      }
      iCount++;
    }

    public void Display()
    {
      node<T> temp = null;
      temp = first;
      while(temp != null)
      {
        System.out.print("| "+temp.data+" | -> ");
        temp = temp.next;
      }
      System.out.println("null");
    }

    public int Count()
    {
      return iCount;
    }

    public void InsertAtPos(T no,int pos)
    {
      node<T> newn = new node<>(no);
      node<T> temp = null;
      if(pos < 1 || pos >iCount+1)
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
        for(int iCnt = 0;iCnt<pos -1;iCnt++)
        {
          temp = temp.next;
        }
        newn.next = temp.next;
        temp.next = newn;
        iCount++;
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
      }
      iCount--;
    }

    public void DeleteLast()
    {
      node<T> temp = null;
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
        temp.next = null;
        iCount--;
      }
    }

    public void DeleteAtPos(int pos)
    {
      node<T> temp = null;
      
      if(pos < 1 || pos > iCount)
      {
        System.out.println("Invalid position");
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
        for(int iCnt = 0 ; iCnt < pos -1;iCnt++)
        {
          temp = temp.next;
        }
        
        temp.next = temp.next.next;
      }
    }


}

class SinglyLinkedList
{
  public static void main(String A[])
  {
    SLL<Integer> sobj = new SLL<>();
    sobj.InsertFirst(11);
    sobj.InsertLast(21);
    sobj.InsertLast(51);
    sobj.InsertAtPos(31, 2);
    // sobj.DeleteFirst();
    // sobj.DeleteLast();
    sobj.Display();
    sobj.DeleteAtPos(2);
    sobj.Display();

  }
}