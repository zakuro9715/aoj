#include<iostream>

using namespace std;

int solve(int d)
{
  d *= d;
  d -= (d / 1000000) * 1000000;
  return d / 100;
}

int main()
{
  int n, s;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> s;
    cout << "Case " << i + 1 << ":\n";
    for(int j = 0; j < 10; j++)
      cout << (s = solve(s)) << endl;
  }
}
