#include<iostream>
#include<vector>
using namespace std;

int pmem[1300000];
vector<int> prime;
void init()
{
  for(int i = 2; i < 1300000; i++)
  {
    if(pmem[i])
      continue;
    pmem[i] = 1;
    prime.push_back(i);
    for(int j = i + i; j < 1300000; j += i)
      pmem[j] = -1;
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
  for(int i = 0; i < prime.size(); i++)
  {
    if(prime[i] == n)
    {
      cout << 0 << endl;
      goto loop;
    }
    if(prime[i] > n)
    {
      cout << prime[i] - prime[i - 1] << endl;
      goto loop;
    }
  }
}
