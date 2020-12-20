#include <iostream>
using namespace std;

int monthnl[12] = {5, 1, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3};
int monthl[12] = {4, 0, 1, 4, 6, 2, 4, 0, 3, 5, 1, 3};

int solve(int year, int month, int date)
{
  int century = year / 100;
  int yearc = year % 100;

  if (century % 4 == 0)
  {
    century = 1;
  }
  else if (century % 4 == 1)
  {
    century = 6;
  }
  else if (century % 4 == 2)
  {
    century = 4;
  }
  else if (century % 4 == 3)
  {
    century = 2;
  }

  if (yearc % 4 == 0 && yearc % 400 != 0)
  {
    month = monthl[month - 1];
  }
  else
  {
    month = monthnl[month - 1];
  }

  yearc = (yearc + yearc / 4) % 7;

  int ans = century + yearc + month + date;
  return ans % 7;
}

int main()
{
  int year, month, date;
  cin >> date >> month >> year;
  cout << solve(year, month, date);
  return 0;
}