////////////////////////////////////////////////////////////////////////////////
//
// Patient.cpp: Implementation file for class that holds a collection of 
// values specific to determining how to display data for an individual prostate
// cancer patient.
//
// Author:    Steve Chall, RENCI
//
// Primary collaborators: 
//            Joseph Lo, Shiva Das, Vorakarn Chanyavanich, Duke Medical Center
//
// Copyright: The Renaissance Computing Institute (RENCI)
//
// License:   Licensed under the RENCI Open Source Software License v. 1.0
//
//            See http://www.renci.org/resources/open-source-software-license
//            for details.
//
////////////////////////////////////////////////////////////////////////////////


#include "Patient.h"


///ctor/////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
Patient::Patient()
  : dataDir("."),
    number(defaultPatientNumber),
    index(-1),
    sliceMin(-1),
    sliceMax(-1),
    sliceOrientation(Z)
{
}

///ctor/////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
Patient::Patient(int n)
  : dataDir("."),
    number(n),
    index(-1),
    sliceMin(-1),
    sliceMax(-1),
    sliceOrientation(Z)
{
}

///dtor/////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
Patient::~Patient()
{
}

////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
QString Patient::getPathToCTData()
{
  CTDataPath = dataDir + "\\CT\\Patient";

  QString numberAsString = 
    QString(("%1")).arg(this->number, 3, 10, QLatin1Char('0'));
  CTDataPath.append(numberAsString);

  CTDataPath.append("\\Primary");

  return CTDataPath;
}

////////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
void Patient::setPathToCTData(const QString &path)
{
  CTDataPath = path;
}
  
////////////////////////////////////////////////////////////////////////////////
// 
////////////////////////////////////////////////////////////////////////////////
QString Patient::getPathToDVHData()
{
  DVHDataPath = dataDir + "\\DVH\\DVH_ORIGINAL" +
    QString::number(this->number);
  //DVHDataPath = dataDir + "/DVHdata/DVH";

  //QString numberAsString = 
  //  QString(("%1")).arg(this->number, 3, 10, QLatin1Char('0'));
  //DVHDataPath.append(numberAsString);

  DVHDataPath.append(".txt");

  return DVHDataPath;

}

////////////////////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////////////////////
void Patient::setPathToDVHData(const QString &path)
{
  DVHDataPath = path;
}
  
