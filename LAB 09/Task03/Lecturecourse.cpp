#include <iostream>
#include "LectureCourse.h"
using namespace std;

LectureCourse::LectureCourse(string code, int cr, float mid, float fin)
    : Course(code, cr), midterm(mid), finalExam(fin) {}

void LectureCourse::displayInfo() {
    cout << "Lecture Course: " << courseCode << " | Credits: " << credits << endl;
}

float LectureCourse::calculateGrade() {
    return (midterm * 0.4f + finalExam * 0.6f);
}
