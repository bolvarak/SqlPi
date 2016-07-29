///////////////////////////////////////////////////////////////////////////////
/// Headers //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#include "Transport/Server.hpp"

///////////////////////////////////////////////////////////////////////////////
/// SqlPi Namespace //////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

namespace SqlPi
{
	///////////////////////////////////////////////////////////////////////////
	/// SqlPi::Transport Namespace ///////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	namespace Transport
	{
		///////////////////////////////////////////////////////////////////////
		/// Constructor //////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////

		Server::Server(QObject* qoParent) : QTcpServer(qoParent) {
			// Make the new client connection
			this->connect(this, SIGNAL(newConnection()), this, SLOT(client()));
		}

		///////////////////////////////////////////////////////////////////////
		/// Public Methods ///////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////

		void Server::start()
		{
			// Try to start the server
			if (this->listen(QHostAddress::Any, 1597)) {
				// Log the status
				qDebug() << "qtDB-API Server:  Started";
			} else {
				// Log the status
				qDebug() << "qtDB-API Server:  Failed to start - " << this->errorString();
			}
		}

		///////////////////////////////////////////////////////////////////////
		/// Public Slots /////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////

		void Server::client()
		{
			// Log the status
			qDebug() << "qtDB-API:  Incoming Connection";
			// Instantiate a new client
			SqlPi::Connection::Client* conClient = new SqlPi::Connection::Client(this);
			// Set the socket descriptor into the client
			conClient->setSocket(this->nextPendingConnection());
		}

	///////////////////////////////////////////////////////////////////////////
	} /// End SqlPi::Transport Namespace /////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} /// End SqlPi Namespace ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
