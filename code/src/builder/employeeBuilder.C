#ifndef EMPLOYEE_BUILDER_C
#define EMPLOYEE_BUILDER_C

#include <random>

#include "employeeBuilder.H"

/// @brief Create the employee object based on the type provided
/// @param typeParam employee type 
/// @return return the employee object if success.
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

  /// @brief Generate random common emplyee data 
  /// @param objParam 
  void EmployeeBuilderInterface::randomDataGeneration(XyzEmployeeInterfaceBase* objParam)
  {
    objParam->getEmpDatabaseInstance().mEmployeeName = Emp::getRandomArrayElement(Emp::names);
    objParam->getEmpDatabaseInstance().mGender = static_cast<Emp::Gender>((std::rand()%( Emp::getEnumToInt(Emp::Gender::ENDMARKER))));
    objParam->getEmpDatabaseInstance().mEmployeeStatus = static_cast<Emp::EmpStatus>((std::rand()%( Emp::getEnumToInt(Emp::EmpStatus::ENDMARKER))));
    randomDateofBirthGeneration(objParam);
    randomDateofJoiningGeneration(objParam);
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
    Emp::DateStruct sTemp =  generateDateofLeavingContractor(objParam->getDateOfJoining());
    objParam->setDateOfLeaving(sTemp);
  }
  
  void EmployeeBuilderInterface::randomDataGenerationInternEmployee(XyzInternEmployee* objParam)
  {
    objParam->getEmpDatabaseInstance().mEmployeeType = Emp::EmpType::INTERN;
    objParam->getEmpDatabaseInstance().mEmployeeId = generateEmployeeId(Emp::EmpType::INTERN,objParam->getId());
    objParam->setBranchName(static_cast<Emp::Branches>(std::rand()%(Emp::getEnumToInt(Emp::Branches::ENDMARKER))));
    objParam->setCollegeName(static_cast<Emp::Colleges>(std::rand()%(Emp::getEnumToInt(Emp::Colleges::ENDMARKER))));
    Emp::DateStruct sTemp =  generateDateofLeavingIntern(objParam->getDateOfJoining());
    objParam->setDateOfLeaving(sTemp);
  }

 void EmployeeBuilderInterface::randomDateofJoiningGeneration(XyzEmployeeInterfaceBase* objParam)
  {
    objParam->getEmpDatabaseInstance().mDateOfJoining.Month = randomNumGeneration(1,12);
    objParam->getEmpDatabaseInstance().mDateOfJoining.Day = randomNumGeneration(1,12);
    int sDiff;
    int sYear;
    do
    {
      sYear = randomNumGeneration(2000,2024);
      sDiff = sYear - objParam->getEmpDatabaseInstance().mDateOfBirth.Year;
    } while(sDiff < 23 );
    
    objParam->getEmpDatabaseInstance().mDateOfJoining.Year = sYear;
  }

  void  EmployeeBuilderInterface::randomDateofBirthGeneration(XyzEmployeeInterfaceBase* objParam)
  {
    objParam->getEmpDatabaseInstance().mDateOfBirth.Month = randomNumGeneration(1,12);
    objParam->getEmpDatabaseInstance().mDateOfBirth.Day  = randomNumGeneration(1,30);
    objParam->getEmpDatabaseInstance().mDateOfBirth.Year  = randomNumGeneration(1990,2000);    
  }

  Emp::DateStruct EmployeeBuilderInterface::generateDateofLeavingContractor(Emp::DateStruct valParam)
  {
    Emp::DateStruct sTemp;
    sTemp.Day = valParam.Day;
    sTemp.Month = valParam.Month;
    sTemp.Year = valParam.Year + 1;
    return sTemp;
  }

  Emp::DateStruct EmployeeBuilderInterface::generateDateofLeavingIntern(Emp::DateStruct valParam)
  {
    Emp::DateStruct sTemp;
    sTemp.Day = valParam.Day;
    if(valParam.Month >= 1 && valParam.Month <= 6)
    {
      sTemp.Month = valParam.Month + 6;
      sTemp.Year = valParam.Year;
    }
    else
    {
      int sDiff = valParam.Month - 6 ;
      sTemp.Month = sDiff;
      sTemp.Year = valParam.Year + 1;
    }
    return sTemp;

  }

  int EmployeeBuilderInterface::randomNumGeneration(int lowerLimitParam,int upperLimitParam)
  {
    std::random_device sDev;
    std::mt19937 rng(sDev());
    std::uniform_int_distribution<std::mt19937::result_type> generate(lowerLimitParam,upperLimitParam);
    return generate(rng);
  }

#endif