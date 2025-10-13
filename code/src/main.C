#ifndef MAIN
#define MAIN



// #include "utils/Edll.H"
// #include "employee/employeeInterface.H"
// #include "builder/employeeBuilderInterface.H"

#include "employeeManager.H"
#include "processMenus.H"


int main()
{
    // Edll<int> queue_;
    // queue_.pushBack(34);
    // queue_.pushBack(35);
    // queue_.pushBack(36);
    // queue_.pushBack(37);
    // queue_.pushBack(38);
    // queue_.print();
    // queue_.insertAtIndex(65,3);
    // queue_.print();
    // queue_.removeFromIndex(3);
    // queue_.print();

    // XyzEmployeeInterface *emp;
    // EmployeeBuilderInterface *builder = new EmployeeBuilderInterface();
    // emp = builder->createEmployee(Emp::EmpType::FULLTIME);
    // emp = builder->build();


    // XyzEmployeeManager* manager = new XyzEmployeeM anager();
    // Emp::EmpType sType = manager->generateEmployeeType();
    // manager->addEmployee(sType);

    ProcessMenu sPmen;
    while (true)
    {
        Menu::MainMenu sChoice;
        sChoice = Menu::MainMenuOptions();
        switch (sChoice)
        {
        case Menu::MainMenu::ADD_EMPLOYEE:
        {
            sPmen.ProcessSubmenu1();
            break;
        }   
        case Menu::MainMenu::REMOVE_EMPLOYEE:
            
            break;
        case Menu::MainMenu::EMPLOYEE_DETAILS:
            {
            sPmen.ProcessSubmenu2();
            break;
        }
        case Menu::MainMenu::OTHERS:
            /* code */
            break;
        case Menu::MainMenu::EXIT:
            exit(1);
            break;
        
        default:
            break;
        }


    }
    





    return 1;
    
    
}

void procesSubmenu1()
{
    
    
}

#endif