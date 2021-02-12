// -*- C++ -*-
/*!
 * @file  ArmPlaneControllerTest.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "ArmPlaneControllerTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* armplanecontroller_spec[] =
  {
    "implementation_id", "ArmPlaneControllerTest",
    "type_name",         "ArmPlaneControllerTest",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ArmPlaneControllerTest::ArmPlaneControllerTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_planeIn("plane", m_plane),
    m_armStatusIn("armStatus", m_armStatus),
    m_armTipTargetOut("armTipTarget", m_armTipTarget),
    m_outDataOut("outData", m_outData)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ArmPlaneControllerTest::~ArmPlaneControllerTest()
{
}



RTC::ReturnCode_t ArmPlaneControllerTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("armTipTarget", m_armTipTargetIn);
  addInPort("outData", m_outDataIn);
  
  // Set OutPort buffer
  addOutPort("plane", m_planeOut);
  addOutPort("armStatus", m_armStatusOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ArmPlaneControllerTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPlaneControllerTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPlaneControllerTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ArmPlaneControllerTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ArmPlaneControllerTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ArmPlaneControllerTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ArmPlaneControllerTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPlaneControllerTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPlaneControllerTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPlaneControllerTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPlaneControllerTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ArmPlaneControllerTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(armplanecontroller_spec);
    manager->registerFactory(profile,
                             RTC::Create<ArmPlaneControllerTest>,
                             RTC::Delete<ArmPlaneControllerTest>);
  }
  
};


