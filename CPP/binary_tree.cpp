//binary tree with recursion

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;
    
    node(int data){
        this->data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* create(node* root){
    cout << "Enter the data(-1 for no node): ";
    int data;
    cin >> data;
    node* root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter the data for the left of " << data << endl;
    root -> left = create(root -> left);

    cout << "Enter the data for the right of " << data << endl;
    root -> right = create(root -> right);

    return root;
}

void inorder(node* root){ //left root right
    if(root){
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}

void preorder(node* root){ //root left right
    if(root){
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}

void iterativePreorder(node* root){ //root left right
    stack<node*> st;
    st.push(root);
    while(!st.empty()){
        node* temp = st.top();
        st.pop();
        cout << temp -> data << " "; //ans.push_back(temp -> data);
        if(temp -> right) //right child is pushed first so that left is processed first
            st.push(temp -> right);
        if(temp -> left)
            st.push(temp -> left);
    }
    //return ans;
}

void postorder(node* root){ //left right root
    if(root){
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << " ";
    }
}

void levelorder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

void mirror(node* root){
    if(root){
        mirror(root -> left);
        mirror(root -> right);
        swap(root -> left, root -> right);
    }
}

int height(node* root){
    if(root){
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        return max(leftheight, rightheight) + 1;
    }
}

void leaf(node* root){
    if(root){
        if(root -> left == NULL && root -> right == NULL){
            cout << root -> data << " ";
        }
        leaf(root -> left);
        leaf(root -> right);
    }
}

int totalnodes(node* root){
    if(root)
        return 1 + totalnodes(root -> left) + totalnodes(root -> right);
}

void balanced(node* root){
    if(root){
        if(abs(height(root -> left) - height(root -> right)) <= 1)
            cout << "Balanced" << endl;
        else
            cout << "Not Balanced" << endl;
        balanced(root -> left);
        balanced(root -> right);
    }   
}

int diameter(node* root){
    if(root){
        int lheight = height(root -> left);
        int rheight = height(root -> right);
        int ldiameter = diameter(root -> left);
        int rdiameter = diameter(root -> right);
        return max(lheight + rheight + 1, max(ldiameter, rdiameter));
    }
    return 0;
} 

int main(){

    node* root = NULL;
    root = create(root);
    
    int choice;
    cout << "Enter the choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            inorder(root);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            levelorder(root);
            break;
        case 5:
            mirror(root);
            break;
        case 6:
            cout << height(root) << endl;
            break;
        case 7:
            leaf(root);
            break;
        case 8:
            totalnodes(root);
            break;
        default:
            cout << "Invalid choice" << endl;
    }
    

    return 0;
}