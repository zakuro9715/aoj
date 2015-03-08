#define MN 10000001

int prime[MN];
int mem[MN];

int N, i, j, a;
int main()
{
  prime[0] = prime[1] = -1;
  for(i = 2; i < MN; i++)
  {
    if(prime[i] != 0)
      continue;
    prime[i] = 1;
    for(j = i + i; j < MN; j += i)
      prime[j] = -1;
  }
loop:
  scanf("%d", &N);
  if(!N)
    return 0;
  a = 0;
  for(i = 9; i < MN; i++)
  {
    if(prime[i - 8] == 1 && prime[i - 6] == 1 && prime[i - 2] == 1 && prime[i] == 1)
      a = a < i ? i : a;
  }
  printf("%d\n", a);
  goto loop;
}
