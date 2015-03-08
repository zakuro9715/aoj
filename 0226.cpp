#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
  string r, a;
  int hit, brow;
  while(1)
  {
    hit = brow = 0;

    cin >> r >> a;
    if(r.length() == 1)
      break;
    
    for(int i = 0; i < 4; i++)
    {
      if(r[i] == a[i])
      {
	hit++;
	r[i] = a[i] = 'a';
      }
    }
    
    for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
      {
	if(r[i] != 'a' && a[j] != 'a' && r[i] == a[j])
	{
	  brow++;
	  r[i] = a[j] = 'a';
	}
      }
    }

    printf("%d %d\n", hit, brow);
  }
  return 0;
}
