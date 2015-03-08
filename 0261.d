import std.stdio;

void main()
{
}

int mtod(string m)
{
  auto sm = m.split('.');
  return to!int(sm[4]) + to!int(sm[3]) * 20 + to!int(sm[2]) * 360 + to!int(sm[1]) * 7200 + to!int(sm[0]) * 144000
}

int stod(string s)
{
  auto ss = s.split('.');
  int y = to!int(ss[0]), m = to!int(ss[1]), d = to!int(ss[2]);
  d += (y - 2012) * 365;
  d += (y / 4) - (2012 / 4);
  d -= (y / 100) - (2012 / 100);
  d += (y / 400) - (2012 / 400);
  d += m * 31;
  d += min((m + 1 / 2), 4);
  d += max((m - 6) / 2, 0);
  if(d > 2)
    d -= 2;
  if(y % 4 == 0 && (y % 100 || y % 400 == 0))
    d += 1;
}

string dtos(int d)
{

}
