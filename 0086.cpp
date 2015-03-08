#include<iostream>

using namespace std;

void judge();

int point[110];

int main()
{
  int a, b;
  while(cin >> a >> b)
  {
    if(a == 0 && a == b)
    {
      judge();
      continue;
    }
    point[a]++;
    point[b]++;
  }
}

void judge()
{
  bool ans = true;
  if(point[1] % 2 == 0)
    ans = false;
  if(point[2] % 2 == 0)
    ans = false;
  point[1] = point[2] = 0;
  for(int i = 3; i < 110; i++)
  {
    if(point[i] % 2)
      ans = false;
    point[i] = 0;
  }
  
  cout << (ans ? "OK" : "NG") << endl;
}
