#include<iostream>
#include<string>
using namespace std;

int ax[7] = {2, 1, 4, 2, 3, 2, 3};
int ay[7] = {2, 4, 1, 3, 2, 3, 2};
int a[7][4][4] = {
  {
    {1, 1},
    {1, 1},
  },
  {
    {1},
    {1},
    {1},
    {1},
  },
  {
    {1, 1, 1, 1},
  },
  {
    {0, 1},
    {1, 1},
    {1, 0},
  },
  {
    {1, 1, 0},
    {0, 1, 1},
  },
  {
    {1, 0},
    {1, 1},
    {0, 1},
  },
  {
    {0, 1, 1},
    {1, 1, 0},
  },
};

string p[8];
int main()
{
  char tmp;
  do
  {
    for(int i = 0; i < 8; i++)
      cin >> p[i];
    for(int i = 0; i < 7; i++)
    {
      for(int y = 0; y < 8 - ay[i] + 1; y++)
      {
        for(int x = 0; x < 8 - ax[i] + 1; x++)
        {
          for(int yy = 0; yy < ay[i]; yy++)
          {
            for(int xx = 0; xx < ax[i]; xx++)
            {
              if(p[y + yy][x + xx] - '0' != a[i][yy][xx])
                goto aaa;
            }
          }
          cout << (char)('A' + i) << endl;
          goto bbb;
aaa:;
        }
      }
    }
bbb:;
  } while(cin >> tmp);
}
