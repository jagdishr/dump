#include <iostream>
#include <bstree.h>

BSTNode::BSTNode(const BSTNode &n)
{
	//val.set(n.val.get());
	//val.set_data(n.val.get_data());
	val = n.val;
	left = n.left;
	right = n.right;
}

BSTNode& BSTNode::operator= (const BSTNode &n)
{
	if (&n == this) return *this;

	val.set(n.val.get());
	val.set_data(n.val.get_data());
	left = n.left;
	right = n.right;

	return *this;
}

BST::BST(BST &t)
{
	if (!t.head)
	{
		head = nullptr;
	}
	else
	{
		copyTree(head, t.head);
	}
}

BST& BST::operator= (const BST &t)
{
	if (&t == this) return *this;

	if(head) deleteNode(head);
	if(t.head) copyTree(head, t.head);
	return *this;
}

BSTNode* BST::copyTree(BSTNode *&node, BSTNode *n)
{
	if(n != nullptr)
	{
		node = new BSTNode(n->get_value(), n->get_left(), n->get_right());
		BSTNode *left = node->get_left();
		node->set_left(copyTree(left, n->get_left()));
		BSTNode *right = node->get_right();
		node->set_right(copyTree(right, n->get_right()));
	}
	return node;
}

BSTNode* BST::insert(BSTNode* node, const Value& v)
{
	if (node == nullptr)
	{
		BSTNode* n = new BSTNode(v);
		return n;
	}

	if (v.get() < node->get_value().get())
	{
		node->set_left(insert(node->get_left(), v));
	}
	else if (v.get() > node->get_value().get())
	{
		node->set_right(insert(node->get_right(), v));
	}

	return node;
}

BSTNode* BST::insert(const Value& v)
{
	if (head == nullptr)
	{
		head = new BSTNode(v);
		return head;
	}
	return insert(head, v);
}

void BST::inorder(BSTNode* node)
{
	if (node != nullptr)
	{
		inorder(node->get_left());
		std::cout << node->get_value().get() << " ";
		inorder(node->get_right());
	}
}

void BST::deleteNode(BSTNode* node)
{
	if (node != nullptr)
	{
		deleteNode(node->get_left());
		deleteNode(node->get_right());
		delete node;
	}
}

BST::~BST()
{
	deleteNode(head);
}

void run_bst_example()
{
	BST tree;
	tree.insert(Value(50, "a"));
	tree.insert(Value(30, "a"));
	tree.insert(Value(20, "a"));
	tree.insert(Value(40, "a"));
	tree.insert(Value(70, "a"));
	tree.insert(Value(60, "a"));
	tree.insert(Value(80, "a"));
	tree.inorder();

	std::cout << "\n";
	BST tree2(tree);
	tree2.inorder();

	std::cout << "\n";
	BST tree3 = tree;
	tree3.inorder();

	std::cout << "\n";
	tree2.insert(Value(90, "a"));
	tree3 = tree2;
	tree3.inorder();
}