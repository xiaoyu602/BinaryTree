# BinaryTree
#pragma once
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
size_t g_size = 0;//全局变量
template <class T>
class BinaryTreeNode
{
public:
	BinaryTreeNode(const T& data)
		:_data(data)
		,_left(NULL)
		,_right(NULL)
	{}
	T _data;//值
	BinaryTreeNode* _left;//左子树
	BinaryTreeNode* _right;//右子树
};

template <class T>
class BinaryTree
{
public:
	BinaryTree()//无参构造函数
		:_root(NULL)
	{}
	BinaryTree(const T* a,size_t size,const T& invalue)//构造函数
	{
		size_t index = 0;
		_root = _CreatTree(a,size,index,invalue); 
	}
	BinaryTree(const BinaryTree<T>& t)//拷贝构造
	{
		_root = _Copy(t._root);
	}
	BinaryTree<T>& operator=(const BinaryTree<T>& t)//赋值函数
	{
		if(this != &t)
		{
			BinaryTreeNode<T>* tmp = _Copy(t._root);
			_Destory(_root);
			_root = tmp;
		}
		return *this;
	}
	//BinaryTree<T>& operator=(const BinaryTree<T> t)//赋值函数
	//{
	//	swap(_root,t._root);
	//	return *this;
	//}
	~BinaryTree()//析构
	{
		_Destory(_root);
		_root = NULL;
	}
public:
	void PrevOrder()//先根遍历
	{
		cout<<"先根遍历:";
		_PrevOrder(_root);
		cout<<endl;
	}
	void InOrder()//中根遍历
	{
		cout<<"中根遍历:";
		_InOrder(_root);
		cout<<endl;
	}
	void PostOrder()//后根遍历
	{
		cout<<"后根遍历:";
		_PostOrder(_root);
		cout<<endl;
	}
	void LevelOrder()//层次遍历
	{
		cout<<"层次遍历:";
		_LevelOrder(_root);
	}
	size_t size()
	{
		size_t size = 0;
		_Size(_root,size);
		return size;
	}
	//size_t size()//节点个数
	//{
	//	return _Size(_root);
	//}
	//size_t size()
	//{
	//	g_size = 0;
	//	_Size(_root);
	//	return g_size;
	//}
	size_t Depth()//树的深度
	{
		return _Depth(_root);
	}
	//size_t LeafSize()//叶子节点个数
	//{
	//	return _LeafSize(_root);
	//}
	size_t LeafSize()
	{
		size_t size = 0;
		_LeafSize(_root,size);
		return size;
	}
	BinaryTreeNode<T>* Find(const T& x)//查找x
	{
		return _Find(_root,x);
	}
	//size_t GelKLevel(size_t k)//求第k层节点的个数
	//{
	//	return _GelKLevel(_root,k);
	//}
	size_t GelKLevel(size_t k)
	{
		size_t size = 0;
		size_t level = 1;
		_GelKLevel(_root,k,level,size);
		return size;
	}
	void Mirro()
	{
		_Mirro(_root);
	}
public:
	public:
	BinaryTreeNode<T>* _CreatTree(const T* a,size_t size,size_t &index,const T& invalue)//创建树
	{
		BinaryTreeNode<T>* root = NULL;
		if(index < size && a[index] != invalue)
		{
			root = new BinaryTreeNode<T>(a[index]);
			root->_left = _CreatTree(a,size,++index,invalue);
			root->_right = _CreatTree(a,size,++index,invalue);
		}
		return root;
	}

	void _PrevOrder(BinaryTreeNode<T>* root)
	{
		if(root == NULL)
			return;
		else
		{
			cout<<root->_data<<" ";
			_PrevOrder(root->_left);
			_PrevOrder(root->_right);
		}
	}

	void _InOrder(BinaryTreeNode<T>* root)
	{
		if(root == NULL)
			return;
		else
		{
			_InOrder(root->_left);
			cout<<root->_data<<" ";
			_InOrder(root->_right);
		}
	}
	
	void _PostOrder(BinaryTreeNode<T>* root)
	{
		if(root == NULL)
			return;
		else
		{
			_PostOrder(root->_left);
			_PostOrder(root->_right);
			cout<<root->_data<<" ";
		}
	}

	void _Destory(BinaryTreeNode<T>* root)//相当于后序删除
	{
		if(root == NULL)
			return;
		else
		{
			_Destory(root->_left);
			_Destory(root->_right);
			delete root;
		}
	}

