#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Student {
    std::string id;
    std::string name;
    std::vector<int> scores;

    double getAverageScore() const {
        int sum = 0;
        for (int score : scores) {
            sum += score;
        }
        return static_cast<double>(sum) / scores.size();
    }
};

bool compareByAverageScore(const Student& student1, const Student& student2) {
    return student1.getAverageScore() > student2.getAverageScore();
}

int main() {
    std::vector<Student> students;

    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    for (int i = 0; i < numStudents; ++i) {
        Student student;
        std::cout << "Enter student ID: ";
        std::cin >> student.id;
        std::cout << "Enter student name: ";
        std::cin.ignore(); // Ignore the newline character left by previous input
        std::getline(std::cin, student.name);

        std::cout << "Enter scores for 8 courses: ";
        for (int j = 0; j < 8; ++j) {
            int score;
            std::cin >> score;
            student.scores.push_back(score);
        }

        students.push_back(student);
    }

    std::sort(students.begin(), students.end(), compareByAverageScore);

    std::cout << "Students sorted by average score:\n";
    for (const Student& student : students) {
        std::cout << "ID: " << student.id << ", Name: " << student.name << ", Average Score: " << student.getAverageScore() << "\n";
    }

    return 0;
}
