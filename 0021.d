module main;
import std.stdio;
import std.string;
import std.conv;
import std.algorithm;
import std.math;
import std.array;

double eps = 0.000000000000001;

void main()
{
  auto n = readln.chomp.to!int;
  for(int i = 0; i < n; i++)
  {
    auto p = readln.split.map!(to!double).array;
    double dx1 = p[0] - p[2], dx2 = p[4] - p[6], dy1 = p[1] - p[3], dy2 = p[5] - p[7];
    if(abs(dx1) < eps || abs(dx2) < eps)
      writeln(max(abs(dx1), abs(dx2)) < eps ? "YES" : "NO");
    else
      writeln(  abs(dy1 / dx1 - dy2 / dx2) < eps ? "YES" : "NO"); 
  }
}
