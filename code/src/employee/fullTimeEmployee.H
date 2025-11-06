#ifndef FULLTIME_EMPLOYEE_H
#define FULLTIME_EMPLOYEE_H

#include "employeeInterfaceBase.H"

class XyzFulltimeEmployee : public XyzEmployeeInterfaceBase
{
public:

    XyzFulltimeEmployee():mLeavesAwailed(0),mLeavesRemaining(0),mTotalLeaves(0){ mFid++;};

    XyzFulltimeEmployee(const XyzFulltimeEmployee &object) = delete;
    XyzFulltimeEmployee(const XyzFulltimeEmployee &&object)= delete;
    XyzFulltimeEmployee& operator= (const XyzFulltimeEmployee& object) = delete;
    XyzFulltimeEmployee& operator= (const XyzFulltimeEmployee&& object)= delete;

    ~XyzFulltimeEmployee() = default;

    virtual void printDetails() override;
    void printEmployeeDetails() override;
    Emp::EmpType getType() override;

    uint8_t getTotalLeaves();
    bool setTotalLeaves(uint8_t valPram);
    uint8_t getLeavesAwailed();
    bool setLeavesAwailed(uint8_t valPram);
    uint8_t getLeavesLeft();
    bool setLeavesLeft(uint8_t valPram);
    int getId();
    void addLeaves(uint8_t valParm);

    // required when Intern to Fulltime conversion happens
    void setFulltimeEmployeeName(std::string valParam);
    void setFulltimeEmployeeID(std::string idParm);
    void setFulltimeEmployeeType(Emp::EmpType typeParam);
    void setFulltimeEmployeeStatus(Emp::EmpStatus statusParam);
    void setFulltimeEmployeeGender(Emp::Gender genderParam);

private:

    unsigned int mTotalLeaves:8;    
    unsigned int mLeavesAwailed:8;
    unsigned int mLeavesRemaining:8;
    static int mFid; // every object generated will be assigned a ID to be used for generating employeeid 
};





#endif