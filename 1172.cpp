#include<iostream>
using namespace std;

int prime[300000];

void init()
{
  for(int i = 2; i <= 300000; i++)
  {
    if(prime[i])
      continue;
    prime[i] = 1;
    for(int j = i + i; j <= 300000; j += i)
      prime[j] = 2;
  }
}

int main()
{
  init();
loop:
  int n, ans = 0;
  cin >> n;
  if(!n)
    return 0;
  for(int i = n; i < 2 * n; i++)
    ans += prime[i + 1] == 1;
  cout << ans << endl;
  goto loop;
}
