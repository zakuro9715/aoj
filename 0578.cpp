#include<iostream>
#include<string>

using namespace std;

string target;
int ans;

bool judge();

int main()
{
  int n;
  cin >> n;
  cin >> target;
  for(int i = 0; i < n; i++)
  {
    if(judge())
      ans++;
  }
  cout << ans << endl;
}

bool judge()
{
  string input;
  cin >> input;
  for(int i = 0; i < input.length(); i++)
  {
    if(input[i] == target[0])
    {
      for(int j = 1; j < input.length(); j++)
      {
	if(input[j + i] == target[1])
	{
	  for(int k = 2; k < target.length(); k++)
	  {
	    if(i + k * j >= input.length() || target[k] != input[i + k * j])
	      goto skip;
	  } 
	  return true;
	skip:;
	}
      }
    }
  }

  return false;
}
