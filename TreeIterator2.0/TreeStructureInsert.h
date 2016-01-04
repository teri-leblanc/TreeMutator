/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeStructureInsert.h
 * Author: teri
 *
 * Created on January 4, 2016, 3:11 PM
 */

#ifndef TREESTRUCTUREINSERT_H
#define TREESTRUCTUREINSERT_H
#include "BSTstructure.h"
#include "RBTstructure.h"

class TreeStructureInsert : public TreeStructureMutator
{
public:
    TreeStructureInsert();
    TreeStructureInsert(const TreeStructureInsert& orig);
    virtual ~TreeStructureInsert();
    bool Insert(BSTstructure &BST);
    bool Insert(RBTstructure &RBT);
private:

};

#endif /* TREESTRUCTUREINSERT_H */

