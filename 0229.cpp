#include<iostream>

using namespace std;

int main()
{
  int b, r, g, c, s, t;
  int coin;
  while(1)
  {
    cin >> b >> r >> g >> c >> s >> t;
    if(b == r && r == g && g == c && c == s && s == 0)
      break;

    coin = 100;
    coin -= t * 3;//コイン投入枚数
    coin += b * 5 + r * 3; //ボーナス中は投入二枚
    coin += (b + r) * 15;//ボーナス突入時にも15枚
    coin += b * 5 * 15 + r * 3 * 15;//ボーナス中は15枚
    coin += g * 7;
    coin += c * 2;
    coin += s * 3;

    cout << coin << endl;
  }
  return 0;
}
