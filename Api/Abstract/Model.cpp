/////////////////////////////////////////////////////////////////////////////////////////
/// Headers ////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#include "Api/Abstract/Model.hpp"

/////////////////////////////////////////////////////////////////////////////////////////
/// SqlPi Namespace ////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

namespace SqlPi
{
	/////////////////////////////////////////////////////////////////////////////////////
	/// SqlPi::Api Namespace ///////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	namespace Api
	{
		/////////////////////////////////////////////////////////////////////////////////
		/// SqlPi::Api::Abstract Namespace /////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		namespace Abstract
		{
			/////////////////////////////////////////////////////////////////////////////
			/// Constructor ////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			Model::Model(QString strTable, QString strSchema, QString strPrimaryKey, QObject* qoParent) : QObject(qoParent)
			{
				// Set the table into the instance
				this->mTable = strTable;
				// Set the schema into the instance
				this->mSchema = strSchema;
				// Set the primary key column name into the instance
				this->mPrimaryKey = strPrimaryKey;
			}

			/////////////////////////////////////////////////////////////////////////////
			/// Protected Methods //////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			bool Model::connectionIsOpen()
			{
				// Reset the error on the instance
				this->mError = QString::null;
				// Check the connection
				if (this->mConnection.isOpen()) {       // Already Open
					// We're done, the connection is open
					return true;
				} else if (!this->mConnection.open()) { // Failed to Open
					// Set the error into the instance
					this->mError = this->mConnection.lastError().text();
					// We're done, the connection cannot be opened
					return false;
				} else {                                // Successfully Opened
					// We're done, the connection was successfully opened
					return true;
				}
			}

			QString Model::findColumn(QString strNeedle)
			{
				// Check for the column as is
				if (this->mColumns.contains(strNeedle)) {
					// We're done, return the column
					return strNeedle;
				}
				// Create the iterator
				QMapIterator<QString, QVariant> itrColumns(this->mColumns);
				// Iterate over the columns
				while (itrColumns.hasNext()) {
					// Localize the column
					QString strColumn = itrColumns.key();
					// Create our regular expression
					QRegExp rxSanitize("/(_|-|\\s)/", Qt::CaseInsensitive);
					// Check the column
					if (strColumn.replace(rxSanitize, "").toLower() == strNeedle.replace(rxSanitize, "").toLower()) {
						// We're done, return the column
						return strColumn;
					}
				}
				// We're done, the column could not be found
				return QString::null;
			}

			bool Model::primaryKeyExists()
			{
				// Check to see if the primary key column is set
				if (this->mPrimaryKey.isEmpty() || this->mPrimaryKey.isNull()) {
					// We're done, the primary key column is not set
					return false;
				}
				// Check to see if the column map contains the key
				if (!this->mColumns.contains(this->mPrimaryKey)) {
					// We're done, no primary key
					return false;
				}
				// Check the primary key value in the column map
				if (this->mColumns.value(this->mPrimaryKey).isNull()) {
					// We're done, the value in the column map is null
					return false;
				}
				// We're done, the primary key exists in the instance
				return true;
			}

			/////////////////////////////////////////////////////////////////////////////
			/// Public Methods /////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			bool Model::hasError()
			{
				// Check for an error
				if (this->mError.isNull() || this->mError.isEmpty()) {
					// We're done, no errors
					return false;
				} else {
					// We're done, an error has occurred
					return true;
				}
			}

			bool Model::isEmpty()
			{
				// Return the empty condition
				return (this->mIsEmpty || this->mColumns.isEmpty());
			}

			Model* Model::load(QVariant qvUniqueIdentifier, QString strColumn)
			{
				// Make sure the connection is open
				if (!this->connectionIsOpen()) {
					// We're done, unable to establish a connection
					return this;
				}
				// Reset the error on the instance
				this->mError = QString::null;
				// Make sure the connection is open
				if (!this->mConnection.isOpen() && !this->mConnection.open()) {
					// Set the error into the instance
					this->mError = this->mConnection.lastError().text();
					// We're done, return the instance
					return this;
				}
				// Try to load the table's meta data
				if (!this->tableDescription(false)) {
					// We're done, return the instance
					return this;
				}
				// Create the query container
				QSqlQuery qsqLoad(this->mConnection);
				// Prepare the SELECT statement
				qsqLoad.prepare(this->selectStatement(strColumn.isNull() ? this->mPrimaryKey : strColumn));
				// We only want to traverse forward in the results
				qsqLoad.setForwardOnly(true);
				// Bind the ID to the statement
				qsqLoad.addBindValue(qvUniqueIdentifier);
				// Try to execute the query
				if (!qsqLoad.exec()) {
					// Set the error into the instance
					this->mError = qsqLoad.lastError().text();
				} else if (qsqLoad.size() > 0) {
					// Clear the columns in the current instance
					this->mColumns.clear();
					// Seek the first record
					qsqLoad.seek(0);
					// Iterate over the columns
					foreach (QString strColumn, this->mTableDescription.keys()) {
						// Set the value into the instance
						this->mColumns.insert(strColumn, qsqLoad.value(strColumn));
					}
				} else {
					// Set the empty flag on the instance
					this->mIsEmpty = true;
				}
				// Close the query
				qsqLoad.finish();
				// We're done, return the instance
				return this;
			}

			Model* Model::purge()
			{
				// Make sure we have a primary key
				if (!this->primaryKeyExists()) {
					// We're done, nothing to do
					return this;
				}
				// Make sure the connection is open
				if (!this->connectionIsOpen()) {
					// We're done, cannot establish a connection
					return this;
				}
				// Reset the error on the instance
				this->mError = QString::null;
				// Create the query container
				QSqlQuery qsqPurge(this->mConnection);
				// Generate and prepare the DELETE statement
				qsqPurge.prepare(this->deleteStatement());
				// Bind the primary key to the query
				qsqPurge.addBindValue(this->mColumns.value(this->mPrimaryKey));
				// Try to execute the query
				if (!qsqPurge.exec()) {
					// Set the error into the instaance
					this->mError = qsqPurge.lastError().text();
				}
				// Close the query
				qsqPurge.finish();
				// We're done, return the instance
				return this;
			}

			Model* Model::recover()
			{
				// Make sure we have a primary key
				if (!this->primaryKeyExists()) {
					// We're done, nothing to do
					return this;
				}
				// Execute the save method, forcing an insert
				return this->save(true);
			}

			Model* Model::save(bool blnForceInsert)
			{
				// Make sure the connection is open
				if (!this->connectionIsOpen()) {
					// We're done, unable to establish a connection
					return this;
				}
				// Reset the error on the instance
				this->mError = QString::null;
				// Create the query container
				QSqlQuery qsqSave(this->mConnection);
				// Determine whether we have an INSERT or UPDATE
				if (!this->primaryKeyExists()) {
					// Generate and prepare the INSERT statement
					qsqSave.prepare(this->insertStatement(blnForceInsert));
				} else {
					// Generate and prepare the UPDATE statement
					qsqSave.prepare(this->updateStatement());
				}
				// Iterate over the values in the instance
				foreach (QString strColumn, this->mColumns.keys()) {
					// Bind the value
					qsqSave.bindValue(QString(":column_%1").arg(strColumn.toLower()), this->mColumns.value(strColumn));
				}
				// Try to execute the query
				if (!qsqSave.exec()) {
					// Set the error into the instance
					this->mError = qsqSave.lastError().text();
				}
				// Reload the model
				this->load(qsqSave.lastInsertId(), this->mPrimaryKey);
				// Close the query
				qsqSave.finish();
				// We're done, return the instance
				return this;
			}

			/////////////////////////////////////////////////////////////////////////////
			/// Converters /////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			QJsonDocument Model::toJson()
			{
				// We're done, return the JSON document
				return QJsonDocument(QJsonObject::fromVariantMap(this->mColumns));
			}

			/////////////////////////////////////////////////////////////////////////////
			/// Getters ////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			QVariant Model::get(QString strColumn)
			{
				// Return the primary getter
				return this->getColumn(strColumn);
			}

			QVariant Model::getColumn(QString strColumn)
			{
				// Find the real column name
				strColumn = this->findColumn(strColumn);
				// Check for an empty column
				if (strColumn.isNull()) {
					// We're done, return an empty variant
					return QVariant();
				} else {
					// We're done, return the column value
					return this->mColumns.value(strColumn);
				}
			}

			QVariantMap Model::getColumns()
			{
				// Return the columns from the instance
				return this->mColumns;
			}

			QSqlDatabase Model::getConnection()
			{
				// Return the database connection from the instance
				return this->mConnection;
			}

			QString Model::getError()
			{
				// Return the last error from the instance
				return this->mError;
			}

			QString Model::getPrimaryKey()
			{
				// Return the primary key from the instance
				return this->mPrimaryKey;
			}

			QString Model::getSchema()
			{
				// Return the schema from the instance
				return this->mSchema;
			}

			QString Model::getTable()
			{
				// Return the table from the instance
				return this->mTable;
			}

			QMap<QString, QVector<QString>> Model::getTableDescription()
			{
				// Return the table description from the instance
				return this->mTableDescription;
			}

			/////////////////////////////////////////////////////////////////////////////
			/// Setters ////////////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			Model* Model::set(QString strColumn, QVariant qvValue)
			{
				// Return the primary setter
				return this->setColumn(strColumn, qvValue);
			}

			Model* Model::setColumn(QString strColumn, QVariant qvValue)
			{
				// Find the real column name
				strColumn = this->findColumn(strColumn);
				// Check for an empty column
				if (!strColumn.isNull()) {
					// Set the new value into the instance
					this->mColumns.insert(strColumn, qvValue);
				}
				// We're done, return the instance
				return this;
			}

			Model* Model::setColumns(QVariantMap qvmColumns)
			{
				// Set the column map into the instance
				this->mColumns = qvmColumns;
				// We're done, return the instance
				return this;
			}

			Model* Model::setConnection(QSqlDatabase qsdConnection)
			{
				// Set the database connection into the instance
				this->mConnection = qsdConnection;
				// We're done, return the instance
				return this;
			}

			Model* Model::setError(QString strLastError)
			{
				// Set the last error into the instance
				this->mError = strLastError;
				// We're done, return the instance
				return this;
			}

			Model* Model::setPrimaryKey(QString strColumn)
			{
				// Set the primary key into the instance
				this->mPrimaryKey = strColumn;
				// We're done, return the instance
				return this;
			}

			Model* Model::setSchema(QString strName)
			{
				// Set the schema into the instance
				this->mSchema = strName;
				// We're done, return the instance
				return this;
			}

			Model* Model::setTable(QString strName)
			{
				// Set the table into the instance
				this->mTable = strName;
				// We're done, return the instance
				return this;
			}

			Model* Model::setTableDescription(QMap<QString, QVector<QString>> mapDescription)
			{
				// Set the table description into the instance
				this->mTableDescription = mapDescription;
				// We're done, return the instance
				return this;
			}

		/////////////////////////////////////////////////////////////////////////////////
		} /// End SqlPi::Api::Abstract Namespace ///////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////
	} /// End SqlPi::Api Namespace /////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} /// End SqlPi Namespace //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
