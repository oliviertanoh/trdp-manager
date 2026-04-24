#ifndef __TRDP_STRUCT__
#define __TRDP_STRUCT__

#include "tau_xml.h"
#include "trdp_if_light.h"


/// Get information when data is receive
struct getInfo_t {
    TRDP_PD_INFO_T *trdp_info ;
    uint8_t *data ;
} ;


/// Read the TRDP device configuration parameters out of the XML configuration file
struct xmlDeviceConfig_t {
    TRDP_MEM_CONFIG_T   memoryConfig; //Memory configuration
    TRDP_DBG_CONFIG_T   debugConfig;  //Debug printout configuration for application use
    TRDP_COM_PAR_T *ComParameter; //Pointer to array of com parameters
    TRDP_IF_CONFIG_T* interfaceConfig; //Pointer to an array of interface parameter sets
    uint32_t numComParameter;
    uint32_t numInterfaceConfig; //Number of configured interfaces
};


/// Read the interface relevant telegram parameters
struct xmlInterfaceConfig_t {
    char* interfaceName ; //Interface name
    uint32_t nbTelegramParam ; //Number of configured telegrams
    TRDP_EXCHG_PAR_T *telegramParam ; //Pointer to array of telegram configurations
};


/// Session configurations
struct sessionConfig_t
{
    TRDP_APP_SESSION_T      sessionHandle;
    TRDP_PD_CONFIG_T        processDatadConfig; /// //PD default configuration for the interface
    TRDP_MD_CONFIG_T        messageDataConfig; /// MD default configuration for the interface
    TRDP_PROCESS_CONFIG_T   processConfig;
};



///  Published telegrams
struct publishTelegram_t
{
    TRDP_APP_SESSION_T  sessionhandle;
    TRDP_PUB_T          pubHandle;
    pTRDP_DATASET_T     pDatasetDesc;
    TRDP_IF_CONFIG_T   *pIfConfig;
    UINT32              comID;
    UINT32              dstID;
};


/// Subscribed telegrams
struct SubscribeTelegram_t
{
    TRDP_APP_SESSION_T  sessionhandle;
    TRDP_SUB_T          subHandle;
    pTRDP_DATASET_T     pDatasetDesc;
    TRDP_FLAGS_T        pktFlags;
    TRDP_PD_INFO_T      pdInfo;
    TRDP_IF_CONFIG_T   *pIfConfig;
    UINT32              comID;
    UINT32              srcID;
    TRDP_ERR_T          result;
};









#endif /* __TRDP_STRUCT__ */

