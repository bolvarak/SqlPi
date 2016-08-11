/////////////////////////////////////////////////////////////////////////////////////////
/// Defintions /////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#ifndef SQLPI_BOOTSTRAP_HPP
#define SQLPI_BOOTSTRAP_HPP

/////////////////////////////////////////////////////////////////////////////////////////
/// Headers ////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QFile>
#include <QObject>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QSqlDatabase>
#include <QSqlError>
#include <iostream>
#include "Process/Configuration.hpp"
#include "Process/Interface.hpp"
#include "Transport/Tcp.hpp"

/////////////////////////////////////////////////////////////////////////////////////////
/// SqlPi Namespace ////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

namespace SqlPi
{
	/////////////////////////////////////////////////////////////////////////////////////
	/// SqlPi::Bootstrap Class Definition //////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	class Bootstrap : public QObject
	{
			/**
			 * Qt Recognition
			 */
			Q_OBJECT

		/////////////////////////////////////////////////////////////////////////////////
		/// Private Methods & Properties ///////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		private:

			/////////////////////////////////////////////////////////////////////////////
			/// Methods ////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			/**
			 * @paragraph This method sets up a MySQL backend connection
			 * @brief SqlPi::Bootstrap::setupBackendMySql()
			 * @param QString &strError
			 * @return bool
			 */
			bool setupBackendMySql(QString &strError);

			/**
			 * @paragraph This method sets up a PostgreSQL backend connection
			 * @brief SqlPi::Bootstrap::setupBackendPgSql()
			 * @param QString &strError
			 * @return bool
			 */
			bool setupBackendPgSql(QString &strError);

			/**
			 * @paragraph This method sets up a SQLite backend connection
			 * @brief SqlPi::Bootstrap::setupBackendSqLite()
			 * @param QString &strError
			 * @return bool
			 */
			bool setupBackendSqLite(QString &strError);

			/**
			 * @paragraph This method sets up a FastCGI socket for the service
			 * @brief SqlPi::Bootstrap::setupSocketFastCGI()
			 * @param QString &strError
			 * @return bool
			 */
			bool setupSocketFastCGI(QString &strError);

			/**
			 * @paragraph This method sets up a TCP socket for the service
			 * @brief SqlPi::Bootstrap::setupSocketTCP()
			 * @param QString &strError
			 * @return bool
			 */
			bool setupSocketTCP(QString &strError);

			/**
			 * @paragraph This method sets up a WebSocket for the service
			 * @brief SqlPi::Bootstrap::setupSocketWeb()
			 * @param QString &strError
			 * @return bool
			 */
			bool setupSocketWeb(QString &strError);

		/////////////////////////////////////////////////////////////////////////////////
		/// Protected Methods & Properties /////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		protected:

			/////////////////////////////////////////////////////////////////////////////
			/// Properties /////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			/**
			 * @paragraph This property contains our application
			 * @brief SqlPi::Bootstrap::mApplication
			 * @var QCoreApplication
			 */
			QCoreApplication mApplication;

			/**
			 * @paragraph This property contains our input from the CLI
			 * @brief SqlPi::Bootstrap::mInput
			 * @var SqlPi::Process::Interface*
			 */
			Process::Interface* mInput;

			/**
			 * @paragraph This property contains the socket listener for the service
			 * @brief SqlPi::mListener
			 * @var SqlPi::Transport::Abstract::Server*
			 */
			Transport::Abstract::Server* mListener;

			/////////////////////////////////////////////////////////////////////////////
			/// Methods ////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			/**
			 * @paragraph This method sets up the backend database for the service
			 * @brief SqlPi::Bootstrap::setupBackend()
			 * @param QString &strError
			 * @return bool
			 */
			bool setupBackend(QString &strError);

			/**
			 * @paragraph This method sets up the service's socket
			 * @brief SqlPi::Bootstrap::setupService()
			 * @param QString &strError
			 * @return bool
			 */
			bool setupService(QString &strError);

		/////////////////////////////////////////////////////////////////////////////////
		/// Public Methods & Properties ////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		public:

			/////////////////////////////////////////////////////////////////////////////
			/// Constructor ////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			/**
			 * @paragraph This method instantiates the Bootstrapper
			 * @brief SqlPi::Bootstrap::Bootstrap()
			 * @param int intArguments
			 * @param char* arrArguments[]
			 * @param QObject* qoParent [0]
			 */
			explicit Bootstrap(int intArguments, char* arrArguments[], QObject* qoParent = 0);

			/////////////////////////////////////////////////////////////////////////////
			/// Methods ////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			/**
			 * @paragraph This method prepares the API for requests
			 * @brief SqlPi::Bootstrap::go()
			 * @return bool
			 */
			bool go();

			/////////////////////////////////////////////////////////////////////////////
			/// Getters ////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			/**
			 * @paragraph This method returns the application from the instance
			 * @brief SqlPi::Bootstrap::getApplication()
			 * @return QCoreApplication&
			 */
			QCoreApplication &getApplication();

			/**
			 * @paragraph This method returns the input parser from the instance
			 * @brief SqlPi::Bootstrap::getInput()
			 * @return SqlPi::Process::Interface*
			 */
			Process::Interface* getInput();

			/**
			 * @paragraph This method returns the current listener from the instance
			 * @brief SqlPi::Bootstrap::getListener()
			 * @return SqlPi::Transport::Abstract::Server*
			 */
			Transport::Abstract::Server* getListener();

	/////////////////////////////////////////////////////////////////////////////////////
	}; /// End SqlPi::Bootstrap Class Definition ///////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} /// End SqlPi Namespace //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif /// End Definitions /////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
