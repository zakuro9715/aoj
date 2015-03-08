#include<algorithm>
#include<map>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

map<string, vector<int> > ans;

int main()
{
  string s;
  int n;
  while(cin >> s >> n)
  {
    ans[s].push_back(n);
  }

  for(map<string, vector<int> >:: iterator i = ans.begin(); i != ans.end(); i++)
  {
    cout << (*i).first << endl;

    sort((*i).second.begin(), (*i).second.end());
    for(int j = 0; j < (*i).second.size() - 1; j++)
    {
      cout << (*i).second[j] << " ";
    }
    cout << (*i).second[(*i).second.size() - 1] << endl;
  }
}
