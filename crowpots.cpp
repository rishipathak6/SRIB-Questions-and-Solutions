#include <iostream>
using namespace std;

int n, k;
int arr[1000];
int dp[1000][1000];

int ans = 100000;

void merge(int arr[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;
  int fh[n1], sh[n2];

  for (i = 0; i < n1; i++)
  {
    fh[i] = arr[l + i];
  }
  for (j = 0; j < n2; j++)
  {
    sh[j] = arr[m + 1 + j];
  }

  i = 0, j = 0, k = l;

  while (i < n1 && j < n2)
  {
    if (fh[i] <= sh[j])
    {
      arr[k] = fh[i];
      i++;
    }
    else
    {
      arr[k] = sh[j];
      j++;
    }
    k++;
  }
  while (i < n1)
  {
    arr[k] = fh[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    arr[k] = sh[j];
    j++;
    k++;
  }
}

void mergesort(int arr[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int solve()
{
  for (int i = 1; i <= n; i++)
  {
    dp[i][1] = (n - i + 1) * arr[i];
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 2; j <= k; j++)
    {
      for (int p = i + 1; p <= n; p++)
      {
        dp[i][j] = min(dp[i][j], dp[p][j - 1] + (p - i) * arr[i]);
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    ans = min(ans, dp[i][k]);
  }
  return ans;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
      cin >> arr[i];
    }

    mergesort(arr, 1, n);

    for (int i = 0; i < 1000; i++)
    {
      for (int j = 0; j < 1000; j++)
      {
        dp[i][j] = 100000;
      }
    }
    cout << solve() << endl;
  }

  return 0;
}