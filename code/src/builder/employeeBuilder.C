#ifndef EMPLOYEE_BUILDER_C
#define EMPLOYEE_BUILDER_C


#include "employeeBuilder.H"

XyzEmployeeInterfaceBase* EmployeeBuilderInterface::createEmployee(Emp::EmpType typeParam)
{
    if (Emp::EmpType::FULLTIME == typeParam)
    {
        XyzFulltimeEmployee *sEmp = new XyzFulltimeEmployee();
        randomDataGeneration(sEmp);
        randomDataGenerationFulltimeEmployee(sEmp);
        return sEmp;
    }
    else if (Emp::EmpType::CONTRACTOR == typeParam)
    {
        XyzContractorEmployee *sEmp = new XyzContractorEmployee();
        randomDataGeneration(sEmp);
        randomDataGenerationContractorEmployee(sEmp);
        return sEmp;
    }
    else if (Emp::EmpType::INTERN == typeParam)
    {
        XyzInternEmployee* sEmp = new XyzInternEmployee();
        randomDataGeneration(sEmp);
        randomDataGenerationInternEmployee(sEmp);
        return sEmp;
    }
  return nullptr;
    
}

  void EmployeeBuilderInterface::randomDataGeneration(XyzEmployeeInterfaceBase* objParam)
  {
    objParam->getEmpDatabaseInstance().mEmployeeName = Emp::getRandomArrayElement(Emp::names);
    objParam->getEmpDatabaseInstance().mGender = static_cast<Emp::Gender>((std::rand()%( Emp::getEnumToInt(Emp::Gender::ENDMARKER))));
    objParam->getEmpDatabaseInstance().mEmployeeStatus = static_cast<Emp::EmpStatus>((std::rand()%( Emp::getEnumToInt(Emp::EmpStatus::ENDMARKER))));
    objParam->getEmpDatabaseInstance().mDateOfBirth = randomDateofBirthGeneration();
    objParam->getEmpDatabaseInstance().mDateOfJoining = randomDateofJoiningGeneration();
  }

  void EmployeeBuilderInterface::randomDataGenerationFulltimeEmployee(XyzFulltimeEmployee* objParam)
  {
    uint8_t sVal = 0 + (std::rand() % 22);
    objParam->setTotalLeaves(sVal);
    objParam->getEmpDatabaseInstance().mEmployeeType = Emp::EmpType::FULLTIME;
    objParam->getEmpDatabaseInstance().mEmployeeId = generateEmployeeId(Emp::EmpType::FULLTIME,objParam->getId());
  }

  void EmployeeBuilderInterface::randomDataGenerationContractorEmployee(XyzContractorEmployee* objParam)
  {
    objParam->getEmpDatabaseInstance().mEmployeeType = Emp::EmpType::CONTRACTOR;
    objParam->getEmpDatabaseInstance().mEmployeeId = generateEmployeeId(Emp::EmpType::CONTRACTOR,objParam->getId());
    objParam->setExternalAgency(static_cast<Emp::ExternalAgencies>(std::rand()%(Emp::getEnumToInt(Emp::ExternalAgencies::ENDMARKER))));

  }
  
  void EmployeeBuilderInterface::randomDataGenerationInternEmployee(XyzInternEmployee* objParam)
  {
    objParam->getEmpDatabaseInstance().mEmployeeType = Emp::EmpType::INTERN;
    objParam->getEmpDatabaseInstance().mEmployeeId = generateEmployeeId(Emp::EmpType::INTERN,objParam->getId());
    objParam->setBranchName(static_cast<Emp::Branches>(std::rand()%(Emp::getEnumToInt(Emp::Branches::ENDMARKER))));
    objParam->setCollegeName(static_cast<Emp::Colleges>(std::rand()%(Emp::getEnumToInt(Emp::Colleges::ENDMARKER))));
  }

  std::string  EmployeeBuilderInterface::randomDateofJoiningGeneration()
  {
    int sMonth = 1 + std::rand() % 12;
    int sDay = 1 + std::rand() % 30;
    int sYear = 1990 + std::rand()% (2024-1990 +1);
    
    std::string sDate = std::to_string(sDay) + "/" + std::to_string(sMonth) + "/" + std::to_string(sYear);

    return sDate;

  }

  std::string  EmployeeBuilderInterface::randomDateofBirthGeneration()
  {
    int sMonth = 1 + std::rand() % 12;
    int sDay = 1 + std::rand() % 30;
    int sYear = 1990 + std::rand() % (2000 - 1990 + 1);
    
    std::string sDate = std::to_string(sDay) + "/" + std::to_string(sMonth) + "/" + std::to_string(sYear);

    return sDate;

  }


#endif