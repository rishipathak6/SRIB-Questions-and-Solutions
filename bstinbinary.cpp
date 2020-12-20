#include <iostream>
using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
};

struct info
{
  int size;
  int min;
  int max;
  int ans;
  bool isbst;
};

node *newnode(int x)
{
  node *newnode = new node();
  newnode->data = x;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

node *insert(node *head, int arr[], int i, int n)
{
  if (i < n)
  {
    node *temp = newnode(arr[i]);
    head = temp;
    head->left = insert(head->left, arr, 2 * i + 1, n);
    head->right = insert(head->right, arr, 2 * i + 2, n);
  }

  return head;
}

void inorder(node *head)
{
  if (head == NULL)
  {
    return;
  }
  inorder(head->left);
  cout << head->data << " ";
  inorder(head->right);
}

info findbst(node *head)
{
  if (head == NULL)
  {
    info temp;
    temp.ans = 0;
    temp.isbst = true;
    temp.max = INT_MIN;
    temp.min = INT_MAX;
    temp.size = 0;
    return temp;
  }
  if (head->left == NULL && head->right == NULL)
  {
    info temp;
    temp.ans = 1;
    temp.isbst = true;
    temp.max = head->data;
    temp.min = head->data;
    temp.size = 1;
    return temp;
  }

  info l = findbst(head->left);
  info r = findbst(head->right);

  info res;
  res.size = 1 + l.size + r.size;
  if (l.isbst && r.isbst && l.max < head->data && r.min > head->data)
  {
    res.min = min(l.min, min(r.min, head->data));
    res.max = max(r.max, max(l.max, head->data));
    res.ans = res.size;
    res.isbst = true;
    // cout << head->data << " " << res.ans << endl;
    return res;
  }
  res.ans = max(l.ans, r.ans);
  res.isbst = false;
  return res;
}

int main()
{
  int t, n;
  cin >> t;
  while (t--)
  {
    cin >> n;
    int nodearr[n];
    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
      cin >> nodearr[i];
    }
    head = insert(head, nodearr, 0, n);
    inorder(head);
    cout << endl;
    info res = findbst(head);
    cout << res.ans;
  }

  return 0;
}