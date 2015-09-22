#include<bits/stdc++.h>
using namespace std;

int W, H, m[1000][1000];
int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1}, dy[] = {1, 1, 1, 0, -1, -1, -1, 0};


int main()
{
  cin >> H >> W;
  queue<int> up1, up2, bks;
  for(int y = 0; y < H; y++)
  {
    for(int x = 0; x < W; x++)
    {
      char c;
      cin >> c;
      if(c == '.')
      {
        m[y][x] = -1;
      }
      else
      {
        m[y][x] = c - '0';
        up1.push(x);
        up1.push(y);
      }
    }
  }
  int ans = 0;
  while(!(up1.empty() && up2.empty()))
  {
    queue<int> *upp1, *upp2;
    if(up1.empty())
    {
      upp2 = &up1;
      upp1 = &up2;
    }
    else
    {
      upp1 = &up1;
      upp2 = &up2;
    }
    while(!upp1->empty())
    {
      int x = upp1->front(); upp1->pop();
      int y = upp1->front(); upp1->pop();
      if(m[y][x] == -1)
        continue;
      int c = 0;
      for(int i = 0; i < 8; i++)
      {
        int tx = x + dx[i], ty = y + dy[i];
        if(m[ty][tx] == -1)
          c++;
      }
      if(c < m[y][x])
        continue;
      bks.push(x);
      bks.push(y);
    }
    if(bks.empty())
      break;
    while(!bks.empty())
    {
      int x = bks.front(); bks.pop();
      int y = bks.front(); bks.pop();
      if(m[y][x] == -1)
        continue;
      m[y][x] = -1;
      for(int i = 0; i < 8; i++)
      {
        int tx = x + dx[i], ty = y + dy[i];
        if(m[ty][tx] != -1)
        {
          upp2->push(tx);
          upp2->push(ty);
        }
      }
    }

    ans += 1;
  }
  cout << ans << endl;
}
