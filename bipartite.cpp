#include <iostream>
using namespace std;

int n;
int map[100][100] = {0};

int isBipartite(int node, int color[])
{
  int flag = 1;
  for (int j = 0; j < n; j++)
  {
    if (map[node][j] == 1)
    {
      if (color[j] == -1)
      {
        color[j] = 1 - color[node];
        flag = flag & isBipartite(j, color);
      }
      else if (color[j] == color[node])
      {
        return 0;
      }
    }
  }
  return flag;
}

int main()
{
  cin >> n;
  int color[n];

  for (int i = 0; i < n; i++)
  {
    color[i] = -1;
    for (int j = 0; j < n; j++)
    {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (color[i] == -1)
    {
      color[i] = 0;
      if (!isBipartite(i, color))
      {
        cout << "-1";
        return 0;
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    cout << color[i] << " ";
    if (color[i] == 1)
    {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}