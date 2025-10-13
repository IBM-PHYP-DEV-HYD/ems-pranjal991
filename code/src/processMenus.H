#ifndef PROCESSMENUS_H
#define PROCESSMENUS_H

#include "employeeManager.H"

class ProcessMenu
{
    public:
    ProcessMenu();
    ~ProcessMenu() = default;

    void ProcessSubmenu1();
    void ProcessSubmenu2();
    void ProcessSubmenu3();
    

    XyzEmployeeManager* mManager;

};





#endif