#include <iostream>
#include "Btree.h"

using namespace std;


int main()
{
    int type, treeNum, nodeValue, arraySize=1, idxTreeToCompare, lastSize;
    //creat the array that keeps the pointers to the trees
    btree** treesArray= (btree**)malloc(sizeof(btree*));
    lastSize=arraySize;
    for(;;)
    {    
        cin>>treeNum;
        if(treeNum==-1){
            for(int i=0; i<arraySize; i++)
                //treesArray[i]->destroyTree(treesArray[i]->root);
                if(treesArray[i]!=NULL)
                    delete treesArray[i];
            // before leaving the program, realese the pointer of the trees array
            free(treesArray);
            return 0;
        }
        else{
            if(treeNum>=arraySize)
            {
                // if needs to inlarge the array
                arraySize=treeNum+1;
                treesArray=(btree**)realloc(treesArray, arraySize*sizeof(btree*));
                for(int i=lastSize; i<arraySize; i++){
                    // this loop update all the trees that are between the last array to the new, to be null
                    treesArray[i]=NULL;
                }
                lastSize=arraySize; // update the index for the next time that the array will inlarge
                if(treesArray== NULL)
                    exit(1);
            }
            cin>>type;
            if(type==0){
                // initialize the tree
                treesArray[treeNum]=new btree();
            }
            if(type==1){
                //if want to insert a new node to the tree
                cin >> nodeValue;
                treesArray[treeNum]->insert(nodeValue);
            }
            if(type==2){
                //if want to print the lowest value of the tree
                treesArray[treeNum]->printLowestValue();
            }
            if(type==4){
                //if want to check whether the tree is search tree
                treesArray[treeNum]->isItSearchTree();
            }
            if(type==5){
                //if want to print the maximum depth of the tree
                treesArray[treeNum]->printMaxDepth();
            }
            if(type==6){
                //if want to transfer the tree into its mirror tree
                treesArray[treeNum]->mirrorTree();
            }
            if(type==7){
                cin >> idxTreeToCompare;
                //if want to compare between two trees
                treesArray[treeNum]->compareTree(treesArray[idxTreeToCompare]->root);
            }
            if(type==9)
                // if want to print the tree
                treesArray[treeNum]->print();
        }
    }
    return 0;
}