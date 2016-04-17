/*
Composite pattern is used where we need to treat a group of objects in similar
way as a single object. Composite pattern composes objects in term of a tree
structure to represent part as well as whole hierarchy. This type of design
pattern comes under structural pattern as this pattern creates a tree structure
of group of objects.
This pattern creates a class that contains group of its own objects. This class
provides ways to modify its group of same objects. We are demonstrating use of
composite pattern via following example in which we will show employees
hierarchy of an organization.
*/
#include <iostream>
#include <stdio.h>
#include <list>

class Employee {
 public:
  Employee(std::string name, std::string dept, int sal) {
    emp_name_ = name;
    dept_ = dept;
    salary_ = sal;
  }

  void add(Employee* emp) { subordinate_.push_back(emp); }

  void remove(Employee* emp) { subordinate_.remove(emp); }

  std::list<Employee*> GetSubordinates() { return subordinate_; }

  std::string emp_name_;
  std::string dept_;
  int salary_;
  std::list<Employee*> subordinate_;
};

int main(int argc, char const* argv[]) {
  Employee* CEO = new Employee("John", "CEO", 30000);
  printf("CEO address : [%p] \n", CEO);
  Employee* headSales = new Employee("Robert", "Head Sales", 20000);
  printf("headSales address : [%p] \n", headSales);
  Employee* headMarketing = new Employee("Michel", "Head Marketing", 20000);
  printf("headMarketing address : [%p] \n", headMarketing);
  Employee* clerk1 = new Employee("Laura", "Marketing", 10000);
  Employee* clerk2 = new Employee("Bob", "Marketing", 10000);
  Employee* salesExecutive1 = new Employee("Richard", "Sales", 10000);
  Employee* salesExecutive2 = new Employee("Rob", "Sales", 10000);

  CEO->add(headSales);
  CEO->add(headMarketing);

  headSales->add(salesExecutive1);
  headSales->add(salesExecutive2);

  headMarketing->add(clerk1);
  headMarketing->add(clerk2);

  std::cout << "Print CEO reporting Employees \n";
  std::cout << CEO->GetSubordinates().size() << std::endl;
  for (std::list<Employee*>::iterator it = CEO->GetSubordinates().begin();
       it != CEO->GetSubordinates().end(); it++) {
    printf("address %p \n", *it);
    std::cout << (*it)->emp_name_ << (*it)->dept_ << (*it)->salary_
              << std::endl;
  }

  std::cout << "Print HeadSales reporting employees \n";
  for (std::list<Employee*>::iterator it = headSales->GetSubordinates().begin();
       it != headSales->GetSubordinates().end(); ++it) {
    std::cout << (*it)->emp_name_ << (*it)->dept_ << (*it)->salary_
              << std::endl;
  }

  std::cout << "Print HeadMarketing reporting employees \n";
  for (std::list<Employee*>::iterator it =
           headMarketing->GetSubordinates().begin();
       it != headMarketing->GetSubordinates().end(); ++it) {
    std::cout << (*it)->emp_name_ << (*it)->dept_ << (*it)->salary_
              << std::endl;
  }

  return 0;
}