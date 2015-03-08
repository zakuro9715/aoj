#include<iostream>
using namespace std;

int card[1000], tmp[1000], n, r;
int main()
{
loop:
  cin >> n >> r;
  if(!n && !r)
    return 0;
  for(int i = n; i > 0; i--)
    card[n - i] = i;
  for(int i = 0; i < r; i++)
  {
    int c, p;
    cin >> p >> c;
    for(int j = 0; j < p - 1; j++)
      tmp[j] = card[j];
    for(int j = 0; j < c; j++)
      card[j] = card[j + p - 1];
    for(int j = 0; j < p - 1; j++)
      card[j + c] = tmp[j];
  }
  cout << card[0] << endl;
  goto loop;
}
