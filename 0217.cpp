#include<iostream>

using namespace std;

int n;

int main()
{
  int len, ans;
  while(true)
  {
    ans = -1;
    len = 0;
    cin >> n;
    if(!n)
      break;
    for(int i = 0; i < n; i++)
    {
      int a, b, c;
      cin >> a >> b >> c;
      if(c + b > len)
      {
        len = c + b;
        ans = a;
      }
    }
    cout << ans << " " << len << endl;
  }
}
