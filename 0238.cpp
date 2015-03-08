#include<iostream>xusing namespace std;

int main()
{
  int t, n, s, f, ans;
  while(true)
  {
    t = n = s = f = ans = 0;
    cin >> t;
    if(!t)
      break;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
      cin >> s >> f;
      ans += f - s;
    }

    if(ans >= t)
      cout << "OK\n";
    else
      cout << t - ans << endl;
  }
}
