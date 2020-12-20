#include <iostream>
using namespace std;

int solve(int n)
{
  int ans = 1, j = 2 * n, k = 1;
  for (int i = 0; i < n; i++)
  {
    ans *= (j - i);
    ans /= (k + i);
    // cout << ans << endl;
  }
  return ans / (n + 1);
}

int main()
{
  int t, n, a;
  cin >> t;
  while (t--)
  {
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      cin >> a;
    }
    cout << "#" << t + 1 << " " << solve(n) << endl;
  }

  return 0;
}