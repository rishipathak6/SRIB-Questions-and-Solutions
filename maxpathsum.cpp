#include <iostream>
using namespace std;

int n, m;
int mat[100][100];
int solve()
{
  cout << n << " " << m << " " << mat[0][0] << endl;
  for (int i = 1; i < n; i++)
  {
    mat[i][0] += mat[i - 1][0];
    cout << i << " "
         << "0"
         << " " << mat[i][0] << endl;
  }
  for (int i = 1; i < m; i++)
  {
    mat[0][i] += mat[0][i - 1];
    cout << 0 << " " << i << " " << mat[0][i] << endl;
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < m; j++)
    {
      mat[i][j] += max(mat[i - 1][j], mat[i][j - 1]);
      cout << i << " " << j << " " << mat[i][j] << endl;
    }
  }
  return mat[n - 1][m - 1];
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> m;
    // int mat[n][m];
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> mat[i][j];
      }
    }
    cout << "#" << t + 1 << " " << solve() << endl;
  }

  return 0;
}