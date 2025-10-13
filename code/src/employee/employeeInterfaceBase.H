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
    bool setEmployeeStatus() final;
    std::string getEmployeeName() final;
    std::string getEmployeeID() final;
    std::string getEmployeeGender() final;
    std::string getEmployeeDOB() final;
    std::string getEmployeeStatus() final;
    std::string getEmployeeType() final;
    std::string getDateOfJoining() final;
    void printDetails() override;
    void printEmployeeDetails() override;

    EmployeeDatabase& getEmpDatabaseInstance()
    {
        return mEmpInstance;
    }


    private:

    EmployeeDatabase mEmpInstance;

};

#endif