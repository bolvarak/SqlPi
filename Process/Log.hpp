/////////////////////////////////////////////////////////////////////////////////////////
/// Definitions ////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#ifndef SQLPI_PROCESS_LOG_HPP
#define SQLPI_PROCESS_LOG_HPP

/////////////////////////////////////////////////////////////////////////////////////////
/// Headers ////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#include <QDateTime>
#include <QFile>
#include <QFileInfo>
#include <QObject>
#include <QString>
#include <iostream>

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
		/// SqlPi::Process::Log Class Definition ///////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		class Log
		{
			/////////////////////////////////////////////////////////////////////////////
			/// Protected Methods & Properties /////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			protected:

				/////////////////////////////////////////////////////////////////////////
				/// Static Properties //////////////////////////////////////////////////
				///////////////////////////////////////////////////////////////////////

				/**
				 * @paragraph This property contains the file path for the log or stdout
				 * @brief SqlPi::Process::Log::mDestination
				 * @var QString
				 */
				static QString mDestination;

				/////////////////////////////////////////////////////////////////////////
				/// Static Methods /////////////////////////////////////////////////////
				///////////////////////////////////////////////////////////////////////

				/**
				 * @paragraph This method writes a log entry to a log file
				 * @brief SqlPi::Process::Log::writeToFile()
				 * @param QString strMessage
				 * @return void
				 */
				static void writeToFile(QString strMessage);

				/**
				 * @paragraph This method writes a log entry to standard out
				 * @brief SqlPi::Process::Log::writeToStd()
				 * @param QString strMessage
				 * @return void
				 */
				static void writeToStd(QString strMessage);

			/////////////////////////////////////////////////////////////////////////////
			/// Public Methods & Properties ////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			public:

				/////////////////////////////////////////////////////////////////////////
				/// Static Methods /////////////////////////////////////////////////////
				///////////////////////////////////////////////////////////////////////

				/**
				 * @paragraph This method adds an entry to the log
				 * @brief SqlPi::Process::Log::addEntry()
				 * @param QString strLevel
				 * @param QString strMessage
				 */
				static void addEntry(QString strLevel, QString strMessage);

				/**
				 * @paragraph This method is a helper method for logging Debug entries
				 * @brief SqlPi::Process::Log::debug()
				 * @param QString strMessage
				 * @return void
				 */
				static void debug(QString strMessage);

				/**
				 * @paragraph This method is a helper method for logging Error entries
				 * @brief SqlPi::Process::Log::error()
				 * @param QString strMessage
				 * @return void
				 */
				static void error(QString strMessage);

				/**
				 * @paragraph This method is a helper method for logging Fatal entries
				 * @brief SqlPi::Process::Log::fatal()
				 * @param QString strMessage
				 * @return void
				 */
				static void fatal(QString strMessage);

				/**
				 * @paragraph This method is a helper method for logging Notification entries
				 * @brief SqlPi::Process::Log::notice()
				 * @param QString strMessage
				 * @return void
				 */
				static void notice(QString strMessage);

				/**
				 * @paragraph This method is a helper method for logging Warning entries
				 * @brief SqlPi::Process::Log::warning()
				 * @param QString strMessage
				 * @return void
				 */
				static void warning(QString strMessage);

				/////////////////////////////////////////////////////////////////////////
				/// Getters ////////////////////////////////////////////////////////////
				///////////////////////////////////////////////////////////////////////

				/**
				 * @paragraph This method returns the output destination from the instance
				 * @brief SqlPi::Process::Log::getDestination()
				 * @return QString
				 */
				static QString getDestination();

				/////////////////////////////////////////////////////////////////////////
				/// Setters ////////////////////////////////////////////////////////////
				///////////////////////////////////////////////////////////////////////

				/**
				 * @paragraph This method sets the destination for the log output
				 * @brief SqlPi::Process::Log::setDestination()
				 * @param QString strDestination
				 * @return void
				 */
				static void setDestination(QString strDestination);

		/////////////////////////////////////////////////////////////////////////////////
		}; /// End SqlPi::Process::Log Class Definition ////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////
	} /// End SqlPi::Process Namespace /////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} /// End SqlPi Namespace //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif /// End Definitions /////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
