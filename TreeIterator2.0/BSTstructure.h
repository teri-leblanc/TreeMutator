/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BSTstructure.h
 * Author: teri
 *
 * Created on January 4, 2016, 1:14 PM
 */

#ifndef BSTSTRUCTURE_H
#define BSTSTRUCTURE_H
#include "TreeStructure.h"

class BSTstructure : public TreeStructure{
    public:
    BSTstructure():TreeStructure(){}
    BSTstructure(int &_key):TreeStructure(_key){}
    virtual ~BSTstructure(){}
    virtual void Accept(){int x = 0;}
    virtual bool Insert(const int &data){
        if(root == nullptr){                                                    // If tree is empty
            root.reset(new TreeNode(data));
            return true;
        }
        else if(Contains(data))return false;                                   // Node already exists
        TreeNode * comparible =root.get();
        while(comparible != nullptr){                                          // Traverse tree and find spot to place
            if(comparible->key > data){
                if(comparible->leftChild == nullptr){ 
                    comparible->leftChild = std::unique_ptr<TreeNode>(new TreeNode(data));
                    return true;
                }
                else comparible = comparible->leftChild.get();
            }
            else if(comparible->key < data){
                if(comparible->rightChild ==nullptr){ 
                    comparible->rightChild =  std::unique_ptr<TreeNode>(new TreeNode(data));
                    return true;
                }
                else comparible = comparible->rightChild.get();
            }
        }
        return false;
    }
    virtual bool Remove(const int &data) {
        TreeNode *parentNode = FindParent(data);
        if (!parentNode) return false;
        if (parentNode->leftChild) {
            if(parentNode->leftChild->key == data)
                Remove(parentNode->leftChild,*parentNode,0);
                return true;
        }
        if(parentNode->rightChild.get()){
            if(parentNode->rightChild.get()->key == data)
                Remove(parentNode->rightChild,*parentNode,1);
                return true;
        }
        return true;
    }
    
    virtual bool Contains(const int &data){
        TreeNode *comparible = root.get();
        while(comparible != NULL){
             if(comparible->key > data) comparible = comparible->leftChild.get();
             else if(comparible->key < data) comparible = comparible->rightChild.get();
             else if(comparible->key == data) return true;
        }
        return false;
    }
    
private:
    int FindMin(std::unique_ptr<TreeNode> &parent){
        if(parent.get()->leftChild)FindMin(parent.get()->leftChild);
        else return parent.get()->key;
    }
// The following function is an internal helper that deletes the unique_ptr before its scope is up.
// side = 0 // This means that the node to be deleted is the left child of the parent
// side = 1 // This means that the node to be deleted is the right child of the parent
    void Remove(std::unique_ptr<TreeNode> &deleteNode, TreeNode &parentNode,bool side){
        if(deleteNode->leftChild == nullptr && deleteNode->rightChild == nullptr){
            if(side) parentNode.rightChild = nullptr;
            else parentNode.leftChild = nullptr;
        
        }  // Remove Leaf
        else if(deleteNode->leftChild == nullptr){                                                            // Remove node with 1 child
            if(side) parentNode.rightChild = std::move(deleteNode->rightChild);
            else parentNode.leftChild = std::move(deleteNode->rightChild);
        }
        else if(deleteNode->rightChild == nullptr){
            if(side) parentNode.rightChild = std::move(deleteNode->leftChild);
            else parentNode.leftChild = std::move(deleteNode->leftChild);
        }
        else{
            TreeNode * minParent = FindParent(FindMin(deleteNode->rightChild));
            deleteNode.reset(new TreeNode(minParent->leftChild->key,nullptr,deleteNode->rightChild.release()));
        }                                                                                                      // Remove node with 2 children
    }
// The following function is an internal helper that returns a pointer to the parent node of a specific node
// This was implemented in order to get access to the unique pointer so that it may be deleted before the end of its scope
// NOTE: This does seem to be dangerous and I am currently looking for better ways of handling this.    
    TreeNode  *FindParent(const int &data) const{
       TreeNode *comparible = root.get();
       TreeNode *comparibleParent = nullptr;
       while(comparible !=nullptr){
           if(comparible->key == data) return comparibleParent;
           else if(comparible->key > data){ 
               comparibleParent = comparible;
               comparible = comparible->leftChild.get();}
           else{ 
               comparibleParent = comparible;
               comparible = comparible->rightChild.get();}
        }
        return nullptr;
    }
};

#endif /* BSTSTRUCTURE_H */

