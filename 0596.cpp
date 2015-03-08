#include<iostream>
#include<vector>
#include<queue>
#define MAX_N 5000
#define MAX_K 10000
#define INF 1000000000
using namespace std;


struct taxi{ int c, r; };
struct edge{ int to, cost; };
int N, K;
taxi taxis[MAX_N];
vector<edge> ways[MAX_N];

void make_edge(taxi

int main()
{
  cin >> N >> K;
  for(int i = 0; i < N; i++)
  {
    int a, b;
    cin >> a >> b;
    taxis[i] = {a, b};
  }
  
  for(int i = 0; i < K; i++)
  {
    int a, b;
    cin >> a >> b;
    a--; b--;
    edge e1 = {a, INF}, e2 = {b, INF};
    ways[a].push_back(e2);
    ways[b].push_back(e1);
  }
}
