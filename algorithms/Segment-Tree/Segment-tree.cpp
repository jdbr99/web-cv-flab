/*
Author: Jose Santiago Vales Mena
*/
#include <bits/stdc++.h>
using namespace std;

#define mit(a, b) ((a+b)/2)

struct nodo{
    int val;//The value of the node
    nodo *l, *r; //Pointer to their children
} *head; //Head is the pointer to the root

int build(int l, int r, nodo* node, int* ar){ /*Tipe int because it will be returning values of the nodes to construct the other nodes, 
    and ar is the array were the values are store. l and r are the range of the current node*/
    if (l == r) node -> val = ar[l]; //If it's a leaf
    else{
        node -> l = new nodo; //Create left child
        node -> r = new nodo; //Create right child
        node -> val = build(l, mit(l, r), node -> l, ar) + build(mit(l, r) + 1, r, node -> r, ar); //Get the value with recursion 
    }
    return node -> val; //Return the value of node, so the other nodes can use it to construct  
}

int query(int lq, int rq, int l, int r, nodo* node){ //lq and rq are the range of the question
    if (r < lq || rq < l) return 0; //Completly outof range
    if (lq <= l && r <= rq) return node -> val; //Completly in range
    return query(lq, rq, l, mit(l, r), node -> l) + query( lq, rq, mit(l, r) + 1, r, node -> r); //With some useful elements
}

int update(int l, int r, int pos, nodo* node, int k){ //Pos is the position of the update and k the new value of the number in pos
    if (r < pos || pos < l) return node -> val; //If this node doesn't contain the update just return the value without change
    if (pos <= l && r <= pos) node -> val = k; //If we are in the leaf number to be uptade we change the value
    else node -> val = update(l, mit(l, r), pos, node -> l, k) + update(mit(l, r)+1, r, pos, node -> r, k) ; /*It's a node thats contains
    the node being updated so it must update its value to whatever their children returns*/
    return node -> val; //return the value for recursive update
}

void erase(nodo *node){
    if (node -> l == NULL){ //Its a leaf because it hasn't children
        delete node;
        return;
    } //If not, is a node with child and we need to erase it children recursive
    erase(node -> l);
    erase(node -> r);
    //We already delete all the node down this one
    node -> l = NULL; //Set pointers to children NULL
    node -> r = NULL;
    delete node; //Delete the actual node
}

int main(){
    int n, actions;
    cin >> n;
    int ar[n];

    for (int i = 0; i < n; i++)
        cin >> ar[i];
    
    build(0, n-1, head, ar);
    
    cin >> actions;

    for (int i = 0; i < actions; i++){
        int number; cin >> number;
        if (number  == 1){
            int range_r, range_l;
            cin >> range_r >> range_l;
            cout << query(range_r, range_l, 0, n-1, head) << '\n';
        }else{
            int pos, k;
            cin >> pos >> k;
            update(0, n-1, pos, head, k);
        }
    }
    erase(head);
    
    return 0;
}