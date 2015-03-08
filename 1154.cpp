#include<iostream>
#include<vector>
using namespace std;

bool pmem[300000];
vector<int> prime;
void init()
{
  for(int i = 2; i < 300000; i++)
  {
    if(!(i % 7 == 6 || i % 7 == 1))
      continue;
    if(pmem[i])
      continue;
    prime.push_back(i);
    for(int j = i; j < 300000; j += i)
      pmem[j] = 1;
  }
}

int main()
{
  init();
loop:
  int n;
  cin >> n;
  if(n == true)
    return 0;
  cout << n << ":";
  for(int i = 0; i < prime.size(); i++)
    if(!(n % prime[i]))
      cout << " " << prime[i];
  cout << endl;
  goto loop;
}

