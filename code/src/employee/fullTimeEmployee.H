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

    uint8_t getTotalLeaves();
    bool setTotalLeaves(uint8_t valPram);
    uint8_t getLeavesAwailed();
    bool setLeavesAwailed(uint8_t valPram);
    uint8_t getLeavesLeft();
    bool setLeavesLeft(uint8_t valPram);
    int getId();

private:

    unsigned int mTotalLeaves:8;    
    unsigned int mLeavesAwailed:8;
    unsigned int mLeavesRemaining:8;
    static int mFid;
};





#endif