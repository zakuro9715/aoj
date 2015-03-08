#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
  int n, i;
  char c[20];
  while(true)
  {
    for(i = 0; i < 20; i++)
      c[i] = 0;
    c[0] = '0';
    cin >> n;
    if(n < 0)
      break;
    for(i = 0; n > 0; i++)
    {
      c[i] = n % 4 + '0';
      n = n / 4;
    }
    reverse(c, c + i);
    cout << c << endl;
  }
}
