#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
};

void inorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    inorder(node->left);
    std::cout << node->value << ' ';
    inorder(node->right);
}

int main() {
    TreeNode root{2, nullptr, nullptr};
    TreeNode left{1, nullptr, nullptr};
    TreeNode right{3, nullptr, nullptr};

    root.left = &left;
    root.right = &right;

    std::cout << "Inorder traversal: ";
    inorder(&root);
    std::cout << '\n';

    return 0;
}
