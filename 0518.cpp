#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

bool mem[5001][5001];
const int H = 5000, W = 5000;
vector<pair<int, int>> points;

bool check(int x, int y, int dx, int dy)
{
  return x - dy <= W && x - dy >= 0 && y + dx <= H && y + dx >= 0 && mem[x - dy][y + dx] &&
         x + dx - dy <= W && x + dx - dy >= 0 && y + dy + dx <= H && y + dy + dx >= 0 && mem[x + dx - dy][y + dy + dx];
}

int main()
{
loop:
  fill((bool*)mem, (bool*)mem + 5001 * 5001, false);
  int n, ans = 0;
  cin >> n;
  if(!n)
    return 0;
  for(int i = 0; i < n; i++)
  {
    int x, y;
    cin >> x >> y;
    points.push_back(make_pair(x, y));
    mem[x][y] = true;
  }

  for(auto st : points)
  {
    for(auto ed: points)
    {
      if(st == ed)
        continue;
      auto sx = st.first, sy = st.second,
           ex = ed.first, ey = ed.second;
      auto dx = ex - sx, dy = ey - sy;
      if(check(sx, sy, dx, dy))
        ans = max(ans, dx * dx + dy * dy);
    }
  }
  cout << ans << endl;
  goto loop;
}
