#ifndef LECTURE_COURSE_H
#define LECTURE_COURSE_H

#include "Course.h"

class LectureCourse : public Course {
    float midterm;
    float finalExam;
public:
    LectureCourse(string code, int cr, float mid, float fin);
    void displayInfo() override;
    float calculateGrade() override;
};

#endif
