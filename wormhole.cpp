#include <iostream>
using namespace std;

int n, ans;
struct point
{
  int x;
  int y;
};

struct wormhole
{
  point p1;
  point p2;
  int cost;
};

int vis[100] = {false};

int dist(point src, point dest)
{
  return (abs(src.x - dest.x) + abs(src.y - dest.y));
}

void solve(point src, point dest, int cost, wormhole worm[])
{
  int tempans = cost + dist(src, dest);
  ans = min(ans, tempans);

  for (int i = 0; i < n; i++)
  {
    if (!vis[i])
    {
      vis[i] = true;

      int val = dist(src, worm[i].p1);
      solve(worm[i].p2, dest, cost + val + worm[i].cost, worm);

      val = dist(src, worm[i].p2);
      solve(worm[i].p1, dest, cost + val + worm[i].cost, worm);

      vis[i] = false;
    }
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    point src, dest;
    cin >> src.x >> src.y >> dest.x >> dest.y;
    cin >> n;
    wormhole worm[n];
    for (int i = 0; i < n; i++)
    {
      cin >> worm[i].p1.x >> worm[i].p1.y >> worm[i].p2.x >> worm[i].p2.y >> worm[i].cost;
    }
    ans = 10000;
    solve(src, dest, 0, worm);
    cout << ans << endl;
  }

  return 0;
}