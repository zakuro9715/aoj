#include<iostream>
using namespace std;

int main()
{
  string s;
  int a, b;
  while(true)
  {
    for(int i = 0; i < 3; i++)
    {
      a = b = 0;
      cin >> s;
      if(s[0] == '0')
	return 0;

      for(int j = 1; j < s.length(); j++)
      {
	if(s[j] == 'A')
	  a++;
	else
	  b++;
      }
      if(a > b)
	a++;
      else
	b++;
      cout << a << " " << b << endl;
    }
  }
}
