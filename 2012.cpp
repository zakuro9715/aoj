#include<iostream>
#include<cmath>
using namespace std;

int main()
{
loop:
  int e, x, y, z, m = 1 << 30;
  cin >> e;
  if(!e)
    return 0;
  for(int z = 0; pow(z, 3) <= e; z++)
  {
    y = (int)sqrt(e - pow(z, 3));
    m = min(z + y + (int)(e - pow(z, 3) - pow(y, 2)), m); 
  }
  cout << m << endl;
  goto loop;
}
