#include <iostream>
#include <memory>
#include <queue>
#include <stack>

class BST{
private:
    struct Node {
        int data;
        //unique_ptr es el dueño de Node*, pero no Node* en sí
        //por eso para coger algo de estos necesito el .get()
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;

        Node(int d) : data(d) {}
    };

    std::unique_ptr<Node> root;

    /* ======PRIVATE HELPERS ======*/
    
    void insert(std::unique_ptr<Node>& node, int data){
        if(!node){
            node = std::make_unique<Node>(data);
            return;
        }
        if(data < node->data){
            insert(node->left, data);
        } else if(data > node->data){
            insert(node->right, data);
        } else {
            std::cout << "The value already exists\n";
        }       
    }

    int height(Node* node) const{
        if(!node) return 0;
        return std::max(height(node->left.get()),
                        height(node->right.get())) + 1;
    }

    Node* getMin(Node *node) const{
        while(node && node->left){
            node = node->left.get();
        }
        return node;
    }

    bool isBST(Node* node, int min, int max) const {
        if(!node) return true;
        if(node->data <=min || node->data >= max) return false;

        return isBST(node->left.get(), min, node->data) &&
               isBST(node->right.get(), node->data, max);
    }

    void deleteNode(std::unique_ptr<Node>& node, int value){
        if(!node) return;

        if(value < node->data){
            deleteNode(node->left, value);
        } else if (value > node->data){
            deleteNode(node->right, value);
        } else {
            if(!node->left && !node->right){
                node.reset();
            } else if (!node->left){
                node = std::move(node->right);
            } else if (!node->right){
                node = std::move(node->left);
            } else {
                Node* successor = getMin(node->right.get());
                node->data = successor->data;
                deleteNode(node->right, successor->data);
            }
        }
    }

public:
    /* ======PUBLIC API======*/

    void insert(int data){
        insert(root, data);
    }

    void bfs() const{
        if(!root) return;

        std::queue<Node*> q;
        q.push(root.get());

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            std::cout << curr->data << " ";

            if(curr->right) q.push(curr->right.get());
            if(curr->left) q.push(curr->left.get());
            
            
        }
        std::cout << "\n";
    }

    void dfs() const{
        if(!root) return;

        std::stack<Node*> s;
        s.push(root.get());

        while(!s.empty()){
            Node* curr = s.top();
            s.pop();

            std::cout << curr->data << " ";
            if(curr->right) s.push(curr->right.get());
            if(curr->left) s.push(curr->left.get());
            
        }
        std::cout << '\n';
    }

    int height() const{
        return height(root.get());
    }

    int min() const{
        Node* m = getMin(root.get());
        if (!m) throw std::runtime_error("Tree is empty");
        return m->data;
    }

    bool isBST() const {
        return isBST(root.get(), 
                    std::numeric_limits<int>::min(),
                    std::numeric_limits<int>::max());
    }

    void deleteNode(int value){
        deleteNode(root, value);
    }   
};

int main(){
    BST tree;
    int option;

    while(true){
        std::cout << "\n0: Exit\n1: Insert\n2: BFS\n3: DFS\n4: Height\n5: Min\n6: Is BST\n";
        std::cin >> option;

        if (option == 0) break;

        switch(option){
            case 1:
                int x;
                std::cout << "Insert value (0 to stop): ";
                while(true){
                    std::cin >> x;
                    if (x == 0) break;
                    tree.insert(x);
                }
                break;
            case 2:
                tree.bfs();
                break;
            case 3:
                tree.dfs();
                break;
            case 4:
                std::cout << "Height: " << tree.height() << '\n';
            case 5:
                try{
                   std::cout << "Min: " << tree.min() << '\n'; 
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << '\n';
                }
            case 6:
                std::cout << (tree.isBST() ? "Is BST\n" : "Not BST\n");
                break;  
            case 7:
                int value = 0;
                std::cin >> "Insert value to delete: " >> value;
                tree.deleteNode(value);
            }

    }

    return 0;
}