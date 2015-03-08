#include<iostream>

using namespace std;

#define A 0
#define B 1
#define C 2
#define D 3

int result[2][4];

int main()
{
  double buf[2];
  while(cin >> buf[0] >> buf[1])
  {
    for(int i = 0; i < 2; i++)
    {
      if(buf[i] >= 1.1)
        result[i][A]++;
      else if(buf[i] >= 0.6)
        result[i][B]++;
      else if(buf[i] >= 0.2)
        result[i][C]++;
      else
        result[i][D]++;
    }
  }

  for(int i = 0; i < 4; i++)
    cout << result[0][i] << " " << result[1][i] << endl;

  return 0;
}
