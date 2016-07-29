/////////////////////////////////////////////////////////////////////////////////////////
/// Headers ////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#include "Api/Abstract/SQLite.hpp"

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
			/////////////////////////////////////////////////////////////////////////
			/// Constructor ////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////

			SQLite::SQLite(QSqlDatabase qsdConnection, QString strTable, QString strSchema, QString strPrimaryKey) : Model(strTable, strSchema, strPrimaryKey)
			{
				// Set the connection into the instance
				this->mConnection = qsdConnection;
			}

			/////////////////////////////////////////////////////////////////////////
			/// Protected Abstract Methods /////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////

			QString SQLite::deleteStatement()
			{
				// Return the DELETE statement
				return QString("DELETE FROM \"%1\".\"%2\" WHERE \"%3\" = ?;").arg(this->mSchema, this->mTable, this->mPrimaryKey);
			}

			QString SQLite::insertStatement(bool blnIncludePrimaryKey)
			{
				// Create our string lists
				QStringList qslColumns;
				QStringList qslPlaceholders;
				// Iterate over the columns
				foreach (QString strColumn, this->mColumns.keys()) {
					// Check the force insert flag
					if (!blnIncludePrimaryKey && (strColumn == this->mPrimaryKey)) {
						// Next iteration please
						continue;
					} else {
						// Add the column to the list
						qslColumns.append(QString("\"%1\"").arg(strColumn));
						// Add the placeholder to the list
						qslPlaceholders.append(QString(":column_%1").arg(strColumn.toLower()));
					}
				}
				// Return the INSERT statement
				return QString("INSERT INTO \"%1\".\"%2\" (%3) VALUES (%4);").arg(this->mSchema, this->mTable, qslColumns.join(", "), qslPlaceholders.join(", "));
			}

			QString SQLite::selectStatement(QString strColumn)
			{
				// Return the SELECT statement
				return QString("SELECT * FROM \"%1\".\"%2\" WHERE \"%3\" = ?;").arg(this->mSchema, this->mTable, strColumn);
			}

			bool SQLite::tableDescription(bool blnCloseConnectionWhenDone)
			{
				// Reset the error on the instance
				this->mError = QString::null;
				// Create the query container
				QSqlQuery qsqTable(this->mConnection);
				// Prepare the statement
				qsqTable.prepare("PRAGMA table_info(?)");
				// Bind the table name
				qsqTable.addBindValue(this->mTable);
				// Try to execute the query
				if (!qsqTable.exec()) {
					// Set the error into the instance
					this->mError = qsqTable.lastError().text();
					// Close the query
					qsqTable.finish();
					// We're done, unable to load table info
					return false;
				}
				// Clear the table description
				this->mTableDescription.clear();
				// Iterate over the query results
				while (qsqTable.next()) {
					// Create the column vector
					QVector<QString> vecColumn;
					// Add the data type
					vecColumn.append(qsqTable.value("type").toString());
					// Add the maximum length
					vecColumn.append("255");
					// Check to see if this column is the primary key
					if (qsqTable.value("pk").toInt() == 1) {
						// Set the primary key
						this->mPrimaryKey = qsqTable.value("name").toString();
					}
					// Set the column into the description
					this->mTableDescription.insert(qsqTable.value("name").toString(), vecColumn);
				}
				// Close the query
				qsqTable.finish();
				// Check the close flag
				if (blnCloseConnectionWhenDone) {
					// Close the connection
					this->mConnection.close();
				}
				// We're done
				return false;
			}

			QString SQLite::updateStatement()
			{
				// Create our string list
				QStringList qslColumns;
				// Iterate over the columns
				foreach (QString strColumn, this->mColumns.keys()) {
					// Make sure this isn't the primary key
					if (strColumn != this->mPrimaryKey) {
						// Add the column to the statement
						qslColumns.append(QString("\%1\" = :column_%2").arg(strColumn, strColumn.toLower()));
					}
				}
				// We're done, return the UPDATE statement
				return QString("UPDATE \"%1\".\"%2\" SET %3 WHERE \"%4\" = :column_%5;").arg(this->mSchema, this->mTable, qslColumns.join(", "), this->mPrimaryKey, this->mPrimaryKey.toLower());
			}

		/////////////////////////////////////////////////////////////////////////////////
		} /// End SqlPi::Api::Abstract Namespace ///////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////
	} /// End SqlPi::Api Namesapce /////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} /// End SqlPi Namespace //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
