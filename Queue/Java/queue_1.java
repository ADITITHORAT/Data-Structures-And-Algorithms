class node
{
  public int data;
  public  node next;

  public node()
  {
    this.data = 0;
    this.next = null;
  }

  public node(int no)
  {
    this.data = no;
    this.next = null;
  }
}


class QueueX
{
  private int iCount;
  private node first;

  public QueueX()
  {
    this.iCount = 0;
    this.first = null;
  }

  public void Enqueue(int no)
  {
    node newn = new node(no);
    node temp = first;
    if(first == null)
    {
      first = newn;
    }
    else
    {
      while(temp.next != null)
      {
        temp = temp.next;
      }
      temp.next = newn;

    }
    iCount++;
  }

  public int Dequeue()
  {
    node temp = first;
    if(first == null)
    {
      System.out.println("Queue is empty");
      return  -1;
    }
    else
    {
      first = first.next;
      iCount--;
      return  temp.data;
    }
  }

  public void Display()
  {
    node temp = first;
    while(temp != null)
    {
      System.out.print("| "+temp.data +" | - ");
      temp = temp.next;
    }
    System.out.println("");
  }

  public int Count()
  {
    return  iCount;
  }
}
class queue_1
{
 public static  void main(String A[])
 {
  QueueX qobj = new QueueX();
  qobj.Enqueue(11);
  qobj.Enqueue(21);
  qobj.Display();
  int iRet = qobj.Dequeue();
  System.out.println("\nDequeued element is : "+iRet);
  qobj.Display();
  qobj.Enqueue(31);
  qobj.Display();
  
 }
}