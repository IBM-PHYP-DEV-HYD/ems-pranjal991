#ifndef EMPLOYEE_DATABASE
#define EMPLOYEE_DATABASE

#include "iostream"
#include "utils/common.H"

// class forwarding
class EmployeeBuilderInterface;
class XyzEmployeeInterfaceBase;

class EmployeeDatabase
{
    private:

    std::string mEmployeeName;
    std::string mEmployeeId;
    Emp::EmpType mEmployeeType;
    Emp::EmpStatus mEmployeeStatus;
    std::string mGender;
    std::string mDateOfBirth;
    std::string mDateOfJoining;

    public:
    EmployeeDatabase():
            mEmployeeName("NA"),
            mEmployeeId("NA"),
            mEmployeeType(Emp::EmpType::ENDMARKER),
            mEmployeeStatus(Emp::EmpStatus::ENDMARKER),
            mGender("NA"),
            mDateOfBirth("NA"),
            mDateOfJoining("NA"){}

    EmployeeDatabase(const EmployeeDatabase &object) = delete;
    EmployeeDatabase(const EmployeeDatabase &&object)= delete;
    EmployeeDatabase& operator= (const EmployeeDatabase& object) = delete;
    EmployeeDatabase& operator= (const EmployeeDatabase&& object)= delete;

    ~EmployeeDatabase() = default;

    friend class EmployeeBuilderInterface;
    friend class XyzEmployeeInterfaceBase;

};


#endif