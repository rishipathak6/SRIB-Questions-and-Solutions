#include <iostream>
using namespace std;

int map[20][20];
bool vis[20][20];
int rare[5][2];
int n, r;

struct node
{
  int x;
  int y;
  int l;
};

node q[1000];
int front, back;

void init()
{
  front = back = 0;
  return;
}
void init2()
{
  for (int i = 0; i < 20; i++)
  {
    for (int j = 0; j < 20; j++)
    {
      vis[i][j] = 0;
    }
  }
  return;
}

bool isempty()
{
  return (front == back);
}

void push(int x, int y, int l)
{
  q[back].x = x;
  q[back].y = y;
  q[back].l = l;
  back++;
  return;
}

node pop()
{
  if (!isempty())
  {
    return q[front++];
  }
  exit(EXIT_FAILURE);
}

bool isvalid(int r, int c)
{
  return (r >= 0 && r < n && c >= 0 && c < n);
}

int dir[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}};

int bfs(int sx, int sy, int dx, int dy)
{
  push(sx, sy, 0);
  vis[sx][sy] = 1;
  while (!isempty())
  {
    node n = pop();
    // cout << n.x << " " << n.y << endl;
    if (n.x == dx && n.y == dy)
    {
      return n.l;
    }
    for (int i = 0; i < 4; i++)
    {
      int valx = n.x + dir[i][0];
      int valy = n.y + dir[i][1];
      int lvl = n.l + 1;
      if (isvalid(valx, valy) && map[valx][valy] == 1 && vis[valx][valy] == 0)
      {
        push(valx, valy, lvl);
        vis[valx][valy] = 1;
      }
    }
  }
  return -1;
}

int main()
{
  int t, x, y;
  cin >> t;
  int m = t;
  while (t--)
  {
    cin >> n >> r;
    for (int j = 0; j < r; j++)
    {
      cin >> x >> y;
      x--;
      y--;
      rare[j][0] = x;
      rare[j][1] = y;
    }
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        cin >> map[j][k];
        vis[j][k] = 0;
      }
    }

    int ans = 10000;

    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        if (map[j][k] == 1)
        {
          int temp = 0;
          for (int l = 0; l < r; l++)
          {
            init();
            init2();
            int res = bfs(j, k, rare[l][0], rare[l][1]);
            // cout << "res = " << res << endl;
            temp = max(temp, res);
          }

          ans = min(temp, ans);
        }
      }
    }
    cout << "#" << m - t << " " << ans << endl;
  }
  return 0;
}