#ifndef EMPLOYEE_MANAGER_C
#define EMPLOYEE_MANAGER_C

#include "employeeManager.H"

/// @brief Add Random generated employee to the queues, based on there type.
/// @param typeParam employee type passed
/// @return 
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

/// @brief Generate random employeeType
/// @return return emp type generated
Emp::EmpType XyzEmployeeManager::generateEmployeeType()
{
    return static_cast<Emp::EmpType>(std::rand()% (Emp::getEnumToInt(Emp::EmpType::ENDMARKER)));
}

/// @brief Display summery of all employees
/// @return True if success otherwise false
bool XyzEmployeeManager::displayAllEmployeeDeatails()
{
    uint64_t iterator = 0;
    bool sRet = false;
    if(!mActiveEmployeeQueue.empty())
    {
        for(iterator=1;iterator <=mActiveEmployeeQueue.size();iterator++)
        {
            mActiveEmployeeQueue[iterator]->printDetails();
        }
        sRet = true;
        
    }
    if(!mInActiveEmployeeQueue.empty())
    {
        for(iterator=1;iterator <=mInActiveEmployeeQueue.size();iterator++)
        {
            mInActiveEmployeeQueue[iterator]->printDetails();
        }
        sRet = true;
    }
    if(!mResignedEmployeeQueue.empty())
    {
        for(iterator=1;iterator <=mResignedEmployeeQueue.size();iterator++)
        {
            mResignedEmployeeQueue[iterator]->printDetails();
        }
        sRet = true;
    }
    return sRet;
    
}


/// @brief Adding leaves to all fulltime employees
/// @param valParam leaves to be added
/// @return true is success false if fail
bool XyzEmployeeManager::addLeavesToFulltimeEmployee(int valParam)
{
    XyzEmployeeInterface* sPtr = nullptr;
    bool ret = false;
    sPtr = searchEmployee(mActiveEmployeeQueue,Emp::EmpType::FULLTIME,&XyzEmployeeInterface::getEmployeeType);
    if(sPtr != nullptr && sPtr->getType() == Emp::EmpType::FULLTIME)
    {
        XyzFulltimeEmployee* sTemp = static_cast<XyzFulltimeEmployee*>(sPtr);
        sTemp->addLeaves(valParam);
        ret = true;
    }
    return ret;

}

/// @brief Wrapper ffunction to Remove the Employee Object from the queues
/// @param idParam name or employee ID
/// @return 
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

/// @brief Internal Function to remove the emp object from the queue and add it to Resigned queue
/// @param queueParam queue to searched passed
/// @param valParam emloyee id or name parameter to be searched passed
/// @return 
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

 /// @brief Convert the Intern object to the fulltime , by creating new fulltime object and deleting the intern obj
 /// @param idParam Employee ID passed here to be searched and converted.
 /// @return 
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