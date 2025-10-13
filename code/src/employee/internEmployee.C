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
    ENTRY(getEmployeeName(),getEmployeeID(),getEmployeeType(),getEmployeeStatus(),getEmployeeGender(),getEmployeeDOB(),"Na");
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