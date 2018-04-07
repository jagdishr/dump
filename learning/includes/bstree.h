#pragma once
#include <string>

class Value
{
	int valueindex;
	std::string data;
public:
	Value() : valueindex(0), data("") {}
	Value(int v, std::string d) : valueindex(v), data(d) {}

	int get() const { return valueindex; }
	std::string get_data() const { return data; }
	void set(int v) { valueindex = v; }
	void set_data(std::string d) { data = d; }

	~Value() {}
};

class BSTNode
{
	Value val;
	BSTNode *left, *right;
	BSTNode() : val(0, "") {}
public:
	BSTNode(Value v) : val(v), left(nullptr), right(nullptr) {}
	BSTNode(Value v, BSTNode *l, BSTNode *r) : val(v), left(l), right(r) {}
	BSTNode(const BSTNode &n);
	BSTNode& operator= (const BSTNode &n);

	Value get_value() const { return val; }
	BSTNode* get_left() { return left; }
	BSTNode* get_right() { return right; }

	void set_value(const Value& v) { val.set(v.get()); val.set_data(v.get_data()); }
	void set_left(BSTNode* n) { left = n; }
	void set_right(BSTNode* n) { right = n; }

	~BSTNode() {}
};

class BST
{
	BSTNode *head;
	BSTNode* copyTree(BSTNode*&, BSTNode*);
	BSTNode* insert(BSTNode*, const Value&);
	void inorder(BSTNode*);
	void deleteNode(BSTNode*);
public:
	BST() : head(nullptr) {}
	BST(BST &t);
	BST& operator= (const BST &t);

	BSTNode* insert(const Value&);
	void inorder() { inorder(head);  }

	~BST();
};

void run_bst_example();