// Online C++ compiler to run C++ program online
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node*lchild;
	struct node*rchild;
};

struct node*root=NULL;

void insert(int element)
{
	struct node*tempnode=new node();
	struct node*current;
	struct node*parent;
	
	tempnode->data=element;
	tempnode->lchild=NULL;
	tempnode->rchild=NULL;
	
	if(root==NULL)
	{
		root=tempnode;
	}
	else
	{
		current=root;
		parent=NULL;
		
		while(1)
		{
			parent=current;
			
			if(element<current->data)//left side
			{
				current=current->lchild;
				if(current==NULL)
				{
					parent->lchild=tempnode;
					return;
				}
			}
			
			else if(element>=current->data)//right side
			{	
				current=current->rchild;
				if(current==NULL)
				{
					parent->rchild=tempnode;
					return;
				}
				
			}
		}
	}
}


void inorder(struct node*temp)
{
	if(temp!=NULL)
	{	
		inorder(temp->lchild);
		cout<<temp->data<<" ";
		inorder(temp->rchild);
	}
}

void preorder(struct node*temp)
{
	if(temp!=NULL)
	{	
		cout<<temp->data<<" ";
		preorder(temp->lchild);
		preorder(temp->rchild);
	}
}

void postorder(struct node*temp)
{
	if(temp!=NULL)
	{	
		postorder(temp->lchild);
		postorder(temp->rchild);
		cout<<temp->data<<" ";
	}
}


node*deletion(node* root, int k) 
{ 
    // Base case 
    if (root == NULL) 
        return root; 
  
    // Recursive calls for ancestors of 
    // node to be deleted 
    if (root->data > k) { 
        root->lchild = deletion(root->lchild, k); 
        return root; 
    } 
    else if (root->data < k) { 
        root->rchild = deletion(root->rchild, k); 
        return root; 
    } 
  
    // We reach here when root is the node 
    // to be deleted. 
  
    // If one of the children is empty 
    if (root->lchild == NULL) { 
        node* temp = root->rchild; 
        delete root; 
        return temp; 
    } 
    else if (root->rchild == NULL) { 
        node* temp = root->lchild; 
        delete root; 
        return temp; 
    } 
  
    // If both children exist 
    else { 
  
        node* succParent = root; 
          
        // Find successor 
        node *succ = root->rchild; 
        while (succ->lchild != NULL) { 
            succParent = succ; 
            succ = succ->lchild; 
        } 
  
        // Delete successor.  Since successor 
        // is always left child of its parent 
        // we can safely make successor's right 
        // right child as left of its parent. 
        // If there is no succ, then assign  
        // succ->right to succParent->right 
        if (succParent != root) 
            succParent->lchild = succ->rchild; 
        else
            succParent->rchild = succ->rchild; 
  
        // Copy Successor Data to root 
        root->data = succ->data; 
  
        // Delete Successor and return root 
        delete succ;          
        return root; 
    } 
}

void height()
{
	
}

int count=0;
void depth(struct node *root, int target)
{
	if(root->data==target)
	{
		cout<<"Depth is:"<<count;
	}
	
	else if(root->data<target)
	{
		count++;
		depth(root->rchild,target);
	}
	else if(root->data>target)
	{
		count++;
		depth(root->lchild,target);
	}
}

bool ancestors(struct node *root, int target) 
{ 
  /* base cases */
  if (root == NULL) 
     return false; 
  
  if (root->data == target) 
     return true; 
  
  /* If target is present in either left or right subtree of this node, 
     then print this node */
  if ( ancestors(root->lchild, target) || ancestors(root->rchild, target) ) 
  { 
    cout << root->data << " "; 
    return true; 
  } 
  
  /* Else return false */
  return false; 
}

void descendents(struct node *root, int target)
{

	
	if(root->data==target)
	{
		preorder(root);
	}
	
	else if(root->data<target)
	{
		descendents(root->rchild,target);
	}
	
	else if(root->data>target)
	{
		descendents(root->lchild,target);
	}
}

