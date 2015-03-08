#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    int c, a, n, ans = 0;
    cin >> c >> a >> n;
    while(c > 0 && a > 0 && n > 0)
    {
      c--; a--; n--;
      ans++;
    }
    while(c > 1 && a > 0)
    {
      c -= 2; a--;
      ans++;
    }
    ans += c / 3;
    cout << ans << endl;
  }
}
