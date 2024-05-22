#include <iostream>
#include <string>
#include <fstream>
using namespace std;



class Employee{
    public:
    string lastname;
    double workingHours;
    double workingDays;
    double hourRate;


    public:
    Employee(string lastname, double workingHours, double workingDays, double hourRate){
        this->lastname = lastname;
        this->workingHours = workingHours;
        this->workingDays = workingDays;
        this->hourRate = hourRate;
    }

   virtual double calculateSalary(){
        return workingHours * workingDays * hourRate;
    }
virtual void printData (){
   std::cout << "Last Name" << lastname << std::endl;
   std::cout << "Working Hours" << workingHours << std::endl;
    std::cout << "Working Days" << workingDays << std::endl;
    std::cout << "Hour Rate" << hourRate << std::endl;
    

}

};



class Manager : public Employee {
  private:
  string department;
  double bonus;

  public:
  Manager(string lastname, double workingHours, double workingDays, double hourRate, string department, double bonus)
  : Employee(lastname, workingHours, workingDays, hourRate) {
    this->department = department;
    this->bonus = bonus;
  }

  double getManagerBonus() {
    return bonus;
  }

  string getDepartment() {
    return department;
  }
};

class branchManager : public Manager {
  private:
  string branchName;

  public:
  branchManager(string lastname, double workingHours, double workingDays, double hourRate, string department, double bonus, string branchName)
  : Manager(lastname, workingHours, workingDays, hourRate, department, bonus) {
    this->branchName = branchName;
  }

  string getBranchName() {
    return branchName;
  }
};

class consultant : public Employee {
  private:
  string project;
  double projectRate;

  public:
  consultant(string lastname, double workingHours, double workingDays, double hourRate, string project, double projectRate)
  : Employee(lastname, workingHours, workingDays, hourRate) {
    this->project = project;
    this->projectRate = projectRate;
  }

  double getProjectRate() {
    return projectRate;
  }

  string getProject() {
    return project;
  }
};
class hourlyConsultaant : public consultant {
  private:
  double hoursWorked;

  public:
  hourlyConsultaant(string lastname, double workingHours, double workingDays, double hourRate, string project, double projectRate, double hoursWorked)
  : consultant(lastname, workingHours, workingDays, hourRate, project, projectRate) {
    this->hoursWorked = hoursWorked;
  }

  double getHoursWorked() {
    return hoursWorked;
  }
  double calculateSalary() override{
  return hoursWorked * hourRate;
  }
};
class contractConsultant : public consultant {
  private:
  double contractDuration;

  public:
  contractConsultant(string lastname, double workingHours, double workingDays, double hourRate, string project, double projectRate, double contractDuration)
  : consultant(lastname, workingHours, workingDays, hourRate, project, projectRate) {
    this->contractDuration = contractDuration;
  }

  double getContractDuration() {
    return contractDuration;
  }
};
class hourlyWorker : public Employee {
  private:
  double hoursWorked;

  public:
  hourlyWorker(string lastname, double workingHours, double workingDays, double hourRate, double hoursWorked)
  : Employee(lastname, workingHours, workingDays, hourRate) {
    this->hoursWorked = hoursWorked;
  }
double calculateSalary() override{
  return hoursWorked * hourRate;
}
  double getHoursWorked() {
    return hoursWorked;
  }
};

class officer : public hourlyWorker {
  private:
  string department;

  public:
  officer(string lastname, double workingHours, double workingDays, double hourRate, double hoursWorked, string department)
  : hourlyWorker(lastname, workingHours, workingDays, hourRate, hoursWorked) {
    this->department = department;
  }

};

class clerk : public hourlyWorker {
  private:
  string department;

  public:
  clerk(string lastname, double workingHours, double workingDays, double hourRate, double hoursWorked, string department)
  : hourlyWorker(lastname, workingHours, workingDays, hourRate, hoursWorked) {
    this->department = department;
  }

};
int main(){
    
    Employee emp("Smith", 8, 20, 15);
    Employee emp2("Sara", 12, 55, 55);
    Employee emp3("mahmoud", 12, 20, 25);
    
    hourlyWorker hw("Johnson", 8, 20, 15, 40);
    hourlyWorker hw2("hassan", 8, 44, 15, 22);
    hourlyWorker hw3("mark", 8, 20, 15, 65);

    
    clerk clrk("Doe", 8, 20, 15, 40, "Accounting");
    clerk clrk1("samson", 8, 22, 44, 40, "cleaner");
    clerk clrk2("david", 8, 20, 15, 40, "carpenter");
    
    emp.printData();
     std::cout << "Employee Salary: " << emp.calculateSalary() << std::endl;
    emp2.printData();
    std::cout << "Employee Salary: " << emp2.calculateSalary() << std::endl;
    emp3.printData();
     std::cout << "Employee Salary: " << emp3.calculateSalary() << std::endl;
    
    hw.printData();
    std::cout << "Hourly Worker Salary: " << hw.calculateSalary() << std::endl;
    hw2.printData();
    std::cout << "Hourly Worker Salary: " << hw2.calculateSalary() << std::endl;
    hw3.printData();
    std::cout << "Hourly Worker Salary: " << hw3.calculateSalary() << std::endl;
  
    clrk.printData();
     std::cout << "Clerk Salary: " << clrk.calculateSalary() << std::endl;
    clrk1.printData();
    std::cout << "Clerk Salary: " << clrk1.calculateSalary() << std::endl;
    clrk2.printData();
    std::cout <<"clerk Salary" << clrk2.calculateSalary() << std::endl;
    
    


    Employee* empPtr = &hw;
    Employee* empPtr2 = &clrk;


    empPtr->printData();
    std::cout << "Hourly Worker Salary: " << empPtr->calculateSalary() << std::endl;
    empPtr2->printData();
    std::cout << "Clerk Salary: " << empPtr2->calculateSalary() << std::endl;
     
     
   

    
   
    
    

return 0;
  }

// Programming Assignment 2
// Drive classes Manager, HourlyWorker, Consultant from class Employee, Also, drive at two
// classes from each of Manager, HourlyWorker, Consultant. For example, Officer and Branch
// manager could be classes derived from Manager. Each subclass should represent information
// that distinguishes it. For example, an HourlyWorker has an hourly wage and overtime rate, but
// an officer has neither of these. Add methods to each of these classes. The constructors of the
// derived classes should use the base class constructor. Implement a test client to test this
// hierarchy. Create at least two objects for each class. Print the data members of these objects
// indicated the inherited members and their base classes.
// You need to submit the hard copy of the report The typed report consists of the following:
// 2- Table of contents
// 1- Cover page
// 4-Problem statement
// 3-Introduction
// 5- The five steps of software life cycle Requirements specifications, Analysis, Object-Oriented
// design (UML), Class Implementation, and Testing)
// 6- The program listing (with internal documentation)
// 8- Conclusion 9- References
// 7- The input test da and the output
// 30
// 

