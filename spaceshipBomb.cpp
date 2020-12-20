#include <iostream>
using namespace std;

int map[100][5] = {0};
int dp[100][5] = {-1};
int n, ans = 0;

bool isValid(int r, int c)
{
  return (r < n && r >= 0 && c < 5 && c >= 0);
}

int solve(int r, int c, int bomb, int effect)
{
  if (r < 0)
  {
    return 0;
  }

  int ans = 0, temp = 0, x, y;

  for (int i = -1; i <= 1; i++)
  {
    x = r - 1;
    y = c + i;
    if (isValid(x, y))
    {
      // cout << map[x][y] << " " << x << " " << y << " " << i << endl;
      if (dp[x][y] >= 0)
      {
        temp = dp[x][y];
      }
      else if (map[x][y] == 2)
      {
        if (bomb == 0 && effect > 0)
        {
          temp = solve(x, y, 0, effect - 1);
        }
        else if (bomb == 1)
        {
          temp = solve(x, y, 0, 5);
        }
      }
      else
      {
        if (bomb == 0)
        {
          temp = solve(x, y, 0, effect - 1);
        }
        else
        {
          temp = solve(x, y, bomb, 5);
        }
      }
      ans = max(ans, temp);
    }
  }
  if (map[r][c] == 1)
  {
    ans++;
  }
  dp[r][c] = ans;
  cout << r << " " << c << " " << dp[r][c] << endl;
  return ans;
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin >> map[i][j];
      dp[i][j] = -1;
    }
  }

  solve(n, 2, 1, 5);

  cout << dp[n][2];
  return 0;
}