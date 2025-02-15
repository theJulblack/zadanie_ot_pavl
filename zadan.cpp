#include <iostream>
#include <string>
#include <vector>
enum class EducationForm
{
  FullTime,
  PartTime
};

struct Student
{
  std::string name;
  std::string surname;
  std::string group;
  int course_number;
  EducationForm form;
  std::string passport;

  void comeRecomendation() const {
    if (form == EducationForm::FullTime)
      std::cout << "You need to come to college\n";
    if (form == EducationForm::PartTime)
      std::cout << "You dont need to come\n";
  }
};

struct Group {
  std::vector<Student> students;

  void addStudent(Student* student) {
    students.push_back(*student);
  }
  void deleteStudent(Student* student) {
    
    for (int i = 0; i < students.size(); i++)
    {
      if (students[i].passport == student->passport)
      {
        students.erase(students.begin() + i);
        std::cout << "умри" << students[i].name << "\n";
      }
    }
  }

};

int main()
{
  Group group;
  Student st1, st2, st3;
  
  st1.name = "Timothe";
  st1.surname = "Chalamet";
  st1.group = "ISiP-1-9-23";
  st1.form = EducationForm::FullTime;
  st1.course_number = 2;
  st1.passport = "1234 123456";

  st2.name = "Egor";
  st2.surname = "Krid";
  st2.group = "ISiP-1-9-23";
  st2.form = EducationForm::FullTime;
  st2.course_number = 2;
  st2.passport = "1234 654321";

  st3.name = "Mia";
  st3.surname = "Boiko";
  st3.group = "ISiP-1-9-23";
  st3.form = EducationForm::FullTime;
  st3.course_number = 2;
  st3.passport = "4321 123456";

  group.addStudent(&st1);
  group.addStudent(&st2);
  group.addStudent(&st3);

  st1.comeRecomendation();
  st2.comeRecomendation();
  st3.comeRecomendation();
}