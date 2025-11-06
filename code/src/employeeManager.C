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
    return static_cast<Emp::EmpType>(std::rand()% (Emp::getEnumToInt(Emp::EmpType::ENDMARKER)));
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
    bool ret = false;
    sPtr = searchEmployee(mActiveEmployeeQueue,Emp::EmpType::FULLTIME,&XyzEmployeeInterface::getEmployeeType);
    if(sPtr->getType() == Emp::EmpType::FULLTIME)
    {
        XyzFulltimeEmployee* sTemp = static_cast<XyzFulltimeEmployee*>(sPtr);
        sTemp->addLeaves(valParam);
        ret = true;
    }
    return ret;

}

Edll<XyzEmployeeInterface*>& XyzEmployeeManager::getActiveEmployeeQueue()
{
    return mActiveEmployeeQueue;
}

bool XyzEmployeeManager::removeEmployee(std::string idParam)
{
    bool ret = false;

    ret = removeEmployeInternal(mActiveEmployeeQueue,idParam);
    if(!ret)
    {
        ret = removeEmployeInternal(mInActiveEmployeeQueue,idParam);

        if(!ret)
        {
            removeEmployeInternal(mResignedEmployeeQueue,idParam);
        }
    }

    return ret;
}

bool XyzEmployeeManager::removeEmployeInternal(Edll<XyzEmployeeInterface*>& queueParam,std::string& valParam)
{
    XyzEmployeeInterface* sPtr = nullptr;
    bool ret = false;
    int sIndex = 0;
    sPtr = searchEmployee(queueParam,valParam,&XyzEmployeeInterface::getEmployeeID,&sIndex);
    // add them to resigned
    sPtr->setEmployeeStatus(Emp::EmpStatus::RESIGNED);
    mResignedEmployeeQueue.pushBack(sPtr);
    if(sPtr!= nullptr)
    {
        queueParam.removeFromIndex(sIndex);
        ret = true;
    }
    return ret;

}

 bool XyzEmployeeManager::convertInternToFulltime(std::string idParam)
 {
    XyzEmployeeInterface* sPtr = nullptr;
    int sIndex = 0;
    bool ret = false;
    sPtr = searchEmployee(mActiveEmployeeQueue,idParam,&XyzEmployeeInterface::getEmployeeID,&sIndex);
    if(sPtr!= nullptr && sPtr->getEmployeeType() == Emp::EmpType::INTERN)
    {
        XyzFulltimeEmployee* sTemp = new XyzFulltimeEmployee();
        sTemp->setTotalLeaves(22);
        sTemp->setFulltimeEmployeeName(sPtr->getEmployeeName());
        sTemp->setFulltimeEmployeeGender(sPtr->getEmployeeGender());
        sTemp->setFulltimeEmployeeID(Emp::generateEmployeeId(Emp::EmpType::FULLTIME,sTemp->getId()));
        sTemp->setFulltimeEmployeeStatus(Emp::EmpStatus::ACTIVE);
        sTemp->setFulltimeEmployeeType(Emp::EmpType::FULLTIME);
        
        ret = removeEmployee(idParam);
        if(ret)
        {
            sPtr = nullptr;
            sPtr = sTemp;
            ret = mActiveEmployeeQueue.pushBack(sPtr);
        }
        return ret;
    }
    return ret;


 }

#endif