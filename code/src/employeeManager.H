#ifndef EMPLOYEE_MANAGER
#define EMPLOYEE_MANAGER

#include "employee/employeeInterface.H"
#include "builder/employeeBuilder.H"
#include "utils/Edll.H"

class XyzEmployeeManager
{
    public:

    XyzEmployeeManager() = default;

    XyzEmployeeManager(const XyzEmployeeManager &object) = delete;
    XyzEmployeeManager(const XyzEmployeeManager &&object)= delete;
    XyzEmployeeManager& operator= (const XyzEmployeeManager& object) = delete;
    XyzEmployeeManager& operator= (const XyzEmployeeManager&& object)= delete;

    bool addEmployee(Emp::EmpType typeParam);
    Emp::EmpType generateEmployeeType();
    void displayAllEmployeeDeatails();
    bool addLeavesToFulltimeEmployee(int valParam);
    Edll<XyzEmployeeInterface*>& getActiveEmployeeQueue();
    bool removeEmployee(std::string idParam);
    bool convertInternToFulltime(std::string idParam);

    template<typename T>
    void printEmployee(T valParam,T (XyzEmployeeInterface::*getter)(),void (XyzEmployeeInterface::*printfunc)())
    {
        searchAndPrint(mActiveEmployeeQueue, valParam ,getter,printfunc);
        searchAndPrint(mInActiveEmployeeQueue, valParam ,getter,printfunc);
        searchAndPrint(mResignedEmployeeQueue, valParam ,getter,printfunc);
    }
    
    template<typename T>
    XyzEmployeeInterface* searchEmployee(Edll<XyzEmployeeInterface*>& queueParam,T reqParam,T (XyzEmployeeInterface::*getter)(),int* val = nullptr)
    {
        uint64_t sItr = 1;
        for(sItr = 1;sItr <= queueParam.size();sItr++)
        {
            if(reqParam == (queueParam[sItr]->*getter)())
            {
                if(val != nullptr){*val = sItr;}
                return queueParam[sItr];
            }
        }

        return nullptr;
    }

    private:

    Edll<XyzEmployeeInterface*> mActiveEmployeeQueue;
    Edll<XyzEmployeeInterface*> mInActiveEmployeeQueue;
    Edll<XyzEmployeeInterface*> mResignedEmployeeQueue;

    bool removeEmployeInternal(Edll<XyzEmployeeInterface*>& queueParam,std::string& valParam);

    template <typename T>
    void searchAndPrint(Edll<XyzEmployeeInterface *> &queueParam, T reqParam, T (XyzEmployeeInterface::*getter)(),void (XyzEmployeeInterface::*printfunc)())
    {
        uint64_t sItr = 1;
        XyzEmployeeInterface *sTemp = nullptr;
        for (sItr = 1; sItr <= queueParam.size(); sItr++)
        {
            if ((queueParam[sItr]->*getter)() == reqParam)
            {                
                (queueParam[sItr]->*printfunc)(); 
            }
        }
     
    }
};




#endif