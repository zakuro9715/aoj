#include<iostream>
#include<cmath>
int main()
{
  for(int i = 0; i < 7; i++)
  {
    int a, b;
    std::cin >> a >> b;
    std::cout << std::abs(a - b) << std::endl;
  }
}
