//
// Created by Eric Slutz on 10/15/22.
//

#include <iostream>
#include "Courses.h"

/**
 * Default constructor
 */
Courses::Courses() {
	// root is equal to nullptr
	root = nullptr;
}

/**
 * Destructor
 */
Courses::~Courses() {
	// recurse from root deleting every node
	destroyRecursive(root);
}

/**
 * Traverse the tree in order
 */
void Courses::InOrder() {
	// call inOrder function and pass root
	inOrder(root);
}

/**
 * Traverse the tree in post-order
 */
void Courses::PostOrder() {
	// postOrder root
	postOrder(root);
}

/**
 * Traverse the tree in pre-order
 */
void Courses::PreOrder() {
	// preOrder root
	preOrder(root);
}

/**
 * Insert a course
 */
void Courses::Insert(Course course) {
	// if root equal to nullptr
	if (root == nullptr) {
		// root is equal to new node course
		root = new Node(course);
	}
		// else
	else {
		// add Node root and course
		this->addNode(root, course);
	}
}

/**
 * Remove a course
 */
void Courses::Remove(std::string& courseId) {
	// remove node root courseID
	this->removeNode(root, courseId);
}

/**
 * Search for a course
 */
Course Courses::Search(const std::string& courseId) {
	// set current node equal to root
	Node *cur = root;
	// keep looping downwards until bottom reached or matching courseId found
	while (cur != nullptr) {
		// if match found, return current course
		if (cur->course.courseId == courseId) {
			return cur->course;
		}
			// if course is smaller than current node then traverse left
		else if (courseId.compare(cur->course.courseId) < 0) {
			cur = cur->left;
		}
			// else larger so traverse right
		else {
			cur = cur->right;
		}
	}
	// course not found so return empty course.
	Course course;
	return course;
}

/**
 * Add a course to some node (recursive)
 *
 * @param node Current node in tree
 * @param course Course to be added
 */
void Courses::addNode(Node* node, Course course) {
	// if node is smaller than add to left
	if (node != nullptr && node->course.courseId.compare(course.courseId) > 0) {
		// if no left node
		if (node->left == nullptr) {
			// this node becomes left
			node->left = new Node(course);
			return;
		}
			// else recurse down the left node
		else {
			this->addNode(node->left, course);
		}
	}
		// else
	else if (node != nullptr && node->course.courseId.compare(course.courseId) < 0) {
		// if no right node
		if (node->right == nullptr) {
			// this node becomes right
			node->right = new Node(course);
			return;
		}
			// else if node is larger than add to right
		else {
			// recurse down the right node
			this->addNode(node->right, course);
		}
	}
}

void Courses::destroyRecursive(Node* node) {
	// if node is not equal to nullptr
	if (node != nullptr) {
		// call for destruction of any children
		destroyRecursive(node->left);
		destroyRecursive(node->right);
		// remove the current node
		delete node;
		node = nullptr;
	}
}

void Courses::inOrder(Node* node) {
	// if node is not equal to null ptr
	if (node != nullptr) {
		// inOrder left
		inOrder(node->left);
		// output courseID and courseName
		std::cout << node->course.courseId << ", "
				  << node->course.courseName << std::endl;
		// inOder right
		inOrder(node->right);
	}
}

void Courses::postOrder(Node* node) {
	// if node is not equal to nullptr
	if (node != nullptr) {
		// postOrder left
		postOrder(node->left);
		// postOrder right
		postOrder(node->right);
		// output courseID and courseName
		std::cout << node->course.courseId << ", "
				  << node->course.courseName << std::endl;
	}
}

void Courses::preOrder(Node* node) {
	// if node is not equal to nullptr
	if (node != nullptr) {
		// output courseID and courseName
		std::cout << node->course.courseId << ", "
			 << node->course.courseName << std::endl;
		// preOrder left
		preOrder(node->left);
		// preOrder right      
		preOrder(node->right);
	}
}

Node *Courses::removeNode(Node *node, const std::string& courseId) {
	if (node == nullptr) {
		return node;
	}
		// if course is smaller than current node then traverse left
	else if (courseId.compare(node->course.courseId) < 0) {
		node->left = removeNode(node->left, courseId);
	}
		// else if course is larger than current node then traverse right
	else if (courseId.compare(node->course.courseId) > 0) {
		node->right = removeNode(node->right, courseId);
	}
		// else match point found
	else {
		// leaf node
		if (node->left == nullptr && node->right == nullptr) {
			delete node;
			node = nullptr;
		}
			// else if left child
		else if (node->left != nullptr && node->right == nullptr) {
			Node *tmp = node;
			node = node->left;
			delete tmp;
			tmp = nullptr;
		}
			// else if right child
		else if (node->left == nullptr && node->right != nullptr) {
			Node *tmp = node;
			node = node->right;
			delete tmp;
			tmp = nullptr;
		}
			// else both children
		else {
			// find the minimum of the right subtree nodes for bst
			Node *tmp = node;
			while (tmp->left != nullptr) {
				tmp = tmp->left;
			}
			node->course = tmp->course;
			node->right = removeNode(node->right, tmp->course.courseId);
		}
	}
	return node;
}