	//size_t _Size(BinaryTreeNode<T>* root)//节点的个数
	//{
	//	size_t count = 0;
	//	if(root == NULL)
	//		return 0;
	//	count = _Size(root->_left) + _Size(root->_right);
	//	return count+1;	
	//}
	

	//size_t _Size(BinaryTreeNode<T>* root)//非递归节点的个数。存在线程安全
	//{
	//	static size_t size = 0;
	//	if(root == NULL)
	//		return 0;
	//	if(root != NULL)
	//	{
	//		++size;
	//	}
	//	_Size(root->_left);
	//	_Size(root->_right);
	//	return size;
	//}

	//void _Size(BinaryTreeNode<T>* root)//利用全局变量 非递归求节点个数.
	//{
	//	if(root == NULL)
	//		return;
	//	++g_size;
	//	_Size(root->_left);
	//	_Size(root->_right);
	//}

	size_t _Depth(BinaryTreeNode<T>* root)//树的深度
	{
		size_t left = 0;
		size_t right = 0;
		size_t max = 0;
		if(root == 0)
			return 0;
		else
		{
			left = _Depth(root->_left);
			right = _Depth(root->_right);
			max = left>right?left:right;
			return max+1;
		}	
	}
	
	//size_t _LeafSize(BinaryTreeNode<T>* root)//叶子节点的个数
	//{
	//	size_t count = 0;
	//	if(root == NULL)
	//		return 0;
	//	
	//	if(root && root->_left == NULL && root->_right == NULL)
	//		return 1;

	//	count = _LeafSize(root->_left)+_LeafSize(root->_right);
	//	return count;
	//}
	//size_t _LeafSize(BinaryTreeNode<T>* root)//遍历整个树来确定叶子节点的个数
	//{
	//	static size_t count = 0;
	//	if(root == NULL)
	//		return 0;
	//	if(root->_left == NULL && root->_right == NULL)
	//	{
	//		++count;
	//	}
	//	_LeafSize(root->_left);
	//	_LeafSize(root->_right);
	//	return count;
	//}
	void _LeafSize(BinaryTreeNode<T>* root,size_t& size)//解决线程安全问题
	{
		if(root == NULL)
			return;
		if(root->_left == NULL && root->_right == NULL)
		{
			++size;
		}
		_LeafSize(root->_left,size);
		_LeafSize(root->_right,size);
	}

	void _Size(BinaryTreeNode<T>* root,size_t& size)//解决线程安全问题
	{
		if(root == NULL)
			return;
		++size;
		_Size(root->_left,size);
		_Size(root->_right,size);
	}
	BinaryTreeNode<T>* _Copy(BinaryTreeNode<T>* root)
	{
		BinaryTreeNode<T>* newroot = NULL;
		if(root != NULL)
		{
			newroot = new BinaryTreeNode<T>(root->_data);
			
			newroot->_left = _Copy(root->_left);
			newroot->_right = _Copy(root->_right);
			
		}
		return newroot;
	}

	void _LevelOrder(BinaryTreeNode<T>* root)//层次遍历
	{
		queue<BinaryTreeNode<T>*> q;
		if(root == NULL)
			return;
		if(root != NULL)
		{
			q.push(root);
		}
		while(!q.empty())
		{
			BinaryTreeNode<T>* node = q.front();
			cout<<node->_data<<" ";
			if(node->_left != NULL)
			{
				q.push(node->_left);
			}
			if(node->_right != NULL)
			{
				q.push(node->_right);
			}
			q.pop();
		}
		cout<<endl;
	}

