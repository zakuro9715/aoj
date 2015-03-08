#include<iostream>
using namespace std;
int prime[100000];
int main()
{
  prime[0] = prime[1] = 2;
  for(int i = 2; i < 100000; i++)
  {
    if(prime[i])
      continue;
    for(int j = i + i; j < 100000; j += i)
      prime[j] = 2;
  }
  int n;
  while(cin >> n)
  {
    int i;
    for(i = n - 1; prime[i] == 2; i--);
    cout << i << " ";
    for(i = n + 1; prime[i] == 2; i++);
    cout << i << endl;
  }
}
