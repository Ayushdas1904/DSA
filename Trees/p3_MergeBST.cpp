#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
// Node* buildTree(string str) {
//     // Corner Case
//     if (str.length() == 0 || str[0] == 'N')
//         return NULL;

//     vector<string> ip;

//     istringstream iss(str);
//     for (string str; iss >> str;)
//         ip.push_back(str);

//     // Create the root of the tree
//     Node* root = new Node(stoi(ip[0]));

//     // Push the root to the queue
//     queue<Node*> queue;
//     queue.push(root);

//     // Starting from the second element
//     int i = 1;
//     while (!queue.empty() && i < ip.size()) {

//         // Get and remove the front of the queue
//         Node* currNode = queue.front();
//         queue.pop();

//         // Get the current node's value from the string
//         string currVal = ip[i];

//         // If the left child is not null
//         if (currVal != "N") {

//             // Create the left child for the current node
//             currNode->left = new Node(stoi(currVal));

//             // Push it to the queue
//             queue.push(currNode->left);
//         }

//         // For the right child
//         i++;
//         if (i >= ip.size())
//             break;
//         currVal = ip[i];

//         // If the right child is not null
//         if (currVal != "N") {

//             // Create the right child for the current node
//             currNode->right = new Node(stoi(currVal));

//             // Push it to the queue
//             queue.push(currNode->right);
//         }
//         i++;
//     }

//     return root;
// }

// } Driver Code Ends

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    // void merge(vector<int> in1, vector<int> in2, vector<int> &in3){
    //     int i =0, j = 0;
    //     while(i < in1.size() && j < in2.size()){
    //         if(in1[i] < in2[j]){
    //             in3.push_back(in1[i]);
    //             i++;
    //         }
    //         else{
    //             in3.push_back(in2[j]);
    //             j++;
    //         }
    //     }

    //     while(i < in1.size()){
    //         in3.push_back(in1[i]);
    //         i++;
    //     }

    //     while(j < in2.size()){
    //         in3.push_back(in2[j]);
    //         j++;
    //     }
    // }
    // void inorder(Node* root, vector<int> &in){
    //     if(!root) return;

    //     inorder(root->left, in);
    //     in.push_back(root->data);
    //     inorder(root->right, in);
    // }

    // Node* createBST(vector<int> in, int &s, int &e){
    //     if(s > e) return NULL;

    //     int mid = (s+e)/2;
    //     Node* root = new Node(in[mid]);
    //     root->left = createBST(in, s, mid-1);
    //     root->right = createBST(in, mid+1, e);

    //     return root;
    // }

    void BSTtoDLL(Node *root, Node *head)
    {
        if (!root)
            return;

        BSTtoDLL(root->right, head);

        root->right = head;

        if (head != NULL)
        {
            head->left = root;
        }

        head = root;

        BSTtoDLL(root->left, head);
    }

    Node *mergeDLL(Node *head1, Node *head2)
    {
        Node *head = NULL;
        Node *tail = NULL;

        while (head1 != NULL && head2 != NULL)
        {
            if (head1->data < head2->data)
            {
                if (head == NULL)
                {
                    head = head1;
                    tail = head1;
                    head1 = head1->right // next iteration
                }
                else
                {
                    tail->right = head1;
                    head1->left = tail;
                    tail = head1;
                    head1 = head1->right; // next iteration
                }
            }

            else
            {
                if (head == NULL)
                {
                    head = head2;
                    tail = head2;
                    head2 = head2->right // next iteration
                }
                else
                {
                    tail->right = head2;
                    head2->left = tail;
                    tail = head2;
                    head2 = head2->right; // next iteration
                }
            }
        }

        while (head1 != NULL)
        {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }

        while (head2 != NULL)
        {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }

        return head;
    }

    int countLL(Node *head)
    {
        Node *temp head;
        int cnt = 0;
        while (temp != NULL)
        {
            cnt++;
            temp = temp->right;
        }
        return cnt;
    }

    void DLLtoBST(Node *&head, int n)
    {
        if (n <= 0 || head == NULL)
        {
            return NULL;
        }

        Node *left = DLLtoBST(head, n / 2);

        Node *root = head;
        root->left = left;

        head = head->right;
        root->right = DLLtoBST(head, n - n / 2 - 1);

        return root;
    }

    vector<int> merge(Node *root1, Node *root2)
    {
        // converting BST to Linked List
        Node *head1 = NULL;
        Node *head2 = NULL;

        BSTtoDLL(root1, head1);
        BSTtoDLL(root2, head2);

        // merging two DLL
        Node *head = mergeDLL(head1, head2);

        // converting DLL to BST
        DLLtoBST(head, countLL);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root1 = buildTree(s);

        getline(cin, s);
        Node *root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends