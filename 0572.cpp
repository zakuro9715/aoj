#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int an, bn, a[5000], b[5000], ans = 0;
  cin >> an >> bn;
  for(int i = 0; i < an; i++)
    cin >> a[i];
  for(int i = 0; i < bn; i++)
    cin >> b[i];

  for(int st = 0; st < bn; st++)
  {
    int ai = 0, bi = st;
    for(; bi < bn; bi++, ai++)
    {
      while(a[ai] != b[bi])
      {
        if(!(ai < an))
          goto countend;
        ai++;
      }
    }
countend:
    ans = max(ans, bi - st);
  }
  cout << ans << endl;
}
