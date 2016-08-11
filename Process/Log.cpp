/////////////////////////////////////////////////////////////////////////////////////////
/// Headers ////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#include "Log.hpp"

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
		/// Protected Static Properties ////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		QString Log::mDestination = "stdout";

		/////////////////////////////////////////////////////////////////////////////////
		/// Public Static Methods //////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		void Log::addEntry(QString strLevel, QString strMessage)
		{
			// Create the message template
			QString strOutputMessage = QString("[SqlPi][%1][%2]\t%3").arg(strLevel, QDateTime(QDate::currentDate()).toString(Qt::RFC2822Date), strMessage.trimmed());
			// Check for stdout as the output
			if ((mDestination.toLower() != "stdout") && mOutput.isOpen() && mOutput.isWritable()) {
				// Log the message
				if (mOutput.write(strOutputMessage.toLatin1()) <= 0) {
					// Set the error
					std::cerr << "[SqlPi][Process][Log]:  " << mOutput.errorString().toStdString() << std::endl;
				}
			} else {
				// Log the message
				std::cerr << strOutputMessage.toStdString() << std::endl;
			}
		}

		void Log::debug(QString strMessage)
		{
			// Log the entry
			return addEntry("Debug", strMessage);
		}

		void Log::error(QString strMessage)
		{
			// Log the entry
			return addEntry("Error", strMessage);
		}

		void Log::fatal(QString strMessage)
		{
			// Log the entry
			return addEntry("Fatal", strMessage);
		}

		void Log::notice(QString strMessage)
		{
			// Log the entry
			addEntry("Notice", strMessage);
		}

		void Log::warning(QString strMessage)
		{
			// Log the entry
			addEntry("Warning", strMessage);
		}

		/////////////////////////////////////////////////////////////////////////////////
		/// Static Getters /////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		QString Log::getDestination()
		{
			// Return the destination from the instance
			return mDestination;
		}

		QFile &Log::getOutput()
		{
			// Return the output from the instance
			return mOutput;
		}

		/////////////////////////////////////////////////////////////////////////////////
		/// Static Setters /////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		void Log::setDestination(QString strDestination)
		{
			// Check the destination
			if (strDestination.trimmed().toLower() != "stdout") {
				// Create the file info object
				QFileInfo qfiDestination(strDestination.trimmed());
				// Make sure the file exists
				if (!qfiDestination.exists()) {
					// Set the error message
					std::cerr <<  QString("File [%1] does not exist.").arg(strDestination).toStdString() << std::endl;
					// We're done, the log file doesn't exist
					return;
				}
				// Make sure the file is writable
				if (!qfiDestination.isWritable()) {
					// Set the error message
					std::cerr << QString("File [%1] is not writable.").arg(strDestination).toStdString() << std::endl;
					// We're done, cannot write to log file
					return;
				}
				// Set the destination into the instance
				mDestination = strDestination;
				// Create the file device
				setOutput(QFile(qfiDestination.fileName()));
			} else {
				// Set the destination
				mDestination = "stdout";
			}
		}

		void Log::setOutput(QFile fleOutput)
		{
			// Make sure the file is open or can be opened
			if (!fleOutput.isOpen() && !fleOutput.open(QIODevice::WriteOnly|QIODevice::Append)) {
				// Set the error message
				std::cerr << QString("File [%s] could not be opened for writing.").arg(fleOutput.fileName()).toStdString() << std::endl;
				// We're done
				return;
			}
			// Set the output device into the instance
			mOutput(fleOutput);
		}

	/////////////////////////////////////////////////////////////////////////////////////
	} /// End SqlPi::Process Namespace /////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} /// End SqlPi Namespace //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
