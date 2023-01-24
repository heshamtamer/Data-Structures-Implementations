#ifndef MY_TREE_H
#define MY_TREE_H
#include <bits/stdc++.h>
#include <vector>
using namespace std;

template <class T>
struct Node {
    T data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(T data) : data(data) {}
    // Add the constructors you want
};

template <class T>
class MyTree{

    private:
    // Add all private fields you want
     int size = 0;
     int height = 0;
     Node<T> *root;

     Node<T>* Binary_Search(vector<T>&vec , int l , int r){ //function to make the tree in efficient way
       if(l>r) return NULL;
       int mid=(l+r)/2+((r-l+1)%2==0); //get the middle to be the root and if even take the larger
       Node<T> *newnode= new Node<T>(vec[mid]);
       newnode->left=Binary_Search(vec , l , mid-1);
       newnode->right=Binary_Search(vec, mid+1 , r);
       return newnode;
     }

     void inorder(Node<T>*node , vector<T>&vec){ //printing sorted tree (left -> root -> right )
        if(node == nullptr) return;
        inorder(node->left , vec);
        vec.push_back(node->data);
        inorder(node->right , vec);
     }

     void preorder(Node<T>*node , vector<T>&vec){ //root -> left -> right
        if(node == nullptr) return;
        vec.push_back(node->data);
        preorder(node->left , vec);
        preorder(node->right , vec);
     }

     void postorder(Node<T>*node , vector<T>&vec){ //left -> right -> root
        if(node == nullptr) return;
        postorder(node->left , vec);
        postorder(node->right , vec);
        vec.push_back(node->data);
     }

     Node<T>* Insert(Node<T>*r , T item){
        if(r == nullptr){
            Node<T>* new_node= new Node<T>(item);
            r = new_node;
        }

        else if(item < r->data){
         r->left = Insert(r->left,item);
        }

        else{
         r->right=Insert(r->right ,item);
        }

        return r;
     }

     Node<T> *Search(Node<T>*r , T item){
        if(r == nullptr)
            return NULL;
        else if(r -> data == item)
            return r;
        else if(item < r -> data)
           return Search(r -> left , item);
        else 
           return Search(r->right  , item);
     }

     Node<T>*findmax(Node<T> *r){ //find maximum element in the tree
        if(r==nullptr)
        return NULL;
        else if(r->right == nullptr)
        return r;
        else
        return findmax(r->right);
     }

     Node<T>* Delete(Node<T>*r , T item){
        if(r == nullptr) //empty tree
        return NULL;
        else if(item < r->data) // item exist in left subtree
            r->left=Delete(r->left , item);
        else if(item > r->data) // item exist in right subtree
            r->right = Delete(r->right , item );
        else{
            if(r->right==nullptr && r->left==nullptr) //leaf node
            r == nullptr;
            else if(r->right==nullptr && r->left!=nullptr){ //node have one child on the left
                r->data = r->left->data;
                delete r->left;
                r->left = nullptr;
            }
            else if(r->right!=nullptr && r->left==nullptr){ //node have one child on the right
                r->data = r->right->data;
                delete r->right;
                r->right = nullptr ;
            }
            else { //node have two children
                Node<T> *max=findmax(r->left); //finding maximum element on the left
                r->data = max->data; // replacing this element with the root
                r->left=Delete(r->left , max->data);
            }
        }
        return r;    
     }

     void Clear(Node<T>* r){ //iterate over the tree and delete each node
        if(r== nullptr) return;
        if(r->left)  Clear(r->left);
        if(r->right) Clear(r->right);
        delete r;
    }

    int Height(Node<T>* r){ //find the hight of the tree
        if(r==nullptr)
        return -1;
        int l=Height(r->left);
        int ri=Height(r->right);
        return max(l,ri)+1;
    }



    public:
        MyTree(){
            root = nullptr;
            size =0;
            height=0;
        }
        
        MyTree(std::vector<T> elements){
            sort(elements.begin(),elements.end());
            root = Binary_Search(elements , 0 , elements.size()-1);
            size = elements.size();
        }
   
       void insert(T key){
            root = Insert(root , key);
            size++;
        }

        void insert(const Node<T> node){
            insert(node->data); //sending the data of the node to the previous function to do the same operations
            size++;
        }

        const Node<T>* search(T key){
            return Search(root , key);
        }
        
        const Node<T>* delete_node(T key){
            Delete(root , key);
            size--;
        }

        const Node<T>* delete_node(const Node<T> node){
            delete_node(node->data);
            size--;
        }

        bool isBST(){
            if(!root) return 0;
              vector<T>vec; inorder(root,vec);
            if(is_sorted(vec.begin(),vec.end())) return 1;
            return 0;
        }
        
        std::vector<T> inorder_rec(){
           vector<T>ans;
           if(root==nullptr) return ans;
           inorder(root , ans);
           return ans;
        }
        
        std::vector<T> preorder_rec(){
           vector<T>ans;
           if(root==nullptr) return ans;
           preorder(root , ans);
           return ans;
        }
        
        std::vector<T> postorder_rec(){
           vector<T>ans;
           if(root==nullptr) return ans;
           postorder(root , ans);
           return ans;
        }
        
        std::vector<T> inorder_it(){
            vector<T> ans;
            Node<T>* cur=root;
            stack<Node<T> *>st;
            if(root == nullptr)
            return ans;
            while(true){
                if(cur!=nullptr){
                    st.push(cur);
                    cur = cur->left;
                }
                else{
                    if(st.empty()) break;
                    ans.push_back(st.top()->data);
                    cur=st.top()->right;
                    st.pop();
                }
            }
            return ans;
        }
        
        std::vector<T> preorder_it(){
            vector<T> ans;
            if(root == nullptr)
            return ans;
            Node<T>* cur;
            stack<Node<T> *>st; 
            st.push(root);
            while(!st.empty()){
                cur = st.top();
                st.pop();
                ans.push_back(cur->data);
                if(cur->right != nullptr)
                st.push(cur->right);
                if(cur->left != nullptr)
                st.push(cur->left);
            }
            return ans;
        }
        
        std::vector<T> postorder_it(){
            vector<T> ans;
            if(root == nullptr)
            return ans;
            Node<T>* cur;
            stack<Node<T> *>st; st.push(root);
            stack<Node<T> *>st_res;
            while(!st.empty()){
                cur=st.top();
                st.pop();
                st_res.push(cur);
                if(cur->left != nullptr)
                st.push(cur->left);
                if(cur->right != nullptr)
                st.push(cur->right);
            }  
            while(!st_res.empty()){
                ans.push_back(st_res.top()->data);
                st_res.pop();
            }
            return ans;
        }

        std::vector<T> breadth_traversal(){ //storing the element level by level
            vector<T> ans;
            if(root == nullptr) return ans;
            queue< Node<T>* > q; 
            q.push(root);
            while(!q.empty()){
                Node<T>* cur = q.front(); 
                q.pop();
                ans.push_back(cur->data);
                if(cur->left != nullptr)
                q.push(cur->left);
                if(cur->right != nullptr)
                q.push(cur->right);
            }
            return ans;
        }

        int get_size(){
            return size;
        }

        int get_height(){
            return Height(root);
        }

        void clear(){
            Clear(root);
            size=0; 
            height=0;
            root=nullptr;
        }

        ~MyTree(){ //it`s the same to the clear function so call it
            clear();
        }
};

#endif