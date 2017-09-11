#include <iostream>
#include <queue>

void traversalBFS(Node* root){
        queue <Node*> binary_tree;
        binary_tree.push(root);
	Node* curr;
        while(!(binary_tree.empty())){
                curr = binary_tree.pop();
		if(!curr){
			continue;
		}
                cout << curr->value << " ";
                binary_tree.push(curr->left);
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

	if(root && root->value %2 == 0){
		return false;
	}

	Node* curr = root;
	isValidTree.push(curr->left);
	isValidTree.push(curr->right);

        while(!(isValidTree.empty())){
                curr = isValidTree.pop();

		if(!curr)
		{
			continue;
		}

		if(!isValidNode(curr)){
			return false;
		}
			
		isValidTree.push(curr->left);
		isValidTree.push(curr->right);
	}
	return true;
}


bool isValidNode(Node* curr){
	if(curr->parent->value %2 == 0){
		if(curr->value%2 == 0){
			return false;
		}
		if(isValidTree.front()){
			if((isValidTree.front()->value % 2 != 0) && (!(isValidTree.front()->value < curr->value)))
			{
				return false;
			}
			
		}
	}else{
		if(curr->value%2 != 0){
			return false;
		}
		if(isValidTree.front(){
			if((isValidTree.front()->value % 2 == 0) && (!(isValidTree.front()->value > curr->value)))
			{
				return false;
			}
		}
	}
	return true;

}
