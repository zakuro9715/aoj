#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string, int> mem;
string m = "";
string ss = "";
int n = 0;
int main()
{
  string s;
  while(cin >> s)
  {
    if(mem.find(s) == mem.end())
      mem[s] = 1;
    else
      mem[s]++;
    if(mem[s] > n)
    {
      n = mem[s];
      ss = s;
    }
    m = m.length() < s.length() ? s : m; 
  }
  cout << ss << " " << m << endl;
}
