#ifndef EMPLOYEE_DATABASE
#define EMPLOYEE_DATABASE

#include "iostream"
#include "utils/common.H"

// class forwarding
class EmployeeBuilderInterface;
class XyzEmployeeInterfaceBase;
class XyzFulltimeEmployee;

class EmployeeDatabase
{
    private:

    std::string mEmployeeName;
    std::string mEmployeeId;
    Emp::EmpType mEmployeeType;
    Emp::EmpStatus mEmployeeStatus;
    Emp::Gender mGender;
    std::string mDateOfBirth;
    std::string mDateOfJoining;

    public:
    EmployeeDatabase():
            mEmployeeName("NA"),
            mEmployeeId("NA"),
            mEmployeeType(Emp::EmpType::ENDMARKER),
            mEmployeeStatus(Emp::EmpStatus::ENDMARKER),
            mGender(Emp::Gender::ENDMARKER),
            mDateOfBirth("NA"),
            mDateOfJoining("NA"){}

    EmployeeDatabase(const EmployeeDatabase &object) = delete;
    EmployeeDatabase(const EmployeeDatabase &&object)= delete;
    EmployeeDatabase& operator= (const EmployeeDatabase& object) = delete;
    EmployeeDatabase& operator= (const EmployeeDatabase&& object)= delete;

    ~EmployeeDatabase() = default;

    friend class EmployeeBuilderInterface;
    friend class XyzEmployeeInterfaceBase;
    friend class XyzFulltimeEmployee;
};


#endif