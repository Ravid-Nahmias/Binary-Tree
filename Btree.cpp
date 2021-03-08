#include "Btree.h"
#include <iostream>
using namespace std;


btree::btree() {
    // constructor for tte tree
    root = NULL;
}

Node* btree:: createNode(int key){
    // this function creats new node
        struct Node* temp= new Node;
        temp->value = key;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
}
void btree::destroyTree(node *root)
{
    // when want to delete the tree, go over its branches in recorsive way
  if(root!=NULL)
  {
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
  }
}

btree::~btree() {
    // destructor
    destroyTree(root);
}

void btree:: insertNodeToTree(int key, node* root){
    // insert new node to the tree
        if(key> root->value){
            // if its bigger then insert to the right side of the tree
            if(root->right==NULL){
                root->right=createNode(key);
                return;
            }
            else
                insertNodeToTree(key, root->right);
        }
        else{
            // if its smaller then insert to the left side of the tree
            if(root->left==NULL){
                root->left=createNode(key);
                return;
            }
            else
                insertNodeToTree(key, root->left);   
        }   
}

void btree:: insert(int key){
    if( this->root!= NULL)
        insertNodeToTree(key, root);
    else
    // if the tree is empty
        root= createNode(key);
}

void btree :: printTree(Node* root) {
    // print the tree in order style, first the left node, then the root, and then the right node
    if(root==NULL)
    return;
    
    printTree(root->left);
    cout<< root->value<< " ";
    printTree(root->right);
}

void btree:: print() {
    // father's method
    cout<< ">>";
    printTree(root);
    cout<< endl;
    
}
bool btree:: isItSearchTreeHelp(node* root){
    if(root == NULL )
        return true;
    if(root->left != NULL && root->left->value > root->value)
    // if the left root is bigger than the right root, the basic rule of btree does not apply
        return false;
    if(root->right != NULL && root->right->value < root->value)
    // if the left root is bigger than the right root, the basic rule of btree does not apply
        return false;
    else
    {
        // sends the right and left branches in recursive way
        isItSearchTreeHelp(root->left);
        isItSearchTreeHelp(root->right);
    }
}

void btree:: isItSearchTree(){
    if(isItSearchTreeHelp(root)){
    // check if the result in any of the branches says that the definition of the btree does not existing
        cout<< ">>1"<<endl;
        return;
    }
    else{
        cout <<">>0"<<endl;
        return ;
    }  
}
void btree:: printLowestValue(){
    node* temp= this->root;
    if(temp==NULL)
        cout<< ">>void tree" << endl;
    if(this->isItSerachTreeHelp(this->root)){
    // if its a search tree the lowest value will be in the leftest node
        while (temp->left!=NULL)
            temp=temp->left;            
        cout<<">>"<< temp->value<< endl; 
    }
    else{
    // if the mirror function switched the tree the lowest value is in the rightest node
        while (temp->right!=NULL)
            temp=temp->right;            
        cout<<">>"<< temp->value<< endl;  
    }
} 

int btree:: printMaxDepthHelp(Node* root){
    if(root== NULL)
    // we arrive to the end of the tree
        return 0;
    else{
        if(root->left!= NULL)
        // bring the max depth of the left branch
            return printMaxDepthHelp(root->left)+1;
        if(root->right!=NULL)
        // bring the max depth of the right branch
            return printMaxDepthHelp(root->right)+1;
        }
}

void btree:: printMaxDepth(){
int maxLeft=0, maxRight=0;
maxLeft= printMaxDepthHelp(root->left)+1;
maxRight= printMaxDepthHelp(root->right)+1;
maxLeft++;// for the root
maxRight++;// for the root
    if(maxRight>maxLeft)
    // check which branch got the max depth
        cout<<">>"<< maxRight<< endl;
    else
        cout<< ">>"<< maxLeft<< endl;
}

int btree:: compareTreeHelp(node* rootA, node* rootB){
    if(rootA==NULL && rootB==NULL)
    // if both null it means both are in the same size and has the same values
        return 1;
    if(rootA!=NULL && rootB!= NULL){
        if(rootA->value != rootB->value)
        // if the values are not equal the trees are not equal
            return 0;
        else {
            // check both sides
            return compareTreeHelp(rootA->left, rootB->left) && compareTreeHelp(rootA->right, rootB->right);
        }
    }
} 
void btree:: compareTree(node* rootA){
    int right=0,left=0;
    if(root->value != rootA->value)
    // if the roots are not equals' we dont need to check the rest of the trees
        cout<< ">>0"<< endl;
    else{
        left=compareTreeHelp(root->left, rootA->left);
        right=compareTreeHelp(root->right, rootA->right);
        if(left==1 && right==1)
        // only if both sides equals the trees are equals
            cout<< ">>1"<< endl;
        else
            cout<< ">>0"<< endl;
    }    
} 

void btree:: mirrorTreeHelp(Node* root){
    if (root == NULL)  
    // if the tree is null- don't do anything
        return;  
    else
    { 
        Node* temp; 
        // sends the left and the right branches to the function in recursive way
        mirrorTreeHelp(root->left); 
        mirrorTreeHelp(root->right); 
        // switch the pointers of the right and left nodes
        temp = root->left; 
        root->left = root->right; 
        root->right = temp; 
    } 
} 
void btree:: mirrorTree(){
    // father's method 
    if (root == NULL)  
        return;
    else
        mirrorTreeHelp(root);
}




