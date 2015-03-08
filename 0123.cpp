#include<iostream>
using namespace std;

double h[] = {35.5, 37.5, 40.0, 43.0, 50.0, 55.0, 70.0};
double f[] = {71.0, 77.0, 83.0, 89.0, 105.0, 116.0, 148.0};
string s[] = {"AAA", "AA", "A", "B", "C", "D", "E"};

int main()
{
  double a, b;
  while(cin >> a >> b)
  {
    for(int i = 0; i < 7; i++)
    {
      if(a < h[i] && b < f[i])
      {
	cout << s[i] << endl;
	goto next;
      }
    }
    cout << "NA\n";
  next:;
  }
}
