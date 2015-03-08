#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
  int n;
  while(cin >> n)
  {
    printf("3C%02d\n", n % 39 ? n % 39 : 39);
  }
}
