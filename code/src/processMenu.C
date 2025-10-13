#ifndef PROCESSMENUS_C
#define PROCESSMENUS_C


#include "processMenus.H"
#include "utils/common.H"

static Emp::EmpType getEmployeeType()
{
    Emp::EmpType sType;
    std::cout<<"Input F for Fulltime Employee, C for Contractor, I for intern : "<<std::endl;
    char sInput = Generic::getInputValues<char>();
    if('F' == sInput)
    {
        sType = Emp::EmpType::FULLTIME;
    }
    else if ('C' == sInput)
    {
        sType = Emp::EmpType::CONTRACTOR;
    }
    else if ('I' == sInput)
    {
        sType = Emp::EmpType::INTERN;
    }
    else
    {
        std::cout<<"Wrong Input "<< std::endl;
        sType = Emp::EmpType::ENDMARKER;
    }   
    return sType;
}

ProcessMenu::ProcessMenu()
{
    mManager = new XyzEmployeeManager();
}

void ProcessMenu::ProcessSubmenu1()
{
    while (true)
    {
        Menu::SubMenu1 sChoice;
        sChoice = Menu::SubMenu1Options();
        switch (sChoice)
        {
            case Menu::SubMenu1::ADD_RANDOM_EMPLOYEE:
            {
                Emp::EmpType sType = mManager->generateEmployeeType();
                mManager->addEmployee(sType);
                break;
            }
            case Menu::SubMenu1::ADD_EMPLOYEE:
            {
                Emp::EmpType sType;
                do
                {
                    sType = getEmployeeType();
                } while (sType == Emp::EmpType::ENDMARKER);
                mManager->addEmployee(sType);
                break;
            }
            case Menu::SubMenu1::EXIT:
            {
                return;
            }
            default:
            {
                std::cout << "Try Again";
            }
            }
        }

}


void ProcessMenu::ProcessSubmenu2()
{
    while (true)
    {
        Menu::SubMenu2 sChoice;
        sChoice = Menu::SubMenu2Options();
        switch (sChoice)
        {
        case Menu::SubMenu2::ALL_EMPLOYEE_SUMMERY:
        {
            Menu::printDetailsHeader();
            mManager->displayAllEmployeeDeatails();

            break;
        }
        case Menu::SubMenu2::EMPLOYEE_DETAILS:
        {
            std::string id;
            std::cout<<"Enter Employee ID: "<<std::endl;
            id = Generic::getInputValues<std::string>();
            mManager->displayEmployeeDetails(id);
            break;
        }
        case Menu::SubMenu2::EMPLOYEE_SUMMERY_AIR:
        {
            break;
        }
        case Menu::SubMenu2::EMPLOYEE_SUMMERY_FCI:
        {
            break;
        }
        case Menu::SubMenu2::EMPLOYEE_SUMMERY_MF:
        {
            break;
        }
        case Menu::SubMenu2::EXIT:
        {
            return;
        }
        default:
        {
            std::cout << "Wrong Input Try Again" << std::endl;
            break;
        }
        }
    }
    

}
void ProcessMenu::ProcessSubmenu3()
{

}



#endif