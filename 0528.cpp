#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int dp[4001][4001];

int main()
{
  string a, b;
  while(cin >> a >> b)
  {
    int ans = 0;
    for(int i = 0; i < a.length(); i++)
    {
      for(int j = 0; j < b.length(); j++)
      {
        if(a[i] == b[j])
          ans = max(dp[i + 1][j + 1] = dp[i][j] + 1, ans);
        else
          dp[i + 1][j + 1] = 0;
      }
    }
    
    cout << ans << endl;
  }
}
