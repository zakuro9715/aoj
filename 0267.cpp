#include<iostream>
using namespace std;

int blocks[1000001], n;


void update()
{
  for(int i = 0; i < n; i++)
    blocks[i]--;
  blocks[n++] = n;
  int m = 0;
  for(int i = 0; i < n; i++)
  {
    if(blocks[i] == 0)
    {
      m++;
    }
    else
      blocks[i - m] = blocks[i];
  }
  n -= m;
}

bool check()
{
  for(int i = 0; i < n; i++)
  {
    if(blocks[i] != i + 1)
      return false;
  }
  return true;
}

int main()
{
  while(true)
  {
    cin >> n;
    if(!n)
      break;
    for(int i = 0; i < n; i++)
      cin >> blocks[i];
    for(int i = 0; i <= 10000; i++)
    {
      if(check())
      {
        cout << i << endl;
        goto success;
      }
      update();
    }
    cout << -1 << endl;
success:;
  }
}
