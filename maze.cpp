#include <iostream>
using namespace std;

int n;
int maze[10][10] = {0};
int matans[10][10] = {0};

bool isvalid(int x, int y)
{
  return ((maze[x][y] == 0 || maze[x][y] == 2) && x >= 0 && x < n && y >= 0 && y < n);
}

int ans = -1;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void solve(int r, int c, int jewel)
{
  if (r == n - 1 && c == n - 1)
  {
    if (jewel > ans)
    {
      ans = jewel;
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          matans[i][j] = maze[i][j];
        }
      }
    }
  }

  for (int i = 0; i < 4; i++)
  {
    int x = r + dir[i][0];
    int y = c + dir[i][1];

    if (isvalid(x, y))
    {
      int check;
      if (maze[x][y] == 2)
      {
        check = 1;
      }
      else if (maze[x][y] == 0)
      {
        check = 0;
      }
      maze[x][y] = 3;
      solve(x, y, jewel + check);
      if (check == 1)
      {
        maze[x][y] = 2;
      }
      else
      {
        maze[x][y] = 0;
      }
    }
  }
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
        cin >> maze[i][j];
        // matans[i][j] = 0;
      }
    }
    ans = -1;
    maze[0][0] = 3;
    solve(0, 0, 0);
    cout << endl;
    cout << ans << endl;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cout << matans[i][j] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}