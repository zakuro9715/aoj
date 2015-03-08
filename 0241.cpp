#include<iostream>
using namespace std;

int main()
{
  int a[4], b[4];
  int n;
  while(1)
  {
    cin >> n;
    if(!n)
      break;
    while(n)
    {  
      for(int i = 0; i < 4; i++)
	cin >> a[i];
      for(int i = 0; i < 4; i++)
	cin >> b[i];
      
      cout << a[0] * b[0] - a[1] * b[1] - a[2] * b[2] - a[3] * b[3] << " "
	   << a[0] * b[1] + a[1] * b[0] + a[2] * b[3] - a[3] * b[2] << " "
	   << a[0] * b[2] - a[1] * b[3] + a[2] * b[0] + a[3] * b[1] << " "
	   << a[0] * b[3] + a[1] * b[2] - a[2] * b[1] + a[3] * b[0] << endl;
      n--;
    }
  }
}
