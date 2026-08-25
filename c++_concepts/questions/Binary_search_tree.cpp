#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinarySearchTree 
{
private:
    Node<T>* root;

    Node<T>* insert(Node<T>* currentNode, const T& value) 
    {
        if (currentNode == nullptr) 
        {
            return new Node<T>(value);
        }

        if (value < currentNode->data) 
        {
            currentNode->left = insert(currentNode->left, value);
        } else if (value > currentNode->data) 
        {
            currentNode->right = insert(currentNode->right, value);
        }

        return currentNode; // duplicate values are ignored
    }

    Node<T>* findMin(Node<T>* currentNode)
    {
        while (currentNode->left != nullptr) 
        {
            currentNode = currentNode->left;
        }
        return currentNode;
    }

    Node<T>* remove(Node<T>* currentNode, const T& value) {
        if (currentNode == nullptr) {
            return nullptr;
        }

        if (value < currentNode->data) 
        {
            currentNode->left = remove(currentNode->left, value);
        }
        else if (value > currentNode->data) 
        {
            currentNode->right = remove(currentNode->right, value);
        } 
        else 
        {
            // Node has no children
            if (currentNode->left == nullptr && currentNode->right == nullptr) {
                delete currentNode;
                return nullptr;
            }

            // Node has one child
            if (currentNode->left == nullptr) {
                Node<T>* temp = currentNode->right;
                delete currentNode;
                return temp;
            }

            if (currentNode->right == nullptr) {
                Node<T>* temp = currentNode->left;
                delete currentNode;
                return temp;
            }

            // Node has two children
            Node<T>* successor = findMin(currentNode->right);
            currentNode->data = successor->data;
            currentNode->right = remove(currentNode->right, successor->data);
        }

        return currentNode;
    }

    bool contains(Node<T>* currentNode, const T& value) const 
    {
        if (currentNode == nullptr) {
            return false;
        }

        if (value == currentNode->data) {
            return true;
        }

        if (value < currentNode->data) {
            return contains(currentNode->left, value);
        }

        return contains(currentNode->right, value);
    }

    void destroy(Node<T>* currentNode) 
    {
        if (currentNode == nullptr) {
            return;
        }
        destroy(currentNode->left);
        destroy(currentNode->right);
        delete currentNode;
    }

    size_t size(Node<T>* currentNode) const 
    {
        if (currentNode == nullptr) {
            return 0;
        }

        return 1 + size(currentNode->left) + size(currentNode->right);
    }

    void preorder(Node<T>* currentNode) const 
    {
        if (currentNode == nullptr) {
            return;
        }

        cout << currentNode->data << " ";
        preorder(currentNode->left);
        preorder(currentNode->right);
    }

    void inorder(Node<T>* currentNode) const 
    {
        if (currentNode == nullptr) {
            return;
        }

        inorder(currentNode->left);
        cout << currentNode->data << " ";
        inorder(currentNode->right);
    }

    void postorder(Node<T>* currentNode) const 
    {
        if (currentNode == nullptr) {
            return;
        }

        postorder(currentNode->left);
        postorder(currentNode->right);
        cout << currentNode->data << " ";
    }

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    ~BinarySearchTree()
    {
        destroy(root);
    }

    void insert(const T& value) 
    {
        root = insert(root, value);
    }

    void remove(const T& value) 
    {
        root = remove(root, value);
    }

    bool contains(const T& value) const 
    {
        return contains(root, value);
    }

    bool empty() const 
    {
        return root == nullptr;
    }

    size_t size() const 
    {
        return size(root);
    }

    void preorder() const 
    {
        preorder(root);
    }

    void inorder() const 
    {
        inorder(root);
    }

    void postorder() const
    {
        postorder(root);
    }
};

int main() {
    BinarySearchTree<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder: ";
    tree.inorder();
    cout << '\n';

    cout << "Preorder: ";
    tree.preorder();
    cout << '\n';

    cout << "Postorder: ";
    tree.postorder();
    cout << '\n';

    cout << "Size: " << tree.size() << '\n';
    cout << "Contains 40: " << tree.contains(40) << '\n';

    tree.remove(50);

    cout << "After removing 50: ";
    tree.inorder();
    cout << '\n';

    
}