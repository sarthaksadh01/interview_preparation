#include<bits/stdc++.h>
using namespace std;

template<typename T>
class MySet{
    struct Node{
        T val;
        Node*left;
        Node*right;
        Node(T data){
            val = data;
            left = right = NULL;
        }
    };
    int size = 0;
    Node*root = NULL;
    bool insertHelper(Node*root,T val){
        while(root){
            if(val > root->val){
                if(root->right)
                    root = root->right;
                else{
                    root->right = new Node(val);
                    return true;
                }
            }
            else if(val < root->val){
                if(root->left)
                    root = root->left;
                else{
                    root->left = new Node(val);
                    return true;
                }
            }
            else return false;
        }
        return false;
    }
    T findMin(Node*root){
        while(root->left)
            root = root->left;
        return root->val;
    }
    Node* eraseHelper(Node*root,T val){
        if(!root)
            return NULL;
        if(val > root->val){
            root->right  = eraseHelper(root->right,val);
        }
        else if(val < root->val){
            root->left = eraseHelper(root->left,val);
        }
        else {
            size--;
            if(!root->left)
                return root->right;
            if(!root->right)
                return root->left;
            root->val = findMin(root->right);
            root->right = eraseHelper(root->right,root->val);
        }
        return root;
    }
    public:
    void insert(T val){
        if(!root){
            root = new Node(val);
            size++;
        }     
        else{
           size+=insertHelper(root,val);
        }
    }
    void erase(T val){
         root = eraseHelper(root,val);
    }
    T begin(){
        Node* curr  = root;
        while(curr->left){
            curr = curr->left;
        }
        return curr->val;
    }
    T end(){
        Node* curr  = root;
        while(curr->right){
            curr = curr->right;
        }
        return curr->val;
    }
    int getSize(){
        return size;
    }
    bool empty(){
        return size == 0;
    }
    pair<bool,T> lowerBound(T val){
        Node*curr = root;
        pair<bool,T>ans ={false,-1};
        while(curr){
            if(val>curr->val)
                curr = curr->right;
            else{
                ans = {true,curr->val};
                curr = curr->left;
            }
        }
        return ans;
    }
    pair<bool,T> upperBound(T val){
        Node*curr = root;
        pair<bool,T>ans ={false,-1};
        while(curr){
            if(val>=curr->val)
                curr = curr->right;
            else{
                ans = {true,curr->val};
                curr = curr->left;
            }
        }
        return ans;
    }
    
};

int main() {
    MySet<int>s;
    s.insert(1);
    s.insert(-1);
    s.insert(1);
    s.insert(-1);
    s.insert(6);
    s.insert(7);
    cout<<s.getSize()<<"\n";
    auto[a,b] = s.upperBound(6);
    cout<<b;
  

}
