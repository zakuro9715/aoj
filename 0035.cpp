#include<iostream>
#include<cstdio>
#include<vector>
#include<complex>
#include<algorithm>
#define P complex<double>
using namespace std;

bool cmp_p(const P& a, const P& b)
{
  return a.real() == b.real() ? a.imag() < b.imag() : a.real() < b.real();
}

double det(P a, P b)
{
  return a.real() * b.imag() - b.real() * a.imag();
}

vector<P> graham_scan(P* ps, int n)
{
  sort(ps, ps + n, cmp_p);
  int k = 0;
  vector<P> qs(n * 2);
  for(int i = 0; i < n; i++)
  {  
    while(k > 1 && det(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  for(int i = n - 2, t = k; i >= 0; i--)
  {  
    while(k > t && det(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  qs.resize(k - 1);
  return qs;
}

P p[4];
double xa, ya, xb, yb, xc, yc, xd, yd;
int main()
{
  while(scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd) != -1)
  {
    p[0] = P(xa, ya);
    p[1] = P(xb, yb);
    p[2] = P(xc, yc);
    p[3] = P(xd, yd);
    cout << (graham_scan(p, 4).size() == 4 ? "YES" : "NO") << endl;
  }
}
