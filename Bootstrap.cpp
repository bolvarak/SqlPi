/////////////////////////////////////////////////////////////////////////////////////////
/// Headers ////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#include "Bootstrap.hpp"

/////////////////////////////////////////////////////////////////////////////////////////
/// SqlPi Namespace ////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

namespace SqlPi
{
	/////////////////////////////////////////////////////////////////////////////////////
	/// Constructor ////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	Bootstrap::Bootstrap(int intArguments, char *arrArguments[], QObject* qoParent) : QObject(qoParent), mApplication(intArguments, arrArguments)
	{
		// Set the application's name
		this->mApplication.setApplicationName("SqlPi Remote Database Interface");
		// Set the application's version
		this->mApplication.setApplicationVersion("1.0.0");
		// Set the application's domain
		this->mApplication.setOrganizationDomain("sqlpi.io");
		// Set the application's organization
		this->mApplication.setOrganizationName("CDN Depot");
		// Instantiate the interface
		this->mInput = new Process::Interface();
		// Make the application connection
		this->connect(&this->mApplication, SIGNAL(aboutToQuit()), this, SLOT(closing()));
	}

	/////////////////////////////////////////////////////////////////////////////////////
	/// Private Methods ////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	bool Bootstrap::setupBackendMySql(QString &strError)
	{
		// Database Name
		if (!this->mInput->isSet("backend-db")) {
			// Set the error message
			strError = "Backend MySQL name not defined.";
			// We're done, there was a problem
			return false;
		}
		// Database Host Name
		if (!this->mInput->isSet("backend-host")) {
			// Set the error message
			strError = "Backend MySQL host not defined.";
			// We're done, there was a problem
			return false;
		}
		// Database Host Port
		if (!this->mInput->isSet("backend-port")) {
			// Set the error message
			strError = "Backend MySQL port not defined.";
			// We're done, there was a problem
			return false;
		}
		// Database Username
		if (!this->mInput->isSet("backend-username")) {
			// Set the error message
			strError = "Backend MySQL username not defined.";
			// We're done, there was a problem
			return false;
		}
		// Database Password
		if (!this->mInput->isSet("backend-password")) {
			// Set the error message
			strError = "Backend MySQL password not defined.";
			// We're done, there was a problem
			return false;
		}
		// Set th backend database engine into the configuration
		Process::Configuration::setBackendType("QMYSQL");
		// Set the backend database name into the configuration
		Process::Configuration::setBackendDatabase(this->mInput->value("backend-db").trimmed());
		// Set the backend database host into the configuration
		Process::Configuration::setBackendHost(this->mInput->value("backend-host").trimmed());
		// Set the backend database port into the configuration
		Process::Configuration::setBackendPort(this->mInput->value("backend-port").trimmed().toInt());
		// Set the backend database username into the configuration
		Process::Configuration::setBackendUsername(this->mInput->value("backend-username").trimmed());
		// Set the backend database password into the configuration
		Process::Configuration::setBackendPassword(this->mInput->value("backend-password").trimmed());
		// Set the backend database table prefix into the configuration
		Process::Configuration::setBackendPrefix(this->mInput->value("backend-prefix").trimmed());
		// We're done
		return true;
	}

	bool Bootstrap::setupBackendPgSql(QString &strError)
	{
		// Database Name
		if (!this->mInput->isSet("backend-db")) {
			// Set the error message
			strError = "Backend PgSQL name not defined.";
			// We're done, there was a problem
			return false;
		}
		// Database Host Name
		if (!this->mInput->isSet("backend-host")) {
			// Set the error message
			strError = "Backend PgSQL host not defined.";
			// We're done, there was a problem
			return false;
		}
		// Database Host Port
		if (!this->mInput->isSet("backend-port")) {
			// Set the error message
			strError = "Backend PgSQL port not defined.";
			// We're done, there was a problem
			return false;
		}
		// Database Username
		if (!this->mInput->isSet("backend-username")) {
			// Set the error message
			strError = "Backend PgSQL username not defined.";
			// We're done, there was a problem
			return false;
		}
		// Database Password
		if (!this->mInput->isSet("backend-password")) {
			// Set the error message
			strError = "Backend PgSQL password not defined.";
			// We're done, there was a problem
			return false;
		}
		// Set th backend database engine into the configuration
		Process::Configuration::setBackendType("QPSQL");
		// Set the backend database name into the configuration
		Process::Configuration::setBackendDatabase(this->mInput->value("backend-db").trimmed());
		// Set the backend database host into the configuration
		Process::Configuration::setBackendHost(this->mInput->value("backend-host").trimmed());
		// Set the backend database port into the configuration
		Process::Configuration::setBackendPort(this->mInput->value("backend-port").trimmed().toInt());
		// Set the backend database username into the configuration
		Process::Configuration::setBackendUsername(this->mInput->value("backend-username").trimmed());
		// Set the backend database password into the configuration
		Process::Configuration::setBackendPassword(this->mInput->value("backend-password").trimmed());
		// Set the backend database table prefix into the configuration
		Process::Configuration::setBackendPrefix(this->mInput->value("backend-prefix").trimmed());
		// We're done
		return true;
	}

