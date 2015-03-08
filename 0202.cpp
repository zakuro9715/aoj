#include<iostream>
#include<vector>

using namespace std;

bool prime[1100000];
int cooking[30];
int dp[30][1100000];
int nn, x;


int dfs(int n, int m)
{
  int res = 0;
  if(dp[n][m] != -1)
    return dp[n][m];
  
  if(m + cooking[n] <= x)
  {
    res = max(dfs(n, m + cooking[n]), n < nn - 1 ? dfs(n + 1, m + cooking[n]) : 0);
  }
  else if(n == nn - 1)
  {
    if(!prime[m])
      return m;
    else
      return 0;
  } 
  
  if(n < nn - 1)
    res = max(res, dfs(n + 1, m));
  
  dp[n][m] = res;

  return res;
}

void cal_prime()
{
  prime[1] = true;
  for(int i = 2; i < 1100000; i++)
  {
    if(prime[i])
    {
      
      continue;
    }
    int j = i * 2;
    for(; j < 1100000; j += i)
      prime[j] = true;
  }
}

int main()
{
  cal_prime();
  while(1)
  {
    for(int i = 0; i < 30; i++)
    {
      for(int j = 0; j < 1100000; j++)
        dp[i][j] = -1;
    }

    cin >> nn >> x;
    if(nn == 0 && x == 0)
      break;

    for(int i = 0; i < nn; i++)
      cin >> cooking[i];

    int ans = dfs(0, 0);
    if(!ans)
      cout << "NA" << endl;
    else
      cout << ans << endl;
  }
}


