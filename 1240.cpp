#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
  int n;
  string s, m;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> m >> s;
    for(int j = m.length() - 1; j >= 0; j--)
    {
      switch(m[j])
      {
        case 'C':
          s = s.substr(1, s.length() - 1) + s[0];
          break;
        case 'J':
          s = s[s.length() - 1] + s.substr(0, s.length() - 1);
          break;
        case 'E':
          {
            int a = s.length() / 2, b = s.length() % 2;
            s = s.substr(a + b, a) + s.substr(a, b) + s.substr(0, a);
          }
          break;
        case 'A':
          reverse(s.begin(), s.end());
          break;
        case 'M':
          for(int k = 0; k < s.length(); k++)
            if(s[k] >= '0' && s[k] <= '9')
              s[k] = (s[k] - '0' + 1) % 10 + '0';
          break;
        case 'P':
          for(int k = 0; k < s.length(); k++)
            if(s[k] >= '0' && s[k] <= '9')
              s[k] = (s[k] - '0' + 9) % 10 + '0';
          break;
      }
    }
    cout << s << endl;
  }
}
