#include "trdpManager.h"
#include <arpa/inet.h>

TRDP_ERR_T trdpManager::initSession (TRDP_MEM_CONFIG_T *p_memoryConfig){

    TRDP_ERR_T err = TRDP_UNKNOWN_ERR  ;

    err = tlc_init(NULL, NULL, p_memoryConfig);
    if (err != TRDP_NO_ERR)
    {
        goto error ;
    }

error :
    return err ;
}


TRDP_ERR_T trdpManager::openSession(const char* p_ipAddr){


    TRDP_ERR_T err = TRDP_UNKNOWN_ERR  ;
    TRDP_IP_ADDR_T ownIp = (TRDP_IP_ADDR_T) ntohl(inet_addr(p_ipAddr));

    err = tlc_openSession(
        &m_configSession.sessionHandle,
        ownIp,
        0,
        NULL,
        &m_configSession.processDatadConfig,
        &m_configSession.messageDataConfig,
        NULL
    );

    if (err != TRDP_NO_ERR){
        goto error ;
    }

error :
    return err ;

}


TRDP_ERR_T trdpManager::closeSession(TRDP_APP_SESSION_T p_sessionHandle){

    TRDP_ERR_T err = TRDP_UNKNOWN_ERR  ;

    err = tlc_closeSession(p_sessionHandle) ;

    if (!err){
        goto error ;
    }

error :
    return err ;
}


TRDP_ERR_T trdpManager::readConfiguration(const char* p_nameFile){

    TRDP_ERR_T err = TRDP_UNKNOWN_ERR  ;

    // ecrire dans un pointeur null ?

    err = tau_prepareXmlDoc(p_nameFile, &configFile) ;

    if (err != TRDP_NO_ERR){
        goto error ;
    }


    err = tau_readXmlDeviceConfig(
        &configFile, 
        &m_xmlConfigFile.memoryConfig,
        &m_xmlConfigFile.debugConfig,
        &m_xmlConfigFile.numComParameter,
        &m_xmlConfigFile.ComParameter,
        &m_xmlConfigFile.numInterfaceConfig,
        &m_xmlConfigFile.interfaceConfig
    );

    if (err != TRDP_NO_ERR){
        goto error ;
    }

    if (m_xmlConfigFile.numInterfaceConfig > 0)
    {
        m_telegramConfig.interfaceName = m_xmlConfigFile.interfaceConfig->ifName ;
    }
    
    err = tau_readXmlInterfaceConfig(
        &configFile,
        m_telegramConfig.interfaceName,
        NULL,
        &m_configSession.processDatadConfig,
        &m_configSession.messageDataConfig,
        &m_telegramConfig.nbTelegramParam,
        &m_telegramConfig.telegramParam
    );

    if (err != TRDP_NO_ERR){
        goto error ;
    }


error : 
    return err ;
    
}

















void trdpManager::terminateSession(){
    tlc_terminate();
}