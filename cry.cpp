// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
#include<iostream>
using namespace std;

    struct TreeNode {
        int data;
        //TreeNode *parent;
        TreeNode* left, * right;
        TreeNode(int d) :data(d), left(NULL), right(NULL) {}
    };
    struct Node {
        int data;
        Node* prev, * next;
        Node(int d, Node* p, Node* n) :data(d), prev(p), next(n) {}

        void inserAfter(int datum) {
            Node* temp = new Node(datum, this, this->next);
            temp->next->prev = temp;
            temp->prev->next = temp;
        }
        void insertBefore(int datum) {
            Node* temp = new Node(datum, this->prev, this);
            temp->next->prev = temp;
            temp->prev->next = temp;
        }
        void remove() {
            this->prev->next = this->next;
            this->next->prev = this->prev;
            delete this;
        }
    };
    class List {
    public:
        List() {
            head = new Node(0, NULL, NULL);
            tail = new Node(0, head, NULL);
            head->next = tail;
        }
        void push(int data) {
            head->inserAfter(Data);
        }
        void pop() {
            tail->prev->remove()
        }
        int top() {
            return tail->prev->data;
        }
        void clear() {
            while (head->next != tail)
                pop();
        }
    private:
        Node* head, * tail;
    };
    class BinaryTree() {
    public:
        BinaryTree(int r) {
            root = new TreeNode(r);
        }
        void push(int data){
            TreeNode* cur = root;
            while (1)
            {
                if (data < *cur->data)
                {
                    if (cur->data != NULL)
                    {
                        cur = cur->left;
                    }
                    else
                        cur->left = new TreeNode(data);
                    break;
                }
                else if (data >= cur->data)
                {
                    if (cur->right != NULL)
                        cur = cur->right;
                    else
                    {
                        cur->right = new TreeNode(data);
                        break;
                    }
                }
                    
            }

        }
        TreeNode* r() { return root; }
    private:
        TreeNode* root;
    }
