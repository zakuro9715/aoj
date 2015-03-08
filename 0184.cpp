#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
  while(1)
  {
    int c[7] = {}, n;
    cin >> n;
    if(!n)
      break;
    for(int i = 0; i < n; i++)
    {
      int a;
      cin >> a;
      c[min(a / 10, 6)]++;
    }
    for(int i = 0; i < 7; i++)
      cout << c[i] << endl;
  }
}
