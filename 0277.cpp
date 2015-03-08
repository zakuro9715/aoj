#include<iostream>
int main()
{
  int value[] = {0, 6000, 4000, 3000, 2000};
  for(int i = 0; i < 4; i++)
  {
    int a, b;
    std::cin >> a >> b;
    std::cout <<  value[a] * b << std::endl;
  }
}
