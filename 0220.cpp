#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
  double n, ans;
  while(1)
  {
    ans = 0;
    cin >> n;
    if(n < 0)
      break;
    
    if(n >= 256)
    {
      cout << "NA\n";
      continue;
    }

    int d;
    int m = (int)n;
    double r = n - m;
    
    for(int i = 0; i <= 8; i++)
    {

      d = m % 2;
      m /= 2;
      ans += d * pow(10, i);
    }
    for(int i = -1; i >= -4; i--)
    {
      d = (int)(r * 2);
      r = r * 2 - d;
      ans += d * pow(10, i);
    }
    if(r > 0.0001)
      cout << "NA\n";
    else
      printf("%013.4f\n", ans);
  }
}
