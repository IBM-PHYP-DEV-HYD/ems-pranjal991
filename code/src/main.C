#ifndef MAIN
#define MAIN


#include "employeeManager.H"
#include "processMenus.H"


int main()
{
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
            sPmen.ProcessRemoveEmployee();
            break;
        case Menu::MainMenu::EMPLOYEE_DETAILS:
            {
            sPmen.ProcessSubmenu2();
            break;
        }
        case Menu::MainMenu::OTHERS:
            sPmen.ProcessSubmenu3();
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

#endif