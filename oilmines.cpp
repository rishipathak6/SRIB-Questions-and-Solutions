#include <iostream>
using namespace std;

int n, m, ans = 100000;

void finddiff(int comp[])
{
  int maxx = -1, minn = 100000;
  for (int i = 0; i < n; i++)
  {
    cout << comp[i] << " ";
    if (comp[i] > maxx)
    {
      maxx = comp[i];
    }
    if (comp[i] < minn)
    {
      minn = comp[i];
    }
  }
  cout << endl;
  cout << maxx << " " << minn << " ";
  ans = min(ans, maxx - minn);
}

void solve(int curr, int end, int comp[], int oilmines[], int coma, int remo)
{
  if (remo < n - coma)
  {
    return;
  }
  if ((curr + 1) % m == end)
  {
    if (coma == n - 1)
    {
      comp[coma] += oilmines[curr];
      finddiff(comp);
      cout << ans << " t" << endl;
      comp[coma] -= oilmines[curr];
    }
    return;
  }
  if (coma >= n)
  {
    return;
  }

  comp[coma] += oilmines[curr];

  solve((curr + 1) % m, end, comp, oilmines, coma, remo - 1);
  solve((curr + 1) % m, end, comp, oilmines, coma + 1, remo - 1);

  comp[coma] -= oilmines[curr];
  if (comp[coma] > 0)
  {
    solve(curr, end, comp, oilmines, coma + 1, remo);
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    int oilmines[m], comp[n] = {0};
    for (int i = 0; i < m; i++)
    {
      cin >> oilmines[i];
    }
    if (m < n)
    {
      cout << "-1" << endl;
      continue;
    }

    for (int i = 0; i < m; i++)
    {
      solve(i, i, comp, oilmines, 0, m);
    }
    cout << ans << endl;
  }

  return 0;
}