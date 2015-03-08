#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;

vector<pair<int, int>> P;

int main()
{
  int n, d = 1000000000;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    int a, b;
    cin >> a >> b;
    P.push_back(make_pair(a, b));
  }
  sort(P.begin(), P.end());
  
  for(int i = 0; i < P.size(); i++)
  {
    for(int j = i + 1; j < P.size(); j++)
    {
      if(pow(P[i].first - P[j].first, 2) > d)
        break;
      d = min((int)(pow(P[i].first - P[j].first, 2) + pow(P[i].second - P[j].second, 2)), d);
    }
  }
  cout << d << endl;
}
