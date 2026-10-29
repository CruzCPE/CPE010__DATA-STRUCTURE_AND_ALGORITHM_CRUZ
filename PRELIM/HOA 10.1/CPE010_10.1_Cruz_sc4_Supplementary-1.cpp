#include <iostream>
#include <queue>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node* node) {
    if (node == NULL)
        return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node) {
    if (node == NULL)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void postorder(Node* node) {
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->data << " ";

        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}

int main() {
    // build the sample tree
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('F');

    cout << "Preorder:    ";
    preorder(root);

    cout << "\nInorder:     ";
    inorder(root);

    cout << "\nPostorder:   ";
    postorder(root);

    cout << "\nLevel-order: ";
    levelOrder(root);
    cout << endl;

    return 0;
}