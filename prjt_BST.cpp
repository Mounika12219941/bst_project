#include <iostream>
using namespace std;

// Defining the structure of a Node in the Binary Search Tree
struct Node {
    int data;       // The data stored in the node
    Node* left;     // Pointer to the left child
    Node* right;    // Pointer to the right child

    // Constructor to initialize a node with a given value
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

// Defining the BST class
class BST {
public:
    Node* root;     

    // Constructor to initialize an empty BST
    BST() : root(NULL) {}

    // Public method to insert a value into the BST
    void insert(int value) {
        root = insertRec(root, value);
    }

    // Public method to search for a value in the BST
    bool search(int value) {
        return searchRec(root, value);
    }

    // Public method to delete a node with a given value from the BST
    void deleteNode(int value) {
        root = deleteRec(root, value);
    }

    // Public method for in-order traversal of the BST
    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    // Public method for pre-order traversal of the BST
    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    // Public method for post-order traversal of the BST
    void postorder() {
        postorderRec(root);
        cout << endl;
    }

private:
    
    Node* insertRec(Node* node, int value) {
        // If the node is NULL, create a new node with the value
        if (node == NULL) {
            return new Node(value);
        }

        // If the value is less than the node's data, go to the left subtree
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } 
        // If the value is greater than the node's data, go to the right subtree
        else if (value > node->data) {
            node->right = insertRec(node->right, value);
        }

        
        return node;
    }

    
    bool searchRec(Node* node, int value) {
        // If the node is NULL, the value is not found
        if (node == NULL) {
            return false;
        }

        
        if (value == node->data) {
            return true;
        }

        // If the value is less than the node's data, search in the left subtree
        if (value < node->data) {
            return searchRec(node->left, value);
        } 
        // If the value is greater than the node's data, search in the right subtree
        else {
            return searchRec(node->right, value);
        }
    }

    
    Node* deleteRec(Node* root, int key) {
        // If the root is NULL, return NULL
        if (root == NULL) return root;

        // If the key is less than the root's data, go to the left subtree
        if (key < root->data) {
            root->left = deleteRec(root->left, key);
        } 
        // If the key is greater than the root's data, go to the right subtree
        else if (key > root->data) {
            root->right = deleteRec(root->right, key);
        } 
        // If the key matches the root's data, this is the node to be deleted
        else {
            // Node with only one child or no child
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteRec(root->right, temp->data);
        }
        return root;
    }

    // Private helper method to find the node with the minimum value in a subtree
    Node* minValueNode(Node* node) {
        Node* current = node;

        // Loop down to find the leftmost leaf
        while (current && current->left != NULL)
            current = current->left;

        return current;
    }

    // Private helper method for recursive in-order traversal
    void inorderRec(Node* root) {
        if (root != NULL) {
            inorderRec(root->left);      // Traverse the left subtree
            cout << root->data << " ";   // Visit the node
            inorderRec(root->right);     // Traverse the right subtree
        }
    }

    // Private helper method for recursive pre-order traversal
    void preorderRec(Node* root) {
        if (root != NULL) {
            cout << root->data << " ";   // Visit the node
            preorderRec(root->left);     // Traverse the left subtree
            preorderRec(root->right);    // Traverse the right subtree
        }
    }

    // Private helper method for recursive post-order traversal
    void postorderRec(Node* root) {
        if (root != NULL) {
            postorderRec(root->left);    // Traverse the left subtree
            postorderRec(root->right);   // Traverse the right subtree
            cout << root->data << " ";   // Visit the node
        }
    }
};

// Main function with a menu-driven interface for BST operations
int main() {
    BST tree;
    int choice, value;
    
    do {
        cout << "\nBinary Search Tree Operations Menu\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2:
            cout << "Enter value to search: ";
            cin >> value;
            if (tree.search(value)) {
                cout << value << " found in the tree.\n";
            } else {
                cout << value << " not found in the tree.\n";
            }
            break;
        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            tree.deleteNode(value);
            break;
        case 4:
            cout << "Inorder traversal: ";
            tree.inorder();
            break;
        case 5:
            cout << "Preorder traversal: ";
            tree.preorder();
            break;
        case 6:
            cout << "Postorder traversal: ";
            tree.postorder();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