	//void PrevOrder_NonR()//非递归的先根遍历
	//{
	//	cout<<"非递归的先根遍历:";
	//	BinaryTreeNode<T>* cur = _root;
	//	stack<BinaryTreeNode<T>*> s;
	//	if(cur != NULL)
	//	{
	//		s.push(cur);
	//		cout<<s.top()->_data<<" ";
	//		s.pop();
	//	}
	//	while(!s.empty() || cur)
	//	{	
	//		if(cur->_right != NULL)
	//		{
	//			s.push(cur->_right);
	//		}
	//		if(cur->_left != NULL)
	//		{
	//			s.push(cur->_left);
	//		}
	//		if(!s.empty())
	//		{
	//			cout<<s.top()->_data<<" ";
	//			cur = s.top();
	//			s.pop();
	//		}
	//		else
	//		{
	//			cur = NULL;
	//		}
	//	}
	//	cout<<endl;
	//}
	void PrevOrder_NonR()//非递归的先根遍历
	{
		cout<<"非递归的先根遍历:";
		stack<BinaryTreeNode<T>*> s;
		if(_root == NULL)
			return;
		else
		{
			s.push(_root);
		}
		while(!s.empty())
		{
			BinaryTreeNode<T>* top = s.top();
			cout<<top->_data<<" ";
			s.pop();
			if(top->_right != NULL)
			{
				s.push(top->_right);
			}
			if(top->_left != NULL)
			{
				s.push(top->_left);
			}			
		}
		cout<<endl;
	}
	void INOrder_NonR()//非递归的中根遍历
	{
		cout<<"非递归的中根遍历:";
		if(_root == NULL)
			return;
		BinaryTreeNode<T>* cur = _root;
		stack<BinaryTreeNode<T>*> s;
		while(cur || !s.empty())
		{
			while(cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			BinaryTreeNode<T>* top = s.top();
			cout<<top->_data<<" ";
			s.pop();
			cur = top->_right;
		}
		cout<<endl;
	}

	//void PostOrder_NonR()//非递归的后根遍历
	//{
	//	cout<<"非递归的后根遍历:";
	//	BinaryTreeNode<T>* cur = _root;
	//	BinaryTreeNode<T>* prev = NULL;
	//	stack<BinaryTreeNode<T>*> s;
	//	BinaryTreeNode<T>* top = NULL; 
	//	if(_root == NULL)
	//		return;
	//	while(cur || !s.empty())
	//	{
	//		while(cur)
	//		{
	//			while(cur)
	//			{
	//				s.push(cur);
	//				cur = cur->_left; 
	//			}
	//			top = s.top();
	//			cur = top->_right;	
	//		}
	//		if(s.top()->_right == NULL)
	//     	{
	//			cout<<s.top()->_data<<" ";
	//			prev = s.top();
	//			s.pop();
	//		}
	//		   if(!s.empty())
	//		   {
	//				if(s.top()->_right == prev)
	//				{
	//					cout<<s.top()->_data<<" ";
	//					prev = s.top();
	//					s.pop();
	//				}
	//				if(!s.empty())
	//				{
	//					cur = s.top()->_right;
	//				}
	//				else
	//				{
	//				   cur = NULL;
	//			    }
	//		   }	  
	//	}
	//	cout<<endl;
	//}
	void PostOrder_NonR()//非递归的后根遍历
	{
		cout<<"非递归的后根遍历:";
		stack<BinaryTreeNode<T>*> s;
		if(_root == NULL)
			return;
		BinaryTreeNode<T>* cur = _root;
		BinaryTreeNode<T>* prev = NULL;
		while(cur || !s.empty())
		{
			while(cur)
			{
				s.push(cur);
				cur = cur->_left;
			}
			BinaryTreeNode<T>* top = s.top();
			if(top->_right == NULL || top->_right == prev)
			{
				cout<<top->_data<<" ";
				s.pop();
				prev = top;
			}
			else
			{
				cur = top->_right;
			}
		}
		cout<<endl;
	}

	BinaryTreeNode<T>* _Find(BinaryTreeNode<T>* root,const T& x)//查找x
	{
		if(root == NULL)
			return NULL;
		if(root->_data == x)
			return root;
		BinaryTreeNode<T>* ret = _Find(root->_left,x);
		if(ret != NULL)
		{
			return ret;
		}
		return _Find(root->_right,x);
	}

	//size_t _GelKLevel(BinaryTreeNode<T>* root,size_t k)
	//{
	//	if(root == NULL)
	//		return 0;
	//	if(k == 1)
	//		return 1;
	//	return _GelKLevel(root->_left,k-1)+_GelKLevel(root->_right,k-1);
	//}
	void _GelKLevel(BinaryTreeNode<T>* root,size_t k,size_t level,size_t& size)
	{
		if(root == NULL)
			return;
		if(level == k)
		{
			++size;
			return;
		}
		_GelKLevel(root->_left,k,level+1,size);
		_GelKLevel(root->_right,k,level+1,size);
	}

	void _Mirro(BinaryTreeNode<T>* root)
	{
		if(root == NULL)
			return;
		if(root->_left== NULL && root->_right == NULL)
			return;

		BinaryTreeNode<T>* tmp = root->_left;
		root->_left = root->_right;
		root->_right = tmp;

		_Mirro(root->_left);
		_Mirro(root->_right);
	}
protected:
	BinaryTreeNode<T>* _root;
};

