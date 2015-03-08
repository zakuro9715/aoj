#include<iostream>
using namespace std;

int d[7];

int main()
{
  int n;
  cin >> n;

  for(int i = 0; i < n; i++)
  {
    double buf;
    cin >> buf;
    if(buf < 165)
      d[1]++;
    else if(buf < 170)
      d[2]++;
    else if(buf < 175)
      d[3]++;
    else if(buf < 180)
      d[4]++;
    else if(buf < 185)
      d[5]++;
    else
      d[6]++;
  }
  for(int i = 1; i <= 6; i++)
  {
    cout << i << ':';
    for(int j = 0; j < d[i]; j++)
      cout << '*';
    cout << endl;
  }
}
