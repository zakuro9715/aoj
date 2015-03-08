#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

double get_d(int a, int b, int c)
{
  int num[3];
  num[0] = a;
  num[1] = b;
  num[2] = c;
  sort(num, num + 3);
  return sqrt(pow(num[0], 2) + pow(num[1], 2));
}

int main()
{
  while(true)
  {
    int a, b, c, n;
    double d;
    cin >> a >> b >> c;
    if(!a && !b && !c)
      break;
    cin >> n;
    d = get_d(a, b, c);
    for(int i = 0; i < n; i++)
    {
      int r;
      cin >> r;
      cout << (r * 2 > d ? "OK" : "NA") << endl;
    }
  }
}
