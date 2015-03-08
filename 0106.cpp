#include<iostream>

using namespace std;

int dp[5001];
int item[] = {200, 300, 500, 1000, 1200, 1500};
int price[] = {380, 550, 850, 1520, 1870, 2244};

int main()
{
  for(int i = 0; i < 5001; i++)
    dp[i] = 10000000;
  dp[0] = 0;
  for(int j = 0; j < 6; j++)
  {
    for(int i = 0; i < 5001; i += 100)
    {
      if(i + item[j] > 5000)
	continue;
      dp[i + item[j]] = min(dp[i + item[j]], dp[i] + price[j]);
    }
  }
  while(true)
  {
    int n;
    cin >> n;
    if(!n)
      break;

    cout << dp[n] << endl;
  }
}
