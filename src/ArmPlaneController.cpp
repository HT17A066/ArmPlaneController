// -*- C++ -*-
/*!
 * @file  ArmPlaneController.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "ArmPlaneController.h"
using namespace std;
// Module specification
// <rtc-template block="module_spec">
static const char* armplanecontroller_spec[] =
  {
    "implementation_id", "ArmPlaneController",
    "type_name",         "ArmPlaneController",
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
ArmPlaneController::ArmPlaneController(RTC::Manager* manager)
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
ArmPlaneController::~ArmPlaneController()
{
}



RTC::ReturnCode_t ArmPlaneController::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("plane", m_planeIn);
  addInPort("armStatus", m_armStatusIn);
  
  // Set OutPort buffer
  addOutPort("armTipTarget", m_armTipTargetOut);
  addOutPort("outData", m_outDataOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ArmPlaneController::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPlaneController::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPlaneController::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ArmPlaneController::onActivated(RTC::UniqueId ec_id)
{
    m_armTipTarget.data.length(6);
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ArmPlaneController::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ArmPlaneController::onExecute(RTC::UniqueId ec_id)
{

    if (m_planeIn.isNew())
    {
        m_planeIn.read();
        Planex.push_back(m_plane.data[2]);
        Planey.push_back(m_plane.data[0]);
        Planez.push_back(m_plane.data[1]);

        double sum_x = 0, sum_y = 0, sum_z = 0;

        sum_x += Planex[0];
        cout << "x" << sum_x << endl;
        sum_y += Planey[0];
        cout << "y" << sum_y << endl;
        sum_z += Planez[0];
        cout << "z" << sum_z << endl;
        cout << (sum_x / 2) << endl;
        cout << "----------------------" << endl;


        m_armTipTarget.data[0] = -((sum_x / 2) + 0.15);
        m_armTipTarget.data[1] = -sum_y;
        m_armTipTarget.data[2] = 0.15 + sum_z + 0.1;
        m_armTipTarget.data[3] = 0.0;
        m_armTipTarget.data[4] = 0.3;
        m_armTipTarget.data[5] = 5;
        m_armTipTargetOut.write();
        Sleep(5000);

        Planex.erase(Planex.begin(), Planex.begin() + 1);
        Planey.erase(Planey.begin(), Planey.begin() + 1);
        Planez.erase(Planez.begin(), Planez.begin() + 1);
    }
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ArmPlaneController::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPlaneController::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPlaneController::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPlaneController::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPlaneController::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ArmPlaneControllerInit(RTC::Manager* manager)
  {
    coil::Properties profile(armplanecontroller_spec);
    manager->registerFactory(profile,
                             RTC::Create<ArmPlaneController>,
                             RTC::Delete<ArmPlaneController>);
  }
  
};


