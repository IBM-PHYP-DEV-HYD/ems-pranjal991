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
    ENTRY(getEmployeeName(),getEmployeeID(), \
    Emp::getEmpTypeToString(getEmployeeType()), \
    Emp::getEmpStatusToString(getEmployeeStatus()), \
    Emp::getGenderToString(getEmployeeGender()), \
    Emp::generateDateToString(getEmployeeDOB()), \
    Emp::generateDateToString(getDateOfJoining()), \
    Emp::generateDateToString(getDateOfLeaving()), \
    "NA", \
    "NA", \
    Emp::getExternalAgenciesToString(getExternalAgency()), \
    "NA", \
    "NA");
}

void XyzContractorEmployee::printEmployeeDetails()
{
    CONTRACTOR_DETAILS( \
    getEmployeeName(), \
    getEmployeeID(), \
    Emp::getEmpTypeToString(getEmployeeType()), \
    Emp::getEmpStatusToString(getEmployeeStatus()), \
    Emp::getGenderToString(getEmployeeGender()), \
    Emp::generateDateToString(getEmployeeDOB()), \
    Emp::generateDateToString(getDateOfJoining()), \
    Emp::getExternalAgenciesToString(getExternalAgency()));  

}

Emp::EmpType XyzContractorEmployee::getType()
 {
    return Emp::EmpType::CONTRACTOR;
 }

void XyzContractorEmployee::setDateOfLeaving(Emp::DateStruct valParam)
{
    mDateOfLeaving = valParam;
}

Emp::DateStruct XyzContractorEmployee::getDateOfLeaving()
{
    return mDateOfLeaving;
}

void XyzContractorEmployee::setExternalAgency( Emp::ExternalAgencies valParam)
{
    mExternalAgency = valParam;
}

Emp::ExternalAgencies XyzContractorEmployee::getExternalAgency()
{
    return mExternalAgency;
}


#endif