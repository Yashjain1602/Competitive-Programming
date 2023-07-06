#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
    public:
     int data;
     Node* left;
     Node* right;
     Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
     }
};
Node* buildtree(Node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root =  new Node(data);

    if(data == -1)
    {
        return NULL;
    }
    cout<<"Enter the value of the left node: "<<data<<endl;
    root->left = buildtree(root->left);
    cout<<"Enter the value of the right node: "<<data<<endl;
    root->right = buildtree(root->right);

    return root;
}
void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelordertraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout<< temp -> data <<" ";
        if(temp->left){
                q.push(temp->left);
            }
        if(temp->right){
                q.push(temp->right);
            }
        }
    }

}
void inorderiterative(Node* root)
{
    stack<Node*> s;
// start from the root node (set current node to the root node)
    Node* curr = root;

// if the current node is null and the stack is also empty, we are done
    while(!s.empty()|| curr!= NULL){
        // if the current node exists, push it into the stack (defer it)
		// and move to its left child
        if(curr != NULL)
        {
            s.push(curr);
            curr = curr -> left;
        }
        else{
            // otherwise, if the current node is null, pop an element from the stack,
			// print it, and finally set the current node to its right child
            curr = s.top();
            s.pop();
            cout<<curr->data<<" ";

            curr = curr->right;
        }
    }
}
void preorderiterative(Node* root)
{
   if(root == NULL)
    return;
   //create an empty stack and push the root node
   stack<Node*> s;
   s.push(root);

   //loop till stack is empty
   while(!s.empty()){
    
    //pop a node from the stack and print it;
    Node* curr = s.top();
    s.pop();
    cout<<curr->data<<" ";

  //push the right child of the popped node into the stack
    if(curr->right){
        s.push(curr->right);
    }
 //push the left child of the popped node into the stack
   if(curr->left){
    s.push(curr->left);
   }
   //the right child must be pushed so that the left child should be processed first
   //to preserve the LIFO order
   }
}
void postorderiterative(Node* root)
{
   //return if the tree is empty
   if(root == NULL)
    return;
   stack<Node*> s;
   s.push(root);

   //create another stack for the postorder traversal
   stack<int> sout;

   //loop till stack is empty
   while(!s.empty()){
    
    //pop a node from the stack and push the data into the stack
    Node* curr = s.top();
    s.pop();

    sout.push(curr->data);

    //Push the left and right child of the popped node into the stack
    if(curr->left){
        s.push(curr->left);
    }
    if(curr->right){
        s.push(curr->right);
    }
   }
   //Print the post order traversal
   while(!sout.empty())
   {
    cout<<sout.top()<<" ";
    sout.pop();
   }
}
int main(){
    Node* root = NULL;

  //Creating a Tree
  root = buildtree(root);
  //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  //level order
  cout<<"Printing the inorder traversal output "<<endl;
  inorder(root);
  cout<<endl;
    cout<<"Printing the preorder traversal output "<<endl;
    preorder(root);
    cout<<endl;
      cout<<"Printing the postorder traversal output "<<endl;
      postorder(root);
      cout<<endl;


    cout<<"Printing the inorder interative approach traversal output "<<endl;
      inorderiterative(root);
      cout<<endl;
    cout<<"Printing the preorder interative approach traversal output "<<endl;
      preorderiterative(root);
      cout<<endl;
    cout<<"Printing the postorder interative approach traversal output "<<endl;
      postorderiterative(root);
      cout<<endl;

      
  cout<<"Printing the level order traversal output "<<endl;
  levelordertraversal(root);

    return 0;
}