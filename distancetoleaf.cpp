#include <iostream>
using namespace std;

int n;

struct node
{
  int data;
  node *left;
  node *right;
};

node *newNode(int x)
{
  node *newnode = new node();
  newnode->data = x;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

node *insert(node *head, int arr[], int i)
{
  if (i < n && arr[i] != 0)
  {
    node *temp = newNode(arr[i]);
    head = temp;
    head->left = insert(head->left, arr, 2 * i + 1);
    head->right = insert(head->right, arr, 2 * i + 2);
  }
  if (arr[i] == 0)
  {
    head = NULL;
  }

  return head;
}

node *search(node *head, int x)
{
  if (head == NULL)
  {
    return NULL;
  }
  if (head->data == x)
  {
    return head;
  }
  node *l, *r;
  if (head->left)
  {
    l = search(head->left, x);
    if (l != NULL)
    {
      return l;
    }
  }
  if (head->right)
  {
    r = search(head->right, x);
    if (r != NULL)
    {
      return r;
    }
  }
  return NULL;
}

int searchnode(node *head)
{
  if (head == NULL)
  {
    return 0;
  }

  if (head->left == NULL && head->right == NULL)
  {
    return 1;
  }
  if (!head->left)
  {
    return searchnode(head->right) + 1;
  }
  if (!head->right)
  {
    return searchnode(head->left) + 1;
  }

  int l = searchnode(head->left);
  int r = searchnode(head->right);
  return 1 + min(l, r);
}

int searchparent(node *head, node *x, int &mindist)
{
  if (head == NULL)
    return -1;
  if (head == x)
    return 0;

  int h;
  int l = searchparent(head->left, x, mindist);
  if (l != -1)
  {
    h = searchnode(head->right);
    cout << h << " hr " << head->right->data << endl;
    mindist = min(mindist, h + l + 1);
    return h + l + 1;
  }
  int r = searchparent(head->right, x, mindist);
  if (r != -1)
  {
    h = searchnode(head->left);
    cout << h << " hl " << head->left->data << endl;
    mindist = min(mindist, h + r + 1);
    return h + r + 1;
  }
  return -1;
}

int solve(node *head, int x)
{
  int mindist = INT_MAX;
  node *xloc = search(head, x);
  int dist = searchnode(xloc);
  searchparent(head, xloc, mindist);
  cout << dist << " " << mindist << endl;
  mindist = min(dist, mindist);
  return mindist;
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

int main()
{
  int t, x;
  cin >> t;
  while (t--)
  {
    cin >> n;
    int arr[n];
    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    head = insert(head, arr, 0);
    cin >> x;
    inorder(head);
    cout << endl;
    cout << solve(head, x);
  }
  return 0;
}