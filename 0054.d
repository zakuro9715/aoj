module main;
import std.stdio;
import std.array;
import std.conv;
import std.string;
import std.algorithm;

void main()
{
  string s;
  while((s=readln).length)
  {
    auto m = s.split();
    auto a = to!int(m[0]);
    auto b = to!int(m[1]);
    int c = to!int(m[2]);
    if(a % b == 0)
      writeln(a / b);
    else
      writeln(reduce!("a + b")((map!("to!int(to!string(a))")(to!string((to!double(a) / b)).split(".")[1]).array ~ [0, 0, 0, 0, 0, 0, 0, 0, 0])[0..c]));
  }
}
