#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
  int len[10];
  int len_s = 0;
  int v[3];
  double t;
  while(scanf("%d", &len[0]) != EOF)
  {
    len_s = len[0];
    for(int i = 1; i < 10; i++)
    {
      scanf(",%d", &len[i]);
      len_s += len[i];
    }
    scanf(",%d,%d", &v[0], &v[1]);
    v[2] = v[0] + v[1];
    t = (double)len_s / (double)v[2];
    
    int s = 0;
    int l = 0;
    bool b = t * v[0] - (int)(t * v[0]) > 0.00001; 
    while(s < (int)(t * v[0]))
    {
      s += len[l];
      l++;
    }
    cout << l + (b ? 1 : 0) << endl;
  }
  return 0;
}
