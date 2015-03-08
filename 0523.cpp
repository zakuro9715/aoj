#include<iostream>
using namespace std;

bool cards[2][201];
int N, field, rest[2];
int main()
{
  while(true)
  {
    cin >> N;
    if(!N)
      break;
    for(int i = 0; i <= N * 2; i++)
      cards[0][i] = 0;
    for(int i = 0; i < N; i++)
    {
      int tmp;
      cin >> tmp;
      cards[0][tmp] = 1;
    }
    for(int i = 0; i <= N * 2; i++)
    {
      if(!cards[0][i])
        cards[1][i] = 1;
      else
        cards[1][i] = 0;
    }
    rest[0] = rest[1] = N;

    field = 0;
    int turn = 0;
    while(rest[0] > 0 && rest[1] > 0)
    {
      bool b = true;
      for(int i = 1; i <= 2 * N; i++)
      {
        if(cards[turn][i] && i > field)
        {
          cards[turn][i] = 0;
          rest[turn]--;
          field = i;
          b = false;
          break;
        }
      }
      if(b)
        field = 0;
      turn = (turn + 1) % 2;
    }
    cout << rest[1] << endl << rest[0] << endl;
  }
}
