#include<iostream>
#include<string>
using namespace std;

int si = 0;
string S;
bool parse(char c)
{
  bool fail = false;
  for(; si < S.length(); si++)
  {
    if(S[si] == c)
      return true;
    switch(S[si])
    {
      case '(':
        si++;
        fail = !parse(')');
        break;
      case '[':
        si++;
        fail = !parse(']');
        break;
      case ']': case ')':
        fail = true;
    }
    if(fail)
      return false;
  }
  return false;
}

int main()
{
loop:
  si = 0;
  getline(cin, S);
  if(S == ".")
    return 0;
  cout << (parse('.') ? "yes" : "no") << endl;
  goto loop;
}
