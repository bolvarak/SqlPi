/////////////////////////////////////////////////////////////////////////////////////////
/// Definitions ////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#ifndef SQLPI_API_ABSTRACT_MODEL_HPP
#define SQLPI_API_ABSTRACT_MODEL_HPP

/////////////////////////////////////////////////////////////////////////////////////////
/// Headers ////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QMap>
#include <QMapIterator>
#include <QObject>
#include <QRegExp>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlResult>
#include <QString>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>
#include <QVector>

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
			/// SqlPi::Api::Abstract::Model Class Definitions //////////////////////////
			///////////////////////////////////////////////////////////////////////////

			class Model : public QObject
			{
					/**
					 * Qt Recognition
					 */
					Q_OBJECT

				/////////////////////////////////////////////////////////////////////////
				/// Protected Methods & Properties /////////////////////////////////////
				///////////////////////////////////////////////////////////////////////

				protected:

					/////////////////////////////////////////////////////////////////////
					/// Properties /////////////////////////////////////////////////////
					///////////////////////////////////////////////////////////////////

					/**
					 * @paragraph This property contains the columns from the database table
					 * @brief SqlPi::Api::Abstract::Model::mColumns
					 * @var QVariantMap
					 */
					QVariantMap mColumns;

					/**
					 * @paragraph This property contains the database connection
					 * @brief SqlPi::Api::Abstract::Model::mConnection
					 * @var QSqlDatabase
					 */
					QSqlDatabase mConnection;

					/**
					 * @paragraph This property contains the last error that occurred
					 * @brief SqlPi::Api::Abstract::Model::mError
					 * @var QString
					 */
					QString mError;

					/**
					 * @paragraph This property contains a flag denoting the model's empty state
					 * @brief SqlPi::Api::Abstract::mIsEmpty
					 * @var bool
					 */
					bool mIsEmpty;

					/**
					 * @paragraph This property contains the primary key column for the table
					 * @brief SqlPi::Api::Abstract::Model::mPrimaryKey
					 * @var QString
					 */
					QString mPrimaryKey;

					/**
					 * @paragraph This property contains the PostgreSQL/SQLite schema name
					 * @brief SqlPi::Api::Abstract::Model::mSchema
					 * @var QString
					 */
					QString mSchema;

					/**
					 * @paragraph This property contains the name of the table to query
					 * @brief SqlPi::Api::Abstract::Model::mTable
					 * @var QString
					 */
					QString mTable;

					/**
					 * @paragraph This property contains the description of the table
					 * @brief SqlPi::Api::Abstract::Model::mTableDescription
					 * @var QMap<Qstring, QVector<QString>>
					 */
					QMap<QString, QVector<QString>> mTableDescription;

					/////////////////////////////////////////////////////////////////////
					/// Abstract Methods ///////////////////////////////////////////////
					///////////////////////////////////////////////////////////////////

					/**
					 * @abstract
					 * @paragraph This method generates a DELETE SQL statement for deleting the model
					 * @brief SqlPi::Api::Abstract::Model::deleteStatement()
					 * @return QString
					 */
					virtual QString deleteStatement() = 0;

					/**
					 * @abstract
					 * @paragraph This method generates an INSERT SQL statement for saving the model
					 * @brief SqlPi::Api::Abstract::Model::insertStatement()
					 * @param bool blnIncludePrimaryKey [false]
					 * @return QString
					 */
					virtual QString insertStatement(bool blnIncludePrimaryKey = false) = 0;

					/**
					 * @paragraph This method generates a SELECT SQL statement for loading the model
					 * @brief SqlPi::Api::Abstract::Model::selectStatement()
					 * @param QString strColumn
					 * @return QString
					 */
					virtual QString selectStatement(QString strColumn) = 0;

					/**
					 * @abstract
					 * @paragraph This method generates the table description for the specific engine
					 * @brief SqlPi::Api::Abstract::Model::tableDescription()
					 * @param bool blnCloseConnectionWhenDone [false]
					 * @return bool
					 */
					virtual bool tableDescription(bool blnCloseConnectionWhenDone = false) = 0;

					/**
					 * @abstract
					 * @paragraph This method generates an UPDATE SQL statement for saving the model
					 * @brief SqlPi::Api::Abstract::Model::updateStatement()
					 * @return QString
					 */
					virtual QString updateStatement() = 0;

					/////////////////////////////////////////////////////////////////////
					/// Methods ////////////////////////////////////////////////////////
					///////////////////////////////////////////////////////////////////

					/**
					 * @paragraph This method determines whether or not the database connection is open or can be opened
					 * @brief SqlPi::Api::Abstract::Model::connectionIsOpen()
					 * @return bool
					 */
					virtual bool connectionIsOpen();

					/**
					 * @paragraph This method case-insensitively searches for a column
					 * @brief SqlPi::Api::Abstract::Model::findColumn()
					 * @param QString strNeedle
					 * @return QString
					 */
					virtual QString findColumn(QString strNeedle);

					/**
					 * @paragraph This method determines whether or not the primary key exists in the instance
					 * @brief SqlPi::Api::Abstract::Model::primaryKeyExists()
					 * @return bool
					 */
					virtual bool primaryKeyExists();

				/////////////////////////////////////////////////////////////////////////
				/// Public Methods & Properties ////////////////////////////////////////
				///////////////////////////////////////////////////////////////////////

				public:

					/////////////////////////////////////////////////////////////////////
					/// Constructor ////////////////////////////////////////////////////
					///////////////////////////////////////////////////////////////////

					/**
					 * @paragraph This method instantiates a new model object
					 * @brief SqlPi::Api::Abstract::Model::Model()
					 * @param QString strTable
					 * @param QString strSchema [QString::null]
					 * @param QString strPrimaryKey [QString::null]
					 * @param QObject* qoParent*
					 */
					Model(QString strTable, QString strSchema = QString::null, QString strPrimaryKey = QString::null, QObject* qoParent = 0);

					/////////////////////////////////////////////////////////////////////
					/// Methods ////////////////////////////////////////////////////////
					///////////////////////////////////////////////////////////////////

					/**
					 * @paragraph This method returns the error state of the model
					 * @brief SqlPi::Api::Abstract::Model::hasError()
					 * @return bool
					 */
					bool hasError();

					/**
					 * @paragraph This method returns the empty state of the model
					 * @brief SqlPi::Api::Abstract::Model::isEmpty()
					 * @return bool
					 */
					virtual bool isEmpty();

					/**
					 * @paragraph This method loads a record from the database into the model
					 * @brief SqlPi::Api::Abstract::Model::load()
					 * @param QVariant qvUniqueIdentifier
					 * @param QString strColumn [QString::null]
					 * @return SqlPi::Api::Abstract::Model* this
					 */
					virtual Model* load(QVariant qvUniqueIdentifier, QString strColumn = QString::null);

					/**
					 * @paragraph This method deletes/purges the record from the database
					 * @brief SqlPi::Api::Abstract::Model::purge()
					 * @param QVariant qvUniqueIdentifier
					 * @return SqlPi::Api::Abstract::Model* this
					 */
					virtual Model* purge();

					/**
					 * @paragraph This method recovers the purged record in the database
					 * @brief SqlPi::Api::Abstract::Model::recover()
					 * @return SqlPi::Api::Abstract::Model* this
					 */
					virtual Model* recover();

					/**
					 * @paragraph This method saves/updates the record in the database
					 * @brief SqlPi::Api::Abstract::Model::save()
					 * @param bool blnForceInsert [false]
					 * @return SqlPi::Api::Abstract::Model* this
					 */
					virtual Model* save(bool blnForceInsert = false);

					/////////////////////////////////////////////////////////////////////
					/// Converters /////////////////////////////////////////////////////
					///////////////////////////////////////////////////////////////////

					/**
					 * @paragraph This method converts the model to a JSON object
					 * @brief SqlPi::Api::Abstract::Model::toJson()
					 * @return QJsonDocument
					 */
					virtual QJsonDocument toJson();

					/////////////////////////////////////////////////////////////////////
					/// Getters ////////////////////////////////////////////////////////
					///////////////////////////////////////////////////////////////////

					/**
					 * @paragraph This method is an alias for SqlPi::Api::Abstract::Model::getColumn()
					 * @brief SqlPi::Api::Abstract::Model::get()
					 * @param QString strColumn
					 * @return QVariant
					 */
					QVariant get(QString strColumn);

					/**
					 * @paragraph This method returns a column value from the instance
					 * @brief SqlPi::Api::Abstract::Model::getColumn()
					 * @param QString strColumn
					 * @return QVariant
					 */
					QVariant getColumn(QString strColumn);

					/**
					 * @paragraph This method returns the column map from the instance
					 * @brief SqlPi::Api::Abstract::Model::getColumns()
					 * @return QVariantMap
					 */
					QVariantMap getColumns();

					/**
					 * @paragraph This method returns the database connection from the instance
					 * @brief SqlPi::Api::Abstract::Model::getConnection()
					 * @return QSqlDatabase
					 */
					QSqlDatabase getConnection();

					/**
					 * @paragraph This method returns the last error from the instance
					 * @brief SqlPi::Api::Abstract::Model::getError()
					 * @return QString
					 */
					QString getError();

					/**
					 * @paragraph This method returns the primary key from the instance
					 * @brief SqlPi::Api::Abstract::Model::getPrimaryKey()
					 * @return QString
					 */
					QString getPrimaryKey();

					/**
					 * @paragraph This method returns the schema name from the instance
					 * @brief SqlPi::Api::Abstract::Model::getSchema()
					 * @return QString
					 */
					QString getSchema();

					/**
					 * @paragraph This method returns the table name from the instance
					 * @brief SqlPi::Api::Abstract::Model::getTable()
					 * @return QString
					 */
					QString getTable();

					/**
					 * @paragraph This method returns the table description from the instance
					 * @brief SqlPi::Api::Abstract::Model::getTableDescription()
					 * @return QMap<QString, QVector<QString>>
					 */
					QMap<QString, QVector<QString>> getTableDescription();

					/////////////////////////////////////////////////////////////////////
					/// Setters ////////////////////////////////////////////////////////
					///////////////////////////////////////////////////////////////////

					/**
					 * @paragraph This method is an alias for SqlPi::Api::Abstract::Model::setColumn()
					 * @brief SqlPi::Api::Abstract::Model::set()
					 * @param QString strColumn
					 * @param QVariant qvValue
					 * @return SqlPi::Api::Abstract::Model* this
					 */
					Model* set(QString strColumn, QVariant qvValue);

					/**
					 * @paragraph This method sets a column's value into the instance
					 * @brief SqlPi::Api::Abstract::Model::setColumn()
					 * @param QString strColumn
					 * @param QVariant qvValue
					 * @return SqlPi::Api::Abstract::Model* this
					 */
					Model* setColumn(QString strColumn, QVariant qvValue);

					/**
					 * @paragraph This method sets the column map into the instance
					 * @brief SqlPi::Api::Abstract::Model::setColumns()
					 * @param QVariantMap qvmColumns
					 * @return SqlPi::Api::Abstract::Model* this
					 */
					Model* setColumns(QVariantMap qvmColumns);

					/**
					 * @paragraph This method sets the database connection into the instance
					 * @brief SqlPi::Api::Abstract::Model::setConnection()
					 * @param QSqlDatabase qsdConnection
					 * @return SqlPi::Api::Abstract::Model* this
					 */
					Model* setConnection(QSqlDatabase qsdConnection);

					/**
					 * @paragraph This method sets the last error into the instance
					 * @brief SqlPi::Api::Abstract::Model::setError()
					 * @param QString strLastError
					 * @return SqlPi::Api::Abstract::Model* this
					 */
					Model* setError(QString strLastError);

					/**
					 * @paragraph This method sets the table's primary key into the instance
					 * @brief SqlPi::Api::Abstract::Model::setPrimaryKey()
					 * @param QString strColumn
					 * @return SqlPi::Api::Abstract::Model* this
					 */
					Model* setPrimaryKey(QString strColumn);

					/**
					 * @paragraph This method sets the schema name into the instance
					 * @brief SqlPi::Api::Abstract::Model::setSchema()
					 * @param QString strName
					 * @return SqlPi::Api::Abstract::Model* this
					 */
					Model* setSchema(QString strName);

					/**
					 * @paragraph This method sets the tabe name into the instance
					 * @brief SqlPi::Api::Abstract::Model::setTable()
					 * @param QString strName
					 * @return SqlPi::Api::Abstract::Model* this
					 */
					Model* setTable(QString strName);

					/**
					 * @paragraph This method sets the table description into the instance
					 * @brief SqlPi::Api::Abstract::Model::setTableDescription()
					 * @param QMap<QString, QVector<QString>> mapDescription
					 * @return SqlPi::Api::Abstract::Model* this
					 */
					Model* setTableDescription(QMap<QString, QVector<QString>> mapDescription);

			/////////////////////////////////////////////////////////////////////////////
			}; /// End SqlPi::Api::Abstract::Model Class Definition ////////////////////
			///////////////////////////////////////////////////////////////////////////

		/////////////////////////////////////////////////////////////////////////////////
		} /// End SqlPi::Api::Abstract Namespace ///////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////
	} /// End SqlPi::Api Namespace /////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} /// End SqlPi Namespace //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif /// End Definitions /////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
