#include<iostream>
#include<cmath>
using namespace std;

int main()
{
  int d;
  int ans;
  while(cin >> d)
  {
    ans = 0;
    for(int i = 0; i * d < 600; i++)
    {
      ans += pow(i * d, 2)  * d;
    }
    cout << ans << endl;
  }
}
