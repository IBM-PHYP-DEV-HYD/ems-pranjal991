#ifndef EMPLOYEE_INTERFACE_BASE_C
#define EMPLOYEE_INTERFACE_BASE_C


#include "employeeInterfaceBase.H"

bool XyzEmployeeInterfaceBase::addDateOfJoining()
{
    return true;
}

void XyzEmployeeInterfaceBase:: setEmployeeStatus(Emp::EmpStatus sParam)
{
    getEmpDatabaseInstance().mEmployeeStatus = sParam;
}

std::string XyzEmployeeInterfaceBase:: getEmployeeName()
{
    return getEmpDatabaseInstance().mEmployeeName;
}

std::string XyzEmployeeInterfaceBase:: getEmployeeID()
{
    return getEmpDatabaseInstance().mEmployeeId;
}

Emp::Gender XyzEmployeeInterfaceBase:: getEmployeeGender()
{
    return getEmpDatabaseInstance().mGender;
}

std::string XyzEmployeeInterfaceBase:: getEmployeeDOB()
{
    return getEmpDatabaseInstance().mDateOfBirth;
}

Emp::EmpStatus XyzEmployeeInterfaceBase::getEmployeeStatus()
{
    return getEmpDatabaseInstance().mEmployeeStatus;
}

Emp::EmpType XyzEmployeeInterfaceBase::getEmployeeType()
{
    return getEmpDatabaseInstance().mEmployeeType;
}

std::string XyzEmployeeInterfaceBase::getDateOfJoining()
{
    return getEmpDatabaseInstance().mDateOfJoining;
}

void XyzEmployeeInterfaceBase::printDetails()
{
    //...
}
void XyzEmployeeInterfaceBase::printEmployeeDetails()
{
    //...
}
Emp::EmpType XyzEmployeeInterfaceBase::getType()
{
    return Emp::EmpType::ENDMARKER;
}



#endif