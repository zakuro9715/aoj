#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

double point[3][2];

int main()
{
  int n;
  float px, py, r, a, b, c, s, A, B, C, S; 
  cin >> n;
  for(int cnt = 0; cnt < n; cnt++)
  {
    for(int i = 0; i < 3; i++)
    {
      cin >> point[i][0];
      cin >> point[i][1];
    }

    a = sqrt(pow(point[0][0] - point[1][0], 2) + pow(point[0][1] - point[1][1], 2));
    b = sqrt(pow(point[1][0] - point[2][0], 2) + pow(point[1][1] - point[2][1], 2));
    c = sqrt(pow(point[2][0] - point[0][0], 2) + pow(point[2][1] - point[0][1], 2));
    A = asin((point[1][1] - point[2][1]) / b) + asin((point[2][1] - point[0][1]) / c);
    B = asin((point[0][1] - point[1][1]) / a) + asin((point[2][1] - point[0][1]) / c);
    C = asin((point[0][1] - point[1][1]) / a) + asin((point[1][1] - point[2][1]) / b);
    s = (a + b + c) / 2;
    S = sqrt(s * (s - a) * (s - b) * (s - c));
    r = abs(a / sin(A) / 2);
    px = (a * a * (b * b + c * c - a * a) * point[2][0]
	  + b * b * (c * c + a * a - b * b) * point[0][0]
	  + c * c * (a * a + b * b - c * c) * point[1][0]) / 16 * S;
    py = (a * a * (b * b + c * c - a * a) * point[2][1]
          + b * b * (c * c + a * a - b * b) * point[0][1]
          + c * c * (a * a + b * b - c * c) * point[1][1]) / 16 * S;
    px = (int)(px * 1000 + 0.5) / 1000.0;
    py = (int)(py * 1000 + 0.5) / 1000.0;

    printf("%.3f %.3f %.3f\n", px, py, r);
  }
  return 0;
}
