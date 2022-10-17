//
// Created by Eric Slutz on 10/15/22.
//

#ifndef PROJECT_2_COURSES_H
#define PROJECT_2_COURSES_H

#include <string>
#include <vector>
#include "Course.h"

struct Node {
	Course course;
	Node *left;
	Node *right;

	// default constructor
	Node() {
		left = nullptr;
		right = nullptr;
	}

	// initialize with a course
	Node(Course newCourse) :
			Node() {
		course = newCourse;
	}
};

class Courses {
private:
	Node* root;
	void destroyRecursive(Node *node);
	void addNode(Node *node, Course course);
	void inOrder(Node *node);
	void postOrder(Node *node);
	void preOrder(Node *node);
	Node *removeNode(Node *node, std::string courseId);
public:
	Courses();
	virtual ~Courses();
	void InOrder();
	void PostOrder();
	void PreOrder();
	void Insert(Course course);
	void Remove(std::string courseId);
	Course Search(std::string courseId);
};

#endif //PROJECT_2_COURSES_H
