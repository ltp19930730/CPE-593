#include <iostream>
#include <Stack>
#include <queue>
#include <string>
using namespace std;
class BinaryTree
{
private:
	class TreeNode{
	public:
		TreeNode* lchild;
		TreeNode* rchild;
        int data;
        TreeNode(int data):
        data(data),lchild(nullptr),rchild(nullptr){}
        
	};

public:
    TreeNode* root;
	BinaryTree():root(nullptr){}
    ~BinaryTree()
    {
    	destroyTree(root);
    }

    void destroyTree(TreeNode* leaf)
	{

		if(leaf!=nullptr)
		{
			destroyTree(leaf->lchild);
			destroyTree(leaf->rchild);
			delete leaf;
		}
	}
	//destroy the tree
    
    void createTree(int data)
    {
    	insert(root,data);
    }

    //insert the number into the tree
	void insert(TreeNode* &root,int data)
	{
		if(root==nullptr)
		{
			root = new TreeNode(data);

		}else if(data<= root->data){
			insert(root->lchild,data);
		}else if(data >root->data){
			insert(root->rchild,data);
		}
        
	}

    void depthFirstSearch()
    {
    	stack<TreeNode *> nodeStack;
    	nodeStack.push(root);
    	TreeNode *node;
    	while(!nodeStack.empty())
    	{
    		node=nodeStack.top();
    		cout<<node->data;
    		nodeStack.pop();
    		if(node->rchild)
    		{
    			nodeStack.push(node->rchild);
    		}
    		if(node->lchild)
    		{
    			nodeStack.push(node->lchild);
    		}

    	}
    }
    void breadthFirstSearch(){
    queue<TreeNode *> nodeQueue;  
    nodeQueue.push(root);
    TreeNode *node;
    while(!nodeQueue.empty()){
        node = nodeQueue.front();
        nodeQueue.pop();
        cout<<node->data;
        if(node->lchild){
            nodeQueue.push(node->lchild);  //先将左子树入队
        }
        if(node->rchild){
            nodeQueue.push(node->rchild);  //再将右子树入队
        }
    }
}
};

int main()
{
	BinaryTree Tree;
	int arr[8]={5,2,3,1,4,6,7,8};
	for(int i=0;i<8;i++){
		Tree.createTree(*(arr+i));
		cout<<*(arr+i);
	}
	cout<<endl;
	
		Tree.depthFirstSearch();
		cout<<endl;
		Tree.breadthFirstSearch();
    return 0;
}