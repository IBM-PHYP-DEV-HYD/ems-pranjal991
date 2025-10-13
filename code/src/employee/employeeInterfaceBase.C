#ifndef EMPLOYEE_INTERFACE_BASE_C
#define EMPLOYEE_INTERFACE_BASE_C


#include "employeeInterfaceBase.H"

bool XyzEmployeeInterfaceBase::addDateOfJoining()
{
    return true;
}

bool XyzEmployeeInterfaceBase:: setEmployeeStatus()
{
    return true;
}

std::string XyzEmployeeInterfaceBase:: getEmployeeName()
{
    return getEmpDatabaseInstance().mEmployeeName;
}

std::string XyzEmployeeInterfaceBase:: getEmployeeID()
{
    return getEmpDatabaseInstance().mEmployeeId;
}

std::string XyzEmployeeInterfaceBase:: getEmployeeGender()
{
    return getEmpDatabaseInstance().mGender;
}

std::string XyzEmployeeInterfaceBase:: getEmployeeDOB()
{
    return getEmpDatabaseInstance().mDateOfBirth;
}

std::string XyzEmployeeInterfaceBase::getEmployeeStatus()
{
    return Emp::getEmpStatusToString(getEmpDatabaseInstance().mEmployeeStatus);
}

std::string XyzEmployeeInterfaceBase::getEmployeeType()
{
    return Emp::getEmpTypeToString(getEmpDatabaseInstance().mEmployeeType);
}

std::string XyzEmployeeInterfaceBase::getDateOfJoining()
{
    return getEmpDatabaseInstance().mDateOfJoining;
}

void XyzEmployeeInterfaceBase::printDetails()
{

}
void XyzEmployeeInterfaceBase::printEmployeeDetails()
{
    
}




#endif