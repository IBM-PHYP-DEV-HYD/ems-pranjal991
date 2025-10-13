#ifndef CONTRACTOR_EMPLOYEE_C
#define CONTRACTOR_EMPLOYEE_C

#include "contractorEmployee.H"

int XyzContractorEmployee::mCid = 0;

int XyzContractorEmployee::getId()
{
    return mCid;
}

void XyzContractorEmployee::printDetails()
{
    ENTRY(getEmployeeName(),getEmployeeID(),getEmployeeType(),getEmployeeStatus(),getEmployeeGender(),getEmployeeDOB(),"Na");
}

bool XyzContractorEmployee::setDateOfLeaving(std::string valParam)
{
    
}

std::string XyzContractorEmployee::getDateOfLeaving()
{

}

void XyzContractorEmployee::setExternalAgency(std::string valParam)
{
    mExternalAgency = valParam;
}

std::string XyzContractorEmployee::getExternalAgency()
{
    return mExternalAgency;
}


#endif