#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int board[6000][6000];
int W, H, N, X1[1000], X2[1000], Y1[1000], Y2[1000];

int comp(int *x1, int *x2, int w)
{
  vector<int> xs;
  for(int i = 0; i < N; i++)
  {
    for(int d = -1; d <= 1; d++)
    {
      int tx1 = x1[i] + d, tx2 = x2[i] + d;
      if(1 <= tx1 && tx1 <= w)
        xs.push_back(tx1);
      if(1 <= tx2 && tx2 <= w)
        xs.push_back(tx2);
    }
  }
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  for(int i = 0; i < N; i++)
  {
    x1[i] = find(xs.begin(), xs.end(), x1[i]) - xs.begin();
    x2[i] = find(xs.begin(), xs.end(), x2[i]) - xs.begin();
  }
  return xs.size();
}

int main()
{
  cin >> W >> H >> N;
  for(int i = 0; i < N; i++)
  {
    cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
    X1[i]--; Y1[i]--; X2[i]--; Y2[i]--;
  }
  int w = comp(X1, X2, W);
  int h = comp(Y1, Y2, H);
  for(int i = 0; i < N; i++)
    for(int y = Y1[i]; y <= Y2[i]; y++)
      for(int x = X1[i]; x <= X2[i]; x++)
        board[x][y] = true;

  for(int y = 0; y < h; y++)
  {
    for(int x = 0; x < w; x++)
      cout << board[x][y] << " ";
    cout << endl;
  }

  int ans = 0;
  for(int y = 0; y < h; y++)
  {
    for(int x = 0; x < w; x++)
    {
      if(board[x][y])
        continue;
      board[x][y] = true;
      ans++;
      queue<int> q;
      q.push(x);
      q.push(y);
      while(!q.empty())
      {
        int sx = q.front(); q.pop();
        int sy = q.front(); q.pop();
        for(int i = 0; i < 4; i++)
        {
          int tx = sx + dx[i];
          int ty = sy + dy[i];
          if(tx >= 0 && tx < w && ty >= 0 && ty < h && !board[tx][ty])
          {
            board[tx][ty] = true;
            q.push(tx);
            q.push(ty);
          }
        }
      }
    }
  }
  cout << ans << endl;
}
