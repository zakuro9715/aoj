#include<iostream>

using namespace std;

int main()
{
  int l, m, n, ans, t;
  while(1)
  {
    t = 0;
    ans = -1;
    cin >> l;
    if(l == 0)
      break;
    for(int i = 0; i < 12; i++)
    {
      cin >> m >> n;
      t += m - n;
      if(t >= l)
        ans = i + 1;
    }
    if(ans == -1)
      cout << "NA\n";
    else
      cout << ans << endl;
  }
}
