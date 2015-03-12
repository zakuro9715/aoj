module main;
import std.stdio;
import std.string;

void main()
{
  string s;
  while((s = chomp(readln())).length)
  {
    char s2[] = new char[s.length];
    for(auto i = 0; i < 26; i++)
    {
      for(auto j = 0; j < s.length; j++)
      {
        s2[j] = s[j];
        if(!(s[j] == ' ' || s[j] == '\n' || s[j] == '.'))
          s2[j] = 'a' + ((s[j] - 'a') + i) % 26;
      }

      if(s2.indexOf("the") != -1 || s2.indexOf("this") != -1 || s2.indexOf("that") != -1)
      {
        writef("%s\n", s2);
        break;
      }
    }
  }
}
