#ifndef PROCESSMENUS_C
#define PROCESSMENUS_C


#include "processMenus.H"
#include "utils/common.H"

static Emp::EmpType inputEmployeeType()
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

static Emp::EmpStatus inputEmployeeStatus()
{
    Emp::EmpStatus sType;
    std::cout<<"Input A for Active Employee, I for Inactive, R for Resigned : "<<std::endl;
    char sInput = Generic::getInputValues<char>();
    if('A' == sInput)
    {
        sType = Emp::EmpStatus::ACTIVE;
    }
    else if ('I' == sInput)
    {
        sType = Emp::EmpStatus::INACTIVE;
    }
    else if ('R' == sInput)
    {
        sType = Emp::EmpStatus::RESIGNED;
    }
    else
    {
        std::cout<<"Wrong Input "<< std::endl;
        sType = Emp::EmpStatus::ENDMARKER;
    }   
    return sType;
}

static Emp::Gender inputEmployeeGender()
{
    Emp::Gender sType;
    std::cout<<"Input M for Male Employee, F for Female : "<<std::endl;
    char sInput = Generic::getInputValues<char>();
    if('M' == sInput)
    {
        sType = Emp::Gender::MALE;
    }
    else if ('F' == sInput)
    {
        sType = Emp::Gender::FEMALE;
    }
    else
    {
        std::cout<<"Wrong Input "<< std::endl;
        sType = Emp::Gender::ENDMARKER;
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
                    sType = inputEmployeeType();
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
            HEADER;
            mManager->displayAllEmployeeDeatails();

            break;
        }
        case Menu::SubMenu2::EMPLOYEE_DETAILS:
        {
            std::string id;
            std::cout<<"Enter Employee ID: "<<std::endl;
            id = Generic::getInputValues<std::string>();
            mManager->printEmployee(id,&XyzEmployeeInterface::getEmployeeID,&XyzEmployeeInterface::printEmployeeDetails);
            break;
        }
        case Menu::SubMenu2::EMPLOYEE_SUMMERY_AIR:
        {
            Emp::EmpStatus sTemp = inputEmployeeStatus();
            HEADER;
            mManager->printEmployee(sTemp,&XyzEmployeeInterface::getEmployeeStatus,&XyzEmployeeInterface::printDetails);
            break;
        }
        case Menu::SubMenu2::EMPLOYEE_SUMMERY_FCI:
        {
            Emp::EmpType sTemp = inputEmployeeType();
            HEADER;
            mManager->printEmployee(sTemp,&XyzEmployeeInterface::getEmployeeType,&XyzEmployeeInterface::printDetails);
            
            break;
        }
        case Menu::SubMenu2::EMPLOYEE_SUMMERY_MF:
        {
            Emp::Gender sTemp = inputEmployeeGender();
            HEADER;
            mManager->printEmployee(sTemp,&XyzEmployeeInterface::getEmployeeGender,&XyzEmployeeInterface::printDetails);
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
    while (true)
    {
        Menu::SubMenu3 sChoice;
        sChoice = Menu::SubMenu3Options();
        switch (sChoice)
        {
            case Menu::SubMenu3::ADD_LEAVES_FULL_TIME_EMPLOYEES:
            {
                int sVal = 1 + std::rand() % 22;
                std::cout<<"Adding random leaves: "<<sVal<<std::endl;
                mManager->addLeavesToFulltimeEmployee(sVal);
                
                break;
            }
            case Menu::SubMenu3::INTERN_TO_FULLTIME:
            {
                ConvertEmployee();
                break;
            }
            case Menu::SubMenu3::SEARCH_EMP_ID:
            {
                std::string id;
                std::cout<<"Enter Employee ID: "<<std::endl;
                id = Generic::getInputValues<std::string>();
                mManager->printEmployee(id,&XyzEmployeeInterface::getEmployeeID,&XyzEmployeeInterface::printEmployeeDetails);
                break;
            }
            case Menu::SubMenu3::SEARCH_EMP_NAME:
            {
                std::string sName;
                std::cout<<"Enter Employee Name: "<<std::endl;
                sName = Generic::getInputValues<std::string>();
                mManager->printEmployee(sName,&XyzEmployeeInterface::getEmployeeName,&XyzEmployeeInterface::printDetails);
                
                break;
            }
            case Menu::SubMenu3::EXIT:
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

void ProcessMenu::ProcessRemoveEmployee()
{
    std::string id;
    bool ret = false;
    std::cout<<"Enter Employee ID: "<<std::endl;
    id = Generic::getInputValues<std::string>();
    ret = mManager->removeEmployee(id);
    if(!ret)
    {
        std::cout<<"FAILED or NOT FOUND"<<std::endl;
    }
    else
    {
         std::cout<<"SUCCESS"<<std::endl;
    }

}

void ProcessMenu::ConvertEmployee()
 {
    std::string id;
    bool ret = false;
    std::cout<<"Enter Employee ID: "<<std::endl;
    id = Generic::getInputValues<std::string>();
    ret = mManager->convertInternToFulltime(id);
    if(!ret)
    {
        std::cout<<"FAILED or NOT FOUND"<<std::endl;
    }
    else
    {
        std::cout<<"SUCCESS"<<std::endl;
    }
    
 }

#endif