#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

#define J 0
#define O 1
#define I 2

int H, W, N;
string c = "JOI";
char s[1001][1001];
int mem[1001][1001][3];

int main()
{
  cin >> H >> W >> N;
  for(int i = 1; i <= H; i++)
    scanf("%s", s[i] + 1);

  for(int i = 0; i < 3; i++)
  {
    mem[1][1][i] = c[i] == s[1][1];
    for(int x = 2; x <= W; x++)
      mem[x][1][i] = mem[x - 1][1][i] + (s[1][x] == c[i] ? 1 : 0);
    for(int y = 2; y <= H; y++)
      mem[1][y][i] = mem[1][y - 1][i] + (s[y][1] == c[i] ? 1 : 0);
  }
  for(int i = 0; i < 3; i++)
    for(int x = 2; x <= W; x++)
      for(int y = 2; y <= H; y++)
        mem[x][y][i] = mem[x - 1][y][i] + mem[x][y - 1][i] - mem[x - 1][y - 1][i] + (s[y][x] == c[i] ? 1 : 0);
  for(int i = 0; i < N; i++)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for(int j = 0; j < 3; j++)
      cout << mem[d][c][j] + mem[b - 1][a - 1][j] - mem[b - 1][c][j] - mem[d][a - 1][j] << (j < 2 ? " " : "");
    cout << endl;
  }
}
