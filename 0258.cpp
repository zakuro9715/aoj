#include<iostream>
using namespace std;
int h[100000050];
int main()
{
  int n, r, r1, r2, r3;
  while(true)
  {
    cin >> n;
    if(!n)
      break;
    for(int i = 0; i <= n; i++)
      cin >> h[i];
    r = h[1] - h[0];
    for(int i = 0; i <= n; i++)
    {
      for(int j = 2; j <=n; j++)
      {
        if(h[j] - h[j - 1] != r)
        {
          cout << h[i] << endl;
          break;
        }
      }
    }
  }
}
