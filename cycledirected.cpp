#include <iostream>
using namespace std;

int n;
int graph[100][100] = {0};
bool vis[100] = {false};
bool recstack[100] = {false};

void addedge(int u, int v)
{
  graph[u][v] = 1;
}

bool iscyclic(int u, bool vis[], bool recstack[])
{
  if (vis[u] == false)
  {
    vis[u] = true;
    recstack[u] = true;
    for (int v = 0; v < n; v++)
    {
      if (graph[u][v] == 1)
      {
        if (!vis[v] && iscyclic(v, vis, recstack))
        {
          return true;
        }
        else if (recstack[v])
        {
          return true;
        }
      }
    }
  }
  recstack[u] = false;
  return false;
}

int main()
{
  int t, e, u, v;
  cin >> t;
  while (t--)
  {
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
      cin >> u >> v;
      addedge(u, v);
    }
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
      if (iscyclic(i, vis, recstack))
      {
        flag = true;
        cout << i << " cyclic" << endl;
      }
    }
    if (flag == false)
    {
      cout << "acyclic";
    }
  }

  return 0;
}