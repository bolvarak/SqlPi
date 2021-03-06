/////////////////////////////////////////////////////////////////////////////////////////
/// Definitions ////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#ifndef SQLPI_API_MODEL_AUTHORIZATION_HPP
#define SQLPI_API_MODEL_AUTHORIZATION_HPP

/////////////////////////////////////////////////////////////////////////////////////////
/// Headers ////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#include <QObject>
#include <QString>
#include <QVariant>
#include "../Abstract/SQLite.hpp"
#include "../../Process/Configuration.hpp"

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
		/// SqlPi::Api::Model Namespace ////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		namespace Model
		{
			/////////////////////////////////////////////////////////////////////////////
			/// SqlPi::Api::Model::Authorization Class Definition //////////////////////
			///////////////////////////////////////////////////////////////////////////

			class Authorization : public Api::Abstract::SQLite
			{
					/**
					 * Qt Recognition
					 */
					Q_OBJECT

				/////////////////////////////////////////////////////////////////////////
				/// Public Methods & Properties ////////////////////////////////////////
				///////////////////////////////////////////////////////////////////////

				public:

					/////////////////////////////////////////////////////////////////////
					/// Constructor ////////////////////////////////////////////////////
					///////////////////////////////////////////////////////////////////

					/**
					 * @paragraph This method instantiates a new Authorization Model
					 * @brief SqlPi::Api::Model::Authorization::Authorization()
					 * @param QVariant qvUniqueIdentifier [QVariant()]
					 * @param QString strColumn [QString::null]
					 */
					explicit Authorization(QVariant qvUniqueIdentifier = QVariant(), QString strColumn = QString::null);

			/////////////////////////////////////////////////////////////////////////////
			}; /// End SqlPi::Api::Model::Authorization Class Definition ///////////////
			///////////////////////////////////////////////////////////////////////////

		/////////////////////////////////////////////////////////////////////////////////
		} /// End SqlPi::Api::Model Namespace //////////////////////////////////////////
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
