#include "avl_tree_.hpp"

int main()
{
	AVLTree<int> tree;
	int a = 30, b = 10, c = 50, d = 5, e = 15, f = 40, g = 60, h = 13, i = 16;
	tree.add(a);
	tree.add(b);
	tree.add(c);
	tree.add(d);
	tree.add(e);
	tree.add(f);
	tree.add(g);
	tree.add(h);
	tree.add(i);
	tree.del(a);
	tree.del(b);
	tree.del(c);
	tree.del(d);
	tree.print();
}