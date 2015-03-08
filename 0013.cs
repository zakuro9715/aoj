using System;
using System.Collections.Generic;
namespace Aoj
{
  class Aoj0013
  {
    static void Main()
    {
      string s;
      var st = new Stack<string>();
      while((s = Console.ReadLine()) != null)
      {
        if(int.Parse(s) == 0)
          Console.WriteLine(st.Pop());
        else
          st.Push(s);
      }
    }
  }
}
