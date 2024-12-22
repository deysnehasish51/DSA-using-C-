#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* right;
    Node* left;
};
Node* createNode(Node* root,int data){
    if(root==NULL){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->right = NULL;
        newNode->left = NULL;
        return newNode;
    }
    if(data < root->data){
        root->left = createNode(root->left,data);
    }else{
        root->right = createNode(root->right,data);
    }
    return root;
}
void insertData(Node* &root){
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    while(data!=-1){
        root = createNode(root,data);
        cout<<"Enter the data: ";
        cin>>data;
    }
}
int recursiveSearching(Node*root,int key){
    if(root==NULL){
        return 0;
    }
    if(root->data == key){
        return 1;xcc
    }else if(root->data > key){
        return recursiveSearching(root->left,key);
    }else{
        return recursiveSearching(root->right,key);
    }
}
int iterativeSearching(Node* root,int key){
    Node* temp = root;
    while(temp!=NULL){
        if(temp->data == key){
            return 1;
        }else if(temp->data > key){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    return 0;
}
void inorderTraversing(Node* root){
    if(root==NULL){
        return;
    }
    inorderTraversing(root->left);
    cout<<root->data<<" ";
    inorderTraversing(root->right);
}
void preorderTraversing(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversing(root->left);
    preorderTraversing(root->right);
}
void postorderTraversing(Node* root){
    if(root == NULL){
        return;
    }
    postorderTraversing(root->left);
    postorderTraversing(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node* root = NULL;
    int choice;
    cout<<"Enter the choice: ";
    cin>>choice;
    while(choice != 4){
    switch(choice){
        case 1:
        insertData(root);
        break;
        case 2:
        int key;
        cout<<"\nEnter the key: ";
        cin>>key;
        if(recursiveSearching(root,key)){
            cout<<"\nThe element is found.";
        }else{
            cout<<"\nThe element is not found.";
        }
        break;
        case 3:
        cout<<"\nInorder Traversal: ";
        inorderTraversing(root);
        cout<<"\nPreorder Traversing: ";
        preorderTraversing(root);
        cout<<"\nPostorder Traversal: ";
        postorderTraversing(root);
        break;
    }
    cout<<"\nEnter the choice: ";
    cin>>choice;
    }
}