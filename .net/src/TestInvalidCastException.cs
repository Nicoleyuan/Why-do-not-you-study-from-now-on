//TestInvalidCastException --类型转换异常，null引用异常

using System;
namespace ConsoleApp.Ch08
{
  class Animal
  {
    public void Breathe()
    {
      Console.WriteLine("An animal need to breathe.");
    }
  }
  class Cat : Animal
  {
    public void CatchMouse()
    {
      Console.WriteLine("A cat must catch mice for his master.");
    }
  }
  class Dog : Animal
  {
    public void ChaseRabbit()
    {
      Console.WriteLine("A dog chases rabbits just for pleasure.");
    }
  }
  class TestInvalidCastException
  {
    public static void Main() {
      Animal[] arr = new Animal[5];
    
      arr[0] = new Dog();
      arr[1] = new Cat();
      arr[2] = new Animal();
      arr[4] = new Dog();
      foreach (Animal e in arr)
      {
        try
        {
          ((Dog)e).ChaseRabbit();
        }
        catch (InvalidCastException ice)
        {
          Console.WriteLine(ice.Message);
        }
        catch (NullReferenceException nre)
        {
          Console.WriteLine(nre.Message);
        }
      }
     
      Console.WriteLine("\n让小动物干活去：");
      for (int i = 0; i < arr.Length; i++)
      {
        if (arr[i] != null &&arr[i] is Cat)  //
        {
          ((Cat)arr[i]).CatchMouse();
        }
        else if (arr[i] != null &&　arr[i] is Dog)  //
        {
          ((Dog)arr[i]).ChaseRabbit();
        }
        else if (arr[i] != null)
        {
          arr[i].Breathe();
        }
        else
        {
          Console.WriteLine("No animal stays at index {0}.", i);
        }
      }/**/
    }
  }
}
