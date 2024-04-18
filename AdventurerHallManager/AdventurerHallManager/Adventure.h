#pragma once
#include "AdventurePoint.h"
#include "Hall.h"


template <typename T>
class TreeNode
{
public:
    TreeNode* left;
    TreeNode* right;
    T data;

    TreeNode(T Data, TreeNode* _left = nullptr, TreeNode* _right = nullptr)
    {
        data = Data;
        left = _left;
        right = _right;
    }

    // ~TreeNode()
    // {
    //     delete left;
    //     delete right;
    // }
};

class BinaryTree
{
public:
    TreeNode<AdventurePoint>* Root;
    BinaryTree(TreeNode<AdventurePoint>* root)
    {
        Root = root;
    };
    ~BinaryTree()
    {
        Clear(Root);
        Root = nullptr;
    };

    void Clear(TreeNode<AdventurePoint>* node)
    {
        if (node == NULL)
        {
            return;
        }
        Clear(node->left);
        Clear(node->right);
        delete node;
    }
};

class Adventure
{
public:
    string name;
    BinaryTree* AdventureTree;
    TreeNode<AdventurePoint>* CurrentNode;

    explicit Adventure(const string& name, TreeNode<AdventurePoint>* root)
        : name(name)
    {
        AdventureTree = new BinaryTree(root);
        CurrentNode = root;
    }

    ~Adventure()
    {
        //delete CurrentNode;
        delete AdventureTree;
    }
};

