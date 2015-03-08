using System;

namespace Aoj
{
  class Aoj10003
  {
    static void Main()
    {
      string[] s = Console.ReadLine().Split();
      int a = int.Parse(s[0]);
      int b = int.Parse(s[1]);
      if(a < b)
        Console.WriteLine("a < b");
      else if(a > b)
        Console.WriteLine("a > b");
      else 
        Console.WriteLine("a == b");
    }
  }
}
