/////////////////////////////////////////////////////////////////////////////////////////
/// Headers ////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#include "Interface.hpp"

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
		/// Constructor ////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		Interface::Interface() : QCommandLineParser()
		{
			// Add the help option
			this->addHelpOption();
			// Add the version option
			this->addVersionOption();
			// Add the backend database name/path option
			this->addOption(this->optionBackendDatabase());
			// Add the backend database host option
			this->addOption(this->optionBackendHost());
			// Add the backend database password option
			this->addOption(this->optionBackendPassword());
			// Add the backend database port option
			this->addOption(this->optionBackendPort());
			// Add the backend database table prefix option
			this->addOption(this->optionBackendPrefix());
			// Add the backend database engine option
			this->addOption(this->optionBackendType());
			// Add the backend database username option
			this->addOption(this->optionBackendUsername());
			// Add the listening address option
			this->addOption(this->optionBindAddress());
			// Add the listening port option
			this->addOption(this->optionBindPort());
			// Add the log file option
			this->addOption(this->optionLogFile());
			// Add the socket type option
			this->addOption(this->optionSocketType());
		}

		/////////////////////////////////////////////////////////////////////////////////
		/// Private Methods ////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		QCommandLineOption Interface::optionBackendDatabase()
		{
			// Create the command line option
			QCommandLineOption cloCommand("backend-db");
			// Set the value name of the option
			cloCommand.setValueName("database");
			// We're done, return the new option
			return cloCommand;
		}

		QCommandLineOption Interface::optionBackendHost()
		{
			// Create the command line option
			QCommandLineOption cloCommand("backend-host");
			// Set the value name of the option
			cloCommand.setValueName("host");
			// Set the default value
			cloCommand.setDefaultValue("localhost");
			// We're done, return the new option
			return cloCommand;
		}

		QCommandLineOption Interface::optionBackendPassword()
		{
			// Create the command line option
			QCommandLineOption cloCommand("backend-password");
			// Set the value name of the option
			cloCommand.setValueName("password");
			// Set the default value
			cloCommand.setDefaultValue(QString::null);
			// We're done, return the new option
			return cloCommand;
		}

		QCommandLineOption Interface::optionBackendPort()
		{
			// Create the command line option
			QCommandLineOption cloCommand("backend-port");
			// Set the value name of the option
			cloCommand.setValueName("1234");
			// Set the default value
			cloCommand.setDefaultValue("0");
			// We're done, return the new option
			return cloCommand;
		}

		QCommandLineOption Interface::optionBackendPrefix()
		{
			// Create the command line option
			QCommandLineOption cloCommand("backend-prefix");
			// Set the value name of the option
			cloCommand.setValueName("tableprefix_");
			// Set the default value
			cloCommand.setDefaultValue(QString::null);
			// We're done, return the new option
			return cloCommand;
		}

		QCommandLineOption Interface::optionBackendType()
		{
			// Create the command line option
			QCommandLineOption cloCommand("backend-type");
			// Set the value name of the option
			cloCommand.setValueName("mysql|pgsql|sqlite");
			// We're done, return the new option
			return cloCommand;
		}

		QCommandLineOption Interface::optionBackendUsername()
		{
			// Create the command line option
			QCommandLineOption cloCommand("backend-username");
			// Set the value name of the option
			cloCommand.setValueName("username");
			// Set the default value
			cloCommand.setDefaultValue(QString::null);
			// We're done, return the new option
			return cloCommand;
		}

		QCommandLineOption Interface::optionBindAddress()
		{
			// Create the command line option
			QCommandLineOption cloCommand("bind-address");
			// Set the value name of the option
			cloCommand.setValueName("localhost|127.0.0.1|::1|any|any4|any6");
			// Set the default value
			cloCommand.setDefaultValue("any");
			// We're done, return the new option
			return cloCommand;
		}

		QCommandLineOption Interface::optionBindPort()
		{
			// Create the command line option
			QCommandLineOption cloCommand("bind-port");
			// Set the value name of the option
			cloCommand.setValueName("1234");
			// Set the default value
			cloCommand.setDefaultValue("1597");
			// We're done, return the new option
			return cloCommand;
		}

		QCommandLineOption Interface::optionLogFile()
		{
			// Create the command line option
			QCommandLineOption cloCommand("log-file");
			// Set the value name of the option
			cloCommand.setValueName("stdout|file_path");
			// Set the default value
			cloCommand.setDefaultValue("stdout");
			// We're done, return the new option
			return cloCommand;
		}

		QCommandLineOption Interface::optionSocketType()
		{
			// Create the command line option
			QCommandLineOption cloCommand("socket-type");
			// Set the value name of the option
			cloCommand.setValueName("tcp|web|fcgi");
			// Set the default value
			cloCommand.setDefaultValue("tcp");
			// We're done, return the new option
			return cloCommand;
		}

	/////////////////////////////////////////////////////////////////////////////////////
	} /// End SqlPi::Process Namespace /////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} /// End SqlPi Namespace //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
