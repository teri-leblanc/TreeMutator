/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeStructure.h
 * Author: teri
 *
 * Created on January 4, 2016, 12:57 PM
 */

#ifndef TREESTRUCTURE_H
#define TREESTRUCTURE_H
#include <memory>
#include <stdio.h>
#include <cstdlib>
#include "TreeNode.h"

class TreeStructure {

protected:
    std::unique_ptr<TreeNode> root;
public:
    TreeStructure() :root(nullptr){}
    TreeStructure(const int &_key):root(new TreeNode(_key)){}
 //   TreeStructure(const TreeStructure& orig):root(new TreeNode(orig.root->key,orig.root->leftChild,orig.root->rightChild)){}
    virtual ~TreeStructure(){}
    virtual void Accept()=0;
    virtual bool Insert(const int &data)=0;
    virtual bool Contains(const int &data)=0;
    virtual bool Remove(const int &data)=0;

};

#endif /* TREESTRUCTURE_H */

