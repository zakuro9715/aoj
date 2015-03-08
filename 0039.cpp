#include<iostream>
using namespace std;

int toint(char c)
{
  if(c <= '9' && c >= '0')
    return c - '0';
  switch(c)
  {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  }
  return 0;
}

int main()
{
  string s;
  int ans;
  while(cin >> s)
  {   
    ans = 0;
    for(int i = 0; i < s.length() - 1; i++)
    {
      int a = toint(s[i]);
      int b = toint(s[i + 1]);
      if(a < b)
      { 
	s[i] = '0';
	s[i + 1] = b - a;
	i++;
      }
    }
    for(int i = 0; i < s.length(); i++)
      {
	cout << i << ':' << (int)s[i] << endl;
      ans += toint(s[i]);
      }
    cout << ans << endl;
  }
  return 0;
}
