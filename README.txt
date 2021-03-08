ravidna
Ravid Nahmias, 316032515

Description of the program:
The program is about binary trees. we creats new trees by the binary trees rules.

The user has 9 possiable options:
1. initialize a tree
2. add a node to the tree
3. print the tree in order style
4. print the lowest value in the tree
6. check whther the tree is binary search tree or not (because of the mirror function)
7. print the maximum depth of the tree 
8.  a function that makes the tree become its mirror tree
9.  compare between two trees and see if theye are equals 
10. exit the program and delete all the trees

The program has 3 files:
1. Ex4.cpp- this is the main, it contains the input and sends to the right fuctions according to the input.
2. Btree.h- class definition- contains the declaration of the class, and a node struct
3. Btree.cpp- class implementation- contains the implement of the functions, where the functions realization.

If you want to compile the program:
ctrl+shift+B

If you want to run the program:
push f5

Input orders:
1. the first input can be 2 options:
    a. insert -1 and that means you want to exit the program
    b. insert any numbert that means the index of the tree in the array
2. the second number is the action type:
    a. insert 0 means initialize the tree in the index that inserted in the first input
    b. insert 1 means insert a new node to the tree
        if you choose this option you need to insert another input for the value of the node.
    c. insert 2 means you want the lowest value of the tree, and that will be the output  
    d. insert 4 meacs you want to check if the tree is search tree or not:
        1. output 1- it is 
        2. output 0- it's not
    e. insert 5 print the maximum depth of the tree 
    f. insert 6 means you want to make the tree in its mirror option
    g. insert 7 means you want to compare between two trees
        you need to insert another number which is the number of the tree to compare
        the output will be:
        1. output 1- they are equals 
        2. output 0- they are not equals
    h. insert 9 means you want to print the tree (the tree in the index that inserted in the first input)

The output can only be the nodes value by inorder sorting.

Until the input won't be -1 it goes in an endless loop.


