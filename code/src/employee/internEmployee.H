#ifndef INTERN_EMPLOYEE_H
#define INTERN_EMPLOYEE_H


#include "employeeInterfaceBase.H"

class XyzInternEmployee:public XyzEmployeeInterfaceBase
{
    public:
    
    XyzInternEmployee():mCollege(),mBranch(),mDateOfLeaving("NULL"){mIid++;};

    XyzInternEmployee(const XyzInternEmployee &object) = delete;
    XyzInternEmployee(const XyzInternEmployee &&object)= delete;
    XyzInternEmployee& operator= (const XyzInternEmployee& object) = delete;
    XyzInternEmployee& operator= (const XyzInternEmployee&& object)= delete;

    ~XyzInternEmployee() = default;

    void printDetails() override;
    void printEmployeeDetails() override;
    Emp::EmpType getType() override;

    void setDateOfLeaving(std::string valParam);
    std::string getDateOfLeaving();
    void setCollegeName(Emp::Colleges valParam);
    std::string getCollegeName();
    void setBranchName(Emp::Branches valParam);
    std::string getBranchName();
    int getId();



    private:

    Emp::Colleges mCollege;
    Emp::Branches mBranch;
    std::string mDateOfLeaving;
    static int mIid;


};

#endif