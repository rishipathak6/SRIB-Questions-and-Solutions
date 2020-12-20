#include <iostream>
using namespace std;

int c, n;

int check(int arr[], int diff)
{
  cout << "diff = " << diff << endl;
  int count = 1, pos = arr[0]; //count = 1 imp
  cout << pos << " p ";
  for (int i = 1; i < n; i++)
  {
    if (arr[i] - pos >= diff)
    {
      pos = arr[i];
      count++;
      cout << arr[i] << " p ";
      if (count == c)
      {
        cout << endl;
        return 1;
      }
    }
  }
  cout << endl;
  return 0;
}

int solve(int arr[])
{
  int start = 0, end = arr[n - 1], mid, max = -1;
  while (start < end)
  {
    mid = (start + end) / 2;
    if (check(arr, mid) == 1)
    {
      if (max < mid)
      {
        max = mid;
        cout << max << " " << start << " " << end << endl;
      }
      start = mid + 1;
    }
    else
    {
      end = mid;
    }
  }
  return max;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> c;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    cout << solve(arr);
  }

  return 0;
}