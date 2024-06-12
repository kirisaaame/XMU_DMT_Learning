//下面是根据copilot生成的AVL树和B树的代码
#include<iostream>
using namespace std;
//AVL树
struct Node {
    int key;
    int height;
    Node* left;
    Node* right;
};
class AVLTree
{
public:
// AVL树节点的定义


// 获取节点的高度
static int getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// 获取节点的平衡因子
static int getBalanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// 更新节点的高度
static void updateHeight(Node* node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = max(leftHeight, rightHeight) + 1;
}

// 右旋操作
static Node* rightRotate(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

// 左旋操作
static Node* leftRotate(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

// 插入节点
static Node* insertNode(Node* root, int key) {
    if (root == nullptr) {
        Node* newNode = new Node;
        newNode->key = key;
        newNode->height = 1;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);
    else
        return root;  // 如果树中已经存在相同的键，则不进行插入
    updateHeight(root);
    int balanceFactor = getBalanceFactor(root);
    // 左子树高度大于右子树，需要进行右旋操作
    if (balanceFactor > 1 && key < root->left->key)
        return rightRotate(root);
    // 右子树高度大于左子树，需要进行左旋操作
    if (balanceFactor < -1 && key > root->right->key)
        return leftRotate(root);
    // 左子树高度大于右子树，需要进行左右旋操作
    if (balanceFactor > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // 右子树高度大于左子树，需要进行右左旋操作
    if (balanceFactor < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

// 中序遍历打印树节点
static void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}
};

// B-树节点的定义
class BTreeNode {
public:
    int* keys;  // 存储键的数组
    int t;      // 最小度数（每个节点最少包含 t-1 个键）
    BTreeNode** children;  // 存储子节点的指针数组
    int numKeys;  // 当前节点包含的键的数量
    bool leaf;   // 是否为叶子节点

public:
    BTreeNode(int t, bool leaf) {
        this->t = t;
        this->leaf = leaf;

        keys = new int[2 * t - 1];
        children = new BTreeNode*[2 * t];
        numKeys = 0;
    }

    // 插入键到当前节点
    void insertNonFull(int key) {
        int i = numKeys - 1;

        if (leaf) {
            // 在叶子节点中找到合适的位置插入键
            while (i >= 0 && keys[i] > key) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = key;
            numKeys++;
        }
        else {
            // 在非叶子节点中找到合适的子节点插入键
            while (i >= 0 && keys[i] > key)
                i--;

            if (children[i + 1]->numKeys == 2 * t - 1) {
                // 如果子节点已满，则先分裂子节点
                splitChild(i + 1, children[i + 1]);

                if (keys[i + 1] < key)
                    i++;
            }
            children[i + 1]->insertNonFull(key);
        }
    }
    // 分裂子节点
    void splitChild(int childIndex, BTreeNode* child) {
        BTreeNode* newNode = new BTreeNode(child->t, child->leaf);
        newNode->numKeys = t - 1;

        for (int j = 0; j < t - 1; j++)
            newNode->keys[j] = child->keys[j + t];

        if (!child->leaf) {
            for (int j = 0; j < t; j++)
                newNode->children[j] = child->children[j + t];
        }

        child->numKeys = t - 1;

        for (int j = numKeys; j >= childIndex + 1; j--)
            children[j + 1] = children[j];

        children[childIndex + 1] = newNode;

        for (int j = numKeys - 1; j >= childIndex; j--)
            keys[j + 1] = keys[j];

        keys[childIndex] = child->keys[t - 1];
        numKeys++;
    }

    // 中序遍历打印树节点
    void inorderTraversal() {
        int i;
        for (i = 0; i < numKeys; i++) {
            if (!leaf)
                children[i]->inorderTraversal();
            cout << " " << keys[i];
        }

        if (!leaf)
            children[i]->inorderTraversal();
    }
};

// B-树的定义
class BTree {
    BTreeNode* root;  // 根节点
    int t;            // 最小度数

public:
    BTree(int t) {
        this->t = t;
        root = nullptr;
    }

    // 插入键到B-树
    void insert(int key) {
        if (root == nullptr) {
            // 如果树为空，则创建一个新的根节点
            root = new BTreeNode(t, true);
            root->keys[0] = key;
            root->numKeys = 1;
        }
        else {
            if (root->numKeys == 2 * t - 1) {
                // 如果根节点已满，则先分裂根节点
                BTreeNode* newNode = new BTreeNode(t, false);
                newNode->children[0] = root;
                newNode->splitChild(0, root);

                int i = 0;
                if (newNode->keys[0] < key)
                    i++;
                newNode->children[i]->insertNonFull(key);

                root = newNode;
            }
            else {
                // 否则直接插入键到根节点
                root->insertNonFull(key);
            }
        }
    }

    // 中序遍历打印B-树节点
    void inorderTraversal() {
        if (root != nullptr)
            root->inorderTraversal();
    }
};

int main() {
    BTree tree(3);

    // 插入键示例
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);

    // 中序遍历打印B-树节点
    tree.inorderTraversal();

    return 0;
}

int main() {
    AVLTree tree;
    Node* root = nullptr ;


    // 插入节点示例
    root = tree.insertNode(root, 10);
    root = tree.insertNode(root, 20);
    root = tree.insertNode(root, 30);
    root = tree.insertNode(root, 40);
    root = tree.insertNode(root, 50);
    root = tree.insertNode(root, 25);

    // 中序遍历打印树节点
    tree.inorderTraversal(root);
    BTree btree(3);

    // 插入键示例
    btree.insert(10);
    btree.insert(20);
    btree.insert(5);
    btree.insert(6);
    btree.insert(12);
    btree.insert(30);

    // 中序遍历打印B-树节点
    btree.inorderTraversal();

    return 0;
    return 0;
}