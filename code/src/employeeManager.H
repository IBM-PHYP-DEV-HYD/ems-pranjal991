#ifndef EMPLOYEE_MANAGER
#define EMPLOYEE_MANAGER

#include "employee/employeeInterface.H"
#include "builder/employeeBuilderInterface.H"
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
    void displayEmployeeDetails(std::string& idParam);
    

    private:

    Edll<XyzEmployeeInterface*> mActiveEmployeeQueue;
    Edll<XyzEmployeeInterface*> mInActiveEmployeeQueue;
    Edll<XyzEmployeeInterface*> mResignedEmployeeQueue;

    XyzEmployeeInterface* searchEmployee(Edll<XyzEmployeeInterface*>& queueParam,std::string& idParam) ;
    
    


};




#endif