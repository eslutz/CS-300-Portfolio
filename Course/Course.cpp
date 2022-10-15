//
// Created by Eric Slutz on 10/15/22.
//

#include "Course.h"

/// Constructor for creating a Course object.
///
/// \param id the id value for the course.
/// \param name the name for the course.
/// \param prerequisites the list of any prerequisites for the course.
Course::Course(std::string &id, std::string &name, std::vector<std::string> &prerequisites) {
	this->courseId = id;
	this->courseName = name;
	this->coursePrerequisites = prerequisites;
}

/// Getter for the course id.
/// \return courseId
std::string Course::getCourseId() {
	return this->courseId;
}

/// Getter for the course name.
/// \return courseName
std::string Course::getCourseName() {
	return this->courseName;
}

/// Getter for the list of course prerequisites.
/// \return coursePrerequisites
std::vector<std::string> Course::getCoursePrerequisites() {
	return this->coursePrerequisites;
}

/// Returns a concatenated string of course values.
/// \return string with courseId and courseName
std::string Course::courseToString() {
	return this->courseId + ", " + this->courseName;
}
