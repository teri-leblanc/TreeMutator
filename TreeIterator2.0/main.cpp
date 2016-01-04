/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: teri
 *
 * Created on January 4, 2016, 12:57 PM
 */

#include <cstdlib>
#include "BSTstructure.h"
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    TreeStructure *tree = new BSTstructure();
    cout<<"Building an integer Tree with root node of 5\n";
    tree->Insert(2);
    cout<<"Inserting 2\n";
    tree->Insert(4);
  /*   cout<<"Inserting 4\n";   
    tree.Insert(1);
        cout<<"Inserting 1\n";
    tree.Remove(2);
        cout<<"Removing 2\n";
        cout<<"Looking for 2\n";
   if(tree.Contains(2))cout<<"Found 2\n";
   else cout<<"Did not find 2\n";
   cout<<"Looking for 4\n";
   if(tree.Contains(4))cout<<"Found 4\n";
   else cout<<"Did not find 4\n";
   cout<<"Looking for 1\n";
   if(tree.Contains(1))cout<<"Found 1\n";
   else cout<<"Did not find 1\n";
   
 */
    return 0;
}

