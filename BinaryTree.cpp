# BinaryTree
#include "BinaryTree.h"


void Test()
{
	int a[10] = {1,2,3,'#','#',4,'#','#',5,6};
	
	BinaryTree<int> b(a,10,'#');
	b.PrevOrder();
	b.InOrder();
	b.PostOrder();
	//b.~BinaryTree();
	int ret1 = b.size();//节点个数
	int ret2 = b.LeafSize();//叶子节点
	int ret3 = b.Depth();//深度
	cout<<ret1<<endl;
	cout<<ret2<<endl;
	cout<<ret3<<endl;
	BinaryTree<int> b1(b);//拷贝构造
	b1.PrevOrder();

	BinaryTree<int> b2;
	b2 = b1;//赋值
	b2.PrevOrder();
	b2.LevelOrder();
	b2.PrevOrder_NonR();
	b2.INOrder_NonR();
	b2.PostOrder_NonR();
	BinaryTreeNode<int>* ret = b2.Find(31);
	if(ret != NULL)
	{
		cout<<"Find 3?"<<ret->_data<<endl;
	}
	else
	{
		cout<<"无此数"<<endl;
	}
	size_t count = b2.GelKLevel(3);
	cout<<count<<endl;
}

void Test1()
{
	int a[13] = {8,6,5,'#','#',4,'#','#',10,3,'#','#',2};
	BinaryTree<int> b(a,13,'#');
	b.Mirro();
	//b.PrevOrder();

}
int main()
{
	Test1();
	return 0;
}
