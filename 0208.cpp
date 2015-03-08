#include<iostream>
using namespace std;


int main()
{
  int n;
  char c[10];
  while(1)
  {
    cin >> n;
    if(!n)
      break;
    for(int i = 0; i < 10; i++)
      c[i] = 50;
    
    int cnt = 0;
    while(n > 0)
    {
      c[cnt++] = n % 8;
      n /=  8;
    }

    for(int i = 9; i >= 0; i--)
    {
      //cout << i << ":" << (int)c[i] << endl;
      if(c[i] == 50)
	continue;
      if(c[i] >= 5)
	cout << (char)(c[i] + 2 + '0');
      else if(c[i] >= 4)
	cout << (char)(c[i] + 1 + '0'); 
      else
	cout << (char)(c[i] + '0');
    }
    cout << endl;
  }
}
