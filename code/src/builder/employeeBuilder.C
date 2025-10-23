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
    
}

  void EmployeeBuilderInterface::randomDataGeneration(XyzEmployeeInterfaceBase* objParam)
  {
    objParam->getEmpDatabaseInstance().mEmployeeName = Emp::getRandomArrayElement(Emp::names);
    objParam->getEmpDatabaseInstance().mGender = static_cast<Emp::Gender>((std::rand()%( Emp::getEnumToInt(Emp::Gender::ENDMARKER) - 1)));
    objParam->getEmpDatabaseInstance().mEmployeeStatus = static_cast<Emp::EmpStatus>((std::rand()%( Emp::getEnumToInt(Emp::EmpStatus::ENDMARKER) - 1)));
    objParam->getEmpDatabaseInstance().mDateOfBirth = "na";
    objParam->getEmpDatabaseInstance().mDateOfJoining = "na";
    
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
    objParam->setExternalAgency(static_cast<Emp::ExternalAgencies>(std::rand()%(Emp::getEnumToInt(Emp::ExternalAgencies::ENDMARKER)-1)));

  }
  
  void EmployeeBuilderInterface::randomDataGenerationInternEmployee(XyzInternEmployee* objParam)
  {
    objParam->getEmpDatabaseInstance().mEmployeeType = Emp::EmpType::INTERN;
    objParam->getEmpDatabaseInstance().mEmployeeId = generateEmployeeId(Emp::EmpType::INTERN,objParam->getId());
    objParam->setBranchName(static_cast<Emp::Branches>(std::rand()%(Emp::getEnumToInt(Emp::Branches::ENDMARKER)-1)));
    objParam->setCollegeName(static_cast<Emp::Colleges>(std::rand()%(Emp::getEnumToInt(Emp::Colleges::ENDMARKER)-1)));
  }

  std::string EmployeeBuilderInterface::generateEmployeeId(Emp::EmpType typeParm, int idParm)
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


#endif