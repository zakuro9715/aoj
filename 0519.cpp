#include<iostream>
#include<vector>
using namespace std;

bool done[5000];
vector<int> wins[5000], sorted;
void dfs(int n)
{
  done[n] = true;
  for(auto m : wins[n])
    if(!done[m])
      dfs(m);
  sorted.push_back(n);
}


int N, M;
int main()
{
  cin >> N >> M;
  for(int i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    wins[--a].push_back(--b);
  }
  for(int i = 0; i < N; i++)
    if(!done[i])
      dfs(i);

  bool plural = false;
  for(int i = N - 1; i >= 0; i--)
  {
    auto m = sorted[i];
    cout << m + 1 << endl;
    if(i == 0)
      break;

    bool b = true;
    for(auto n : wins[m])
      b &= n != sorted[i - 1];
    plural |= b;
  }
  cout << plural << endl;
}
