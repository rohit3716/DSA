#include<bits/stdc++.h>
using namespace std;


class Node {
    public:
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node( int d) {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};


void inorder(Node* root) {
      //base case
      if(root == NULL) {
        return;
      }

      inorder(root->left);
      cout<< root->data << " " ;
      inorder(root->right);
}

void preOrder(Node* root) {
    //base case
    if(root == NULL) {
        return;
    }
    
    cout<< root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    //base case
    if(root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<< root->data << " ";
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            //purana level complete traverse ho chuka hai
            cout<<endl;
            if(!q.empty()) {
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else {
            cout << temp ->data << " ";
            if(temp ->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
    
}


Node* insertIntoBST( Node* root, int d) {
    //base case
    if( root == NULL ){
        root = new Node(d);
        return root;
    }

    if( d > root->data) {
        //right part me insert krna hai
        root->right = insertIntoBST( root->right, d);
    }
    else{
        //left part me insert krna hai
        root->left = insertIntoBST( root->left, d);
    }

    return root;

}

Node* minVal( Node* root) {
    Node* temp = root;
    while( temp -> left != NULL ){
        temp = temp->left;
    }
    return temp;
}

Node* maxVal( Node* root) {
    Node* temp = root;
    while( temp->right != NULL ) {
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBST( Node* root, int val ) {
    //base case
    if( root == NULL ){
        return root;
    }

    if( root->data == val) {
        //0 child
        if( root->left == NULL && root->right == NULL ) {
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if( root->left != NULL && root->right == NULL ) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if( root->left == NULL && root->right != NULL ) {
            Node* temp = root->right;
            delete root;
            return temp;
        }


        //2 child
        if( root->left != NULL && root->right != NULL ) {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST( root->right, mini);
            return root;
        }
    }   

    else if (root->data > val )
    {
        //left part me jao
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBST( root -> right, val);
        return root;
    }
    
}

void takeInput( Node* &root){
    int data;
    cin>>data;

    while( data != -1) {
        root = insertIntoBST( root, data);
        cin>>data;
    }
}

int main( ){
    Node* root = NULL;

    cout<< "Enter data to create BST :" << endl;
    takeInput(root);


    cout<<"Printing the BST in Level Order: " << endl;
    levelOrderTraversal(root);

    cout<<endl<<"Printing Inorder "<<endl;
    inorder(root);

    cout<<endl<<"Printing PreOrder"<<endl;
    preOrder(root);

    cout<<endl<<"printing postorder"<<endl;
    postOrder(root);


    cout<<endl<<" Minimum Value of given BST : " << minVal(root)->data<<endl;

    cout<<" Maximum value of given BST : "<<maxVal(root)->data<<endl;

    //DELETION

    root = deleteFromBST(root, 7);

    cout<<endl<<"After deletion :"<<endl;

    cout<<"Printing the BST in Level Order: " << endl;
    levelOrderTraversal(root);

    cout<<endl<<"Printing Inorder "<<endl;
    inorder(root);

    cout<<endl<<"Printing PreOrder"<<endl;
    preOrder(root);

    cout<<endl<<"printing postorder"<<endl;
    postOrder(root);


    cout<<endl<<" Minimum Value of given BST : " << minVal(root)->data<<endl;

    cout<<" Maximum value of given BST : "<<maxVal(root)->data<<endl;


    return 0;
}