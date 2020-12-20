#include <iostream>
using namespace std;

int n;
int graph[100][100] = {0};
bool vis[100] = {false};

void addedge(int u, int v)
{
  graph[u][v] = 1;
  graph[v][u] = 1;
  return;
}

bool iscyclic(int u, int parent)
{
  if (!vis[u])
  {
    // cout << u << " p " << parent << endl;
    vis[u] = true;
    for (int v = 0; v < n; v++)
    {
      // cout << u << " o " << v << endl;
      if (graph[u][v] == 1)
      {
        // cout << u << " c " << v << endl;
        if (!vis[v] && iscyclic(v, u))
        {
          return true;
        }
        else if (v != parent)
        {
          return true;
        }
      }
    }
  }
  return false;
}

int main()
{
  int t, e, u, v;
  cin >> t;
  while (t--)
  {
    cin >> n >> e;
    for (int i = 0; i < n; i++)
    {
      vis[i] = false;
      for (int j = 0; j < n; j++)
      {
        graph[i][j] = 0;
      }
    }

    for (int i = 0; i < e; i++)
    {
      cin >> u >> v;
      addedge(u, v);
    }

    bool flag = false;
    for (int i = 0; i < n; i++)
    {
      if (iscyclic(i, -1))
      {
        flag = true;
        cout << i << " cyclic" << endl;
        return 0;
      }
    }
    if (flag == false)
    {
      cout << "acyclic";
    }
  }

  return 0;
}