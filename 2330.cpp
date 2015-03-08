#include<iostream>
using namespace std;

int main()
{
  int n, m = 0;
  cin >> n;
  n--;
  while(n)
  {
    n /= 3;
    m++;
  }
  cout << m << endl;
}
