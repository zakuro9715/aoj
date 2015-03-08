#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int prime[1000000];

int init()
{
  memset(prime, -1, sizeof prime);
  prime[0] = prime[1] = 0;
  for(int i = 2; i < 1000000; i++)
  {
    if(prime[i] != -1)
      continue;
    prime[i] = 1;
    for(int j = i + i; j < 1000000; j += i)
      prime[j] = 0;
  }
}

int main()
{
  init();
loop:
  int n, p;
  vector<int> prm;
  vector<int> m;
  cin >> n >> p;
  if(n == -1)
    return 0;
  int i = n;
  for(int cnt = 0; cnt < 100; cnt++)
  {
    i++;
    while(!prime[i])
      i++;
    prm.push_back(i);
  }
  for(int i = 0; i < 100; i++)
    for(int j = i; j < 100; j++)
      m.push_back(prm[i] + prm[j]);
  sort(m.begin(), m.end());
  cout << m[p - 1] << endl;
  goto loop;
}
