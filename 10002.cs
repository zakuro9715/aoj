using System;

namespace Aoj
{
  class Aoj10002
  {
    static void Main()
    {
      string[] s = Console.ReadLine().Split(' ');
      int a = int.Parse(s[0]);
      int b = int.Parse(s[1]);
      Console.WriteLine("{0} {1}", a * b, (a + b) * 2);
    }
  }
}
