///////////////////////////////////////////////////////////////////////////////
/// Headers //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

#include <QCoreApplication>
#include "Transport/Server.hpp"

///////////////////////////////////////////////////////////////////////////////
/// Main Event Loop //////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/**
 * @paragraph This function executes the API's main event loop
 * @brief ::main()
 * @param int intArguments
 * @param char* chrArguments[]
 * @return int
 */
int main(int intArguments, char* chrArguments[])
{
	// Initialize the resources file
	Q_INIT_RESOURCE(dependencies);
	// Create our new application
	QCoreApplication appDbApi(intArguments, chrArguments);
	// Instantiate the server
	SqlPi::Transport::Server* srvDbApi = new SqlPi::Transport::Server();
	// Start the server
	srvDbApi->start();
	// Return our application execution
	return appDbApi.exec();

///////////////////////////////////////////////////////////////////////////////
} /// End Main Event Loop ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
