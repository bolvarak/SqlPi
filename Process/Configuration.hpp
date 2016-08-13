/////////////////////////////////////////////////////////////////////////////////////////
/// Definitions ////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#ifndef SQLPI_PROCESS_CONFIGURATION_HPP
#define SQLPI_PROCESS_CONFIGURATION_HPP

/////////////////////////////////////////////////////////////////////////////////////////
/// Headers ////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#include <QObject>
#include <QString>
#include <QtNetwork/QHostAddress>

/////////////////////////////////////////////////////////////////////////////////////////
/// SqlPi Namespace ////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

namespace SqlPi
{
	/////////////////////////////////////////////////////////////////////////////////////
	/// SqlPi::Process Namespace ///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	namespace Process
	{
		/////////////////////////////////////////////////////////////////////////////////
		/// SqlPi::Process::Configuration Class Definition /////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		class Configuration : public QObject
		{
				/**
				 * Qt Recognition
				 */
				Q_OBJECT

			/////////////////////////////////////////////////////////////////////////////
			/// Protected Methods & Properties /////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			protected:

				/////////////////////////////////////////////////////////////////////////
				/// Static Properties //////////////////////////////////////////////////
				///////////////////////////////////////////////////////////////////////

				/**
				 * @paragraph This property contains the name/path to the backend database
				 * @brief SqlPi::Process::Configuration::mBackendDatabase
				 * @var QString
				 */
				static QString mBackendDatabase;

				/**
				 * @paragraph This property contains the host that the backend database resides on
				 * @brief SqlPi::Process::Configuration::mBackendHost
				 * @var QHostAddress
				 */
				static QHostAddress mBackendHost;

				/**
				 * @paragraph This property contains the password for accessing the backend database
				 * @brief SqlPi::Process::Configuration::mBackendPassword
				 * @var QString
				 */
				static QString mBackendPassword;

				/**
				 * @paragraph This property contains the port in which the backend database host is listening on
				 * @brief SqlPi::Process::Configuration::mBackendPort
				 * @var int
				 */
				static int mBackendPort;

				/**
				 * @paragraph This property contains the prefix for tables specific to SqlPi in the backend database
				 * @brief SqlPi::Process::Configuration::mBackendPrefix
				 * @var QString
				 */
				static QString mBackendPrefix;

				/**
				 * @paragraph This property contains the database engine for the backend database
				 * @brief SqlPi::Process::Configuration::mBackendType
				 * @var QString
				 */
				static QString mBackendType;

				/**
				 * @paragraph This property contains the username for accessing the backend database
				 * @brief SqlPi::Process::Configuration::mBackendUsername
				 * @var QString
				 */
				static QString mBackendUsername;

				/**
				 * @paragraph This property contains the address in which SqlPi should bind to
				 * @brief SqlPi::Process::Configuration::mBindAddress
				 * @var QHostAddress
				 */
				static QHostAddress mBindAddress;

				/**
				 * @paragraph This property contains the port in which SqlPi should listen on
				 * @brief SqlPi::Process::Configuration::mBindPort
				 * @var int
				 */
				static int mBindPort;

				/**
				 * @paragraph This property contains the path to the log file that SqlPi should use
				 * @brief SqlPi::Process::Configuration::mLogFile
				 * @var QString
				 */
				static QString mLogFile;

				/**
				 * @paragraph This property contains the type of socket SqlPi should spawn
				 * @brief SqlPi::Process::Configuration::mSocketType
				 * @var QString
				 */
				static QString mSocketType;

			/////////////////////////////////////////////////////////////////////////////
			/// Public Methods & Properties ////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			public:

				/////////////////////////////////////////////////////////////////////////
				/// Static Getters /////////////////////////////////////////////////////
				///////////////////////////////////////////////////////////////////////

				/**
				 * @paragraph This method returns the backend database name/path from the instance
				 * @brief SqlPi::Process::Configuration::getBackendDatabase()
				 * @return QString
				 */
				static QString getBackendDatabase();

				/**
				 * @paragraph This method returns the backend database host from the instance
				 * @brief SqlPi::Process::Configuration::getBackendHost()
				 * @return QHostAddress
				 */
				static QHostAddress getBackendHost();

				/**
				 * @paragraph This method returns the backend database password from the instance
				 * @brief SqlPi::Process::Configuration::getBackendPassword()
				 * @return QString
				 */
				static QString getBackendPassword();

				/**
				 * @paragraph This method returns the backend database port from the instance
				 * @brief SqlPi::Process::Configuration::getBackendPort()
				 * @return int
				 */
				static int getBackendPort();

				/**
				 * @paragraph This method returns the backend database table prefix from the instance
				 * @brief SqlPi::Process::Configuration::getBackendPrefix()
				 * @return QString
				 */
				static QString getBackendPrefix();

				/**
				 * @paragraph This method returns the backend database engine from the instance
				 * @brief SqlPi::Process::Configuration::getBackendType()
				 * @param bool blnAsEngine [false]
				 * @return QString
				 */
				static QString getBackendType(bool blnAsEngine = false);

				/**
				 * @paragraph This method returns the backend database username from the instance
				 * @brief SqlPi::Process::Configuration::getBackendUsername()
				 * @return QString
				 */
				static QString getBackendUsername();

				/**
				 * @paragraph This method returns the listening address from the instance
				 * @brief SqlPi::Process::Configuration::getBindAddress()
				 * @return QHostAddress
				 */
				static QHostAddress getBindAddress();

				/**
				 * @paragraph This method returns the listening port from the instance
				 * @brief SqlPi::Process::Configuration::getBindPort()
				 * @return int
				 */
				static int getBindPort();

				/**
				 * @paragraph This method returns the log file path from the instance
				 * @brief SqlPi::Process::Configuration::getLogFile()
				 * @return QString
				 */
				static QString getLogFile();

				/**
				 * @paragraph This method returns the socket type from the instance
				 * @brief SqlPi::Process::Configuration::getSocketType()
				 * @return QString
				 */
				static QString getSocketType();

				/////////////////////////////////////////////////////////////////////////
				/// Static Settings ////////////////////////////////////////////////////
				///////////////////////////////////////////////////////////////////////

				/**
				 * @paragraph This method sets the backend database name/path into the instance
				 * @brief SqlPi::Process::Configuration::setBackendDatabase()
				 * @param QString strDatabase
				 * @return void
				 */
				static void setBackendDatabase(QString strDatabase);

				/**
				 * @paragraph This method sets the backend database host into the instance
				 * @brief SqlPi::Process::Configuration::setBackendHost()
				 * @param QHostAddress qhaHost
				 * @return void
				 */
				static void setBackendHost(QHostAddress qhaHost);

				/**
				 * @paragraph This method sets the backend database host into the instance
				 * @brief SqlPi::Process::Configuration::setBackendHost()
				 * @param QString strHost
				 * @return void
				 */
				static void setBackendHost(QString strHost);

				/**
				 * @paragraph This method sets the backend database password into the instance
				 * @brief SqlPi::Process::Configuration::setBackendPassword()
				 * @param QString strPassword
				 * @return void
				 */
				static void setBackendPassword(QString strPassword);

				/**
				 * @paragraph This method sets the backend database port into the instance
				 * @brief SqlPi::Process::Configuration::setBackendPort()
				 * @param int intPort
				 * @return void
				 */
				static void setBackendPort(int intPort);

				/**
				 * @paragraph This method sets the backend database table prefix into the instance
				 * @brief SqlPi::Process::Configuration::setBackendPrefix()
				 * @param QString strPrefix
				 * @return void
				 */
				static void setBackendPrefix(QString strPrefix);

				/**
				 * @paragraph This method sets the backend database engine into the instance
				 * @brief SqlPi::Process::Configuration::setBackendType()
				 * @param QString strType
				 * @return void
				 */
				static void setBackendType(QString strType);

				/**
				 * @paragraph This method sets the backend database username into the instance
				 * @brief SqlPi::Process::Configuration::setBackendUsername()
				 * @param QString strUsername
				 * @return void
				 */
				static void setBackendUsername(QString strUsername);

				/**
				 * @paragraph This method sets the listen address into the instance
				 * @brief SqlPi::Process::Configuration::setBindAddress()
				 * @param QHostAddress qhaAddress
				 * @return void
				 */
				static void setBindAddress(QHostAddress qhaAddress);

				/**
				 * @paragraph This method sets the listen address into the instance
				 * @brief SqlPi::Process::Configuration::setBindAddress()
				 * @param QString strHost
				 * @return void
				 */
				static void setBindAddress(QString strHost);

				/**
				 * @paragraph This method sets the listen port into the instance
				 * @brief SqlPi::Process::Configuration::setBindPort()
				 * @param int intPort
				 * @return void
				 */
				static void setBindPort(int intPort);

				/**
				 * @paragraph This method sets the log file path into the instance
				 * @brief SqlPi::Process::Configuration::setLogFile()
				 * @param QString strPath
				 * @return void
				 */
				static void setLogFile(QString strPath);

				/**
				 * @paragraph This method sets the socket type into the instance
				 * @brief SqlPi::Process::Configuration::setSocketType()
				 * @param QString strType
				 * @return void
				 */
				static void setSocketType(QString strType);

		/////////////////////////////////////////////////////////////////////////////////
		}; /// End SqlPi::Process::Configuration Class Definition //////////////////////
		///////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////
	} /// End SqlPi::Process Namespace /////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} /// End SqlPi Namespace //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif /// End Definitions /////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
