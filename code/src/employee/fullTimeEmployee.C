#ifndef FULLTIME_EMPLOYEE_C
#define FULLTIME_EMPLOYEE_C

#include "fullTimeEmployee.H"

int XyzFulltimeEmployee::mFid = 0;

void XyzFulltimeEmployee::printDetails()
{
    
    ENTRY(getEmployeeName(),getEmployeeID(),getEmployeeType(),getEmployeeStatus(),getEmployeeGender(),getEmployeeDOB(),getDateOfJoining());

}

void XyzFulltimeEmployee::printEmployeeDetails()
{
    FULLTIME_EMP_DETAILS( \
    getEmployeeName(), \
    getEmployeeID(), \
    getEmployeeType(), \
    getEmployeeStatus(), \
    getEmployeeGender(), \
    getEmployeeDOB(), \
    getDateOfJoining(), \
    getLeavesAwailed(), \
    getLeavesLeft());

  
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



#endif