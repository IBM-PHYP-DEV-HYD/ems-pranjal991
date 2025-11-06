#ifndef CONTRACTOR_EMPLOYEE_H
#define CONTRACTOR_EMPLOYEE_H

#include "employeeInterfaceBase.H"

class XyzContractorEmployee: public XyzEmployeeInterfaceBase
{
    public:
    XyzContractorEmployee():mExternalAgency(Emp::ExternalAgencies::ENDMARKER),mDateOfLeaving("NULL"){mCid++;};

    XyzContractorEmployee(const XyzContractorEmployee &object) = delete;
    XyzContractorEmployee(const XyzContractorEmployee &&object)= delete;
    XyzContractorEmployee& operator= (const XyzContractorEmployee& object) = delete;
    XyzContractorEmployee& operator= (const XyzContractorEmployee&& object)= delete;

    ~XyzContractorEmployee() = default;

    void printDetails() override;
    void printEmployeeDetails() override;
    Emp::EmpType getType() override;

    void setDateOfLeaving(std::string valParm);
    std::string getDateOfLeaving();
    void setExternalAgency(Emp::ExternalAgencies valParm);
    Emp::ExternalAgencies getExternalAgency();
    int getId();

    private:

    Emp::ExternalAgencies mExternalAgency;
    std::string mDateOfLeaving;
    static int mCid;  // every object generated will be assigned a ID to be used for generating employeeid   

};




#endif