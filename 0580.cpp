#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<long long> sp[3];
int N, K;
int input[50][6];

int cnt[100][100][100];

int main()
{
  cin >> N >> K;
  for(int i = 0; i < N; i++)
  {
    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    sp[0].push_back(x1);
    sp[0].push_back(x2);
    sp[1].push_back(y1);
    sp[1].push_back(y2);
    sp[2].push_back(z1);
    sp[2].push_back(z2);
    input[i][0] = x1;
    input[i][1] = y1;
    input[i][2] = z1;
    input[i][3] = x2;
    input[i][4] = y2;
    input[i][5] = z2;
  }
  for(int i = 0; i < 3; i++)
  {
    sort(sp[i].begin(), sp[i].end());
    unique(sp[i].begin(), sp[i].end());
  }
  for(int i = 0; i < N; i++)
  {
    auto x1 = distance(sp[0].begin(), lower_bound(sp[0].begin(), sp[0].end(), input[i][0]));
    auto y1 = distance(sp[1].begin(), lower_bound(sp[1].begin(), sp[1].end(), input[i][1]));
    auto z1 = distance(sp[2].begin(), lower_bound(sp[2].begin(), sp[2].end(), input[i][2]));
    auto x2 = distance(sp[0].begin(), lower_bound(sp[0].begin(), sp[0].end(), input[i][3]));
    auto y2 = distance(sp[1].begin(), lower_bound(sp[1].begin(), sp[1].end(), input[i][4]));
    auto z2 = distance(sp[2].begin(), lower_bound(sp[2].begin(), sp[2].end(), input[i][5]));
    for(int x = x1; x < x2; x++)
      for(int y = y1; y < y2; y++)
        for(int z = z1; z < z2; z++)
          cnt[x][y][z]++;
  }
  long long area = 0;
  for(int x = 0; x < 100; x++)
    for(int y = 0; y < 100; y++)
      for(int z = 0; z < 100; z++)
        if(cnt[x][y][z] >= K)
          area += (sp[0][x + 1] - sp[0][x]) * (sp[1][y + 1] - sp[1][y]) * (sp[2][z + 1] - sp[2][z]);
  cout << area << endl;
}
