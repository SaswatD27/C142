#include<iostream>
using namespace std;
class node
{
	int a;
	Node *left;
	Node *right,*par;
	public:
	node(int n)
	{
		a=n;
		par=NULL;
		left=NULL;
		right=NULL;
	}
};
class BSTree
{
	node *root,*curr;
	public:
	BSTree()
	{
		root=NULL;
		curr=root;
	}
	void insertn(int n,node *curr)
	{
		if(root==NULL)
		{
			root=new node;		
			root->a=n;
		}
		else
		{
			int flag=0;
			if(n<curr->a)
			{	
				cout<<" Left ";
				if(curr->left==NULL)
				{
					curr->left=new node;
					curr->left->par=curr;
					curr->left->a=n;
					return;
				}
				insertn(n,curr->left);
			}
			else if(n>curr->a)
			{
				cout<<" Right ";
				{
					curr->right=new node;
					curr->right->par=curr;
					curr->right->a=n;
					return;
				}
				insertn(n,curr->right);
			}
		}
	}
	void insert(int n)
	{
		insertn(n,root);
	}
	void display(node *curr=root)
	{
		//base condition
		if(curr==NULL) return;
		//display left
		display(curr->left);
		//display current
		cout<<curr->a<<",";
		//display right
		display(curr->right);
	}
	/*node displayfancy(int spaces)
	{
		//Increase no. of spaces
		//display right
		//print req spaces
		//display curr
		//display left*/
	node *search(int n,node *curr)
	{
		if(curr==NULL)
		{
			cout<<"Not found";
			return NULL;
		}
		else
		{
			if(curr->a==n)
			{
				cout<<n<<" found.";
				return curr;
			}
			else if(curr->a>n)
			return search(n,curr->left);
			else if(curr->a<n)
			return search(n,curr->right);
		}		
		/*else
		{
			while(t->left!=NULL||t->right!=NULL)
			{
				if(t->a==n)
				return t;
				else if(n<t->a)
				{
					if(t->left!=NULL)
					{					
						t=t->left;
						cout<<" Left ";
					}
					else
					{
						cout<<n<<" was not found."
						return NULL;
					}	
				}
				else if(n>t->a)
				{
					if(t->right!=NULL)
					{					
						t=t->right;
						cout<<" Right ";
					}				
					else
					{
						cout<<n<<" was not found."
						return NULL;
					}	
				}
			}
		}*/
	}	
	int height(node *curr=root,int h=0)
	{
		if(curr==NULL)
		return h;
		else
		{
			int l=height(curr->left,h+1);
			int r=height(curr->right,h+1);
			if(l>=r)
			return l;
			if(r>l)
			return r;
		}
	}
	/*node *searchpar(node *p,node *t)
	{
		if(p->left==t||p->right==t)
		return p;
		else
		{
			if(t->a<p->a)
			return searchpar(p->left,t);
			if(t->a>p->a)
			return searchpar(p->right,t);
		}
	}*/
	void deleten(int n) //WIP
	{
		node *t=search(n);
		if(t==NULL)
		cout<<"Not found hence couldn't be deleted.";
		else if(t->left!=NULL&&t->right!=NULL)
		{
			node *t1=find_min(t->right);
			t->a=t1->a;
			deleten(t->a);
		}
		else if(t->left!=NULL||t->right!=NULL)
		{
			if(t->left!=NULL)
			node *temp=t->left;
			else if(t->right!=NULL)
			node *temp=t->right;
			temp->par=t->par;
			if(t->par->left==t)
			t->par->left=temp;
			if(t->par->right==t)
			t->par->right=temp;
			delete t;
		}
		else //if t has no children
		delete t;		
		/*else
		{
			if(t->par->left==t)
			p->left=NULL;
			else if(t->par->right==t)
			p->right=NULL;
			delete t;
		}
	}
		node *curr=search(n);
		if(curr!=NULL)
		{
			if(curr==root)
			{
				delete root;
				root=NULL
			}
			else
			{
				node *t1=NULL, *t2=NULL;
				int flag=0;
				for(int i=n-1,int j=n+1;flag==0;i--,j++)
				{
					t1=search(i);
					t2=search(j);					
					if(t1!=NULL&&t2==NULL)
					{
						flag=1;
						if(t1->left==curr)
						{
							t1->left=NULL;
							delete curr;					
						}
						if(t1->right==curr)
						{
							t1->right=NULL;
							delete curr;					
						}
					}
					if(t2!=NULL&&t1==NULL)
					{
						flag=1;
						if(t2->left==curr)
						{
							t2->left=NULL;
							delete curr;					
						}
						if(t2->right==curr)
						{
							t2->right=NULL;
							delete curr;					
						}
					}						
					if(t1!=NULL&&t2!=NULL)
					{
						if(t1->left==curr)
						{
							t1->left=NULL;
							delete curr;					
						}
						if(t1->right==curr)
						{
							t1->right=NULL;
							delete curr;					
						}
						if(t2->left==curr)
						{
							t2->left=NULL;
							delete curr;					
						}
						if(t2->right==curr)
						{
							t2->right=NULL;
							delete curr;					
						}
						flag=1;
					}
				}
			}
		}
	} alt delete*/
	node *find_min(node *curr)
	{
		if(curr->left==NULL)
		return curr;
		else
		find_min(curr->left);
	}
	int count(node *curr,int h=0)
	{
		if(curr!=NULL)
		{
			int l=count(curr->left,h+1);
			int r=count(curr->right,h+1);
			return (l+r);
		}
		else
		return h;
	}
};
void main()
{
	int ch=1,a;
	BSTree b;
	do
	{
		cout<<"\t\tBinary Search Tree Gen\n\n1. Insert Node\n2.Delete Node\n3. Search value\n4. Display Tree\n5. Display Height\nMake your choice - "
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"Enter an int value - ";
				cin>>a;
				b.insert(a);
				break;
			case 2:cout<<"Enter the value of the node you wish to delete - ";
				cin>>a;
				b.deleten(a);
			case 3:cout
