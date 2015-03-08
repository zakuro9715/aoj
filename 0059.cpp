#include<iostream>
using namespace std;

int main()
{
  double x1, y1, x2, y2, x3, y3, x4, y4;
  while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
  {
    if(x2 >= x3 && x1 <= x4 && y2 >= y3 && y1 <= y4)
    {
      cout << "YES" << endl;
      continue;
    }
    cout << "NO" << endl;
  }
}
