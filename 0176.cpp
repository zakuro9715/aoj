#include<iostream>
#include<string>
#include<cmath>
using namespace std;

#define R 0
#define G 1
#define B 2

void print_col(int r, int g, int b)
{
  string col[] = {"black", "blue", "lime", "aqua", "red", "fuchsia", "yellow", "white"};
  int c[][3] = {{0, 0, 0}, {0, 0, 255}, {0, 255, 0}, {0, 255, 255}, 
	       {255, 0, 0}, {255, 0, 255}, {255, 255, 0}, {255, 255, 255}};
  double d = 1000000;
  double dd;
  int a = -1;

  for(int i = 0; i < 8; i++)
  {
    dd = pow(r - c[i][R], 2) + pow(g - c[i][G], 2) + pow(b - c[i][B], 2);
    if(dd < d)
    {
      d = dd;
      a = i;
    }
  }
  cout << col[a] << endl;
}

int to_num(char n)
{
  return n >= 'a' ? n - 'a' + 10 : n - '0';
}

int main()
{
  string s;
  int r, g, b;
  while(true)
  {
    cin >> s;
    if(s[0] == '0')
      break;
    r = to_num(s[1]) * 16 + to_num(s[2]);
    g = to_num(s[3]) * 16 + to_num(s[4]);
    b = to_num(s[5]) * 16 + to_num(s[6]);
    print_col(r, g, b);
  }
}
