#ifndef EMPLOYEE_MANAGER
#define EMPLOYEE_MANAGER

#include "employee/employeeInterface.H"
#include "builder/employeeBuilder.H"
#include "utils/Edll.H"

/// @brief 
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
    bool displayAllEmployeeDeatails();
    bool addLeavesToFulltimeEmployee(int valParam);
    bool removeEmployee(std::string idParam);
    bool convertInternToFulltime(std::string idParam);

    /// @brief Wrapper function to search the employee and print its details in all 3 queues
    /// @tparam T 
    /// @param valParam 
    /// @param getter 
    /// @param printfunc 
    template<typename T>
    void printEmployee(T valParam,T (XyzEmployeeInterface::*getter)(),void (XyzEmployeeInterface::*printfunc)())
    {
        searchAndPrint(mActiveEmployeeQueue, valParam ,getter,printfunc);
        searchAndPrint(mInActiveEmployeeQueue, valParam ,getter,printfunc);
        searchAndPrint(mResignedEmployeeQueue, valParam ,getter,printfunc);
    }
    
    /// @brief Search the employee based on  reqparam in the queue, and return the respective employee object
    /// @tparam T 
    /// @param queueParam desired queue in which search to be performed
    /// @param reqParam parameter passed based on which search to be done
    /// @param getter pass the respective getter function for comparision
    /// @param val provides the index of the employeeInterface object in the queue, required while removing the object from queue
    /// @return 
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

    /// @brief To search the queue based on reqparm and  call the print function of respective Employee objects
    /// @tparam T 
    /// @param queueParam queue passed
    /// @param reqParam enum or string parameter based on which comparison need to be done.
    /// @param getter pass the  respective getter function for comparision
    /// @param printfunc pass the respective print function of the EmployeeInterface class
    template <typename T>
    void searchAndPrint(Edll<XyzEmployeeInterface *> &queueParam, T reqParam, T (XyzEmployeeInterface::*getter)(),void (XyzEmployeeInterface::*printfunc)())
    {
        uint64_t sItr = 1;
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