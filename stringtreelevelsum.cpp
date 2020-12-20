#include <iostream>
using namespace std;

int solve(string s, int k)
{
  int level = -1, l = s.length(), sum = 0;
  for (int i = 0; i < l; i++)
  {
    // cout << s[i];
    if (s[i] == '(')
    {
      level++;
    }
    else if (s[i] == ')')
    {
      level--;
    }
    else if (level == k)
    {
      sum += (s[i] - '0');
      // cout << sum << " " << s[i] << endl;
    }
  }
  return sum;
}

int main()
{
  int t, k;
  string s;
  cin >> t;
  while (t--)
  {
    cin >> s;
    cin >> k;
    cout << "#" << t + 1 << " " << solve(s, k) << endl;
  }

  return 0;
}