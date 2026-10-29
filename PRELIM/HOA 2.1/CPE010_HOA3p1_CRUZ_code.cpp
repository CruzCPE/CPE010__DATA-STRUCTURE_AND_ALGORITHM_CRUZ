#include <iostream>
#include <string>

class Student{
    private:
        std::string studentName;
        int studentAge;
    public:
        //constructor
        Student(std::string newName = "JimLord Quejado", int newAge = 56) {
            studentName = std::move(newName);
            studentAge = newAge;
            std::cout << "Constructor Called.\n";
        };
        //destructor
        ~Student () {
            std::cout << "Destructinator is called.\n" << std::endl;
        }
        //copy constructor
        Student (const Student & copyStudent) {
            std::cout << "Copy Constructor Called.\n" << std::endl;
            studentName = copyStudent.studentName;
            studentAge = copyStudent.studentAge;
        }   
        //Display Attributes
        void printDetails () {
            std::cout << this->studentName << " " << this->studentAge <<std::endl;
        }
};

int main() {
    Student student1 ("Alden Richards", 25);
    Student student2 (student1);
    Student student3; 
    student3 = student2;

    const size_t j = 5;

    Student studentList[j] = {};
    std::string namesList[j] {"Jimmy", "Elijah", "Casi", "Zack", "Cody"};
    int ageList[j] = {38, 20, 19, 25, 31};

    for (size_t i = 0; i < j; ++i) {
       
        studentList[i] = Student(namesList[i], ageList[i]);
        
        // Prints the updated details
        std::cout << "Student " << i + 1 << ": ";
        studentList[i].printDetails();
    }

    return 0;
}
