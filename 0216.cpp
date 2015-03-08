#include<iostream>
using namespace std;

int main()
{
  int w, p;
  while(1)
  {
    cin >> w;
    if(w < 0)
      break;
    if(w > 30)
      p = 160 * (w - 30) + 1400 + 1250 + 1150;
    else if(w > 20)
      p = 140 * (w - 20) + 1250 + 1150;
    else if(w > 10)
      p = 125 * (w - 10) + 1150;
    else
      p = 1150;
    cout << 4280 - p << endl;
  }
}
