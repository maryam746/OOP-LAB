#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course {
protected:
    string courseCode;
    int credits;

public:
    Course(string code, int cr) : courseCode(code), credits(cr) {}
    virtual void displayInfo() = 0;
    virtual float calculateGrade() = 0;
    virtual ~Course() {}
};

#endif
