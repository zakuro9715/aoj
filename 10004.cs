using System;

namespace Aoj
{
  class Aoj10004
  {
    static void Main()
    {
      string[] s = Console.ReadLine().Split();
      Array.Sort<string>(s);
      for(int i = 0; i < s.Length - 1; i++)
        Console.Write(s[i] + " ");
      Console.WriteLine(s[s.Length - 1]);
    }
  }
}
