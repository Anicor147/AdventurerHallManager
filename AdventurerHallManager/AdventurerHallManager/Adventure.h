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

    TreeNode(T Data)
    {
        data = Data;
    }

    ~TreeNode()
    {
        delete left;
        delete right;
    };
};

class BinaryTree
{
public:
    TreeNode<AdventurePoint>* Root;
    BinaryTree()
    {
        Root = nullptr;
    };
    ~BinaryTree()
    {
        delete Root;
    };
};

class Adventure
{
public:
    string name;
    BinaryTree* AdventureTree;
    TreeNode<AdventurePoint>* CurrentNode;

    explicit Adventure(const string& name)
        : name(name)
    {
        AdventureTree = new BinaryTree();
        CurrentNode = AdventureTree->Root;
    }

    ~Adventure()
    {
        delete CurrentNode;
        delete AdventureTree;
    };
};

