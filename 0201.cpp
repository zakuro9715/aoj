#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

map<string, vector<string> > mix;
map<string, int> prise;
map<string, int> min_prise;

int cal_min(string s)
{
  if(min_prise.find(s) != min_prise.end())
    return min_prise[s];
  if(mix.find(s) == mix.end())
    return prise[s];
  int p = 0;
  for(vector<string>::iterator i = mix[s].begin(); i != mix[s].end(); i++)
  {
    p += cal_min(*i);
    if(p >= prise[s])
    {
      min_prise.insert(pair<string, int>(s, prise[s]));
      return min_prise[s];
    }
  }
  min_prise.insert(pair<string, int>(s, p));
  return p;
}

int main()
{
  int n, m;
  while(1)
  {
    mix.clear();
    prise.clear();
    min_prise.clear();
    cin >> n;
    if(!n)
      break;
    for(int i = 0; i < n; i++)
    {
      string s;
      int p;
      cin >> s >> p;
      prise.insert(pair<string, int>(s, p));
    }
    cin >> m;

    for(int i = 0; i < m; i++)
    {
      string item;
      int d;
      vector<string> v;
      cin >> item >> d;
      for(int j = 0; j < d; j++)
      {
        string s;
        cin >> s;
        v.push_back(s);
      }
      mix.insert(pair<string, vector<string> >(item, v));
    }

    string str;
    cin >> str;
    cout << cal_min(str) << endl;
  }
}
