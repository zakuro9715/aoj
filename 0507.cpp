#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void dfs(int n, int b, int rest, vector<int> block)
{
  block.push_back(b);
  if(!rest)
  {
    for(int i = 1; i < block.size() - 1; i++)
      cout << block[i] << " ";
    cout << block[block.size() - 1] << endl;
  }
  int ans = 0;
  for(int i = min(b, rest); i > 0; i--)
  {
    dfs(n + 1, i, rest - i, block);
  }
}

int main()
{
  int n;

loop:
  cin >> n;
  if(!n)
    return 0;
  dfs(0, n, n, vector<int>());
  goto loop;
}
