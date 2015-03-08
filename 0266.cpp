#include<iostream>
#include<string>

using namespace std;

#define A 0
#define X 1
#define Y 2
#define Z 3
#define W 4
#define B 5

bool solve(int, int);

int map[10][2];
string s;

int main()
{
  
  for(int i = 0; i < 10; i++)
    map[i][0] = map[i][1] = -1;

  map[A][0] = X;
  map[A][1] = Y;
  map[X][1] = Z;
  map[Y][0] = X;
  map[Z][0] = W;
  map[Z][1] = B;
  map[W][0] = B;
  map[W][1] = Y;
  map[B][0] = Y;
  map[B][1] = X;
  while(1)
  {
    cin >> s;
    if(s[0] == '#')
      break;

    if(solve(0, A))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}

bool solve(int n, int city)
{
  if(city == -1)
    return false;
  if(n == s.length())
    return city == B;

  return solve(n + 1, map[city][s[n] - '0']);
}
