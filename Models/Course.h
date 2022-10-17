//
// Created by Eric Slutz on 10/15/22.
//

#ifndef PROJECT_2_COURSE_H
#define PROJECT_2_COURSE_H

#include <string>
#include <vector>

class Course {
// private fields for a course object.
private:
	std::string courseId;
	std::string courseName;
	std::vector<std::string> coursePrerequisites;
// public methods for a course object.
public:
	Course() = default;
	Course(std::string &id, std::string &name, std::vector<std::string> &prerequisites);
	std::string getCourseId();
	std::string getCourseName();
	std::vector<std::string> getCoursePrerequisites();
	std::string courseToString();
};

#endif //PROJECT_2_COURSE_H
