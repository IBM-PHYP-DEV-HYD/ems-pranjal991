#ifndef INTERN_EMPLOYEE_C
#define INTERN_EMPLOYEE_C

#include "internEmployee.H"

int XyzInternEmployee::mIid = 0;

int XyzInternEmployee::getId()
{
    return mIid;
}

void XyzInternEmployee::printDetails()
{
    ENTRY(getEmployeeName(),getEmployeeID(),Emp::getEmpTypeToString(getEmployeeType()),Emp::getEmpStatusToString(getEmployeeStatus()), \
    Emp::getGenderToString(getEmployeeGender()),getEmployeeDOB(),"Na");
}

void XyzInternEmployee::printEmployeeDetails()
{
    INTERN_DETAILS( \
    getEmployeeName(), \
    getEmployeeID(), \
    Emp::getEmpTypeToString(getEmployeeType()), \
    Emp::getEmpStatusToString(getEmployeeStatus()), \
    Emp::getGenderToString(getEmployeeGender()), \
    getEmployeeDOB(), \
    getDateOfJoining(), \
    getCollegeName(), \
    getBranchName());


}

 Emp::EmpType XyzInternEmployee::getType()
 {
    return Emp::EmpType::INTERN;
 }

bool XyzInternEmployee::setDateOfLeaving(std::string valParm)
{
    
}

std::string  XyzInternEmployee::getDateOfLeaving()
{
    
}

bool XyzInternEmployee::setCollegeName(Emp::Colleges valParm)
{
    mCollege = valParm;
}

std::string  XyzInternEmployee::getCollegeName()
{
    return Emp::getCollegesToString(mCollege);
}

bool XyzInternEmployee::setBranchName(Emp::Branches valParm)
{
    mBranch = valParm;
}

std::string  XyzInternEmployee::getBranchName()
{
    return Emp::getBranchesToString(mBranch);
}




#endif