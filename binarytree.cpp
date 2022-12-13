#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the data:" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "enter the data for inserting at left of:" << data << endl;
    root->left = buildTree(root->left);
    cout << "enter the data for inserting at right of :" << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void leveOrderTraversal(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // old level has completed traversal
            cout << endl;
            if (!q.empty())
            {
                // has some child nodes
                q.push(NULL);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}



//LNR
void inorder(node* root){

    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data <<" ";
    inorder(root->right);
}

void preorder(node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}



void buildFromlevelOrder(node* &root){

    queue<node*> q;
    cout<<" Enter the data for root :";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();


        cout<<" Enter the left node for : "<<temp->data <<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<" Enter the right node for : "<<temp->data <<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp-> right = new node(rightData);
            q.push(temp->right);
        }
    }



}




int main()
{
    //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    node* root = NULL;
    buildFromlevelOrder(root);
    leveOrderTraversal(root);

    // node *root = NULL;
    // root = buildTree(root);


    // // level order
    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // cout << "Printing the level order traversal :" << endl;
    // leveOrderTraversal(root);



    // //inorder traversa
    // cout<<"Inorder traversal :"<<endl;
    // inorder(root);



    // //preorder traversal
    // cout<<endl;
    // cout<<"Preorder traversal :"<<endl;
    // preorder(root);


    //  //postorder traversal
    //  cout<<endl;
    // cout<<"Postorder traversal :"<<endl;
    // postorder(root);

    return 0;
}