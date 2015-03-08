#include<iostream>

using namespace std;

int n;
int limits[4];
int foods[1000][4];
bool b;
int main()
{
  while(true)
  {
    b = true;
    cin >> n;
    if(!n)
      break;
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < 4; j++)
        cin >> foods[i][j];
      foods[i][4] = foods[i][1] * 4 + foods[i][2] * 4 + foods[i][3] * 9;
    }
    for(int i = 0; i < 4; i++)
      cin >> limits[i];
    for(int i = 0; i < n; i++)
    {
      if(foods[i][1] <= limits[0] && foods[i][2] <= limits[1] && foods[i][3] <= limits[2] && foods[i][4] <= limits[3])
      {
        cout << foods[i][0] << endl;
        b = false;
      }
    }

    if(b)
      cout << "NA" << endl;
  }
}
