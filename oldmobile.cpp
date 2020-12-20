#include <iostream>
using namespace std;

struct node
{
  int data;
  int touch;
};

node queue[1000];
int vis[10000];
int digit[10];
int op[4];

int front, back, n, o, lim, num;

void init()
{
  front = back = 0;
}

void push(int data, int touch)
{
  queue[back].data = data;
  queue[back].touch = touch;
  back = (back + 1) % 1000;
  return;
}

node pop()
{
  node temp = queue[front];
  front = (front + 1) % 1000;
  return temp;
}

bool isempty()
{
  return front == back;
}

int solve()
{
  node ans;
  while (!isempty())
  {
    node temp = pop();
    int data = temp.data;
    int touch = temp.touch;

    if (touch > lim)
    {
      continue;
    }

    if (data == num)
    {
      ans.data = data;
      ans.touch = touch;
      break;
    }

    if (!vis[data])
    {
      for (int i = 0; i < n; i++)
      {
        push(10 * data + digit[i], touch + 1);
      }

      for (int i = 0; i < o; i++)
      {
        for (int j = 0; j < 1000; j++)
        {
          if (vis[j])
          {

            if (op[i] == 1)
            {
              cout << data + j << endl;
              push(data + j, touch + 3);
            }
            else if (op[i] == 2 && data - j >= 0)
            {
              cout << data - j << endl;
              push(data - j, touch + 3);
            }
            else if (op[i] == 3)
            {
              cout << data * j << endl;
              push(data * j, touch + 3);
            }
            else if (op[i] == 4 && j != 0)
            {
              cout << data / j << endl;
              push(data / j, touch + 3);
            }
          }
        }
      }
      vis[data] = true;
    }
  }
  return ans.touch;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    cin >> n >> o >> lim;
    int x;
    init();
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      digit[i] = x;
      push(x, 1);
    }
    for (int i = 0; i < o; i++)
    {
      cin >> x;
      op[i] = x;
    }
    cin >> num;
    cout << solve();
  }

  return 0;
}