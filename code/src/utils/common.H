#ifndef COMMON_H
#define COMMON_H

#include <iomanip>
#include <sstream>
#include <iostream>

#define ENTRY(employeename,id,type,status,gender,dob,doj) \
   { \
    std::cout<<" | "<<employeename<<"    " \
                                "| "<<id<<"     " \
                                "| "<<type<<"      " \
                                "| "<<status<<"     " \
                                "| "<<gender<<"     " \
                                "| "<<dob<<"        " \
                                "| "<<doj<<"        |" <<std::endl;}

#define COMMON_DETAILS(empname, id, type, status, gender, dob, doj) \
{ \
    std::cout << "Employee Name:     " << empname << std::endl; \
    std::cout << "Employee Id:       " << id << std::endl; \
    std::cout << "Employee Type:     " << type << std::endl; \
    std::cout << "Employee Status:   " << status << std::endl; \
    std::cout << "Gender:            " << gender << std::endl; \
    std::cout << "Date of Birth:     " << dob << std::endl; \
    std::cout << "Date of Joining:   " << doj << std::endl; \
}

#define FULLTIME_EMP_DETAILS(empname, id, type, status, gender, dob, doj,to_leave, leave_left) \
{ \
    COMMON_DETAILS(empname, id, type, status, gender, dob, doj) \
    std::cout << "Leaves Awailed:    " << static_cast<int>(to_leave) << std::endl; \
    std::cout << "Leaves Left:       " << static_cast<int>(leave_left) << std::endl; \
}

#define CONTRACTOR_DETAILS(empname, id, type, status, gender, dob, doj,externalAgency) \
{ \
    COMMON_DETAILS(empname, id, type, status, gender, dob, doj) \
    std::cout << "External Agency:    " << externalAgency << std::endl; \
}

#define INTERN_DETAILS(empname, id, type, status, gender, dob, doj,college,branch) \
{ \
    COMMON_DETAILS(empname, id, type, status, gender, dob, doj) \
    std::cout << "Collage:  " << college << std::endl; \
    std::cout << "Branch:   " << branch << std::endl; \
}



namespace Generic
{
    enum class Common
    {
        DEFAULT_ZERO_VALUE =  0
    };

    enum class Direction
    {
        FRONTDIRECTION = 1, 
        BACKDIRECTION = -1
    };

/// @brief Generic Input Function for all data types
/// @tparam T 
/// @return user input
template <typename T> 
T getInputValues()
{
    T sInput = T();

    while(true)
    { 
        std::cin >> sInput;        
        if (std::cin.fail())
        {
            std::cout << "Wrong input Type,Try Again: " << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    return sInput;
}

}

namespace Emp
{
    constexpr int Leaves  = 5;
    enum class EmpType
    {
        FULLTIME,
        CONTRACTOR,
        INTERN,
        ENDMARKER
    };

    enum class EmpStatus
    {
        ACTIVE,
        INACTIVE,
        RESIGNED,
        ENDMARKER
    };

    enum class ExternalAgencies
    {
        AVENGERS,
        JUSTICELEAGUE,
        XMEN,
        ENDMARKER        
    };

    enum class Colleges
    {
        IITDELHI,
        IITMUMBAI,
        IITKANPUR,
        IITHYDERABAD,
        NITWARANGAL,
        NITTIRUCHI,
        ENDMARKER
    };

    enum class Branches
    {
        CSE,
        CSIT,
        ECE,
        ENDMARKER
    };

    enum class Gender
    {
        MALE,
        FEMALE,
        ENDMARKER
    };

    struct DateStruct
    {
        uint8_t Day;
        std::string Month;
        uint16_t Year;
    };

    static std::string names[10] = {"Mohan","Reena","Gauri","Saket","Sangeeta","Zoravar","Anirudh","Reddy","Tom","Jerry"};

    template <typename T, size_t N>
    T getRandomArrayElement(T (&arr)[N])
    {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        int sRandomIndex = std::rand() % N;
        return arr[sRandomIndex];
    }    

    static std::string getFourDigitNo(int valParam)
    {
        std::ostringstream oss;
        oss << std::setfill('0') << std::setw(4) << valParam;
        return oss.str();
    }
    template <typename T>
    static int getEnumToInt(T args)
    {
        int sRet;
        sRet = static_cast<int>(args);
        return sRet;
    }

    std::string getEmpTypeToString(Emp::EmpType valParam);
    std::string getEmpStatusToString(Emp::EmpStatus valParam);
    std::string getExternalAgenciesToString(Emp::ExternalAgencies valParam);
    std::string getCollegesToString(Emp::Colleges valParam);
    std::string getBranchesToString(Emp::Branches valParam);
    std::string getGenderToString(Emp::Gender valParam);
    std::string getExternalAgenciesToString(Emp::ExternalAgencies valParam);
    std::string generateEmployeeId(Emp::EmpType typeParm, int idParm);
    
}

namespace Menu
{

    enum class MainMenu
    {
        ADD_EMPLOYEE = 1,
        REMOVE_EMPLOYEE,
        EMPLOYEE_DETAILS,
        OTHERS,
        EXIT = 255
    };

    enum class SubMenu1
    {
        ADD_RANDOM_EMPLOYEE = 1,
        ADD_EMPLOYEE,
        EXIT = 255
    };

    enum class SubMenu2
    {
        ALL_EMPLOYEE_SUMMERY = 1,
        EMPLOYEE_SUMMERY_FCI,
        EMPLOYEE_SUMMERY_MF,
        EMPLOYEE_SUMMERY_AIR,
        EMPLOYEE_DETAILS,
        EXIT = 255
    };

    enum class SubMenu3
    {
        ADD_LEAVES_FULL_TIME_EMPLOYEES = 1,
        INTERN_TO_FULLTIME,
        SEARCH_EMP_ID,
        SEARCH_EMP_NAME,
        EXIT = 255

    };

    Menu::MainMenu MainMenuOptions();
    Menu::SubMenu1 SubMenu1Options();
    Menu::SubMenu2 SubMenu2Options();
    Menu::SubMenu3 SubMenu3Options();

    void printDetailsHeader();




}

#endif