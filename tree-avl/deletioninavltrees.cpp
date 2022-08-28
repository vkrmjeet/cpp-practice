#include<iostream>
using namespace std;

struct node
{
	struct node *lchild;
	int height;
	int data;
	struct node *rchild;
}*root=nullptr;

int nodeheight(struct node *t)
{
	int hl,hr;
	hl = (t && t->lchild) ? t->lchild->height : 0;
	hr = (t && t->rchild) ? t->rchild->height : 0;

	return hl>hr ? hl+1 : hr+1;
}

int balancefactor(struct node *t)
{
	int hl,hr;
	hl = (t && t->lchild) ? t->lchild->height : 0;
	hr = (t && t->rchild) ? t->rchild->height : 0;

	return hl-hr;
}

node *inpred(struct node *t)
{
	while(t && t->rchild)
	{
		t = t->rchild;
	}
	return t;
}

node * insucc(struct node *t)
{
	while(t && t->lchild)
	{
		t = t->lchild;
	}
	return t;
}

node * LLrotation(struct node *t)
{
	struct node *tl = t->lchild;
	struct node *tlr = tl->rchild;

	tl->rchild = t;
	t->lchild = tlr;

	t->height = nodeheight(t);
	tl->height = nodeheight(tl);

	if(root==t)
	{
		root = tl;
	}

	return tl;
}

node * LRrotation(struct node *t)
{
	struct node *tl = t->lchild;
	struct node *tlr = tl->rchild;

	tl->rchild = tlr->lchild;
	t->lchild = tlr->rchild;
	tlr->lchild = tl;
	tlr->rchild = t;

	t->height = nodeheight(t);
	tl->height = nodeheight(tl);
	tlr->height = nodeheight(tlr);

	if(root==t)
	{
		root = tlr;
	}

	return tlr;
}

node * RRrotation(struct node *t)
{
	struct node *tr = t->rchild;
	struct node *trl = tr->lchild;

	t->rchild = trl;
	tr->lchild = t;

	t->height = nodeheight(t);
	tr->height = nodeheight(tr);

	if(root==t)
	{
		root = tr;
	}
	return tr;
}

node * RLrotation(struct node *t)
{
	struct node *tr = t->rchild;
	struct node *trl = tr->lchild;

	t->rchild = trl->lchild;
	tr->lchild = trl->rchild;
	trl->lchild = t;
	trl->rchild = tr;

	t->height = nodeheight(t);
	tr->height = nodeheight(tr);
	trl->height = nodeheight(trl);

	if(root==t)
	{
		root = trl;
	}

	return trl;
}

node * insert(struct node *t, int key)
{
	struct node *temp;
	if(t==nullptr)
	{
		temp = new node;
		temp->data = key;
		temp->height = 1;
		temp->rchild = temp->lchild = nullptr;
		return temp;
	}

	if(key<t->data)
	{
		t->lchild = insert(t->lchild,key);
	}
	else if(key>t->data)
	{
		t->rchild = insert(t->rchild,key);
	}
	else
	{
		cout<<key<<" node already exist in the tree"<<endl;
	}
	t->height = nodeheight(t);

	if(balancefactor(t)==2 && balancefactor(t->lchild)==1)
	{
		return LLrotation(t);
	}
	else if(balancefactor(t)==2 && balancefactor(t->lchild)==-1)
	{
		return LRrotation(t);
	}
	else if(balancefactor(t)==-2 && balancefactor(t->rchild)==-1)
	{
		return RRrotation(t);
	}
	else if(balancefactor(t)==-2 && balancefactor(t->rchild)==1)
	{
		return RLrotation(t);
	}

	return t;
}

node *deletee(struct node *t,int key)
{
	if(t==nullptr)
	{
		return nullptr;
	}
	if(t->lchild==nullptr && t->rchild==nullptr)
	{
		if(t==root)
		{
			root = nullptr;
		}
		delete t;
		return nullptr;
	}
	if(key<t->data)
	{
		t->lchild = deletee(t->lchild,key);
	}
	else if(key>t->data)
	{
		t->rchild = deletee(t->rchild,key);
	}
	else
	{
		struct node *q;
		if(nodeheight(t->lchild)>nodeheight(t->rchild))
		{
			q = inpred(t->lchild);
			t->data = q->data;
			q->lchild = deletee(q->lchild,key);
		}
		else
		{
			q = insucc(t->rchild);
			t->data = q->data;
			t->rchild = deletee(t->rchild,key);
		}
	}
	t->height = nodeheight(t);

	if(balancefactor(t)==2 && balancefactor(t->lchild)==1)
	{
		LLrotation(t);
	}
	else if(balancefactor(t)==2 && balancefactor(t->lchild)==-1)
	{
		LRrotation(t);
	}
	else if(balancefactor(t)==-2 && balancefactor(t->rchild)==-1)
	{
		RRrotation(t);
	}
	else if(balancefactor(t)==-2 && balancefactor(t->rchild)==1)
	{
		RLrotation(t);
	}
	else if(balancefactor(t)==2 && balancefactor(t->lchild)==0)
	{
		LLrotation(t);
	}
	else if(balancefactor(t)==-2&& balancefactor(t->rchild)==0)
	{
		RRrotation(t);
	}
	return t;
}

void inorder(struct node *t)
{
	if(t)
	{
		inorder(t->lchild);
		cout<<t->data<<" ";
		inorder(t->rchild);
	}
	else
	{
		return ;
	}
}

int main()
{
	root = insert(root,20);
	insert(root,25);
	insert(root,30);
	insert(root,15);
	insert(root,10);
	insert(root,5);

	cout<<"before deletion : " ; inorder(root);  cout<<endl;
	cout<<"enter node to delete : ";
	int x ; cin>>x;
	deletee(root,x);
	cout<<"after deletition : "; inorder(root); cout<<endl;

	return 0;
}
