#ifndef LAB_COURSE_H
#define LAB_COURSE_H

#include "Course.h"

class LabCourse : public Course {
    float labReports;
    float practicalExam;
public:
    LabCourse(string code, int cr, float lab, float prac);
    void displayInfo() override;
    float calculateGrade() override;
};

#endif
