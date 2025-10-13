#ifndef EMPLOYEE_MANAGER_C
#define EMPLOYEE_MANAGER_C

#include "employeeManager.H"

bool XyzEmployeeManager::addEmployee(Emp::EmpType typeParam)
{
    bool sRet = false;
    XyzEmployeeInterface *emp;
    EmployeeBuilderInterface *builder = new EmployeeBuilderInterface();

    emp = builder->createEmployee(typeParam);

    std::string sStaus = emp->getEmployeeStatus();
    if (sStaus == "Active")
    {
        mActiveEmployeeQueue.pushBack(emp);
        sRet = true;
    }
    else if (sStaus == "Inactive")
    {
        mInActiveEmployeeQueue.pushBack(emp);
        sRet = true;
    }
    else if (sStaus == "Resigned")
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

void XyzEmployeeManager::displayEmployeeDetails(std::string& idParam)
{
    XyzEmployeeInterface* ptr = nullptr;

    ptr = searchEmployee(mActiveEmployeeQueue, idParam);
    if(nullptr == ptr)
    {
        ptr = searchEmployee(mInActiveEmployeeQueue, idParam);
    }
    if(nullptr == ptr)
    {
        ptr = searchEmployee(mInActiveEmployeeQueue, idParam);
    }
    if(nullptr !=ptr)
    {
        ptr->printEmployeeDetails();
    }
    else
    {
        std::cout<<"Invalid Emp ID: "<<idParam<<std::endl;
    }
    
}

XyzEmployeeInterface* XyzEmployeeManager::searchEmployee(Edll<XyzEmployeeInterface*>& queueParam,std::string& idParam)
{
    uint64_t sItr = 1;
    XyzEmployeeInterface* sTemp = nullptr;
    for(sItr = 1;sItr <= queueParam.size();sItr++)
    {
        std::string sID =  queueParam[sItr]->getEmployeeID();
        if(idParam == sID)
        {
            sTemp =  queueParam[sItr];
            break;
        }
    }
    return sTemp;

}

#endif