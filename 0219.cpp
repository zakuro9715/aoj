#include<iostream>
using namespace std;

int main()
{
  int n, d;
  int ice[10];
  
  while(1)
  {
    cin >> n;
    if(!n)
      break;

    for(int i = 0; i < 10; i++)
      ice[i] = 0;

    for(int i = 0; i < n; i++)
    {
      cin >> d;
      ice[d]++;
    }
    
    for(int i = 0; i < 10; i++)
    {
      for(int j = 0; j < ice[i]; j++)
	cout << '*';
      if(!ice[i])
	cout << '-';
      cout << endl;
    }
  }
}
