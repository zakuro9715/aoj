#include<iostream>

using namespace std; 
int main()
{
  int in[5], a[3]; 
  while(true)
  {
    a[0] = a[1] = a[2] = 0;
    cin >> in[0];
    if(!in[0])
      break;
    cin >> in[1] >> in[2] >> in[3] >> in[4];
    for(int i = 0; i < 5; i++)
      a[in[i] - 1]++;
    if(a[0] > 0 && a[1] > 0 && a[2] > 0
        || !a[0] && !a[1] || !a[1] && !a[2] || !a[2] && !a[0])
    {
      for(int i = 0; i < 5; i++)
        cout << 3 << endl;
      continue;
    }
    if(!a[0])
    {
      for(int i = 0; i < 5; i++)
      {
        cout << (in[i] == 2 ? 1 : 2) << endl;
      }
      continue;
    }
    if(!a[1])
    {
      for(int i = 0; i < 5; i++)
      {
        cout << (in[i] == 3 ? 1 : 2) << endl;
      }
      continue;
    } 
    if(!a[2])
    {
      for(int i = 0; i < 5; i++)
      {
        cout << (in[i] == 1 ? 1 : 2) << endl;
      }
      continue;
    }
  }
}
