#ifndef FULLTIME_EMPLOYEE_C
#define FULLTIME_EMPLOYEE_C

#include "fullTimeEmployee.H"

int XyzFulltimeEmployee::mFid = 0;

void XyzFulltimeEmployee::printDetails()
{
    
    ENTRY(getEmployeeName(),getEmployeeID(), \
    Emp::getEmpTypeToString(getEmployeeType()), \
    Emp::getEmpStatusToString(getEmployeeStatus()), \
    Emp::getGenderToString(getEmployeeGender()), \
    Emp::generateDateToString(getEmployeeDOB()), \
    Emp::generateDateToString(getDateOfJoining()), \
    std::to_string(getLeavesAwailed()),\
    std::to_string(getLeavesLeft()),\
    "NA",\
    "NA",\
    "NA",\
    "NA");

}

void XyzFulltimeEmployee::printEmployeeDetails()
{
    FULLTIME_EMP_DETAILS( \
    getEmployeeName(), \
    getEmployeeID(), \
    Emp::getEmpTypeToString(getEmployeeType()), \
    Emp::getEmpStatusToString(getEmployeeStatus()), \
    Emp::getGenderToString(getEmployeeGender()), \
    Emp::generateDateToString(getEmployeeDOB()), \
    Emp::generateDateToString(getDateOfJoining()), \
    getLeavesAwailed(), \
    getLeavesLeft());

  
}

Emp::EmpType XyzFulltimeEmployee::getType()
 {
    return Emp::EmpType::FULLTIME;
 }

int XyzFulltimeEmployee::getId()
{
    return mFid;
}

uint8_t XyzFulltimeEmployee::getTotalLeaves()
{
    return mTotalLeaves;
}

bool XyzFulltimeEmployee::setTotalLeaves(uint8_t valParm)
{
    mTotalLeaves = valParm;
    mLeavesRemaining = mTotalLeaves - mLeavesAwailed;
    return true;
}


uint8_t XyzFulltimeEmployee::getLeavesAwailed()
{
    return mLeavesAwailed;
}

bool XyzFulltimeEmployee::setLeavesAwailed(uint8_t valParm)
{
    mLeavesAwailed = static_cast<int>(valParm);
    mLeavesRemaining = mTotalLeaves - mLeavesAwailed;
    return true;
}

uint8_t XyzFulltimeEmployee::getLeavesLeft()
{
    return mLeavesRemaining;
}

bool XyzFulltimeEmployee::setLeavesLeft(uint8_t valParm)
{
    return true;
}

void XyzFulltimeEmployee::addLeaves(uint8_t valParm)
{
    mTotalLeaves = mTotalLeaves+ static_cast<int>(valParm);
    mLeavesRemaining = mTotalLeaves - mLeavesAwailed;

}

void XyzFulltimeEmployee::setFulltimeEmployeeName(std::string valParam)
{
    getEmpDatabaseInstance().mEmployeeName = valParam;
}

void XyzFulltimeEmployee::setFulltimeEmployeeID(std::string idParm)
{
    getEmpDatabaseInstance().mEmployeeId = idParm;

}
void XyzFulltimeEmployee::setFulltimeEmployeeType(Emp::EmpType typeParam)
{
    getEmpDatabaseInstance().mEmployeeType = typeParam;
}
void XyzFulltimeEmployee::setFulltimeEmployeeStatus(Emp::EmpStatus statusParam)
{
    getEmpDatabaseInstance().mEmployeeStatus = statusParam;
}
void XyzFulltimeEmployee::setFulltimeEmployeeGender(Emp::Gender genderParam)
{
    getEmpDatabaseInstance().mGender = genderParam;
}


#endif