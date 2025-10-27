#ifndef EMPLOYEE_INTERFACE
#define EMPLOYEE_INTERFACE

#include "iostream"
#include "utils/common.H"

class XyzEmployeeInterface
{
    public:
    XyzEmployeeInterface() = default;

    XyzEmployeeInterface(const XyzEmployeeInterface &object) = delete;
    XyzEmployeeInterface(const XyzEmployeeInterface &&object)= delete;
    XyzEmployeeInterface& operator= (const XyzEmployeeInterface& object) = delete;
    XyzEmployeeInterface& operator= (const XyzEmployeeInterface&& object)= delete;

    virtual ~XyzEmployeeInterface() = default;

    virtual bool addDateOfJoining() = 0;
    virtual bool setEmployeeStatus() = 0;
    virtual std::string getEmployeeName() = 0;
    virtual std::string getEmployeeID() = 0;
    virtual Emp::Gender getEmployeeGender() = 0;
    virtual std::string getEmployeeDOB() = 0;
    virtual Emp::EmpStatus getEmployeeStatus() = 0;
    virtual Emp::EmpType getEmployeeType() = 0;
    virtual std::string getDateOfJoining() = 0;
    virtual void printDetails() = 0;
    virtual void printEmployeeDetails() = 0;
    virtual Emp::EmpType getType() = 0;


};


#endif