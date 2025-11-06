#ifndef EMPLOYEE_INTERFACE_BASE_H
#define EMPLOYEE_INTERFACE_BASE_H


#include "employeeInterface.H"
#include "employeeDatabase.H"

class XyzEmployeeInterfaceBase : public XyzEmployeeInterface
{
    public:

    XyzEmployeeInterfaceBase() = default;

    XyzEmployeeInterfaceBase(const XyzEmployeeInterfaceBase &object) = delete;
    XyzEmployeeInterfaceBase(const XyzEmployeeInterfaceBase &&object)= delete;
    XyzEmployeeInterfaceBase& operator= (const XyzEmployeeInterfaceBase& object) = delete;
    XyzEmployeeInterfaceBase& operator= (const XyzEmployeeInterfaceBase&& object)= delete;

    virtual ~XyzEmployeeInterfaceBase() = default;
    
    bool addDateOfJoining() override;
    void setEmployeeStatus(Emp::EmpStatus) final;
    std::string getEmployeeName() final;
    std::string getEmployeeID() final;
    Emp::Gender getEmployeeGender() final;
    std::string getEmployeeDOB() final;
    Emp::EmpStatus getEmployeeStatus() final;
    Emp::EmpType getEmployeeType() final;
    std::string getDateOfJoining() final;
    void printDetails() override;
    void printEmployeeDetails() override;
    Emp::EmpType getType() override;


    EmployeeDatabase& getEmpDatabaseInstance()
    {
        return mEmpInstance;
    }


    private:

    EmployeeDatabase mEmpInstance;

};

#endif