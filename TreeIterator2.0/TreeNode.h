/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeNode.h
 * Author: teri
 *
 * Created on January 4, 2016, 12:59 PM
 */

#ifndef TREENODE_H
#define TREENODE_H
#include <memory>
class TreeNode {
public:
    std::unique_ptr<TreeNode> leftChild;
    std::unique_ptr<TreeNode> rightChild;
    const int &key;
    TreeNode(const int &_key, TreeNode  *_leftChild, TreeNode *_rightChild) : leftChild(_leftChild),rightChild(_rightChild),key(_key){}
    TreeNode(const int &_key): key(_key){
        leftChild.reset(nullptr);
        rightChild.reset(nullptr);

}
};


#endif /* TREENODE_H */

