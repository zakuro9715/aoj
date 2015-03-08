#include<iostream>

using namespace std;

int main()
{
  int n, m = 0;
  int num[3];
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> num[i];
    m = max(m, num[i]);
  }
  for(int i = 1; i < m / 2 + 1; i++)
  {
    bool b = true;
    for(int j = 0; j < n; j++)
      b &= !(num[j] % i);
    if(b)
      cout << i << endl;
  }
}
