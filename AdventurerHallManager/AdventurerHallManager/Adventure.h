#pragma once
#include "AdventurePoint.h"
#include "Hall.h"


template <typename T>
class TreeNode
{
public:
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    T data;
     
     
};

class BinaryTree
{
public:
    TreeNode<AdventurePoint> Root;
};

class Adventure
{
public:
    BinaryTree AdventureTree;
    
};

