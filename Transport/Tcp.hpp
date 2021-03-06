/////////////////////////////////////////////////////////////////////////////////////////
/// Definitions ////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#ifndef SQLPI_TRANSPORT_TCP_HPP
#define SQLPI_TRANSPORT_TCP_HPP

/////////////////////////////////////////////////////////////////////////////////////////
/// Headers ////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#include <QObject>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include "Abstract/Server.hpp"
#include "../Connection/Client.hpp"

/////////////////////////////////////////////////////////////////////////////////////////
/// SqlPi Namespace ////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

namespace SqlPi
{
	/////////////////////////////////////////////////////////////////////////////////////
	/// SqlPi::Transport Namespace /////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

	namespace Transport
	{
		/////////////////////////////////////////////////////////////////////////////////
		/// SqlPi::Transport::Tcp Class Definition /////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

		class Tcp : public Abstract::Server
		{
			/////////////////////////////////////////////////////////////////////////////
			/// Protected Methods & Properties /////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			protected:

				/////////////////////////////////////////////////////////////////////////
				/// Properties /////////////////////////////////////////////////////////
				///////////////////////////////////////////////////////////////////////

				/**
				 * @paragraph This property contains the socket connection for the server
				 * @brief SqlPi::Transport::Tcp::mConnection
				 * @var QTcpServer
				 */
				QTcpServer* mConnection;

			/////////////////////////////////////////////////////////////////////////////
			/// Public Methods & Properties ////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			public:

				/////////////////////////////////////////////////////////////////////////
				/// Constructor ////////////////////////////////////////////////////////
				///////////////////////////////////////////////////////////////////////

				/**
				 * @paragraph This method instantiates a new TCP socket server
				 * @brief SqlPi::Transport::Tcp::Tcp()
				 */
				explicit Tcp();

				/////////////////////////////////////////////////////////////////////////
				/// Abstract Implementations ///////////////////////////////////////////
				///////////////////////////////////////////////////////////////////////

				/**
				 * @abstract
				 * @paragraph This method opens the server and awaits connections
				 * @brief SqlPi::Transport::Tcp::await()
				 * @param QString &strError
				 * @return bool
				 */
				bool await(QString &strError);

			/////////////////////////////////////////////////////////////////////////////
			/// Public Slots ///////////////////////////////////////////////////////////
			///////////////////////////////////////////////////////////////////////////

			public slots:

				/**
				 * @abstract
				 * @paragraph This method handles a new client connection
				 * @brief SqlPi::Transport::Tcp::client()
				 * @return void
				 */
				void client();

				/**
				 * @abstract
				 * @paragraph This method handles a disconnected client
				 * @brief SqlPi::Transport::Tcp::shutdown()
				 * @return void
				 */
				void shutdown();

		/////////////////////////////////////////////////////////////////////////////////
		}; /// End SqlPi::Transport::Tcp Class Definition //////////////////////////////
		///////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////////////////
	} /// End SqlPi::Transport Namespace ///////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
} /// End SqlPi Namespace //////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////
#endif /// End Definitions /////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
