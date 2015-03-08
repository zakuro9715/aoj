#include<iostream>
#include<algorithm>
using namespace std;


int J[65000];
int N;

int main()
{
loop:
  int sum = 0;
  cin >> N;
  if(!N)
    return 0;
  for(int i = 0; i < N; i++)
  {
    int p;
    cin >> p;
    sum += p;
  }
  for(int i = 0; i < N - 1; i++)
    cin >> J[i];
  sort(J, J + N - 1, greater<int>());
  
  unsigned int ans = sum * N;
  for(int i = 0; i < N - 1; i++)
  {
    sum += J[i];
    if(ans >= sum * (N - i - 1))
      break;
    ans = sum * (N - i - 1);
  }
  cout << ans << endl;
  goto loop;
}
