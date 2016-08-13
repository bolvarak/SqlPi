/////////////////////////////////////////////////////////////////////////////////////////
/// Headers ////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#include "Configuration.hpp"

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
		/// Protected Static Properties ////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		QString Configuration::mBackendDatabase  = QString::null;
		QHostAddress Configuration::mBackendHost = QHostAddress(QHostAddress::LocalHost);
		QString Configuration::mBackendPassword  = QString::null;
		int Configuration::mBackendPort          = 0;
		QString Configuration::mBackendPrefix    = QString::null;
		QString Configuration::mBackendType      = QString::null;
		QString Configuration::mBackendUsername  = QString::null;
		QHostAddress Configuration::mBindAddress = QHostAddress(QHostAddress::Any);
		int Configuration::mBindPort             = 1597;
		QString Configuration::mLogFile          = "stdout";
		QString Configuration::mSocketType       = "tcp";

		/////////////////////////////////////////////////////////////////////////////////
		/// Public Static Getters //////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		QString Configuration::getBackendDatabase()
		{
			// Return the backend database from the instance
			return mBackendDatabase;
		}

		QHostAddress Configuration::getBackendHost()
		{
			// Return the backend database host from the instance
			return mBackendHost;
		}

		QString Configuration::getBackendPassword()
		{
			// Return the backend database password from the instance
			return mBackendPassword;
		}

		int Configuration::getBackendPort()
		{
			// Return the backend database port from the instance
			return mBackendPort;
		}

		QString Configuration::getBackendPrefix()
		{
			// Return the backend database table prefix from the instance
			return mBackendPrefix;
		}

		QString Configuration::getBackendType(bool blnAsEngine)
		{
			// Check the engine flag
			if (!blnAsEngine) {
				// Return the backend database engine from the instance
				return mBackendType;
			}
			// Check for MySQL
			if (mBackendType.toLower() == "qmysql") {
				// We're done, return the engine name
				return "MySQL";
			}
			// Check for PostgreSQL
			if (mBackendType.toLower() == "qpsql") {
				// We're done, return the engine name
				return "PgSQL";
			}
			// Check for SQLite
			if (mBackendType.toLower() == "qsqlite") {
				// We're done, return the engine name
				return "SQLite";
			}
			// We're done, there is an unknow engine in play
			return "Unknown";
		}

		QString Configuration::getBackendUsername()
		{
			// Return the backend database username from the instance
			return mBackendUsername;
		}

		QHostAddress Configuration::getBindAddress()
		{
			// Return the listening address from the instance
			return mBindAddress;
		}

		int Configuration::getBindPort()
		{
			// Return the listening port from the instance
			return mBindPort;
		}

		QString Configuration::getLogFile()
		{
			// Return the log file path from the instance
			return mLogFile;
		}

		QString Configuration::getSocketType()
		{
			// Return the socket type from the instance
			return mSocketType;
		}

		/////////////////////////////////////////////////////////////////////////////////
		/// Public Static Setters //////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		void Configuration::setBackendDatabase(QString strDatabase)
		{
			// Set the backend database name/path into the instance
			mBackendDatabase = strDatabase;
		}

		void Configuration::setBackendHost(QHostAddress qhaHost)
		{
			// Set the backend database host into the instance
			mBackendHost = qhaHost;
		}

		void Configuration::setBackendHost(QString strHost)
		{
			// Check the host
			if (strHost.toLower() == "localhost") {
				// Set the backend database host into the instance
				setBackendHost(QHostAddress(QHostAddress::LocalHost));
			} else if (strHost == "127.0.0.1") {
				// Set the backend database host into the instance
				setBackendHost(QHostAddress(QHostAddress::LocalHost));
			} else if (strHost == "::1") {
				// Set the backend database host into the instance
				setBackendHost(QHostAddress(QHostAddress::LocalHostIPv6));
			} else {
				// Set the backend database host into the instance
				setBackendHost(QHostAddress(strHost));
			}
		}

		void Configuration::setBackendPassword(QString strPassword)
		{
			// Set the backend database password into the instance
			mBackendPassword = strPassword;
		}

		void Configuration::setBackendPort(int intPort)
		{
			// Set the backend database port into the instance
			mBackendPort = intPort;
		}

		void Configuration::setBackendPrefix(QString strPrefix)
		{
			// Set the backend database table prefix into the instance
			mBackendPrefix = strPrefix;
		}

		void Configuration::setBackendType(QString strType)
		{
			// Set the backend database engine into the instance
			mBackendType = strType;
		}

		void Configuration::setBackendUsername(QString strUsername)
		{
			// Set the backend database username into the instance
			mBackendUsername = strUsername;
		}

		void Configuration::setBindAddress(QHostAddress qhaAddress)
		{
			// Set the listening address into the instance
			mBindAddress = qhaAddress;
		}

		void Configuration::setBindAddress(QString strHost)
		{
			// Check the host
			if (strHost.toLower() == "localhost") {
				// Set the backend database host into the instance
				setBindAddress(QHostAddress(QHostAddress::LocalHost));
			} else if (strHost == "127.0.0.1") {
				// Set the backend database host into the instance
				setBindAddress(QHostAddress(QHostAddress::LocalHost));
			} else if (strHost == "::1") {
				// Set the backend database host into the instance
				setBindAddress(QHostAddress(QHostAddress::LocalHostIPv6));
			} else if (strHost.toLower() == "any") {
				// Set the backend database host into the instance
				setBindAddress(QHostAddress(QHostAddress::Any));
			} else  if (strHost.toLower() == "any4") {
				// Set the backend database host into the instance
				setBindAddress(QHostAddress(QHostAddress::AnyIPv4));
			} else if (strHost.toLower() == "any6") {
				// Set the backend database host into the instance
				setBindAddress(QHostAddress(QHostAddress::AnyIPv6));
			} else {
				// Set the backend database host into the instance
				setBindAddress(QHostAddress(strHost));
			}
		}

		void Configuration::setBindPort(int intPort)
		{
			// Set the listening port into the instance
			mBindPort = intPort;
		}

		void Configuration::setLogFile(QString strPath)
		{
			// Set the log file path into the instance
			mLogFile = strPath;
		}

		void Configuration::setSocketType(QString strType)
		{
			// Set the socket type into the instance
			mSocketType = strType;
		}

	/////////////////////////////////////////////////////////////////////////////////////
	} /// End SqlPi::Process Namespace /////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} /// End SqlPi Namespace //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
