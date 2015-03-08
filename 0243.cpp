#include<iostream>
#include<sstream>
#include<string>
#include<queue>
#include<utility>
using namespace std;

typedef pair<string, int> P;
int W, H, N, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
string rgb = "RGB";

bool check(const string& s)
{
  char c = s[0];
  for(int i = 0; i < W * H; i++)
    if(s[i] != c)
      return false;
  return true;
}

string f(char c, string s)
{
  char a = s[0];
  N = 0;
  queue<int> q;
  q.push(0);
  q.push(0);
  while(!q.empty())
  {
    int x = q.front(); q.pop();
    int y = q.front(); q.pop();
    if(s[y * W + x] == c)
      continue;
    s[y * W + x] = c;
    N++;
    for(int i = 0; i < 4; i++)
    {
      int tx = x + dx[i], ty = y + dy[i];
      if(tx >= 0 && tx < W && ty >= 0 && ty < H && 
          s[ty * W + tx] == a)
      {
        q.push(tx);
        q.push(ty);
      }
    }
  }
  return s;
}

int main()
{
loop:
  stringstream ss;
  string s;
  cin >> W >> H;
  if(!W)
    return 0;

  for(int y = 0; y < H; y++)
  {
    for(int x = 0; x < W; x++)
    {
      string tmp;
      cin >> tmp;
      ss << tmp;
    }
  }
  s = ss.str();
  queue<P> q;
  q.push(make_pair(s, 0));
  while(!q.empty())
  {
    P p = q.front(); q.pop();
    char c = p.first[0];
    for(int i = 0; i < 3; i++)
    {
      if(c != rgb[i])
      {
        q.push(make_pair(f(rgb[i], p.first), p.second + 1));
        if(N == W * H)
        {
          cout << p.second << endl;
          goto loop;
        }
      }
    }
  }
}
