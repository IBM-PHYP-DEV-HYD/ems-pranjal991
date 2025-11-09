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
    ENTRY(getEmployeeName(),getEmployeeID(), \
    Emp::getEmpTypeToString(getEmployeeType()), \
    Emp::getEmpStatusToString(getEmployeeStatus()), \
    Emp::getGenderToString(getEmployeeGender()), \
    Emp::generateDateToString(getEmployeeDOB()), \
    Emp::generateDateToString(getDateOfJoining()), \
    Emp::generateDateToString(getDateOfLeaving()), \
    "NA", \
    "NA", \
    "NA", \
    getCollegeName(), \
    getBranchName());
}

void XyzInternEmployee::printEmployeeDetails()
{
    INTERN_DETAILS( \
    getEmployeeName(), \
    getEmployeeID(), \
    Emp::getEmpTypeToString(getEmployeeType()), \
    Emp::getEmpStatusToString(getEmployeeStatus()), \
    Emp::getGenderToString(getEmployeeGender()), \
    Emp::generateDateToString(getEmployeeDOB()), \
    Emp::generateDateToString(getDateOfJoining()), \
    getCollegeName(), \
    getBranchName());


}

 Emp::EmpType XyzInternEmployee::getType()
 {
    return Emp::EmpType::INTERN;
 }

void XyzInternEmployee::setDateOfLeaving(Emp::DateStruct valParm)
{
    mDateOfLeaving = valParm;
}

Emp::DateStruct XyzInternEmployee::getDateOfLeaving()
{
    return mDateOfLeaving;
}

void XyzInternEmployee::setCollegeName(Emp::Colleges valParm)
{
    mCollege = valParm;
}

std::string  XyzInternEmployee::getCollegeName()
{
    return Emp::getCollegesToString(mCollege);
}

void XyzInternEmployee::setBranchName(Emp::Branches valParm)
{
    mBranch = valParm;
}

std::string  XyzInternEmployee::getBranchName()
{
    return Emp::getBranchesToString(mBranch);
}




#endif