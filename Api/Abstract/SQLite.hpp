/////////////////////////////////////////////////////////////////////////////////////////
/// Definitions ////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#ifndef SQLPI_API_ABSTRACT_MODEL_SQLITE_HPP
#define SQLPI_API_ABSTRACT_MODEL_SQLITE_HPP

/////////////////////////////////////////////////////////////////////////////////////////
/// Headers ////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#include <QMap>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlResult>
#include <QString>
#include <QStringList>
#include <QVariant>
#include <QVariantList>
#include <QVariantMap>
#include <QVector>
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
			/// SqlPi::Api::Abstract::SQLite Class Definitions /////////////////////////
			///////////////////////////////////////////////////////////////////////////

			class SQLite : public Model
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
					/// Abstract Methods ///////////////////////////////////////////////
					///////////////////////////////////////////////////////////////////

					/**
					 * @abstract
					 * @paragraph This method generates a DELETE SQL statement for SQLite
					 * @brief SqlPi::Api::Abstract::SQLite::deleteStatement()
					 * @return QString
					 */
					virtual QString deleteStatement();

					/**
					 * @abstract
					 * @paragraph This method generates an INSERT SQL statement for SQLite
					 * @brief SqlPi::Api::Abstract::SQLite::insertStatement()
					 * @param bool blnIncludePrimaryKey [false]
					 * @return QString
					 */
					virtual QString insertStatement(bool blnIncludePrimaryKey = false);

					/**
					 * @abstract
					 * @paragraph This method generates a SELECT SQL statement for SQLite
					 * @brief SqlPi::Api::Abstract::SQLite::selectStatement()
					 * @param QString strColumn
					 * @return QString
					 */
					virtual QString selectStatement(QString strColumn);

					/**
					 * @abstract
					 * @paragraph This method generates a SQLite table's meta data and description
					 * @brief SqlPi::Api::Abstract::SQLite::tableDescription()
					 * @param bool blnCloseConnectionWhenDone [false]
					 * @return bool
					 */
					virtual bool tableDescription(bool blnCloseConnectionWhenDone = false);

					/**
					 * @abstract
					 * @paragraph This method generate an UPDATE SQL statement for SQLite
					 * @brief SqlPi::Api::Abstract::SQLite::updateStatement()
					 * @return QString
					 */
					virtual QString updateStatement();

				/////////////////////////////////////////////////////////////////////////
				/// Public Methods & Properties ////////////////////////////////////////
				///////////////////////////////////////////////////////////////////////

				public:

					/////////////////////////////////////////////////////////////////////
					/// Constructor ////////////////////////////////////////////////////
					///////////////////////////////////////////////////////////////////

					/**
					 * @paragraph This method instantiates a new SQLite model
					 * @brief SqlPi::Api::Abstract::SQLite::SQLite()
					 * @param QSqlDatabase qsdConnection
					 * @param QString strTable
					 * @param QString strSchema ["main"]
					 * @param QString strPrimaryKey [QString::null]
					 */
					SQLite(QSqlDatabase qsdConnection, QString strTable, QString strSchema = "main", QString strPrimaryKey = QString::null);

			/////////////////////////////////////////////////////////////////////////////
			}; /// End SqlPi::Api::Abstract::SQLite Class Definition ///////////////////
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
