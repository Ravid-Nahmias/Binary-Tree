#ifndef A_TREE
#define A_TREE

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

typedef struct Node node;

class btree {
public:
    btree();
    ~btree();

    Node *root;
    void insert(int key);
    void print();
    void printLowestValue();
    void isItSearchTree();
    void printMaxDepth();
    void mirrorTree();
    void compareTree(node* rootA);
    void destroyTree(node *root);

private:
    Node* createNode(int key);
    void insertNodeToTree(int key, node* root);
    void printTree(Node* root);
    bool isItSearchTreeHelp(Node* root);
    int printMaxDepthHelp(Node* root);
    int compareTreeHelp(node* rootA, node* rootB);
    void mirrorTreeHelp(Node* root);

};

#endif
