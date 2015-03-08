#include<iostream>
#include<algorithm>
int main()
{
  int n;
  std::cin >> n;
  for(int i = 0; i < n; i++)
  { 
    int x, y, p, b, v;
    std::cin >> x >> y >> b >> p;
    
    v = x * b + y * p;

    b = std::max(b, 5); 
    p = std::max(p, 2);
    v = std::min(v, (int)((x * b + y * p) * 0.8));
    
    std::cout << v << std::endl;
  }
}
