// #include<iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node* link;
// };

// void print(Node* &head)
// {
//     Node* temp=head;
//     while(temp!=NULL)
//     {
//         cout<<temp->data<<" ";
//         temp=temp->link;
//     }
// }

// int main()
// {
//     Node* head=nullptr;
//     Node* temp=nullptr;

//     int choice=1;
//     while (choice==1)
//     {
//         temp=new Node;
//         cout<<"Enter data : ";
//         cin>>temp->data;
//         temp->link=head;
//         head=temp;
//         cout<<"Enter choice 0 or 1";
//         cin>>choice;
//     }
//     print(head);
//     head=head->link;
//     print(head);
    
//     return 0;
// }
// #include<iostream>
// using namespace std;

// class node
// {
//     public:
//     int data;
//     node* next;
//     node* prev;
//     node(){}
//     node(int d)
//     {
//         this->data=d;
//         next=nullptr;
//         prev=nullptr;
//     }
// };
// void insertAtHead(node* &head)
// {
//     int data;
//     cout<<"Enter data to insert";
//     cin>>data;
//     node* temp=new node(data);
//     temp->next=head;
//     head->prev=nullptr;
//     head=temp;
// }
// void deleteAtHead(node* &head)
// {
//     node* temp=head;
//     head=temp->next;
//     head->prev=nullptr;
//     delete temp;
// }
// void printForward(node* &head)
// {
//     node* temp=head;
//     cout<<"Printing in forward direcion"<<endl;
//     while(temp!=nullptr)
//     {
//         cout<<temp->data<<" ->  ";
//         temp=temp->next;
//     }
//     cout<<endl;
// }
// int main()
// {
//     node* head=nullptr;
//     node* tail=nullptr;
//     node* temp=nullptr;
//     int choice=1;
//     while(choice==1)
//     {
//         int data;
//         cout<<"Enter data : ";
//         cin>>data;
//         node* newNode=new node(data);
//         if(head==nullptr)
//         {
//             head=temp=newNode;
//         }
//         else
//         {
//             temp->next=newNode;
//             newNode->prev=temp;
//             temp=newNode;
//         }
//         tail=temp;
//         cout<<"Enter choice 0 or 1";
//         cin>>choice;
//     }
//     insertAtHead(head);
//     printForward(head);
//     deleteAtHead(head);
//     printForward(head);
//     return 0;
// }
// 
// #include<iostream>
// using namespace std;
// struct node
// {
//     int data;
//     node* left;
//     node* right;
// };

// node* createNode(node* &root,int data)
// {
//     if(root==nullptr)
//     {
//         node* newNode=new node();
//         newNode->data=data;
//         newNode->left=nullptr;
//         newNode->right=nullptr;
//         return newNode;
//     }
//     if(data<root->data)
//     {
//         root->left=createNode(root->left,data);
//     }
//     if(data>root->data)
//     {
//         root->right=createNode(root->right,data);
//     }
//     return root;
// }

// void insertData(node* &root)
// {
//     int data;
//     cout<<"Enter the Data : "<<endl;
//     cin>>data;
//     while(data!=-1)
//     {
//         root=createNode(root,data);
//         cout<<"Enter the data : "<<endl;
//         cin>>data;
//     }            
// }
// int recursiveSearch(node* &root,int key)
// {
//     if(root==nullptr)
//     {
//         return 1;
//     }
//     else if (root->data>key)            
//     {
//         return recursiveSearch(root->left,key);
//     }
//     else if(root->data<key)
//     {
//         return recursiveSearch(root->right,key);
//     }
// }
// int itrativeSearch(node* &root,int key)
// {
//     node* temp=root;
//     while (temp!=nullptr)
//     {
//         if(temp->data=key)
//         {
//             return 1; 
//         {
//             temp->left=temp;
//         }
//         else{
//             temp->right=temp;
//         }
//     }
//     return 0;
// }
// void inOrderTraversing(node* &root)
// {
//     if(root==nullptr)
//     {
//         return;
//     }
//     inOrderTraversing(root->left);
//     cout<<root->data<<"     ";
//     inOrderTraversing(root->right);
// }
// void preOrderTraversing(node* &root)
// {
//     if(root==nullptr)
//     {
//         return;
//     }
//     cout<<root->data<<"     ";
//     preOrderTraversing(root->left);
//     preOrderTraversing(root->right);
// }
// void postOrderTraversing(node* &root)
// {
//     if(root==nullptr)
//     {
//         return;
//     }
//     postOrderTraversing(root->left);
//     postOrderTraversing(root->right);
//     cout<<root->data<<"     ";
// }

// int main()
// {
//     node* root=nullptr;
//     int choice;
//     cout<<"Enter the choice";
//     cin>>choice;
//     while(choice!=4)
//     {
//         switch (choice)
//         {
//         case 1:
//             insertData(root);
//             break;
//         case 2:
//             int key;
//             cout<<"Enter the Key : ";
//             cin>>key;
//             if(recursiveSearch(root,key))
//             {
//                 cout<<"The Element is Found."<<endl;
//             }
//             else{
//                 cout<<"The Element is not Found."<<endl;
//             }
//             break;
//             case 3:
//             cout<<"Inorder Traversing"<<endl;
//             inOrderTraversing(root);
//             cout<<"Preorder Traversing"<<endl;
//             preOrderTraversing(root);
//             cout<<"Postorder Trversing."<<endl;
//             postOrderTraversing(root);
//             break;
//         default:
            
//             break;
//         }
//         cout<<"Enter Choice :"<<endl;
//         cin>>choice;
//     }
    
//     return 0;
// }
#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int data)
    {
        this->data=data;
        next=nullptr;
    }
};
void enqueue(node* &rear,node* &front,int data)
{
    if(rear==nullptr&&front==nullptr)
    {
        node* newNode=new node(data);
        rear=front=newNode;
    }
    else{
        node* newNode=new node(data);
        rear->next=newNode;
        rear=newNode;
    }
}
void dequeue(node* &front,node* &rear)
{
    if(front==nullptr)
    {
        cout<<"Underflow"<<endl;
    }
    else{
        node* temp=front;
        front=front->next;
        delete temp;
    }
}
void traverse(node* front)
{
    if(front==nullptr)
    {
        cout<<"Underflow"<<endl;
    }
    else{
        node* temp=front;
        while(temp!=nullptr)
        {
                cout<<temp->data<<" ";
                temp=temp->next;
        }
    }
}
int main()
{
    node* rear=nullptr;
    node* front=nullptr;
    int choice;
    cout<<"Enter the Choice";
    cin>>choice;
    while(choice!=4)
    {
        switch (choice)
        {
        case 1:
            int data;
            cout<<"Enter data u want to insert"<<endl;
            cin>>data;
            enqueue(rear,front,data);
            break;
        case 2:
        dequeue(front,rear);
        break;
        case 3:
        traverse(front);
        default:
        cout<<"Invalid Choice"<<endl;
            break;
        }
        cout<<"Enter choice : "<<endl;
        cin>>choice;
    }
    return 0;
}