#include<iostream>
#include<map>
using namespace std;

int A[200][2], B[2000][2], M, N;
int main()
{
  while(true)
  { 
    cin >> M;
    if(!M)
      break;
    for(int i = 0; i < M; i++)
      cin >> A[i][0] >> A[i][1];
    cin >> N;
    for(int i = 0; i < N; i++)
      cin >> B[i][0] >> B[i][1];
    for(int i = 0; i < N; i++)
    {
      int dx = B[i][0] - A[0][0];
      int dy = B[i][1] - A[0][1];
      int mn = 0;
      for(int j = 0; j < M; j++)
      {
        for(int k = 0; k < N; k++)
        {
          if(A[j][0] + dx == B[k][0] && A[j][1] + dy == B[k][1])
            mn++;
        }
      }
      if(mn == M)
      {
        cout << dx << " " << dy << endl;
        break;
      }
    }
  }
}
