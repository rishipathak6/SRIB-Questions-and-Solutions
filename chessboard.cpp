#include <iostream>
using namespace std;

int n, m, r, c, s, k;
bool vis[100][100] = {false};

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
  front = 0;
  back = 0;
  return;
}

bool isempty()
{
  return front == back;
}

node pop()
{
  return q[front++];
}

void push(int x, int y, int l)
{
  q[back].x = x;
  q[back].y = y;
  q[back].l = l;
  back++;
  return;
}

int dir[8][2] = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}};

bool isvalid(int x, int y)
{
  return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]);
}

int solve()
{
  vis[r][c] = true;
  push(r, c, 0);
  while (!isempty())
  {
    node temp = pop();
    int x = temp.x;
    int y = temp.y;
    int l = temp.l;

    if (x == s && y == k)
    {
      return l;
    }

    for (int i = 0; i < 8; i++)
    {
      int r = x + dir[i][0];
      int c = y + dir[i][1];

      if (isvalid(r, c))
      {
        vis[r][c] = true;
        push(r, c, l + 1);
      }
    }
  }
  return 0;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    cin >> r >> c >> s >> k;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        vis[i][j] = false;
      }
    }
    cout << solve() << endl;
    cout << endl;
  }

  return 0;
}