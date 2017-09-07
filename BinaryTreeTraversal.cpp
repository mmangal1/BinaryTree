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