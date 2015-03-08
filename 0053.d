module main;
import std.stdio;
import std.conv;
import std.string;
import std.algorithm;

void main()
{
  int N = 1000000;
  bool pb[] = new bool[N];
  int p[];
  for(int i = 2; i < N; i++)
  {
    if(pb[i])
      continue;
    p ~= i;
    for(int j = i; j < N; j += i)
      pb[j] = true;
  }
  while(true)
  {
    int n = chomp(readln()).to!int();
    if(!n)
      break;
    writeln(reduce!("a + b")(p[0..n]));
  };
}
