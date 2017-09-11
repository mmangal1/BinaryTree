#include <iostream>
#include <queue>

void traversalBFS(Node* root){
        queue <Node*> binary_tree;
        binary_tree.push(root);

        while(!(binary_tree.empty())){
                curr = binary_tree.pop();
                cout << curr->value << " ";
                if(curr->left)
                        binary_tree.push(curr->left);
                if(curr->right)
                        binary_tree.push(curr->right);
        }

}

void traversalDFS(Node* root){

        if(root){
                traversalDFS(root->left);
                traversalDFS(root->right);
                cout << root->value << " ";
        }

}

bool isValid(Node* root){
        queue <Node*> isValidTree;
        isValidTree.push(root);

        while(!(isValidTree.empty())){
                curr = isValidTree.pop();
                if(!curr)
		{
			continue;
		}
                if(curr->value %2 != 0)
		{        //current node is odd
			if(!(curr->left->value %2 == 0))
			{
				return false;
			}
			isValidTree.push(curr->left);
			
			if(!(curr->right->value %2 == 0))
			{
				return false;
			}
			isValidTree.push(curr->right);

			if(isValidTree.front())
			{
				if((isValidTree.front() % 2 != 0) && (!(isValidTree.front()->value < curr->value)))
				{
					return false;
				}
			}
                }
                else
		{                           //current node is even
			if(!(curr->left->value %2 != 0))
			{
				return false;
			}
			
			isValidTree.push(curr->left);
                   
			if(!(curr->right->value %2 != 0))
			{
				return false;
			}
			
			isValidTree.push(curr->right);
                        
			if(isValidTree.front())
			{
				if((isValidTree.front() % 2 == 0) && (!(isValidTree.front()->value > curr->value)))
				{
					return false;
				}
			}
                }
        }
	return true;
}
