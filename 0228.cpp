#include<iostream>

using namespace std;

void setByte(bool *xb, int n)
{
  static bool v[11][7] = 
    {{0, 1, 1, 1, 1, 1, 1},
     {0, 0, 0, 0, 1, 1, 0},
     {1, 0, 1, 1, 0, 1, 1},
     {1, 0, 0, 1, 1, 1, 1},
     {1, 1, 0, 0, 1, 1, 0},
     {1, 1, 0, 1, 1, 0, 1},
     {1, 1, 1, 1, 1, 0, 1},
     {0, 1, 0, 0, 1, 1, 1},
     {1, 1, 1, 1, 1, 1, 1},
     {1, 1, 0, 1, 1, 1, 1},
     {0, 0, 0, 0, 0, 0, 0}};
  for(int i = 0; i < 7; i++)
    b[i] = v[n][i];
}

int main()
{
  bool state[7];
  bool b[7];
  int n;
  while(1)
  {
    setByte(state, 10);
    cin >> n;

    if(n == -1)
      break;

    for(int i = 0; i < n; i++)
    {
      int d;
      cin >> d;
      setByte(b, d);
 
      for(int j = 0; j < 7; j++)
      {	
	state[j] = !(state[j] == b[j]);
	cout << state[j];
      }
      cout << endl;
      setByte(state, d);
    }
  }
}
