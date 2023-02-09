#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const* argv[])
{
    	//XXX = 574
	
	int server_A_port = 21574;
	int server_B_port = 22574;
	int server_C_port = 23574;
	int server_main_port = 24574;
	int client_A_port = 25574;
	int client_B_port = 26574;
	
	int client_A_sock;
    char info_received[256];
    string user_A_name = argv[1];
     
    cout << "The client A is up and running." << endl;
     
    //Send to Main Server (Static Port) 
    
    if ((client_A_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);}
		
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(client_A_port);
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	int client_A__status = connect(client_A_sock, (struct sockaddr *) &server_address, sizeof(server_address));
	if (client_A__status == -1) {
		cout << "Connection Error" << endl;	
		} 
		
	//send request to know how many entries
	//string number_of_entries_str = std::to_string(argc);
	//char const *number_of_entries = number_of_entries_str.c_str();

	//string std_argc = to_string(argc);
	//char const *number_of_entries = std_argc.c_str();
	
	//send(client_A_sock, number_of_entries, sizeof(number_of_entries), 0);
	
	
	if (argv[1] == "TXLIST"){
		}
	
	
	
	if (argc == 4) {
		//TXCOINS
		string user_B_name = argv[2];
		string transfer_amount = argv[3];
		send(client_A_sock, argv[1], sizeof(argv[1]), 0);
		send(client_A_sock, argv[2], sizeof(argv[2]), 0);
		send(client_A_sock, argv[3], sizeof(argv[3]), 0);
		
		cout <<  user_A_name << " has requested to transfer "
		<< transfer_amount << " coins to "  << user_B_name << "." << endl;
		}
		
	else if (argc == 2){
		//CHECK WALLET
		cout << user_A_name << " sent a balance enquiry request to the main server." << endl;
		send(client_A_sock, argv[1], sizeof(argv[1]), 0);
		}
		
		close(client_A_sock);

	// Recv from Server (Dynamic Port)
	string from_server_std;
		

	
 return 0;
}
