#ifndef EMPLOYEE_DATABASE
#define EMPLOYEE_DATABASE

#include "iostream"
#include "utils/common.H"

// class forwarding
class EmployeeBuilderInterface;
class XyzEmployeeInterfaceBase; // to access private memebers of EmployeeDatabase class
class XyzFulltimeEmployee;

class EmployeeDatabase
{
    private:

    std::string mEmployeeName;
    std::string mEmployeeId;
    Emp::EmpType mEmployeeType;
    Emp::EmpStatus mEmployeeStatus;
    Emp::Gender mGender;
    Emp::DateStruct mDateOfBirth;
    Emp::DateStruct mDateOfJoining;
    Emp::DateStruct obj;

    public:
    EmployeeDatabase():
            mEmployeeName("NA"),
            mEmployeeId("NA"),
            mEmployeeType(Emp::EmpType::ENDMARKER),
            mEmployeeStatus(Emp::EmpStatus::ENDMARKER),
            mGender(Emp::Gender::ENDMARKER),
            mDateOfBirth(),
            mDateOfJoining(){}

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