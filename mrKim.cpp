#include <iostream>
using namespace std;

int n, ox, oy, hx, hy;

struct point
{
  int x;
  int y;
};

point cust[10];
bool vis[10] = {false};

int solve(int x, int y, int count)
{
  if (count == n)
  {
    return abs(x - hx) + abs(y - hy);
  }

  int ans = INT_MAX, val;

  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      vis[i] = true;
      val = abs(x - cust[i].x) + abs(y - cust[i].y);
      ans = min(ans, val + solve(cust[i].x, cust[i].y, count + 1));
      vis[i] = false;
    }
  }
  return ans;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    cin >> ox >> oy >> hx >> hy;
    for (int i = 0; i < n; i++)
    {
      cin >> cust[i].x >> cust[i].y;
    }
    cout << "#" << t + 1 << " " << solve(ox, oy, 0);
  }

  return 0;
}