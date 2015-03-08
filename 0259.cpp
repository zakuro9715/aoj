#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
using namespace std;

char N[4], n[4];
int L, S, d;

int main()
{
  while(true)
  {
    cin >> N;
    if(N[0] == '0' && N[1] == '0' && N[2] == '0' && N[3] == '0')
      break;
    if(N[0] == N[1] && N[1] == N[2] && N[2] == N[3])
    {
      cout << "NA" << endl;
      continue;
    }
    for(int i = 0; i < 10; i++)
    {
      if(N[0] == '6' && N[1] == '1' && N[2] == '7' && N[3] == '4')
      {
	cout << i << endl;
	break;
      }

      L = S = 0;
      sort(N, N + 4);
      for(int j = 0; j < 4; j++)
	S += (N[j] - '0') * pow(10, 3 - j);
      reverse(N , N + 4);
      for(int j = 0; j < 4; j++)
	L += (N[j] - '0') * pow(10, 3 - j);
      d = L - S;
      for(int j = 0; j < 4; j++)
      {
	N[j] = (d / (int)pow(10, 3 - j)) + '0';
        d -= (N[j] - '0') * (int)pow(10, 3 - j); 
      }
    }
  }
}
