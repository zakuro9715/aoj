#include<iostream>
#include<map>
#include<cstdio>
using namespace std;

map<double, int> t[4];


int main()
{
  int aa;
  double bb;
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      cin >> aa >> bb;
      t[i][bb] = aa;
    }
  }
  for(int i = 0; i < 3; i++)
  {
    map<double, int>::iterator it = t[i].begin();
    printf("%d %2.2f\n", (*it).second, (*it).first);
    it++;
    printf("%d %2.2f\n", (*it).second, (*it).first);
    it++;
    for(;it != t[i].end(); it++)
      t[3][(*it).first] = (*it).second;
  }
  map<double, int>::iterator it = t[3].begin();
  printf("%d %2.2f\n",  (*it).second, (*it).first);
  it++;
  printf("%d %2.2f\n",  (*it).second, (*it).first);
}
