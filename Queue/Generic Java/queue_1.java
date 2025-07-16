class node<T>
{
  public T data;
  public  node<T> next;

  public node()
  {
    this.data = data;
    this.next = null;
  }

  public node(T no)
  {
    this.data = no;
    this.next = null;
  }
}


class QueueX<T>
{
  private int iCount;
  private node<T> first;

  public QueueX()
  {
    this.iCount = 0;
    this.first = null;
  }

  public void Enqueue(T no)
  {
    node<T> newn = new node<>(no);
    node<T> temp = first;
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

  public T Dequeue()
  {
    node<T> temp = first;
    if(first == null)
    {
      System.out.println("Queue is empty");
      return  null;
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
    node<T> temp = first;
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
  QueueX<Integer> qobj = new QueueX<>();
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