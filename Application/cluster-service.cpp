#include "cluster-service.hxx"

#if DISABLE_CLUSTER_BACKEND
#include <climits>
#include <cluster-api-sdevent.h>
#include <cluster_api.h>
#include <systemd/sd-daemon.h>
#include <systemd/sd-event.h>
#endif

//-----------------------------------------------------------------------------------
QClusterService::QClusterService()
{

}
//-----------------------------------------------------------------------------------
QClusterService::~QClusterService()
{


}
//-----------------------------------------------------------------------------------
Q_INVOKABLE int QClusterService::getSpAnalogVal()
{
    uint32_t speed_u32 = 0;
    int retval = 0;
#if DISABLE_CLUSTER_BACKEND
    speed_u32 = ::getSpAnalogVal();
#endif
    if (speed_u32 > (uint32_t)INT_MAX)
        retval = INT_MAX;
    else
        retval = (int)speed_u32;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE int QClusterService::getTaAnalogVal()
{
    uint32_t ta_u32 = 0;
    int retval = 0;
#if DISABLE_CLUSTER_BACKEND
    ta_u32 = ::getTaAnalogVal();
#endif
    if (ta_u32 > (uint32_t)INT_MAX)
        retval = INT_MAX;
    else
        retval = (int)ta_u32;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE int QClusterService::getTrcomTripAVal()
{
    uint32_t tripa_u32 = 0;
    int retval = 0;
#if DISABLE_CLUSTER_BACKEND
    tripa_u32 = ::getTrcomTripAVal();
#endif
    if (tripa_u32 > (uint32_t)INT_MAX)
        retval = INT_MAX;
    else
        retval = (int)tripa_u32;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE int QClusterService::getOTempVal()
{
    int16_t tmp_val = -40;
    int retval = -40;
#if DISABLE_CLUSTER_BACKEND
    tmp_val = ::getOTempVal();
#endif
    retval = (int)tmp_val;

    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getTurnR()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getTurnR();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getTurnL()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getTurnL();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getFrontRightSeatbelt()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getFrontRightSeatbelt();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getFrontLeftSeatbelt()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getFrontLeftSeatbelt();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getGeneralWarn()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getGeneralWarn();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getEngine()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getEngine();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getLowBattery()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getLowBattery();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getLdwOff()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getLdwOff();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getSrsAirbag()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getSrsAirbag();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getEspOff()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getEspOff();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getBrake()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getBrake();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getAbs()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getAbs();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getEspAct()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getEspAct();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getHillDescent()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getHillDescent();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getImmobi()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getImmobi();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getDoor()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getDoor();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getEps()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getEps();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getAutoHiBeamGreen()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getAutoHiBeamGreen();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE bool QClusterService::getHighbeam()
{
    bool retval = false;
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_ON_OFF on_off_flag = IC_HMI_OFF;

    on_off_flag = ::getHighbeam();
    if (on_off_flag == IC_HMI_OFF)
        retval = false;
    else
        retval = true;
#endif
    return retval;
}
//-----------------------------------------------------------------------------------
Q_INVOKABLE QString QClusterService::getGearAtVal()
{
#if DISABLE_CLUSTER_BACKEND
    IC_HMI_GEAR_AT_VAL gear_val = IC_HMI_AT_UNUSED;
    QString gear_string = QString("");

    gear_val = ::getGearAtVal();

    switch (gear_val) {
    case IC_HMI_AT_OFF :
        gear_string = QString("Off");
        break;
    case IC_HMI_AT_PARKING :
        gear_string = QString("P");
        break;
    case IC_HMI_AT_REVERSE :
        gear_string = QString("R");
        break;
    case IC_HMI_AT_NEUTRAL :
        gear_string = QString("N");
        break;
    case IC_HMI_AT_DRIVE :
        gear_string = QString("D");
        break;
    case IC_HMI_AT_SECOND :
        gear_string = QString("S");
        break;
    case IC_HMI_AT_LOW_GEAR :
        gear_string = QString("L");
        break;
    case IC_HMI_AT_FIRST :
        gear_string = QString("F");
        break;
    case IC_HMI_AT_MANUAL :
        gear_string = QString("M");
        break;
    case IC_HMI_AT_BRAKE :
        gear_string = QString("B");
        break;
    case IC_HMI_AT_ALL_ON :
    case IC_HMI_AT_ALL_OFF :
    case IC_HMI_AT_UNUSED :
        gear_string = QString("Error");
        break;
    default:
        gear_string = QString("Off");
        break;
    }

    return gear_string;
#else
    return QStringLiteral("Test");
#endif
}
//-----------------------------------------------------------------------------------
/*
static void ic_notify(uint64_t signal, IC_HMI_ON_OFF val)ui
{
    fprintf(stdout, "Signal change notify %016lx , val=%1d\r", signal, val);
}
*/
void QClusterService::run()
{
#if DISABLE_CLUSTER_BACKEND
    sd_event *event = NULL;
    data_pool_client_handle_sdevent handle = NULL;
    int ret = -1;

    ret = sd_event_default(&event);
    if (ret < 0)
        goto finish;

    do {
        ret = data_pool_client_setup_sdevent(event, &handle);
        if (ret == 0)
            break;
        this->msleep(10);
    } while(true);

    //(void) registerIcHmi(IC_HMI_TT_TURN_R, ic_notify);
    //(void) registerIcHmi(IC_HMI_TT_TURN_L, ic_notify);

    ret = sd_event_loop(event);
    if (ret < 0) {
        //TODO
    }
finish:
    (void) data_pool_client_cleanup_sdevent(handle);
    event = sd_event_unref(event);

#endif
    return;
}

//-----------------------------------------------------------------------------------
