#include<iostream>
using namespace std;

int main()
{
  int a, b;
  char s[20];
  for(int i = 0; i < 9; i++)
  {
    cin >> s >> a >> b;
    cout << s << " " << a + b << " " << a * 200 + b * 300 << endl;
  }
}
