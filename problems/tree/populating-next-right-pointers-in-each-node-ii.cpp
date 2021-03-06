//https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

#include <cstddef>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

#include <queue>

class Solution {
public:
	//bfs level-traverse
    Node* connect(Node* root) 
    {
    	Node dummy;
    	dummy.next = root;
    	while(dummy.next)
    	{
    		Node* tail = &dummy, *cur = dummy.next;
            dummy.next = nullptr;
    		while(cur)
    		{
    			if(cur->left)
    			{
    				tail->next = cur->left;
    				tail = tail->next;
    			} 	
    			if(cur->right)
    			{
    				tail->next = cur->right;
    				tail = tail->next;
    			}
    			cur = cur->next;
    		}
    	}
    	return root;
    }

    //dfs
    std::vector<Node*> rNodeInEachLevel;

	void dfs(Node* root, int level)
    {
	    if (!root)
	        return;
	    if (level < rNodeInEachLevel.size())
        {
	        rNodeInEachLevel[level]->next = root;
	        rNodeInEachLevel[level] = root;
        }
	    else
        {
	        rNodeInEachLevel.push_back(root);
        }
        dfs(root->left, level+1);
	    dfs(root->right, level+1);
    }

    Node* connect2(Node* root)
    {
        dfs(root, 0);
        return root;
    }
};