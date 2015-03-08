#include<iostream>
#include<cmath>

using namespace std;

int main()
{
  double a, b, c, d, x1, x2, y1, y2, z1, z2, s1, s2, t1, t2, r = 6378.1;
  while(true)
  {
    cin >> a >> b >> c >> d;
    if(a == b && b == c && c == d && d == -1)
      break;
    s1 = (90 - a) * M_PI / 180.0;
    t1 = b * M_PI / 180.0;
    s2 = (90 - c) * M_PI / 180.0;
    t2 = d * M_PI / 180.0;
    x1 = r * sin(s1) * cos(t1);
    y1 = r * sin(s1) * sin(t1);
    z1 = r * cos(s1);
    x2 = r * sin(s2) * cos(t2);
    y2 = r * sin(s2) * sin(t2);
    z2 = r * cos(s2);

    cout << (int)((r * acos(1 - (pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2)) / (2 * r * r))) + 0.5) << endl;

  }
}
