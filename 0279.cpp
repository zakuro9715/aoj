#include<iostream>
#include<algorithm>
int main()
{
  while(true)
  {
    int n, sum = 0;
    int zero_item = 0;
    bool is_na = true;
    
    std::cin >> n;
    if(!n)
      break;
    for(int i = 0; i < n; i++)
    {
      int v;
      std::cin >> v;
      if(v > 1)
        is_na = false;
      if(v == 0)
        zero_item++;
    }
    if(is_na)
    {
      std::cout << "NA\n";
      continue;
    }
    std::cout << n - zero_item + 1 << std::endl;
  }
}
