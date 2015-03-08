#include<iostream>
#include<math.h>
#define MN 10000001
using namespace std;

bool prime[MN];

int main()
{
  prime[0] = prime[1] = true;
  for(int i = 2; i < sqrt(MN) + 1; i++)
  {
    if(prime[i])
      continue;
    for(int j = i + i; j < MN; j += i)
      prime[j] = true;
  }
loop:
  int N;
  cin >> N;
  if(!N)
    return 0;
  for(int i = N; i >= 0; i--)
  {
    if(!(prime[i - 8] || prime[i - 6] || prime[i - 2] || prime[i]))
    {
      cout << i << endl;
      break;
    }
  }
  goto loop;
}
