#include<iostream>
#include<cmath>

using namespace std;

int main()
{
  int n, y, b, r, t;
  int ans_num;
  double ans_value;
  double v;
  while(1)
  {
    ans_value = ans_num = -1;

    cin >> n;
    if(!n)
      break;
    cin >> y;
    for(int i = 0; i < n; i++)
    {
      cin >> b >> r >> t;
      if(t == 1)
	v = 1.0 * (1.0 + y * (r / 100.0));
      else
	v = 1.0 * pow(1.0 + r / 100.0, y);
      if(v > ans_value)
      {
	ans_value = v;
	ans_num = b;
      }
    }
    cout << ans_num << endl;
  }
}
