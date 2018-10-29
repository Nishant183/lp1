#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;


class node
{
   public:
	
	node *left, *right;
	int data;

};	 

class Breadthfs
{
 
 public:
 
 node *insert(node *, int);
 void bfs(node *);
 
};


node *insert(node *root, int data)
{

	if(!root)
	{
		
		root=new node;
		root->left=NULL;
		root->right=NULL;
		root->data=data;
		return root;
	}

	queue<node *> q;
	q.push(root);
	
	while(!q.empty())
	{

		node *temp=q.front();
		q.pop();
	
		if(temp->left==NULL)
		{
			
			temp->left=new node;
			temp->left->left=NULL;
			temp->left->right=NULL;
			temp->left->data=data;	
			return root;
		}
		else
		{

		q.push(temp->left);

		}

		if(temp->right==NULL)
		{
			
			temp->right=new node;
			temp->right->left=NULL;
			temp->right->right=NULL;
			temp->right->data=data;	
			return root;
		}
		else
		{

		q.push(temp->right);

		}

	}
	
}


void bfs(node *head)
{

		queue<node*> q;
		q.push(head);
		
		int f;
		
		while (!q.empty()) 
		{
			f = q.size();
			#pragma omp parallel for
			for (int i = 0; i < f ; i++) 
			{
				node* temp ;
				#pragma omp critical
				{
				  temp = q.front();
				  q.pop();
				  cout<<"  "<<temp->data;
				
				}
				#pragma omp critical
				{
				if(temp->left)
					q.push(temp->left);
				if(temp->right)
					q.push(temp->right);
				}		

			}
		}

}

int main(){

	node *root=NULL;
	int data;
	char ans;
	
	do
	{
		cout<<"\n Enter Value :";
		cin>>data;
		
		root=insert(root,data);
	
		cout<<"Want to insert one more ?(y/n)";
		cin>>ans;
	
	}while(ans=='y'||ans=='Y');
	
	cout<<"BFS: ";
	bfs(root);
	
	return 0;
}


/*output

 Enter Value :1
Want to insert one more ?(y/n)y

 Enter Value :2
Want to insert one more ?(y/n)y

 Enter Value :8
Want to insert one more ?(y/n)y

 Enter Value :7
Want to insert one more ?(y/n)y

 Enter Value :10
Want to insert one more ?(y/n)n

BFS:   1  2  8  7  10

*/
