#ifndef EMPLOYEE_INTERFACE_BASE_C
#define EMPLOYEE_INTERFACE_BASE_C


#include "employeeInterfaceBase.H"

/// @brief Add the joining date
/// @return 
bool XyzEmployeeInterfaceBase::addDateOfJoining()
{
    return true;
}

/// @brief Setter to the set the Employee status
/// @param sParam 
void XyzEmployeeInterfaceBase:: setEmployeeStatus(Emp::EmpStatus sParam)
{
    getEmpDatabaseInstance().mEmployeeStatus = sParam;
}

/// @brief Getter to get the employee name
/// @return 
std::string XyzEmployeeInterfaceBase:: getEmployeeName()
{
    return getEmpDatabaseInstance().mEmployeeName;
}

/// @brief getter to get the employee ID
/// @return 
std::string XyzEmployeeInterfaceBase:: getEmployeeID()
{
    return getEmpDatabaseInstance().mEmployeeId;
}

/// @brief getter to get the employee gender
/// @return 
Emp::Gender XyzEmployeeInterfaceBase:: getEmployeeGender()
{
    return getEmpDatabaseInstance().mGender;
}

/// @brief getter to get the rmployee DOB
/// @return 
Emp::DateStruct XyzEmployeeInterfaceBase:: getEmployeeDOB()
{
    return getEmpDatabaseInstance().mDateOfBirth;
}

/// @brief getter to get the employee status
/// @return 
Emp::EmpStatus XyzEmployeeInterfaceBase::getEmployeeStatus()
{
    return getEmpDatabaseInstance().mEmployeeStatus;
}

/// @brief getter to get the employee type
/// @return 
Emp::EmpType XyzEmployeeInterfaceBase::getEmployeeType()
{
    return getEmpDatabaseInstance().mEmployeeType;
}

/// @brief getter to get the date of joining
/// @return 
Emp::DateStruct XyzEmployeeInterfaceBase::getDateOfJoining()
{
    return getEmpDatabaseInstance().mDateOfJoining;
}

void XyzEmployeeInterfaceBase::printDetails()
{
    //...–
}
void XyzEmployeeInterfaceBase::printEmployeeDetails()
{
    //...
}

/// @brief getter to get the employee Type
/// @return 
Emp::EmpType XyzEmployeeInterfaceBase::getType()
{
    return Emp::EmpType::ENDMARKER;
}



#endif