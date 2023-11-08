
#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() {
        root = nullptr;
    }

    // Function to insert a value into the BST
    void Insert(int value) {
        root = InsertRecursive(root, value);
    }

    // Function to delete a value from the BST
    void Delete(int value) {
        root = DeleteRecursive(root, value);
    }

    // Function to search for a value in the BST
    bool Search(int value) {
        return SearchRecursive(root, value);
    }

    // Function to print the BST in in-order traversal
    void InOrderTraversal() {
        InOrderRecursive(root);
        cout << endl;
    }

    // Function to print the BST in pre-order traversal
    void PreOrderTraversal() {
        PreOrderRecursive(root);
        cout << endl;
    }

    // Function to print the BST in post-order traversal
    void PostOrderTraversal() {
        PostOrderRecursive(root);
        cout << endl;
    }

    // Function to print the BST in level-order traversal
    void LevelOrderTraversal() {
        LevelOrder();
        cout << endl;
    }

private:
    TreeNode* root;

    // Recursive helper function for inserting a value
    TreeNode* InsertRecursive(TreeNode* node, int value) {
        if (node == nullptr)
            return new TreeNode(value);
        
        if (value < node->value)
            node->left = InsertRecursive(node->left, value);
        else if (value > node->value)
            node->right = InsertRecursive(node->right, value);
        
        return node;
    }

    // Recursive helper function for deleting a value
    TreeNode* DeleteRecursive(TreeNode* node, int value) {
        if (node == nullptr)
            return node;

        if (value < node->value)
            node->left = DeleteRecursive(node->left, value);
        else if (value > node->value)
            node->right = DeleteRecursive(node->right, value);
        else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = FindMin(node->right);
            node->value = temp->value;
            node->right = DeleteRecursive(node->right, temp->value);
        }
        return node;
    }

    // Helper function to find the minimum value in the BST
    TreeNode* FindMin(TreeNode* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // Recursive helper function for searching a value
    bool SearchRecursive(TreeNode* node, int value) {
        if (node == nullptr)
            return false;

        if (value == node->value)
            return true;
        else if (value < node->value)
            return SearchRecursive(node->left, value);
        else
            return SearchRecursive(node->right, value);
    }

    // Recursive helper function for in-order traversal
    void InOrderRecursive(TreeNode* node) {
        if (node == nullptr)
            return;

        InOrderRecursive(node->left);
        cout << node->value << " ";
        InOrderRecursive(node->right);
    }

    // Recursive helper function for pre-order traversal
    void PreOrderRecursive(TreeNode* node) {
        if (node == nullptr)
            return;

        cout << node->value << " ";
        PreOrderRecursive(node->left);
        PreOrderRecursive(node->right);
    }

    // Recursive helper function for post-order traversal
    void PostOrderRecursive(TreeNode* node) {
        if (node == nullptr)
            return;

        PostOrderRecursive(node->left);
        PostOrderRecursive(node->right);
        cout << node->value << " ";
    }

    // Level-order traversal using a queue
    void LevelOrder() {
        if (root == nullptr)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            cout << current->value << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
    }
};

int main() {
    int number_of_queries;
    cin >> number_of_queries;

    BinarySearchTree bst;

    while (number_of_queries--) {
        string command;
        cin >> command;

        if (command == "INSERT") {
            int value;
            cin >> value;
            bst.Insert(value);
        } else if (command == "DELETE") {
            int value;
            cin >> value;
            bst.Delete(value);
        } else if (command == "SEARCH") {
            int value;
            cin >> value;
            bool found = bst.Search(value);
            cout << (found ? "True" : "False") << endl;
        } else if (command == "INORDER") {
            bst.InOrderTraversal();
        } else if (command == "PREORDER") {
            bst.PreOrderTraversal();
        } else if (command == "POSTORDER") {
            bst.PostOrderTraversal();
        } else if (command == "LEVELORDER") {
            bst.LevelOrderTraversal();
        }
    }

    return 0;
}
