#include <iostream>
using namespace std;

struct node
{
  int data;
  node *left;
  node *right;
};

node *newnode(int x)
{
  node *newnode = new node;
  newnode->data = x;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

node *insert(node *head, int x)
{
  if (head == NULL)
  {
    return newnode(x);
  }
  else if (x < head->data)
  {
    head->left = insert(head->left, x);
  }
  else
  {
    head->right = insert(head->right, x);
  }
  return head;
}

int sumtree(node *head)
{
  if (head == NULL)
  {
    return 0;
  }

  int oldval = head->data;
  head->data = sumtree(head->left) + sumtree(head->right);
  return head->data + oldval;
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
  int t, n, x;
  cin >> t;
  while (t--)
  {
    cin >> n;
    node *head = NULL;
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      head = insert(head, x);
    }
    inorder(head);
    cout << endl;
    sumtree(head);
    inorder(head);
    cout << endl;
  }

  return 0;
}