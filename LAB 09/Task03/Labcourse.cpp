#include <iostream>
#include "LabCourse.h"
using namespace std;

LabCourse::LabCourse(string code, int cr, float lab, float prac)
    : Course(code, cr), labReports(lab), practicalExam(prac) {}

void LabCourse::displayInfo() {
    cout << "Lab Course: " << courseCode << " | Credits: " << credits << endl;
}

float LabCourse::calculateGrade() {
    return (labReports * 0.5f + practicalExam * 0.5f);
}
