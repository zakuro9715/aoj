#include<queue>
#include<iostream>
using namespace std;

#define INF 1000000000

int d[100][100];

int main()
{
  fill((int*)d, (int*)d + 10000, INF);
  
  int N;
  cin >> N;
  for(int i = 0; i < N; i++)
  {
    int r, k, t;
    cin >> r >> k;
    for(int j = 0; j < k; j++)
    {
      cin >> t;
      d[r - 1][t - 1] = 1;
    }
  }

  for(int k = 0; k < N; k++)
    for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  int S, D, V, P;
  cin >> P;
  for(int i = 0; i < P; i++)
  {
    cin >> S >> D >> V;
    if(d[S - 1][D - 1] < V)
      cout << d[S - 1][D - 1] + 1 << endl;
    else
      cout << "NA" << endl;
  }
}
