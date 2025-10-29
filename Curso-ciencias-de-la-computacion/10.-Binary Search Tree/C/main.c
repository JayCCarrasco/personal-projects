#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int run_dfs = 1; //global variable to control how many times dfs is called

typedef struct Node{
    int data;
    int visited;   //Visited will be compare to run_dfs to determine if the node has been visited in that dfs call
    struct Node* left;
    struct Node* right;
} Node;

typedef struct queueNode{
    Node* treeNode;
    struct queueNode* next;
} queueNode;

void enqueue(Node* node, queueNode** front, queueNode** rear){
    queueNode* newNode = malloc(sizeof(queueNode));
    newNode->treeNode = node;
    newNode->next = NULL;

    if(*rear) (*rear)->next = newNode;
    else (*front) = newNode;
    (*rear) = newNode;
}

Node* dequeue(queueNode** front, queueNode** rear){
    if(*front == NULL) return NULL;

    queueNode* temp = *front;
    Node* node = temp->treeNode;
    *front = temp->next;
    if(*front == NULL) (*rear = NULL);
    free(temp);
    return node;
}

void breadthFirstSearch(Node* node){
    if (node == NULL) return;

    queueNode* front = NULL;
    queueNode* rear = NULL;

    enqueue(node, &front, &rear);

    while(front != NULL){
        Node* current = dequeue(&front, &rear);
        printf("%d ", current->data);

        if(current->left){
            enqueue(current->left, &front, &rear);
        }
        if(current->right){
            enqueue( current->right, &front, &rear);
        }
    }

}

Node* createNode(int data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->visited = 0;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void addNode(Node** root, int data){
    Node* newNode = createNode(data);

    if (*root == NULL) {
        *root = newNode;
        return;
    }
   
    Node* temp = *root;
    Node* parent = NULL;

    while(temp != NULL) {
        parent = temp;
        if (newNode->data < temp->data){
            temp = temp->left;
        } else if (newNode->data > temp->data){
            temp = temp->right;
        } else {
            printf("The value is already in the tree\n");
            return;
        }
    }
    if (newNode->data < parent->data){
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
}

//depthFirstSearch configure as PostOrder DFS
void depthFirstSearch(Node* root, int type){
    if (root == NULL) return;
    if(type == 0){
        printf("%d ", root->data);
    }
    depthFirstSearch(root->left, type);
    if(type == 1){
        printf("%d ", root->data);
    }
    depthFirstSearch(root->right, type); 
    if(type == 2){
        printf("%d ", root->data);
    } 
}

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int lookHeight(Node* root){
    if (root == NULL) return 0;

    int lHeight = lookHeight(root->left);
    int rHeight = lookHeight(root->right);

    return (lHeight > rHeight ? lHeight : rHeight) + 1;
}

Node* getMin(Node* root){
    if (root == NULL) return root;

    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* getMax(Node* root){
    if (root == NULL) return root;

    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

Node* deleteNode(Node* root, int data){
    if (root == NULL) return root;
    if(data < root->data) root->left = deleteNode(root->left, data);
    else if (data > root->data) root->right = deleteNode(root->right, data);
    else{
        if(root->right == NULL && root->left == NULL){
            free(root);
            root = NULL;
        } else if (root->left == NULL){
            Node* temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL){
            Node* temp = root;
            root = root->left;
            free(temp);
        } else {
            Node* temp = getMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int isBSTUtil(Node* root, int min, int max){
    if (root == NULL){
        return 1;
    }
    if (root->data <= min || root->data >= max){
        return 0;
    }
    return  isBSTUtil(root->left, min, root->data) &&
            isBSTUtil(root->right, root->data, max);
}

int isBST(Node* root){
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

Node* inOrderSuccessor(Node* root, int target){
    if (root == NULL) return NULL;

    if (root->data == target){
        return getMin(root->right);
    }

    Node* curr = root;
    Node* succ = NULL;
    
    while(curr != NULL){
        if (target < curr->data){
            succ = curr;
            curr = curr->left;
        } else if (target >= curr->data){
            curr = curr->right;
        }
    }
    return succ;
}

int main(){
    Node* root = NULL;
    int exit = -1;      //Exit main    
    int option = -1;    //Main option
    int data = -1;      //Data to insert    
    int type = -1;      //Type of DFS
    int target = 0;

    while (exit != 0){       
        printf("Choose an option: \n");
        printf("0: Exit\n");
        printf("1: Insert data\n");
        printf("2: Breadth First Search\n");
        printf("3: Depth First Search\n");
        printf("4: Print values from min to max\n");
        printf("5: Height of the tree\n");
        printf("6: Get minimum value\n");
        printf("7: Delete value\n");
        printf("8: Check if is BST\n");
        printf("9: Get successor\n");
        printf("10: Get maximum value\n");
        scanf("%d", &option);

        switch(option){
            case 0:
                printf("Exiting...\n");
                exit = 0;
                break;
            case 1:
                while(data != 0){
                    printf("Insert data (0 to stop): ");
                    scanf("%d", &data);
                    if(data == 0) break;
                    addNode(&root, data);
                }
                data = -1;
                break;
            case 2:
                breadthFirstSearch(root);
                break;
            case 3:
                printf("Choose type: \n");
                printf("0: Preorder DFS\n");
                printf("1: Inorder DFS\n");
                printf("2: Postorder DFS\n");
                scanf("%d", &type);
                depthFirstSearch(root, type);
                run_dfs++;
                break;   
            case 4:
                depthFirstSearch(root, 1);
                break;  
            case 5:
                int height = lookHeight(root);
                printf("The high is %d\n", height); 
                break;   
            case 6:
                Node* min = getMin(root);
                if (min == NULL){
                    printf("Tree is empty\n");
                    break;
                }
                printf("The min is %d\n", min->data); 
                break;    
            case 7:
                printf("Insert data to delete: ");
                scanf("%d", &data);
                deleteNode(root, data);
                break;
            case 8:
                int confirmed = isBST(root);
                if (confirmed == 1){
                    printf("It is a tree\n");
                }else{
                    printf("It is not a tree");
                }
                root->left->right->right = createNode(9); // 9 violates BST property
                confirmed = isBST(root);
                if (confirmed == 1){
                    printf("It is a tree\n");
                }else{
                    printf("It is not a tree\n");
                }
                break;
            case 9:
                printf("Insert target: ");
                scanf("%d", &target);
                Node* successor = inOrderSuccessor(root, target);
                if(successor == NULL){
                    printf("There is no successor\n");
                    break;
                }
                printf("The successor is %d\n", successor->data);
                break;
            case 10:
                Node* max = getMax(root);
                if (max == NULL){
                    printf("Tree is empty\n");
                    break;
                }
                printf("The max is %d\n", max->data); 
                break; 
        }      
    }
    
    freeTree(root);   

    return 0;
}