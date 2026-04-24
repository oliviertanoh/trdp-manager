#ifndef __TRDP_MANAGER__
#define __TRDP_MANAGER__

#include "trdp_struct.h"

class trdpManager {

    public :

        /**
         * @brief Initialise le protocole TRDP.
         * @param [in] p_memoryConfig Definit la mémoire alloué au protocole.
         */
        TRDP_ERR_T initSession (TRDP_MEM_CONFIG_T *p_memoryConfig);


        /**
         * @brief Cette methode ouvre sesssion TRDP.
         * @param [in] p_sessionHandle Le handle (ou l'identifiant) de la session à ouvrir.
         * @param [in] p_ipAddr L'adresse ip de la machine.
         * @param [in] p_processDataConfig La configuration des messages de type Process Data.
         * @param [in] p_messageDataConfig La configuration des messages de type Message Data.
         * @param [in] p_ProcessConfig La configuration global de protocole (hostname, cycle time, etc).
         * @return Un code d'erreur TRDP_ERR_T indiquant le résultat de l'opération.
         */
        TRDP_ERR_T openSession(const char* p_ipAddr);

        /**
         * @brief Cette methode ferme une session TRDP.
         * Cette méthode permet de fermé une session TRDP spécifique.
         * @param [in] p_sessionHandle Le handle (ou l'identifiant) de la session à fermer.
         * @return Un code d'erreur TRDP_ERR_T indiquant le résultat de l'opération.
         */
        TRDP_ERR_T closeSession(TRDP_APP_SESSION_T p_sessionHandle);


         /**
         * @brief Cette methode ferme toutes les sesssions TRDP.
         * Cette méthode ferme toute les séssions deja ouverte.
         * Elle est principalement utilisé pour des tests ou du debug.
         */
        void terminateSession();
        
        /**
         * @ Cette methode lit le fichier de configuartion.
         * Elle permet la lecture des différents paramtètre pour
         * la communication (ip, nombre de device, timeot, etc..).
         * @param [in] p_nameFile Le nom du ficher de configuration.
         * @return Un code d'erreur TRDP_ERR_T indiquant le résultat de l'opération.
         */
        TRDP_ERR_T readConfiguration(const char* p_nameFile) ;



    protected :

        /// Fichier de configuration
        TRDP_XML_DOC_HANDLE_T configFile;

        /// Configuration du device (chargée depuis XML)
        xmlDeviceConfig_t m_xmlConfigFile ;

        /// Configuration des interfaces (telegram = canal de communication)
        xmlInterfaceConfig_t m_telegramConfig ;

        /// Paramètres de session (runtime)
        sessionConfig_t m_configSession ;



};

#endif /* __TRDP_MANAGER__ */