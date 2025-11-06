#ifndef EMPLOYEE_BUILDER_H
#define EMPLOYEE_BUILDER_H

#include "employee/employeeInterfaceBase.H"
#include "employee/fullTimeEmployee.H"
#include "employee/contractorEmployee.H"
#include "employee/internEmployee.H"

#include "utils/common.H"

class EmployeeBuilderInterface:public XyzEmployeeInterfaceBase
{
    public:
    EmployeeBuilderInterface() = default;

    EmployeeBuilderInterface(const EmployeeBuilderInterface &object) = delete;
    EmployeeBuilderInterface(const EmployeeBuilderInterface &&object)= delete;
    EmployeeBuilderInterface& operator= (const EmployeeBuilderInterface& object) = delete;
    EmployeeBuilderInterface& operator= (const EmployeeBuilderInterface&& object)= delete;

    ~EmployeeBuilderInterface() = default;

    XyzEmployeeInterfaceBase* createEmployee(Emp::EmpType typeParam);

    private:
    void randomDataGeneration(XyzEmployeeInterfaceBase* obj);
    void randomDataGenerationFulltimeEmployee(XyzFulltimeEmployee* objParam);
    void randomDataGenerationContractorEmployee(XyzContractorEmployee* objParam);
    void randomDataGenerationInternEmployee(XyzInternEmployee* objParam);
    std::string randomDateofJoiningGeneration();
    std::string randomDateofBirthGeneration();


  

    
    
    




    

};





#endif