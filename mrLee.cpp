#include <iostream>
using namespace std;

int n;
int map[12][12];
int dp[4096][12] = {-1};

int solve(int stat, int city, int comp)
{
  if (stat == comp)
  {
    // cout << ans + map[city][0] << " " << city << endl;
    return map[city][0];
  }

  if (dp[stat][city] != -1)
  {
    return dp[stat][city];
  }

  int ans = INT_MAX, temp = 0;
  for (int i = 0; i < n; i++)
  {
    // cout << ans << " " << temp << " " << (stat & (1 << i));
    if ((stat & (1 << i)) == 0)
    {
      // cout << city << " " << i << " " << stat << " " << ans << endl;
      temp = map[city][i] + solve((stat | (1 << i)), i, comp);
      // cout << " " << temp << endl;
      if (temp < ans)
      {
        ans = temp;
        // cout << "city = " << city << " " << i << " " << ans << endl;
      }
      else
      {
        // cout << "rejected = " << ans << " temp = " << temp << " city = " << city << " " << i << endl;
      }
    }
  }
  dp[stat][city] = ans;
  return ans;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> map[i][j];
      }
    }
    for (int i = 0; i < (1 << n); i++)
    {
      for (int j = 0; j < n; j++)
      {
        dp[i][j] = -1;
      }
    }
    int comp = (1 << n) - 1;
    cout << solve(1, 0, comp) << endl;
    for (int i = 0; i < (1 << n); i++)
    {
      cout << i << " ";
      for (int j = 0; j < n; j++)
      {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}