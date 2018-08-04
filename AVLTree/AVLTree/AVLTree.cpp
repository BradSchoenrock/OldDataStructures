#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename Key, typename Data>class AVLNode
{
	template<typename Key, typename Data> friend class AVLTree;
	Key key;
	Data data;
	bool isroot;
	int height; //the height of a leaf node is 0
	AVLNode *left,*right;
	AVLNode()
	{
		isroot=false;
		height=0;//everything else is null
	}
	AVLNode(Key k,Data d)
	{
		isroot=false;
		key=k;
		data=d;
		left=0;
		right=0;
		height=0;
	}
	int adjustheight(AVLNode *toadjust)
	{
		if(toadjust->right==0&&toadjust->left==0)
			return 0;
		if(toadjust->right==0)
			return toadjust->left->height+1;
		if(toadjust->left==0)
			return toadjust->right->height+1;
		if(toadjust->right->height>toadjust->left->height)
			return toadjust->right->height+1;
		return (toadjust->left->height+1);
	}
	int balancefactor(AVLNode *tocalc)
	{
		if(tocalc->left==0&&tocalc->right==0)
			return 0;
		if(tocalc->left==0)
			return (-1)-tocalc->right->height;
		if(tocalc->right==0)
			return tocalc->left->height-(-1);
		return tocalc->left->height-tocalc->right->height;
	}
	AVLNode *rotateright(AVLNode *tempy)
	{
		AVLNode *temp2=tempy->left;
		tempy->left=0;
		AVLNode *temp3=temp2->right;
		temp2->right=tempy;
		tempy->left=temp3;
		tempy->height=adjustheight(tempy);
		temp2->height=adjustheight(temp2);
		return temp2;
	}
	AVLNode *rotateleft(AVLNode *tempy)
	{
		AVLNode *temp2=tempy->right;
		tempy->right=0;
		AVLNode *temp3=temp2->left;
		temp2->left=tempy;
		tempy->right=temp3;
		tempy->height=adjustheight(tempy);
		temp2->height=adjustheight(temp2);
		return temp2;
	}
	void rebalance(AVLNode *rebal)
	{
		if(rebal->right!=0)
		{
			int rightbf=balancefactor(rebal->right);
			if(rightbf>1)
			{//right rotation fixes height of children
				if(rebal->right->left!=0&&balancefactor(rebal->right->left)<0)
					rebal->right->left=rotateleft(rebal->right->left);
				rebal->right=rotateright(rebal->right);
				if(rebal->isroot==true)
					rebal->left=rebal->right;
			}
			else if(rightbf<-1)
			{//left rotation fixes height of children
				if(rebal->right->right!=0&&balancefactor(rebal->right->right)>0)
					rebal->right->right=rotateright(rebal->right->right);
				rebal->right=rotateleft(rebal->right);
				if(rebal->isroot==true)
					rebal->left=rebal->right;
			}
		}
		if(rebal->left!=0)
		{
			int leftbf=balancefactor(rebal->left);
			if(leftbf>1)
			{//right rotation fixes height of children
				if(rebal->left->left!=0&&balancefactor(rebal->left->left)<0)
					rebal->left->left=rotateleft(rebal->left->left);
				rebal->left=rotateright(rebal->left);
				if(rebal->isroot==true)
					rebal->right=rebal->left;
			}
			else if(leftbf<-1)
			{//left rotation fixes height of children
				if(rebal->left->right!=0&&balancefactor(rebal->left->right)>0)
					rebal->left->right=rotateright(rebal->left->right);
				rebal->left=rotateleft(rebal->left);
				if(rebal->isroot==true)
					rebal->right=rebal->left;
			}
		}
		rebal->height=adjustheight(rebal);//fixing my height
	}
	AVLNode *rightmost(AVLNode *tempz)
	{
		if(tempz->right==0)
			return tempz;
		return tempz->right->rightmost(tempz->right);
	}
	void insert(Key twoadd,Data toadd)
	{
		if(twoadd<key)
		{
			if(left!=0)
			{
				left->insert(twoadd,toadd);
				rebalance(this);//rebalance rebalances my children, not this as the code would seem to suggest
			}
			else
			{
				left=new AVLNode(twoadd,toadd);
				height=1;
			}
		}
		else // do it all to the right because it didn't need to be added to the left
		{
			if(right!=0)
			{
				right->insert(twoadd,toadd);
				rebalance(this);//rebalance rebalances my children, not this as the code would seem to suggest
			}
			else
			{
				right=new AVLNode(twoadd,toadd);
				height=1;
			}
		}
	}
	void remove(Key twotake)
	{
		if(key==twotake&&isroot==true)//these two lines ensure that if by chance tworemove==root->key (don't delete root)
			right->remove(twotake);//it doesn't preclude the possibility of the user wanting to delete that key elsewhere
		if(key>twotake)
		{//do stuff on the left
			if(left==0)
				return;
			if(left->key==twotake)
			{
				if(left->left==0&&left->right==0)
				{
					AVLNode *temp=left;
					left=0;
					if(isroot==true)
						right=left;
					delete temp;
				}
				else if(left->left==0)//we know that left->right!=0 already
				{
					AVLNode *temp=left;
					left=left->right;
					if(isroot==true)
						right=left;
					temp->right=0;
					delete temp;
				}
				else if(left->right==0)//we know that left->left!=0 already
				{
					AVLNode *temp=left;
					left=left->left;
					if(isroot==true)
						right=left;
					temp->left=0;
					delete temp;
				}
				else //if(left->right!=0&&left->left!=0)//the thing to be deleted is to my left and has two children
				{
					AVLNode *pred=left->left->rightmost(left->left);
					left->key=pred->key;
					left->data=pred->data;
					left->remove(pred->key);
					pred=0;
					delete pred;
				}
			}
			else //the thing to remove is not to my left and i have a left 
				left->remove(twotake);
		}
		else if(key<twotake)
		{//do stuff on the right
			if(right==0)
				return;
			if(right->key==twotake)
			{
				if(right->left==0&&right->right==0)
				{
					AVLNode *temp=right;
					right=0;
					if(isroot==true)
						left=right;
					delete temp;
				}
				else if(right->left==0)//we know that right->right!=0 already
				{
					AVLNode *temp=right;
					right=right->right;
					if(isroot==true)
						left=right;
					temp->right=0;
					delete temp;
				}
				else if(right->right==0)//we know that right->left!=0 already
				{
					AVLNode *temp=right;
					right=right->left;
					if(isroot==true)
						left=right;
					temp->left=0;
					delete temp;
				}
				else //if(right->right!=0&&right->left!=0)//the thing to be deleted is on my right and has two children
				{
					AVLNode *pred=right->left->rightmost(right->left);
					right->key=pred->key;
					right->data=pred->data;
					right->remove(pred->data);
					pred=0;
					delete pred;
				}
			}
			else //the thing to remove is not to my right and i have a right 
				right->remove(twotake);
		}
		rebalance(this);//rebalances my children not me as the code might suggest
	}
	bool exists(Key twofind)
	{
		if(twofind==key)
			return true;
		if(twofind<key&&left!=0)
			return left->exists(twofind);
		if(twofind>key&&right!=0)
			return right->exists(twofind);
		return false;//either twofind<key&&left==null or twofind>key&&right==null
	}
	Data search(Key twofind)
	{
		if(twofind==key)
			return data;
		if(twofind<key&&left!=0)
			return left->search(twofind);
		if(twofind>key&&right!=0)
			return right->search(twofind);
		return -99999;//either twofind<key&&left==null or twofind>key&&right==null
	}
	void print()
	{
		if(isroot!=true)
		{
			if(left!=0)
			{
				cout<<'L';
				left->print();
			}
			cout<<data<<'\n';
			if(right!=0)
			{
				cout<<'R';
				right->print();
			}
			cout<<'*';
		}
		else
			left->print();
	}
	bool isbalanced(AVLNode *bal)
	{
		bool temp=true;
		if(bal->left)
		{
			if(abs(bal->left->balancefactor(bal->left))>1)
				return false;
			if(temp)
				temp=bal->left->isbalanced(bal->left);
		}
		if(right)
		{
			if(abs(bal->right->balancefactor(bal->right))>1)
				return false;
			if(temp)
				temp=bal->right->isbalanced(bal->right);
		}
		if(bal->left==0&&bal->right==0)
			return true;
		return temp;
	}
	~AVLNode()
	{
		if(left)
			delete left;
		if(isroot==false)
			if(right)
				delete right;
		else//isroot==true
			right=0;
	}
};
template <typename Key, typename Data>class AVLTree
{
	AVLNode <Key,Data>*root;
public:
	int numitems;
	AVLTree()
	{ 
		root=new AVLNode<Key,Data>();
		root->isroot=true;
		numitems=0;
	}
	AVLTree(Key twoadd,Data toadd)
	{
		root=new <Key,Data>AVLNode();
		root->isroot=true;
		root->left=new <Key,Data>AVLNode(twoadd,toadd);
		root->right=root->left;
		numitems=1;
	}
	AVLTree(Key twoadd[],Data toadd[],int numinto)
	{//numinto is the size of the arrays (which should be the same size damnit)
		numitems=0;
		root=new AVLNode();
		root->isroot=true;
		for(int i=0;i<numinto;i++)
		{
			insert(twoadd[i],toadd[i]);
			numitems++;
		}
	}
	void insert(Key twoadd,Data toadd)
	{
		if(numitems>0)
		{
			root->insert(twoadd,toadd);
		}
		else
		{
			root->left=new AVLNode<Key,Data>(twoadd,toadd);
			root->right=root->left;
			root->height=1;
		}
		numitems++;
	}
	void remove(Key twotake)
	{
		root->remove(twotake);
		numitems--;
	}
	bool exists(Key twofind)
	{
		if(numitems>0)
			return root->exists(twofind);
		else
			return false;
	}
	double search(Key twofind)
	{
		return root->search(twofind);
	}
	bool isbalanced()
	{
		return root->isbalanced(root);
	}
	void print()
	{
		if(numitems>0)
		{
			root->print();
			cout<<'\n'<<'\n';
		}
		else
			cout<<"there was nothing in the list!"<<'\n'<<'\n';
	}
	~AVLTree()
	{
		delete root;
	}
};