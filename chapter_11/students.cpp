/*
Write the following program:
Create a struct that holds a student’s first name and grade (on a scale of 0-100).
Ask the user how many students they want to enter.
Create a std::vector to hold all of the students.
Then prompt the user for each name and grade.
Once the user has entered all the names and grade pairs,
sort the list by grade (highest first).
Then print all the names and grades in sorted order.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // std::sort
#include <cstddef> // std::size_t

struct Student
{
    std::string name{};
    int grade{};
};

bool compareStudents(const Student& a, const Student& b)
{
    return (a.grade > b.grade);
}

int main()
{   
    // Ask the user how many students they want to enter.
    std::cout << "How many students? ";
    int num_students{};
    std::cin >> num_students;

    // Create a std::vector to hold all of the students.
    std::vector<Student> students(static_cast<std::vector<Student>::size_type>(num_students));

    // Then prompt the user for each name and grade.
    int studentNumber{ 1 };
    
    for (Student& student : students)
    {
        std::cout << "Enter name: ";
        std::cin >> student.name;
        std::cout << "Enter grade: ";
        std::cin >> student.grade;

        ++studentNumber;
    }

    // Sort the list by grade (highest first).
    std::sort(students.begin(), students.end(), compareStudents);

    // Then print all the names and grades in sorted order.
    for (const Student& student: students)
    {
        std::cout << student.name << ": " << student.grade << '\n';
    }

    return 0;
}
