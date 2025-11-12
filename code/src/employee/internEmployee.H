#ifndef INTERN_EMPLOYEE_H
#define INTERN_EMPLOYEE_H


#include "employeeInterfaceBase.H"

class XyzInternEmployee:public XyzEmployeeInterfaceBase
{
    public:
    
    XyzInternEmployee():mCollege(Emp::Colleges::ENDMARKER),mBranch(Emp::Branches::ENDMARKER),mDateOfLeaving(){mIid++;};

    XyzInternEmployee(const XyzInternEmployee &object) = delete;
    XyzInternEmployee(const XyzInternEmployee &&object)= delete;
    XyzInternEmployee& operator= (const XyzInternEmployee& object) = delete;
    XyzInternEmployee& operator= (const XyzInternEmployee&& object)= delete;

    ~XyzInternEmployee() = default;

    void printDetails() override;
    void printEmployeeDetails() override;
    Emp::EmpType getType() override;

    void setDateOfLeaving(Emp::DateStruct valParam);
    Emp::DateStruct getDateOfLeaving();
    void setCollegeName(Emp::Colleges valParam);
    std::string getCollegeName();
    void setBranchName(Emp::Branches valParam);
    std::string getBranchName();
    int getId();



    private:

    Emp::Colleges mCollege;
    Emp::Branches mBranch;
    Emp::DateStruct mDateOfLeaving;
    static int mIid; // every object generated will be assigned a ID to be used for generating employeeid 


};

#endif