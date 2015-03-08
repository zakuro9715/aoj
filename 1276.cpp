#include<iostream>
using namespace std;

int prime[1299709];
void init()
{
  for(int i = 2; i < 1300000; i++)
  {
    if(prime[i])
      continue;
    prime[i] = 1;
    for(int j = i + i; j < 1300000; j += i)
      prime[j] = -1;
  }
}

int main()
{
loop:
  init();
  int n;
  cin >> n;
  if(!n)
    return 0;
  if(prime[n] == 1)
  {
    cout << 0 << endl;
    goto loop;
  }
  int b;
  for(int i = 0; i < 1299709; i++)
  {
    if(prime[i] == 1 && i > n)
    {
      cout << i - b << endl;
      goto loop;
    }
    else if(prime[i] == 1)
      b = i;
  }
}
