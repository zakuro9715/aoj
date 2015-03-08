#include<iostream>
using namespace std;
int main()
{
  int sum = 0;
  for(int i = 0; i < 10; i++)
  {
    int in;
    cin >> in;
    sum += in;
  }
  cout << sum << endl;
  return 0;
}
