# include<iostream>
using namespace std;

class tbt{
	public:
	int data;
	tbt*left,*right;
	bool rthread,lthread;
	tbt(){
		left=NULL;
		right=NULL;
		lthread=true;
		rthread=true;
	}

	tbt*creat(int);
	tbt*insert(tbt*,tbt*);
	tbt*leftmostnode(tbt*);
	void inorder(tbt*,tbt*);
	tbt*preorder(tbt*,tbt*);
};
tbt*tbt::creat(int value){    //pointer is use to write whole newnode 
	tbt*newnode=new tbt();
	newnode->data=value;
	/*newnode->left=newnode;
	newnode->right=newnode;*/
/*	newnode->lthread=true;
	newnode->rthread=true;*/
	return newnode;
}
tbt*tbt::insert(tbt*root,tbt*head){
	int value;
	
	cout<<"enter the your number ";
	cin>>value;
	tbt*newnode=creat(value);
	if(root==NULL){
		head->left=newnode;
		root=newnode;
		root->left=head;
		root->right=head;
		head->lthread=false;
	//	cout<<root->data;
		return root;
		
	}
	else {
	tbt* curr=root;
		while(1){
		//	cout<<curr->data;
			if(curr->data==value){
				cout<<"the element is already present in tree";
				return root;
				break;
			}
			 else if(value<curr->data){
				if(curr->lthread){
						 
				newnode->left=curr->left;
				curr->left=newnode;
				newnode->right=curr;
				curr->lthread=false;
			
					break;
				}
				else{
					curr=curr->left;
				}
			}
			else {
				if(curr->rthread){
					newnode->right=curr->right;
				newnode->left=curr;
				curr->right=newnode;
				curr->rthread=false;
					break;
				}
				else{
					curr=curr->right;
				}
			}
			}
		
		
				
			
		}
		
		return root;
	}
	
	

tbt*tbt::leftmostnode(tbt*node){
	if(node==NULL){
		return NULL;
	}
	else{
		while(node->lthread!=true){
			node=node->left;
		
		}
		return node;
	}
	
}
void tbt::inorder(tbt*root,tbt*head){
	tbt*curr=leftmostnode(root);
//	cout<<curr->data;
	while(curr!=head){
		cout<<curr->data<<" ";
		if(curr->rthread){
			curr=curr->right;
		}
		else{
			curr=leftmostnode(curr->right);
		}
	}
}
tbt*tbt::preorder(tbt*root,tbt*head){
	tbt*curr=root;
while(1){
	cout<<curr->data<<" ";
	if(curr->lthread==false){
		curr=curr->left;
	}
	else if(curr->rthread==false){
		curr=curr->right;
	}
	else{
		while(curr->right!=head && curr->rthread==true){
			curr=curr->right;}
			if(curr->right!=head){
				curr=curr->right;
			}
			else{
				break;
			}
		
	}
}
}


int main()
{
	tbt*root=NULL;
	tbt a1;
	tbt*head=a1.creat(999);
	int ch;
	do{
		cout<<"\n1) 1 for creat a tbt \n2) 2 for inorder traversal \n3) 3 for preorder traversal"<<endl;
		cin>>ch;
		switch(ch){
			case 1:
			root=a1.insert(root,head);
			break;
			case 2:
				a1.inorder(root,head);
				break;
			case 3:
				a1.preorder(root,head);
			
		}
	}while(ch!=0);
	
}