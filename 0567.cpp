#include<iostream>
#include<algorithm>
using namespace std;

int n, a, b, c, toppings[100], value, cal;

int main()
{
  cin >> n >> a >> b >> c;
  for(int i = 0; i < n; i++)
  {
    cin >> toppings[i];
  }
  value = a;
  cal = c;
  sort(toppings, toppings + n);
  for(int i = n - 1; i >= 0; i--)
  {
    if(cal / value <= (cal + toppings[i]) / (value + b))
    {
      value += b;
      cal += toppings[i];
    }
  }
  cout << cal / value << endl;
}
