#ifndef EMPLOYEE_MANAGER_C
#define EMPLOYEE_MANAGER_C

#include "employeeManager.H"

bool XyzEmployeeManager::addEmployee(Emp::EmpType typeParam)
{
    bool sRet = false;
    XyzEmployeeInterface *emp;
    EmployeeBuilderInterface *builder = new EmployeeBuilderInterface();

    emp = builder->createEmployee(typeParam);

    Emp::EmpStatus sStaus = emp->getEmployeeStatus();
    if (sStaus == Emp::EmpStatus::ACTIVE)
    {
        mActiveEmployeeQueue.pushBack(emp);
        sRet = true;
    }
    else if (sStaus == Emp::EmpStatus::INACTIVE)
    {
        mInActiveEmployeeQueue.pushBack(emp);
        sRet = true;
    }
    else if (sStaus == Emp::EmpStatus::RESIGNED)
    {
        mResignedEmployeeQueue.pushBack(emp);
        sRet = true;
    }
    return sRet;


}

Emp::EmpType XyzEmployeeManager::generateEmployeeType()
{
    return static_cast<Emp::EmpType>(std::rand()% (Emp::getEnumToInt(Emp::EmpType::ENDMARKER)-1));
}

void XyzEmployeeManager::displayAllEmployeeDeatails()
{
    uint64_t iterator = 0;
    if(!mActiveEmployeeQueue.empty())
    {
        for(iterator=1;iterator <=mActiveEmployeeQueue.size();iterator++)
        {
            mActiveEmployeeQueue[iterator]->printDetails();
        }
        
    }
    if(!mInActiveEmployeeQueue.empty())
    {
        for(iterator=1;iterator <=mInActiveEmployeeQueue.size();iterator++)
        {
            mInActiveEmployeeQueue[iterator]->printDetails();
        }
    }
    if(!mResignedEmployeeQueue.empty())
    {
        for(iterator=1;iterator <=mResignedEmployeeQueue.size();iterator++)
        {
            mResignedEmployeeQueue[iterator]->printDetails();
        }
    }
    
}


bool XyzEmployeeManager::addLeavesToFulltimeEmployee(int valParam)
{
    XyzEmployeeInterface* sPtr = nullptr;
    sPtr = searchEmployee(mActiveEmployeeQueue,Emp::EmpType::FULLTIME,&XyzEmployeeInterface::getEmployeeType);
    if(sPtr->getType() == Emp::EmpType::FULLTIME)
    {
        XyzFulltimeEmployee* sTemp = static_cast<XyzFulltimeEmployee*>(sPtr);
        sTemp->addLeaves(valParam);
    }
  

}

Edll<XyzEmployeeInterface*>& XyzEmployeeManager::getActiveEmployeeQueue()
{
    return mActiveEmployeeQueue;
}

#endif