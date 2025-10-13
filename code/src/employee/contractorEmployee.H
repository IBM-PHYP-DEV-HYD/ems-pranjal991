#ifndef CONTRACTOR_EMPLOYEE_H
#define CONTRACTOR_EMPLOYEE_H

#include "employeeInterfaceBase.H"

class XyzContractorEmployee: public XyzEmployeeInterfaceBase
{
    public:
    XyzContractorEmployee():mExternalAgency("NULL"),mDateOfLeaving("NULL"){mCid++;};

    XyzContractorEmployee(const XyzContractorEmployee &object) = delete;
    XyzContractorEmployee(const XyzContractorEmployee &&object)= delete;
    XyzContractorEmployee& operator= (const XyzContractorEmployee& object) = delete;
    XyzContractorEmployee& operator= (const XyzContractorEmployee&& object)= delete;

    ~XyzContractorEmployee() = default;

    void printDetails() override;

    bool setDateOfLeaving(std::string valParm);
    std::string getDateOfLeaving();
    void setExternalAgency(std::string valParm);
    std::string getExternalAgency();
    int getId();

    private:

    std::string mExternalAgency;
    std::string mDateOfLeaving;
    static int mCid;    

};




#endif