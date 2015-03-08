#include<iostream>
#include<algorithm>

using namespace std;

int n, field, players[10];

void do_s(int num)
{
  field += players[num] + 1;
  players[num] = 0;
}

void do_m(int num)
{
  players[num]++;
}

void do_l(int num)
{
  players[num] += field + 1;
  field = 0;
}


int main()
{
  while(true)
  {
    field = 0;
    for(int i = 0; i < 10; i++)
      players[i] = 0;
    cin >> n;

    if(!n)
      break;

    for(int turn = 0; turn < 100; turn++)
    {
      char c;
      cin >> c;
      switch(c)
      {
        case 'S':
          do_s(turn % n); break;
        case 'M':
          do_m(turn % n); break;
        case 'L':
          do_l(turn % n); break;
      }
    }
    sort(players, players + n);
    for(int i = 0; i < n; i++)
      cout << players[i] << " ";
    cout << field << endl;
  }
}