	bool Bootstrap::setupBackendSqLite(QString &strError)
	{
		// Database Name
		if (!this->mInput->isSet("backend-db")) {
			// Set the error message
			strError = "Backend SQLite database path not defined.";
			// We're done, there was a problem
			return false;
		}
		// Create the file
		QFile fleDb(this->mInput->value("backend-db"));
		// Check for existence
		if (!fleDb.exists()) {
			// Set the error message
			strError = QString("Backend SQLite Database at [%1] does not exist.").arg(this->mInput->value("backend-db"));
			// We're done, the database doesn't exist
			return false;
		}
		// Set th backend database engine into the configuration
		Process::Configuration::setBackendType("QSQLITE");
		// Set the backend database name into the configuration
		Process::Configuration::setBackendDatabase(this->mInput->value("backend-db").trimmed());
		// Set the backend database username into the configuration
		Process::Configuration::setBackendUsername(this->mInput->value("backend-username").trimmed());
		// Set the backend database password into the configuration
		Process::Configuration::setBackendPassword(this->mInput->value("backend-password").trimmed());
		// Set the backend database table prefix into the configuration
		Process::Configuration::setBackendPrefix(this->mInput->value("backend-prefix").trimmed());
		// We're done
		return true;
	}

	bool Bootstrap::setupSocketFastCGI(QString &strError)
	{
		// Reset the error
		strError = QString::null;
		// We're done, the socket is good to go
		return true;
	}

	bool Bootstrap::setupSocketTCP(QString &strError)
	{
		// Set the listener into the instance
		this->mListener = new Transport::Tcp();
		// Try to start the socket
		if (!this->mListener->await(strError)) {
			// Set the error
			strError = QString("TCP Socket [%1]").arg(strError);
			// We're done, there was an error starting the socket
			return false;
		}
		// We're done, the socket is good to go
		return true;
	}

	bool Bootstrap::setupSocketWeb(QString &strError)
	{
		// Reset the error
		strError = QString::null;
		// We're done, the socket is good to go
		return true;
	}

	/////////////////////////////////////////////////////////////////////////////////////
	/// Protected Methods //////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	bool Bootstrap::setupBackend(QString &strError)
	{
		// Define our CLI driver list
		QStringList qslInterfaceDrivers = QStringList() << "mysql" << "pgsql" << "sqlite";
		// Define our Qt driver list
		QStringList qslQtDrivers = QStringList() << "QMYSQL" << "QPSQL";
		// Make sure we have a backend type
		if (!this->mInput->isSet("backend-type")) {
			// Set the error message
			strError = "No backend type was defined, the backend type should be mysql, pgsql or sqlite.";
			// We're done, there is no backend
			return false;
		}
		// Validate the engine
		if (!qslInterfaceDrivers.contains(this->mInput->value("backend-type").trimmed(), Qt::CaseInsensitive)) {
			// Set the error message
			strError = QString("Invalid backend driver provided [%1].  Valid backends are mysql, pgsql and sqlite.").arg(this->mInput->value("backend-type"));
			// We're done, invalid backend type
			return false;
		}
		// Setup MySQL
		if ((this->mInput->value("backend-type").toLower() == "mysql") && !this->setupBackendMySql(strError)) {
			// We're done, something went wrong
			return false;
		}
		// Setup PostgreSQL
		if ((this->mInput->value("backend-type").toLower() == "pgsql") && !this->setupBackendPgSql(strError)) {
			// We're done, something went wrong
			return false;
		}
		// Setup SQLite
		if ((this->mInput->value("backend-type").toLower() == "sqlite") && !this->setupBackendSqLite(strError)) {
			// We're done, something went wrong
			return false;
		}
		// Create the database connection
		QSqlDatabase qsdBackend = QSqlDatabase::addDatabase(Process::Configuration::getBackendType());
		// Set the database name/path
		qsdBackend.setDatabaseName(Process::Configuration::getBackendDatabase());
		// Check for mysql or postgresql
		if (qslQtDrivers.contains(Process::Configuration::getBackendType(), Qt::CaseInsensitive)) {
			// Set the database host name
			qsdBackend.setHostName(Process::Configuration::getBackendHost().toString());
			// Set the database port
			qsdBackend.setPort(Process::Configuration::getBackendPort());
			// Set the database username
			qsdBackend.setUserName(Process::Configuration::getBackendUsername());
			// Set the database password
			qsdBackend.setPassword(Process::Configuration::getBackendPassword());
		} else {
			// Check for a username
			if (!Process::Configuration::getBackendUsername().isNull()) {
				// Set the database username
				qsdBackend.setUserName(Process::Configuration::getBackendUsername());
			}
			// Check for a password
			if (!Process::Configuration::getBackendPassword().isNull()) {
				// Set the database password
				qsdBackend.setPassword(Process::Configuration::getBackendPassword());
			}
		}
		// Try to open the backend connection
		if (!qsdBackend.isOpen() && !qsdBackend.open()) {
			// Set the error
			strError = QString("Backend Connection failed [%1]").arg(qsdBackend.lastError().text());
			// We're done, something went wrong with the connection
			return false;
		}
		// Send the message
		Process::Log::notice(QString("Backend Connection Established (%1)").arg(Process::Configuration::getBackendType(true)));
		// We're done, the backend is good to go
		return true;
	}

