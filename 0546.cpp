#include<iostream>
#include<string>
#include<bitset>
#include<set>
using namespace std;
int N, K;

string cards[100];
set<string> ans;

void dfs(int k, bitset<100> c, string s)
{
  if(k == K)
  {
    ans.insert(s);
    return;
  }
  for(int i = 0 ;i < N; i++)
  {
    if(!c[i])
      continue;
    c[i] = false;
    dfs(k + 1, c, s + cards[i]);
    c[i] = true;
  } 
  return;
}

int main()
{
  while(1)
  {
    ans.clear();
    cin >> N >> K;
    if(!N && !K)
      break;
    for(int i = 0; i < N; i++)
      cin >> cards[i];
    dfs(0, bitset<100>(0xFFFF), "");
    cout << ans.size() << endl;
  }
}
