#include<iostream>
using namespace std;

int prime[1000000];

void init()
{
  for(int i = 2; i <= 1000000; i++)
  {
    if(prime[i])
      continue;
    prime[i] = 1;
    for(int j = i + i; j <= 1000000; j += i)
      prime[j] = 2;
  }
}

int main()
{
  init();
loop:
  int n, a, d, ans = 0;
  cin >> a >> d >> n;
  if(!n)
    return 0;
  for(int i = 0; ;)
  {
    if(prime[a] == 1)
      i++;
    if(i == n)
    {
      cout << a << endl;
      break;
    }
    a += d;
  }
  goto loop;
}
