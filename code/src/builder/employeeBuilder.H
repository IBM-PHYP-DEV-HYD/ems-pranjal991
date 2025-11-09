#ifndef EMPLOYEE_BUILDER_H
#define EMPLOYEE_BUILDER_H

#include "employee/employeeInterfaceBase.H"
#include "employee/fullTimeEmployee.H"
#include "employee/contractorEmployee.H"
#include "employee/internEmployee.H"

#include "utils/common.H"

/**
 * This class generates the Employee Objects, fill it with random data and return it to the Manager class
 */

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
    void randomDataGeneration(XyzEmployeeInterfaceBase* objParam);
    void randomDataGenerationFulltimeEmployee(XyzFulltimeEmployee* objParam);
    void randomDataGenerationContractorEmployee(XyzContractorEmployee* objParam);
    void randomDataGenerationInternEmployee(XyzInternEmployee* objParam);

    void randomDateofJoiningGeneration(XyzEmployeeInterfaceBase* objParam);
    void randomDateofBirthGeneration(XyzEmployeeInterfaceBase* objParam);

    Emp::DateStruct generateDateofLeavingContractor(Emp::DateStruct valParam);
    Emp::DateStruct generateDateofLeavingIntern(Emp::DateStruct valParam);


  

    
    
    




    

};





#endif