void find(node *root,node*& pre,node*& suc,int element) 
{
	if(root==NULL)
	{
		return ;
	}
	
	/*if key(the given node) is the root*/ 
	if(root->data==element)        
	{
		if(root->lchild != NULL)
		{
			node* temp=root->lchild;
			while(temp->rchild != NULL)
			{
				temp=temp->rchild;
			}
			pre=temp;
		}
		if(root->rchild != NULL)
		{
			node* temp=root->rchild;
			while(temp->lchild != NULL)
			{
				temp=temp->lchild;
			}
			suc=temp;
		}
		return ;
	}
	
	/*if key is less than current node(root)*/
	if(root->data >element)       
	{
		suc=root;
		/*Search the left subtree*/
		find(root->lchild,pre,suc,element);   
	}
	/*if key is greater than current node(root)*/
	else
	{
		pre=root;
		/*Search the right subtree*/
		find(root->rchild,pre,suc,element);  
	}
} 


int main()
{
	int n,i,a[50],choice;
	char ch;
	cout<<"Enter the initial number of elements to be inserted:";
	cin>>n;
	cout<<"Enter the elements:";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		insert(a[i]);
	}
	cout<<"Initial elements inserted successfully."<<endl;
	do{
	cout<<"--------------------------------------------------------"; 
	cout<<endl;
	cout<<"Please Choose the desired operation number from the menu"<<endl;
	cout<<"1-Insert an element"<<endl;
	cout<<"2-Delete an element"<<endl;
	cout<<"3-Find height of a node"<<endl;
	cout<<"4-Find depth of a node"<<endl;
	cout<<"5-Find ancestors of a node"<<endl;
	cout<<"6-Find descendants of a node"<<endl;
	cout<<"7-Find predecessor"<<endl;
	cout<<"8-Find successor"<<endl;
	cout<<"9-Print in inorder"<<endl;
	cout<<"10-Print in preorder"<<endl;
	cout<<"11-Print in postorder"<<endl;
	cout<<"Your choice is: ";
	cin>>choice;
	int ele;
	node*pre=NULL;
	node*suc=NULL;
	
	switch(choice)
	{
		case 1:
			{
				
				cout<<"Enter element:";
				cin>>ele;
				insert(ele);
				break;
			}
			
		case 2:
			{
				node*rootz;
				cout<<"Enter element:";
				cin>>ele;
				rootz=deletion(root,ele);
				cout<<"The inorder traversal after deletion is:";
				inorder(rootz);
				cout<<endl;
				break;
				
			}
			
		case 3:
			{
				
				break;	
			}
			
		case 4:
			{
				cout<<"Enter element:";
				cin>>ele;
				depth(root,ele);
				break;
			}
		
		case 5:
			{
				cout<<"Enter element:";
				cin>>ele;
				cout<<"The ancestors are:"<<endl;
				ancestors(root,ele);
				break;
			}
			
		case 6:
			{
				cout<<"Enter element:";
				cin>>ele;
				cout<<"The descendents are:"<<endl;
				descendents(root,ele);
				break;
			}			
				
		case 7:
			{
				
				cout<<"Enter element:";
				cin>>ele;
				find(root,pre,suc,ele);
				cout<<"The predecessor of "<<ele<<" is: "<<pre->data;
				cout<<endl;
				break;
			}
			
		case 8:
			{
				
				cout<<"Enter element:";
				cin>>ele;
				find(root,pre,suc,ele);
				cout<<"The successor of "<<ele<<" is: "<<suc->data;
				cout<<endl;
				break;
			}	
		case 9:
			{
				struct node*tempnode=new node();
				tempnode=root;
				inorder(tempnode);
				cout<<endl;
				break;
			}
		
		case 10:
			{
				struct node*tempnode=new node();
				tempnode=root;
				preorder(tempnode);
				cout<<endl;
				break;	
			}
		case 11:
			{
				struct node*tempnode=new node();
				tempnode=root;
				postorder(tempnode);
				cout<<endl;
				break;	
			}
		
	}

	cout<<"Press q to exit,or any other key to continue:";
	cin>>ch;
	}
	while(ch!='q');

	return (0);
}
