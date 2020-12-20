#include <iostream>
using namespace std;

int n, m, ans;
int map[100][100];
int dp[100][100];
int vis[100][100];

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool valid(int x, int y)
{
  return (x >= 0 && x < n && y >= 0 && y < m && map[x][y] && !vis[x][y]);
}

void solve(int sx, int sy, int dx, int dy, int ans)
{
  cout << sx << " " << sy << " " << ans << endl;
  vis[sx][sy] = 1;
  if (dp[sx][sy] > ans)
  {
    dp[sx][sy] = ans;
  }
  if (sx == dx && sy == dy)
  {
    return;
  }

  for (int i = 0; i < 4; i++)
  {
    int x = sx + dir[i][0];
    int y = sy + dir[i][1];
    int temp;
    if (valid(x, y))
    {
      if (x == sx)
      {
        temp = 0;
      }
      if (y == sy)
      {
        temp = 1;
      }
      solve(x, y, dx, dy, ans + temp);
    }
  }

  return;
}

int main()
{
  int t, sx, sy, dx, dy;
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> map[i][j];
        dp[i][j] = 10000;
        vis[i][j] = 0;
      }
    }
    cin >> sx >> sy >> dx >> dy;
    solve(sx, sy, dx, dy, 0);
    cout << "#" << t + 1 << " " << dp[dx][dy];
  }

  return 0;
}