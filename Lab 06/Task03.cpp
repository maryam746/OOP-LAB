#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    void displayDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Teacher : virtual public Person
{
protected:
    string subject;

public:
    Teacher(string n, int a, string sub) : Person(n, a), subject(sub) {}
    void displayDetails()
    {
        Person::displayDetails();
        cout << "Subject Expertise: " << subject << endl;
    }
};

class Researcher : virtual public Person
{
protected:
    string researchArea;

public:
    Researcher(string n, int a, string area) : Person(n, a), researchArea(area) {}
    void displayDetails()
    {
        cout << "Research Area: " << researchArea << endl;
    }
};

class Professor : public Teacher, public Researcher
{
private:
    int publications;

public:
    Professor(string n, int a, string sub, string area, int pubs)
        : Person(n, a), Teacher(n, a, sub), Researcher(n, a, area), publications(pubs) {}

    void displayDetails()
    {
        Person::displayDetails();
        cout << "Subject Expertise: " << subject << endl;
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
    }
};

int main()
{
    Professor prof("Dr. John Doe", 45, "Computer Science", "Artificial Intelligence", 50);
    prof.displayDetails();
    return 0;
}
