#include <iostream>
using namespace std;

void solve(int n, int k, int arr[])
{
  if (k == 0)
  {
    return;
  }

  int len = 0, ans = 0, start, last, mid;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0)
    {
      len++;
    }
    if (arr[i] == 1)
    {
      len = 0;
    }
    if (len >= ans)
    {
      ans = len;
      last = i;
    }
  }
  start = last - ans + 1;
  mid = (start + last) / 2;
  // cout << start << " " << mid << " " << last << endl;
  arr[mid] = 1;
  return solve(n, k - 1, arr);
}

int main()
{
  int t, n, k;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cin >> n >> k;
    int arr[n] = {0};
    solve(n, k, arr);
    for (int j = 0; j < n; j++)
    {
      cout << arr[j] << " ";
    }
    cout << endl;
  }

  return 0;
}