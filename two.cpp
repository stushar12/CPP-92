#include<bits/stdc++.h>
using namespace std;

struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted start lesser, insert inorder left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert inorder right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}



vector<int> bottom_view(Node *root)
{
        map<int,int> m;
        queue<pair<Node*,int>> q;
		vector<int> v; 
		int horizontal_distance=0;

        q.push({root,horizontal_distance});

        while(q.empty()!=true)
        {
            auto temp=q.front();
            Node * curr=temp.first;
            horizontal_distance=temp.second;

			m[horizontal_distance]=curr->data;

            q.pop();
            if(curr->left)
            q.push({curr->left,horizontal_distance-1});
            if(curr->right)
            q.push({curr->right,horizontal_distance+1});
        }
       
    for(auto itr:m)
    {
    v.push_back(itr.second);
    }

    return v;
}

int main() 
{
	Node* root = NULL;  			// Creating an empty tree
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,17);
	root = Insert(root,25);

	vector<int>v;
	int horizontal_distance=0;
	v=bottom_view(root);

	for(auto itr:v)
		cout<<itr<<" ";
}