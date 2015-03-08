#include<iostream>
#include<string>
using namespace std;

int W, H;
string mem[50];
int t[50][50];

int main()
{
  cin >> W >> H;
  for(int i = 0; i < H; i++)
    cin >> mem[i];
  for(int i = 0; i < H; i++)
  {
    for(int j = 0; j < W; j++)
    {
      if(mem[i][j] != '.')
      {
        for(int y = i + 1; y < H; y++)
        {
          if(mem[y][j] != '.')
            break;
          if(t[j][y] == 0 || t[j][y] == 'W' ? 1 : -1)
            t[j][y] = mem[i][j] == 'W' ? 1 : -1;
          else
            t[j][y] = 10;
        }
        for(int y = i - 1; y >= 0; y--)
        {
          if(mem[y][j] != '.')
            break;
          if(t[j][y] == 0 || t[j][y] == 'W' ? 1 : -1)
            t[j][y] = mem[i][j] == 'W' ? 1 : -1;
          else
            t[j][y] = 10;
        }
        for(int x = j + 1; x < W; x++)
        {
          if(mem[i][x] != '.')
            break;
          if(t[x][i] == 0 || t[x][i] == 'W' ? 1 : -1)
            t[x][i] = mem[i][j] == 'W' ? 1 : -1;
          else
            t[x][i] = 10;
        }
        for(int x = j - 1; x >= 0; x--)
        {
          if(mem[i][x] != '.')
            break;
          if(t[x][i] == 0 || t[x][i] == 'W' ? 1 : -1)
            t[x][i] = mem[i][j] == 'W' ? 1 : -1;
          else
            t[x][i] = 10;
        }
      }
    }
  }
  int b = 0, w = 0;
  for(int i = 0; i < H; i++)
  {
    for(int j = 0; j < W; j++)
    {
      b += t[j][i] == -1;
      b += t[j][i] == 1;
      cout << t[j][i];
    }
    cout << endl;
  }
  cout << b << " " << w << endl;
}
