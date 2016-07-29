///////////////////////////////////////////////////////////////////////////////
/// Definitions //////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#ifndef SQLPI_CONNECTION_CLIENT_HPP
#define SQLPI_CONNECTION_CLIENT_HPP

///////////////////////////////////////////////////////////////////////////////
/// Headers //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#include <QDebug>
#include <QJsonDocument>
#include <QObject>
#include <QThreadPool>
#include <QTcpSocket>
#include "Process/Task.hpp"

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
		/// SqlPi::Connection::Client Class Definition ///////////////////////
		/////////////////////////////////////////////////////////////////////

		class Client : public QObject
		{
				/**
				 * Qt Recognition
				 */
				Q_OBJECT

			///////////////////////////////////////////////////////////////////
			/// Protected Methods & Properties ///////////////////////////////
			/////////////////////////////////////////////////////////////////

			protected:

				///////////////////////////////////////////////////////////////
				/// Properties ///////////////////////////////////////////////
				/////////////////////////////////////////////////////////////

				/**
				 * @paragraph This property contains the instance of our socket
				 * @brief SqlPi::Connection::Client::mSocket
				 * @var QTcpSocket*
				 */
				QTcpSocket* mSocket;

			///////////////////////////////////////////////////////////////////
			/// Public Methods & Properties //////////////////////////////////
			/////////////////////////////////////////////////////////////////

			public:

				///////////////////////////////////////////////////////////////
				/// Constructor //////////////////////////////////////////////
				/////////////////////////////////////////////////////////////

				/**
				 * @paragraph This method instantiates a new client connection
				 * @brief SqlPi::Connection::Client::Client()
				 * @param QObject* qoParent [0]
				 */
				explicit Client(QObject* qoParent = 0);

				///////////////////////////////////////////////////////////////
				/// Setters //////////////////////////////////////////////////
				/////////////////////////////////////////////////////////////

				/**
				 * @paragraph This method sets the socket descriptor into the instance
				 * @brief SqlPi::Connection::Client::setSocket()
				 * @param QTcpSocket* tcpSocket
				 * @return void
				 */
				void setSocket(QTcpSocket* tcpSocket);

			///////////////////////////////////////////////////////////////////
			/// Public Slots /////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////

			public slots:

				/**
				 * @paragraph This method gets executed when a successful client connection is established
				 * @brief SqlPi::Connection::Client::connected()
				 * @return void
				 */
				void connected();

				/**
				 * @paragraph This method gets executed when a client disconnects
				 * @brief SqlPi::Connection::Client::disconnected()
				 * @return void
				 */
				void disconnected();

				/**
				 * @paragraph This method gets executed when an error occurs
				 * @brief SqlPi::Connection::Client::error()
				 * @param QString strMessage
				 * @param int intCode [0]
				 * @return void
				 */
				void error(QString strMessage, int intCode = 0);

				/**
				 * @paragraph This method gets executed when the client task has finished
				 * @brief SqlPi::Connection::Client::finished()
				 * @param QJsonDocument qjdResponse
				 * @return void
				 */
				void finished(QJsonDocument qjdResponse);

				/**
				 * @paragraph This method gets executed when the client connection is ready
				 * @brief SqlPi::Connection::Client::ready()
				 * @return void
				 */
				void ready();

		///////////////////////////////////////////////////////////////////////
		}; /// End SqlPi::Connection::Client Class Definition ////////////////
		/////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	} /// End SqlPi::Connection Namespace ////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
} /// End SqlPi Namespace ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
#endif /// End Definitions ///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
