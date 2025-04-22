#include <iostream>
#include "LectureCourse.h"
#include "LabCourse.h"
using namespace std;

int main() {
    LectureCourse lec("CS101", 3, 75, 85);
    LabCourse lab("CS101L", 1, 90, 80);

    Course* courses[2];
    courses[0] = &lec;
    courses[1] = &lab;

    for (int i = 0; i < 2; ++i) {
        courses[i]->displayInfo();
        cout << "Final Grade: " << courses[i]->calculateGrade() << "\n\n";
    }

    return 0;
}
