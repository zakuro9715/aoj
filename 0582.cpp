#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

int main()
{
  int n[3]; 
  int a = 0, b = 0, c = 0;
  while(true)
  {
    cin >> n[0] >> n[1] >> n[2];
    sort(n, n + 3);
    if(n[0] + n[1] <= n[2])
    {
      printf("%d %d %d %d\n", a + b + c, a, b, c);
      return 0;
    }
    double d = pow(n[0], 2) + pow(n[1], 2), v = pow(n[2], 2);
    
    if(d == v)
      a++;
    else if(d > v)
      b++;
    else if(d < v)
      c++;
  }
}
