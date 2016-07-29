///////////////////////////////////////////////////////////////////////////////
/// Headers //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#include "Backend.hpp"

///////////////////////////////////////////////////////////////////////////////
/// SqlPi Namespace //////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

namespace SqlPi
{
	///////////////////////////////////////////////////////////////////////////
	/// SqlPi::Api Namespace /////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	namespace Api
	{
		///////////////////////////////////////////////////////////////////////
		/// Constructor //////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////

		Backend::Backend(QObject* qoParent) : QObject(qoParent)
		{
			// Setup the backend connection as the default connection
			this->mConnection = QSqlDatabase::addDatabase("QSQLITE");
			// Set the database path
			this->mConnection.setDatabaseName(":/storage/local/backend.sqlite");
			// Set the database username
			this->mConnection.setUserName("sqlpi");
			// Set the database password
			this->mConnection.setPassword("BO481GbD8H9Q0zppNo0q905xmzRAQ6cx");
			// Open the connection to the database
			if (!this->mConnection.open()) {
				// Set the error into the instance
				this->mError = this->mConnection.lastError().text();
			}
		}

		///////////////////////////////////////////////////////////////////////
		/// Public Methods ///////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////

		QSqlQuery Backend::execute(QString strQuery, QVariantList qvlReplacements)
		{
			// Check an errors from the instance
			this->mError = QString::null;
			// Create the query
			QSqlQuery qsqExecution(this->mConnection);
			// Prepare the query
			qsqExecution.prepare(strQuery);
			// Iterate over the replacement values
			foreach (QVariant qvValue, qvlReplacements) {
				// Bind the value
				qsqExecution.addBindValue(qvValue);
			}
			// Execute the query
			if (!qsqExecution.exec()) {
				// Set the error
				this->mError = qsqExecution.lastError().text();
			}
			// We're done, return the sql query
			return qsqExecution;
		}

		bool Backend::hasError()
		{
			// Check the error
			if (this->mError.isNull() && this->mError.isEmpty()) {
				// We're done, no errors
				return false;
			} else {
				// We're done, we have errors
				return true;
			}
		}

		///////////////////////////////////////////////////////////////////////
		/// Getters //////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////

		QSqlDatabase Backend::getConnection()
		{
			// Return the current connection from the instance
			return this->mConnection;
		}

		QString Backend::getError()
		{
			// Return the last error from the instance
			return this->mError;
		}

		///////////////////////////////////////////////////////////////////////
		/// Setters //////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////

		Backend* Backend::setConnection(QSqlDatabase qsdConnection)
		{
			// Set the connection into the instance
			this->mConnection = qsdConnection;
			// We're done, return the instance
			return this;
		}

		Backend* Backend::setError(QString strLastError)
		{
			// Set the error into the instance
			this->mError = strLastError;
			// We're done, return the instance
			return this;
		}

	///////////////////////////////////////////////////////////////////////////
	} /// End SqlPi::Api Namespace ///////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} /// End SqlPi Namespace ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
