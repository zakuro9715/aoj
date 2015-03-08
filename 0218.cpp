#include<iostream>
using namespace std;

int main()
{
  int n, m, e, j;
  while(1)
  {
    cin >> n;
    if(!n)
      break;

    for(int i = 0; i < n ; i++)
    {
      cin >> m >> e >> j;
      if((m + e) / 2 >= 90 || m == 100 || e == 100 || j == 100 || (m + e + j) / 3 >= 80)
	cout << 'A' << endl;
      else if((m + e + j) / 3 >= 70 || (m + e + j) / 3 >= 50 && (m >= 80 || e >= 80))
	cout << 'B' << endl;
      else
	cout << 'C' << endl;
    }
  }
}
