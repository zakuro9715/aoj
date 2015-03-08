#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Deck
{
public:
  int start, end;
  Deck(int s, int e)
  {
    start = s;
    end = e;
  }

  vector<Deck> divide(int a, int b = -1)
  {
    vector<Deck> v;
    v.push_back(Deck(start, a));
    if(b == -1)
      v.push_back(Deck(a + 1, end));
    else
      v.push_back(Deck(a + 1, b));
      v.push_back(Deck(b + 1, end));
    return v;
  }

  int get_ans(int n, int p, int q, int r)
  {
    int s = max(n, p);
    int res = min(min(q - s + 1, end - start + n - s + 1), r - start);
    if(res < 0)
      res = 0;
    cout << start << " " << end << ":" << s << " " << res << endl;
    return res;
  }

  int size()
  {
    return end - start + 1;
  }
};

int main()
{
  vector<Deck> vp;
  vector<Deck> *v = &vp;

  int m, n, p, q, r, ans = 0;
  cin >> n >> m >> p >> q >> r;
  (*v).push_back(Deck(1, n));
  for(int cnt = 0; cnt < m; cnt++)
  {
    int a, b;
    vector<Deck> bufp[3];
    bufp[0] = vector<Deck>();
    bufp[1] = vector<Deck>();
    bufp[2] = vector<Deck>();
    vector<Deck> *buf[3];
    buf[0] = &(bufp[0]);
    buf[1] = &(bufp[1]);
    buf[2] = &(bufp[2]);
    int bc = 0;
    cin >> a >> b;
    for(int i = 0; i < (*v).size(); i++)
    {
      if((*v)[i].end < a || (*v)[i].start > b 
          || (*v)[i].start > a && (*v)[i].end < b)
      {
        (*buf[bc]).push_back(Deck(a, b));
      }
      else if((*v)[i].start <= a && (*v)[i].end >= b)
      {
        vector<Deck> vv = (*v)[i].divide(a, b);
        (*buf[0]).push_back(vv[2]);
        (*buf[1]).push_back(vv[1]);
        (*buf[2]).push_back(vv[0]);
        bc = 2;
      }
      else if((*v)[i].start <= a)
      {

        vector<Deck> vv = (*v)[i].divide(a);        
        (*buf[0]).push_back(vv[1]);
        (*buf[1]).push_back(vv[0]);
        bc = 1;
      }
      else if((*v)[i].end >= b)
      {
        vector<Deck> vv = (*v)[i].divide(b);        
        (*buf[1]).push_back(vv[1]);
        (*buf[2]).push_back(vv[0]);
        bc = 2;
      }
    }
    (*v).clear();
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < (*buf[i]).size(); j++)
        (*v).push_back((*buf[i])[j]);
    }
  }
  int nn = 0;
  for(int i = 0; i < (*v).size(); i++)
  {
    ans += (*v)[i].get_ans(nn, p, q, r);
    nn += (*v)[i].size();
  }
  cout << ans<< endl; 
}
