///////////////////////////////////////////////////////////////////////////////
/// Headers //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#include "Client.hpp"

///////////////////////////////////////////////////////////////////////////////
/// SqlPi Namespace //////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

namespace SqlPi
{
	///////////////////////////////////////////////////////////////////////////
	/// SqlPi::Connection Namespace //////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	namespace Connection
	{
		///////////////////////////////////////////////////////////////////////
		/// Constructor //////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////

		Client::Client(QObject* qoParent) : QObject(qoParent)
		{
			// Define the maximum number of threads this service can spawn
			QThreadPool::globalInstance()->setMaxThreadCount(15);
		}

		///////////////////////////////////////////////////////////////////////
		/// Setters //////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////

		void Client::setSocket(QTcpSocket* tcpSocket)
		{
			// Instantiate our new socket
			this->mSocket = tcpSocket;
			// Connect the connected slot
			this->connect(this->mSocket, SIGNAL(connected()), this, SLOT(connected()));
			// Connect the disconnected slot
			this->connect(this->mSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));
			// Connect the ready state slot
			this->connect(this->mSocket, SIGNAL(readyRead()), this, SLOT(ready()));
			// Log the status
			Process::Log::notice("Incoming Client Connection");
		}

		///////////////////////////////////////////////////////////////////////
		/// Public Slots /////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////

		void Client::connected()
		{
			// Log the status
			Process::Log::notice("Client Connection Established");
		}

		void Client::disconnected()
		{
			// Log the status
			Process::Log::notice("Client Connection Terminated");
		}

		void Client::error(QString strMessage, int intCode)
		{
			// Create the JSON object
			QJsonObject qjoResponse = QJsonObject();
			// Set the error message key
			qjoResponse.insert("error", QJsonValue(strMessage));
			// Set the error code key
			qjoResponse.insert("code", QJsonValue(intCode));
			// Set the success key
			qjoResponse.insert("success", false);
			// Emit the finished signal
			this->finished(QJsonDocument(qjoResponse));
		}

		void Client::finished(QJsonDocument qjdResponse)
		{
			// Check the object for a success key
			if (!qjdResponse.object().contains("success")) {
				// Set the success key
				qjdResponse.object().insert("success", QJsonValue(true));
			}
			// Create the buffer
			QByteArray qbaBuffer;
			// Add the command
			qbaBuffer.append("RESPONSE-JSON\t");
			// Add the response to the buffer
			qbaBuffer.append(qjdResponse.toJson());
			// Finalize the response
			qbaBuffer.append("\r\n");
			// Send the response
			this->mSocket->write(qbaBuffer);
		}

		void Client::ready()
		{
			// Grab the command
			QByteArray qbaCommand = this->mSocket->readLine();
			// Send the command to debug
			Process::Log::debug(QString("Command Received:  %1").arg(QString::fromLatin1(qbaCommand.trimmed())));
			// Instantiate the new task
			SqlPi::Process::Task* procTask = new SqlPi::Process::Task(qbaCommand);
			// We would like to auto delete the task once it's finished
			procTask->setAutoDelete(true);
			// Connect the instance to the task finished slot
			this->connect(procTask, SIGNAL(finished(QJsonDocument)), this, SLOT(finished(QJsonDocument)), Qt::QueuedConnection);
			// Connect the instance to the task error slot
			this->connect(procTask, SIGNAL(oops(QString,int)),  this, SLOT(error(QString,int)));
			// Start the task
			QThreadPool::globalInstance()->start(procTask);
		}

	///////////////////////////////////////////////////////////////////////////
	} /// End SqlPi::Connection Namespace ////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} /// End SqlPi Namespace ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
