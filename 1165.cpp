#include<iostream>
#include<vector>
using namespace std;
struct square 
{
  int x, y;
  square(int _x, int _y)
  {
    x = _x;
    y = _y;
  }
};

int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
vector<square> sq;

int main()
{
loop:
  sq.clear();
  int n;
  cin >> n;
  if(!n)
    return 0;
  sq.push_back(square(0, 0));
  for(int i = 0; i < n - 1; i++)
  {
    int a, b;
    cin >> a >> b;
    sq.push_back(square(sq[a].x + dx[b], sq[a].y + dy[b]));
  }
  int l = 0, b = 0, r = 0, t = 0;
  for(int i = 0; i < sq.size(); i++)
  {
    l = min(l, sq[i].x);
    b = min(b, sq[i].y);
    r = max(r, sq[i].x + 1);
    t = max(t, sq[i].y + 1);
  }
  cout << r - l << " " << t - b << endl;
  goto loop;
}
