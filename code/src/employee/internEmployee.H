#ifndef INTERN_EMPLOYEE_H
#define INTERN_EMPLOYEE_H


#include "employeeInterfaceBase.H"

class XyzInternEmployee:public XyzEmployeeInterfaceBase
{
    public:
    
    XyzInternEmployee():mCollege(),mBranch(),mDateOfLeaving("NULL"){};

    XyzInternEmployee(const XyzInternEmployee &object) = delete;
    XyzInternEmployee(const XyzInternEmployee &&object)= delete;
    XyzInternEmployee& operator= (const XyzInternEmployee& object) = delete;
    XyzInternEmployee& operator= (const XyzInternEmployee&& object)= delete;

    ~XyzInternEmployee() = default;

    void printDetails() override;

    bool setDateOfLeaving(std::string valParam);
    std::string getDateOfLeaving();
    bool setCollegeName(Emp::Colleges valParam);
    std::string getCollegeName();
    bool setBranchName(Emp::Branches valParam);
    std::string getBranchName();
    int getId();


    private:

    Emp::Colleges mCollege;
    Emp::Branches mBranch;
    std::string mDateOfLeaving;
    static int mIid;


};

#endif