#include <iostream>
using namespace std;

struct node
{
    int x;
    int y;
    int l;
};

node q[10000];
int front, rear;

int map[50][50];
int vis[50][50] = {0};
int t, n, m, ans, srcx, srcy, len;

void init()
{
    front = 0;
    rear = 0;
}

bool isempty()
{
    return rear == front;
}

void push(int x, int y, int l)
{
    q[rear].x = x;
    q[rear].y = y;
    q[rear].l = l;
    rear++;
}

node pop()
{
    // if (!isempty())
    // {
    return q[front++];
    // }
    // exit(EXIT_FAILURE);
}

bool isvalid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]);
}

int solve()
{
    if (map[srcx][srcy] == 0)
    {
        return -1;
    }
    ans = 1;
    vis[srcx][srcy] = 1;
    push(srcx, srcy, 1);
    while (!isempty())
    {
        node newnode = pop();
        int x = newnode.x;
        int y = newnode.y;
        int l = newnode.l;

        if (isvalid(x - 1, y) && l < len &&
            (map[x - 1][y] == 1 || map[x - 1][y] == 2 || map[x - 1][y] == 5 || map[x - 1][y] == 6) &&
            (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 4 || map[x][y] == 7))
        {
            ans++;
            vis[x - 1][y] = 1;
            push(x - 1, y, l + 1);
        }

        if (isvalid(x + 1, y) && l < len &&
            (map[x + 1][y] == 1 || map[x + 1][y] == 2 || map[x + 1][y] == 4 || map[x + 1][y] == 7) &&
            (map[x][y] == 1 || map[x][y] == 2 || map[x][y] == 5 || map[x][y] == 6))
        {
            ans++;
            vis[x + 1][y] = 1;
            push(x + 1, y, l + 1);
        }

        if (isvalid(x, y - 1) && l < len &&
            (map[x][y - 1] == 1 || map[x][y - 1] == 3 || map[x][y - 1] == 4 || map[x][y - 1] == 5) &&
            (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 6 || map[x][y] == 7))
        {
            ans++;
            vis[x][y - 1] = 1;
            push(x, y - 1, l + 1);
        }

        if (isvalid(x, y + 1) && l < len &&
            (map[x][y + 1] == 1 || map[x][y + 1] == 3 || map[x][y + 1] == 6 || map[x][y + 1] == 7) &&
            (map[x][y] == 1 || map[x][y] == 3 || map[x][y] == 4 || map[x][y] == 5))
        {
            ans++;
            vis[x][y + 1] = 1;
            push(x, y + 1, l + 1);
        }
    }
    return ans;
}

int main()
{
    cin >> t;
    int res[t];
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m >> srcx >> srcy >> len;
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> map[j][k];
                vis[j][k] = 0;
            }
        }
        init();
        res[i] = solve();
    }

    for (int i = 0; i < t; i++)
    {
        cout << "#" << i + 1 << " " << res[i] << endl;
    }

    return 0;
}