	bool Bootstrap::setupService(QString &strError)
	{
		// Define our socket type list
		QStringList qslSocketTypes = QStringList() << "tcp" << "web" << "fcgi";
		// Make sure we have a socket type
		if (!this->mInput->isSet("socket-type")) {
			// Set the error
			strError = "No socket type defined.  Valid types are tcp, web and fcgi.";
			// We're done, no socket type defined
			return false;
		}
		// Make sure the socket type is valid
		if (!qslSocketTypes.contains(this->mInput->value("socket-type").trimmed(), Qt::CaseInsensitive)) {
			// Set the error
			strError = QString("Socket type [%1] is not valid.  Valid types are tcp, web and fcgi.").arg(this->mInput->value("socket-type").trimmed());
			// We're done, invalid socket type
			return false;
		} else {
			// Set the socket type into the configuration
			Process::Configuration::setSocketType(this->mInput->value("socket-type").trimmed());
		}
		// Make sure we have a bind address
		if (!this->mInput->isSet("bind-address")) {
			// Set the error
			strError = "No bind address was defined.";
			// We're done, no bind address set
			return false;
		}
		// Make sure we have a bind port
		if (!this->mInput->isSet("bind-port")) {
			// Set the error
			strError = "No bind port was defined.";
			// We're done, no bind port set
			return false;
		}
		// Set the bind address into the configuration
		Process::Configuration::setBindAddress(this->mInput->value("bind-address").trimmed());
		// Set the bind port into the configuration
		Process::Configuration::setBindPort(this->mInput->value("bind-port").trimmed().toInt());
		// Check for a TCP socket
		if (Process::Configuration::getSocketType().toLower() == "tcp") {
			// We're done, setup the TCP socket
			return this->setupSocketTCP(strError);
		}
		// Check for a Web Socket
		if (Process::Configuration::getSocketType().toLower() == "web") {
			// We're done, setup the Web Socket
			return this->setupSocketWeb(strError);
		}
		// Check for a FastCGI socket
		if (Process::Configuration::getSocketType().toLower() == "fcgi") {
			// We're done, setup the FastCGI socket
			return this->setupSocketFastCGI(strError);
		}
		// Set the error
		strError = "No provider available.";
		// We're done, no provider available
		return false;
	}

	/////////////////////////////////////////////////////////////////////////////////////
	/// Public Methods /////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	bool Bootstrap::go()
	{
		// Create our error placeholder
		QString strError;
		// Process the CLI
		this->mInput->process(this->mApplication);
		// Set the log file
		Process::Configuration::setLogFile(this->mInput->value("log-file"));
		Process::Log::setDestination(Process::Configuration::getLogFile());
		// Setup the backend database
		if (!this->setupBackend(strError)) {
			// Output the error
			Process::Log::fatal(strError);
			// We're done, something went wrong
			return false;
		} else {
			// Send the message
			Process::Log::notice("Backend Initialized");
		}
		// Setup the service
		if (!this->setupService(strError)) {
			// Output the error
			Process::Log::fatal(strError);
			// We're done, something went wrong
			return false;
		} else {
			// Send the message
			Process::Log::notice("Service Started");
		}
		// We're done, the service is good to go
		return true;
	}

	/////////////////////////////////////////////////////////////////////////////////////
	/// Getters ////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	QCoreApplication &Bootstrap::getApplication()
	{
		// Return the application from the instance
		return this->mApplication;
	}

	Process::Interface* Bootstrap::getInput()
	{
		// Return the CLI from the instance
		return this->mInput;
	}

	Transport::Abstract::Server* Bootstrap::getListener()
	{
		// Return the listener from the instance
		return this->mListener;
	}

	/////////////////////////////////////////////////////////////////////////////////////
	/// Public Slots ///////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	void Bootstrap::closing()
	{
		// Send the message
		Process::Log::notice("Service Shutting Down");
	}

/////////////////////////////////////////////////////////////////////////////////////////
} /// End SqlPi Namespace //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
