#include <iostream>
#include <bstree.h>
#include <stack>

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

void BST::preorder(BSTNode* node)
{
	if (node != nullptr)
	{
		std::cout << node->get_value().get() << " ";
		preorder(node->get_left());
		preorder(node->get_right());
	}
}

void BST::postorder(BSTNode* node)
{
	if (node != nullptr)
	{
		postorder(node->get_left());
		postorder(node->get_right());
		std::cout << node->get_value().get() << " ";
	}
}

void BST::it_inorder(BSTNode* node)
{
	if (node == nullptr) return;

	std::stack<BSTNode*> nodeStack;
	nodeStack.push(node);
	BSTNode* current = node;

	bool done = false;
	while (!done)
	{
		if (current->get_left())
		{
			nodeStack.push(current->get_left());
			current = current->get_left();
		}
		else
		{
			if (!nodeStack.empty())
			{
				current = nodeStack.top();
				std::cout << current->get_value().get() << " ";
				nodeStack.pop();

				if (current->get_right())
				{
					nodeStack.push(current->get_right());
					current = current->get_right();
				}
			}
			else
			{
				done = true;
			}
		}
	}
}

void BST::it_preorder(BSTNode* node)
{
	if (node == nullptr) return;

	std::stack<BSTNode*> nodeStack;
	nodeStack.push(node);

	while (!nodeStack.empty())
	{
		BSTNode* current = nodeStack.top();
		std::cout << current->get_value().get() << " " ;

		nodeStack.pop();
		if (current->get_right()) nodeStack.push(current->get_right());
		if (current->get_left()) nodeStack.push(current->get_left());
	}
}

void BST::it_postorder(BSTNode* node)
{
	if (node == nullptr) return;

	std::stack<BSTNode*> nodeStack1;
	std::stack<BSTNode*> nodeStack2;
	nodeStack1.push(node);
	BSTNode* current = node;

	bool done = false;
	while (!nodeStack1.empty())
	{
		current = nodeStack1.top();
		nodeStack1.pop();
		nodeStack2.push(current);
		if(current->get_left()) nodeStack1.push(current->get_left());
		if(current->get_right()) nodeStack1.push(current->get_right());
	}

	while (!nodeStack2.empty())
	{
		std::cout << nodeStack2.top()->get_value().get() << " ";
		nodeStack2.pop();
	}
}

void BST::it_postorder1stack(BSTNode* node)
{
	if (node == nullptr) return;
	
	std::stack<BSTNode*> nodeStack;
	BSTNode* current = node;

	do
	{
		while (current)
		{
			if (current->get_right()) nodeStack.push(current->get_right());
			nodeStack.push(current);
			current = current->get_left();
		}

		current = nodeStack.top();
		nodeStack.pop();
	
		BSTNode *tmp = nullptr;
		if (!nodeStack.empty())
		{
			tmp = nodeStack.top();
		}
		if (current->get_right() != nullptr && tmp == current->get_right())
		{
			nodeStack.pop();
			nodeStack.push(current);
			current = current->get_right();
		}
		else
		{
			std::cout << current->get_value().get() << " ";
			current = nullptr;
		}
	} while (!nodeStack.empty());
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
	tree.it_inorder();

	std::cout << "\n";
	std::cout << "\n";
	BST tree2(tree);
	tree2.inorder();
	std::cout << "\n";
	tree2.it_inorder();

	std::cout << "\n";
	std::cout << "\n";
	BST tree3 = tree;
	tree3.inorder();
	std::cout << "\n";
	tree3.it_inorder();

	std::cout << "\n";
	std::cout << "\n";
	tree2.insert(Value(90, "a"));
	tree3 = tree2;
	tree3.inorder();
	std::cout << "\n";
	tree3.it_inorder();

	std::cout << "\n\nPreorder:\n";
	tree3.preorder();
	std::cout << "\n";
	tree3.it_preorder();

	std::cout << "\n\nPostorder:\n";
	tree3.postorder();
	std::cout << "\n";
	tree3.it_postorder();
	std::cout << "\n";
	tree3.it_postorder1stack();
}