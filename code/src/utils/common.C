#ifndef COMMON_C
#define COMMON_C

#include "common.H"

std::string Emp::generateEmployeeId(Emp::EmpType typeParm, int idParm)
  {
    
    std::string sRet = " ";
    sRet= "XYZ" + Emp::getFourDigitNo(idParm);
    if(Emp::EmpType::FULLTIME == typeParm)
    {
        sRet+="F";
    }
    else if (typeParm == Emp::EmpType::CONTRACTOR)
    {
        sRet+= "C";
    }
    else if (typeParm == Emp::EmpType::INTERN)
    {
        sRet+= "I";
    }

    return sRet;

  }

std::string Emp::getFourDigitNo(int valParam)
  {
      std::ostringstream oss;
      oss << std::setfill('0') << std::setw(4) << valParam;
      return oss.str();
  }

std::string Emp::getEmpTypeToString(Emp::EmpType valParam)
{
    std::string sRet;
    switch (valParam)
    {
    case Emp::EmpType::FULLTIME:
        sRet = "Fulltime";
        break;
    case Emp::EmpType::CONTRACTOR:
        sRet = "Contractor";
        break;
    case Emp::EmpType::INTERN:
        sRet = "Intern";
        break;
    default:
        sRet = "Invalid";
        break;
    }
    return sRet;
}

std::string Emp::getEmpStatusToString(Emp::EmpStatus valParam)
{
    std::string sRet;
    switch (valParam)
    {
    case Emp::EmpStatus::ACTIVE:
        sRet = "Active";
        break;
    case Emp::EmpStatus::INACTIVE:
        sRet = "Inactive";
        break;
    case Emp::EmpStatus::RESIGNED:
        sRet = "Resigned";
        break;
    default:
        sRet = "Invalid";
        break;
    }
    return sRet;
}

std::string Emp::getExternalAgenciesToString(Emp::ExternalAgencies valParam)
{
    std::string sRet;
    switch (valParam)
    {
    case Emp::ExternalAgencies::AVENGERS:
        sRet = "Avengers";
        break;
    case Emp::ExternalAgencies::JUSTICELEAGUE:
        sRet = "Justice League";
        break;
    case Emp::ExternalAgencies::XMEN:
        sRet = "X-Men";
        break;
    default:
        sRet = "Invalid";
        break;
    }
    return sRet;
}

std::string Emp::getCollegesToString(Emp::Colleges valParam)
{
    std::string sRet;
    switch (valParam)
    {
    case Emp::Colleges::IITDELHI:
        sRet = "IIT Delhi";
        break;
    case Emp::Colleges::IITMUMBAI:
        sRet = "IIT Mumbai";
        break;
    case Emp::Colleges::IITKANPUR:
        sRet = "IIT Kanpur";
        break;
    case Emp::Colleges::IITHYDERABAD:
        sRet = "IIT Hyderabad";
        break;
    case Emp::Colleges::NITTIRUCHI:
        sRet = "NIT Tiruchi";
        break;
    case Emp::Colleges::NITWARANGAL:
        sRet = "NIT Warangal";
        break;
    default:
        sRet = "Invalid";
        break;
    }
    return sRet;
}

std::string Emp::getBranchesToString(Emp::Branches valParam)
{
    std::string sRet;
    switch (valParam)
    {
    case Emp::Branches::CSE:
        sRet = "CSE";
        break;
    case Emp::Branches::CSIT:
        sRet = "CSIT";
        break;
    case Emp::Branches::ECE:
        sRet = "ECE";
        break;
    default:
        sRet = "Invalid";
        break;
    }
    return sRet;
}

std::string Emp::getGenderToString(Emp::Gender valParam)
{
    std::string sRet;
    switch (valParam)
    {
    case Emp::Gender::MALE:
        sRet = "Male";
        break;
    case Emp::Gender::FEMALE:
        sRet = "Female";
        break;
    default:
        sRet = "Invalid";
        break;
    }
    return sRet;

}

// std::string getExternalAgenciesToString(Emp::ExternalAgencies valParam)
// {
//     std::string sRet;
//     switch (valParam)
//     {
//     case Emp::ExternalAgencies::AVENGERS:
//         sRet = "AVENGERS";
//         break;
//     case Emp::ExternalAgencies::JUSTICELEAGUE:
//         sRet = "JUSTICELEAGUE";
//         break;
//     case Emp::ExternalAgencies::XMEN:
//         sRet = "XMEN";
//         break;
//     default:
//         sRet = "Invalid";
//         break;
//     }
//     return sRet;

// }

std::string Emp::generateDateToString(Emp::DateStruct valParm)
{
    std::string sTemp;
    return std::to_string(valParm.Day) + "/" + std::to_string(valParm.Month) + "/" + std::to_string(valParm.Year);

}

Menu::MainMenu Menu::MainMenuOptions()
{
    std::cout << " \
    ---------------------------------------------------------------------------------\n \
    |                                    Main Menu                                  |\n \
    ---------------------------------------------------------------------------------\n \
    | 1.  Add an Employee                                                           |\n \
    | 2.  Remove an Employee                                                        |\n \
    | 3.  Employee Details                                                          |\n \
    | 4.  Others                                                                    |\n \
    ---------------------------------------------------------------------------------\n \
    Your Choice: "
              << std::endl;
    uint8_t sChoice;
    sChoice = Generic::getInputValues<int>();
    return static_cast<Menu::MainMenu>(sChoice);
}

Menu::SubMenu1 Menu::SubMenu1Options()
{
    std::cout << " \
    ---------------------------------------------------------------------------------\n \
    |                                    Add an Employee                            |\n \
    ---------------------------------------------------------------------------------\n \
    | 1.  Add an Employee st Random                                                 |\n \
    | 2.  Add an Employee (F/C/I)                                                   |\n \
    ---------------------------------------------------------------------------------\n \
    Your Choice: "
              << std::endl;
    uint8_t sChoice;
    sChoice = Generic::getInputValues<int>();
    return static_cast<Menu::SubMenu1>(sChoice);
}



Menu::SubMenu2 Menu::SubMenu2Options()
{
    std::cout << " \
    ---------------------------------------------------------------------------------\n \
    |                                    Employee Details                            |\n \
    ---------------------------------------------------------------------------------\n \
    | 1.  All Employees Summary                                                      |\n \
    | 2.  Employee Summary (F/C/I)                                                   |\n \
    | 3.  Employee Summary (M/F)                                                     |\n \
    | 4.  Employee Summary (A/I/R)                                                   |\n \
    | 5.  Display Employee Details                                                   |\n \
    ---------------------------------------------------------------------------------\n \
    Your Choice: "
              << std::endl;
    uint8_t sChoice;
    sChoice = Generic::getInputValues<int>();
    return static_cast<Menu::SubMenu2>(sChoice);

}

Menu::SubMenu3 Menu::SubMenu3Options()
{
    std::cout << " \
    ---------------------------------------------------------------------------------\n \
    |                                    Others                                      |\n \
    ---------------------------------------------------------------------------------\n \
    | 1.  Add N number of leaves to all the Full-Time employees                      |\n \
    | 2.  Convert an Intern to Full-Time employee.                                   |\n \
    | 3.  Search an Employee by ID                                                   |\n \
    | 4.  Search an Employee by Name                                                 |\n \
    ---------------------------------------------------------------------------------\n \
    Your Choice: "
              << std::endl;
    uint8_t sChoice;
    sChoice = Generic::getInputValues<int>();
    return static_cast<Menu::SubMenu3>(sChoice);

}













#endif