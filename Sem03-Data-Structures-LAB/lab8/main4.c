/*
4)Construct a binary tree using array and perform 
i) pre order traversal
ii) inorder traversal
iii) post order traversal
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} Node;

Node *newNode(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node *constructTree(int *arr, int n) {
  if (n == 0) {
    return NULL;
  }

  Node *root = newNode(arr[0]);
  int leftIndex = 1;
  int rightIndex = 2;

  while (leftIndex < n) {
    root->left = constructTree(arr + leftIndex, n - leftIndex);
    leftIndex += 2;

    if (rightIndex < n) {
      root->right = constructTree(arr + rightIndex, n - rightIndex);
      rightIndex += 2;
    }
  }

  return root;
}

void preOrderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }

  printf("%d ", root->data);
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }

  inOrderTraversal(root->left);
  printf("%d ", root->data);
  inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }

  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  printf("%d ", root->data);
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  Node *root = constructTree(arr, n);

  printf("Pre-order traversal: ");
  preOrderTraversal(root);
  printf("\n");

  printf("In-order traversal: ");
  inOrderTraversal(root);
  printf("\n");

  printf("Post-order traversal: ");
  postOrderTraversal(root);
  printf("\n");

  return 0;
}


