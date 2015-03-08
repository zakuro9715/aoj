#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int m, n;
  int num, ans = 0;;
  bool f = true;
  cin >> n >> m;
  num = ans = m;
  for(int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    num += a - b;
    ans = max(ans, num);
    f &= num >= 0;
  }
  if(!f)
    ans = 0;
  cout << ans << endl;
}
