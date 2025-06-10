#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void LevelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl; // End of level
            if (!q.empty())
                q.push(NULL); // Push marker for next level
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void preorder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data); // Fix: No shadowing of root
    }

    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data); // Fix: Capture returned root
        cin >> data;
    }
}

Node *minValue(Node *root)
{
    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node *maxValue(Node *root)
{
    Node *temp = root;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node *deleteNode(Node *&root, int val)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {

        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child (left NULL)
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 1 child (RIGHT NULL)
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // 2 child of the node
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini); // isko call krne se jo min val ko root banaya wo orignal position se delete ho jayega
            return root;
        }
    }

    else if (root->data < val)
    {
        root->right = deleteNode(root->right, val);
    }

    else
    {
        root->left = deleteNode(root->left, val);
    }

    return root;
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create tree: " << endl;
    takeInput(root);

    cout << "Printing the BST: " << endl;
    LevelOrderTraversal(root);

    cout << endl
         << "Printing Inorder : " << endl;
    inorder(root);

    cout << endl
         << "Printing Preorder : " << endl;
    preorder(root);

    cout << endl
         << "Printing Postorder : " << endl;
    postorder(root);

    cout << endl
         << "min value : " << minValue(root)->data << endl;
    cout << endl
         << "max value : " << maxValue(root)->data << endl;

    root = deleteNode(root, 7);
    cout << "Printing the BST: " << endl;
    LevelOrderTraversal(root);

    return 0;
}

// 10 8 21 7 27 5 4 3 -1