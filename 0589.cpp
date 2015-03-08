#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
  int n, value;
  string key;
  map<string, int> m;

  cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin >> key >> value;
    if(m.find(key) == m.end())
      m[key] = value;
    else
      m[key] += value;
  }
  for(map<string, int>::iterator i = m.begin(); i != m.end(); i++)
  {
    cout << i->first << " " << i->second;
  }
}
