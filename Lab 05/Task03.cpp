#include <iostream>
using namespace std;

class Project; // Forward declaration

class Employee {
    string name;
    string designation;
    Project **projectsAssigned;
    int projectCount;
    int projectCap;

public:
    Employee(string n, string d, int capacity = 2) {
        name = n;
        designation = d;
        projectCap = capacity;
        projectCount = 0;
        projectsAssigned = new Project*[projectCap](); // Initialize to nullptr
    }

    ~Employee() {
        delete[] projectsAssigned;
    }

    string getname() {
        return name;
    }

    void addProject(Project *p) {
        if (projectCount < projectCap) {
            projectsAssigned[projectCount++] = p;
        }
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
        cout << "Projects Assigned: " << endl;
        for (int i = 0; i < projectCount; i++) {
            cout << projectsAssigned[i]->gettitle() << endl;
        }
    }
};

class Project {
    string title;
    string deadline;
    Employee **employees;
    int employeeCount;
    int employeeCap;

public:
    Project(string t, string d, int capacity = 2) {
        title = t;
        deadline = d;
        employeeCap = capacity;
        employeeCount = 0;
        employees = new Employee*[employeeCap](); // Initialize to nullptr
    }

    ~Project() {
        delete[] employees;
    }

    string gettitle() {
        return title;
    }

    void assignEmployee(Employee *e) {
        if (employeeCount < employeeCap) {
            employees[employeeCount++] = e;
            e->addProject(this);
        } else {
            cout << "Cannot assign more employees to " << title << endl;
        }
    }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Deadline: " << deadline << endl;
        cout << "Employees Assigned: " << endl;
        for (int i = 0; i < employeeCount; i++) {
            cout << employees[i]->getname() << endl; // Now it works!
        }
    }
};

int main() {
    Project p1("Project1", "2024-03-20");
    Project p2("Project2", "2024-03-21");
    Employee e1("John", "Software Engineer");
    Employee e2("Doe", "Project Manager");

    p1.assignEmployee(&e1);
    p1.assignEmployee(&e2);
    p2.assignEmployee(&e2);

    cout << "\n--- Project Details ---\n";
    p1.display();
    p2.display();

    cout << "\n--- Employee Details ---\n";
    e1.display();
    e2.display();

    return 0;
}
