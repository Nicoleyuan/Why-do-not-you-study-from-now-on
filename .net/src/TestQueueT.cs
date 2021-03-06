//TestQueueT.cs  泛型集合Queue<T>

using System;
using System.Collections.Generic;
//需要访问Queue<T>泛型集合类
class TestQueueT {
  static void Main() {  
   Queue<string> myQ = new  Queue<string>();
   myQ.Enqueue("one");
    myQ.Enqueue("two");
    myQ.Enqueue("three"); 
    myQ.Enqueue("four");
    myQ.Enqueue("five");
  
  foreach(string s in myQ)
    Console.Write(s + "\t");
   
  Console.WriteLine("\nDequeuing ’{0}’", myQ.Dequeue());
  Console.WriteLine("\nPeek at next item to dequeue: {0}.",
    myQ.Peek());
  Console.WriteLine("\nDequeuing ’{0}’", myQ.Dequeue());
  foreach(string s in myQ)
    Console.Write(s + "\t");
   
  Console.WriteLine("\n\nTest myQ.Contains(...):");
  Console.WriteLine(myQ.Contains("two"));
  Console.WriteLine(myQ.Contains("four"));
  Console.WriteLine("\nmyQ.Count={0}.", myQ.Count);
  myQ.Clear();
  Console.WriteLine("\nAfter myQ.Clear(), myQ.Count={0}.",
    myQ.Count);
 }
}
 
 
