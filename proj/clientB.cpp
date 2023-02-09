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
	
	int client_B_sock;
    char info_received[256];
    string user_A_name = argv[1];
     
    cout << "The client B is up and running." << endl;
     
    //Send to Main Server (Static Port) 
    
    if ((client_B_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);}
		
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(client_B_port);
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	int client_B__status = connect(client_B_sock, (struct sockaddr *) &server_address, sizeof(server_address));
	if (client_B__status == -1) {
		cout << "Connection Error" << endl;	
		} 
	
	if (argc == 4) {
		//TXCOINS
		string user_B_name = argv[2];
		string transfer_amount = argv[3];
		send(client_B_sock, argv[1], sizeof(argv[1]), 0);
		send(client_B_sock, argv[2], sizeof(argv[2]), 0);
		send(client_B_sock, argv[3], sizeof(argv[3]), 0);
		
		cout <<  user_A_name << " has requested to transfer "
		<< transfer_amount << " coins to "  << user_B_name << "." << endl;

		}
	else if (argc == 2){
		//CHECK WALLET
		send(client_B_sock, argv[1], sizeof(argv[1]), 0);
		cout << user_A_name << " sent a balance enquiry request to the main server." << endl;
		
		}
		
		
		
		
		
		
	// Recv from Server (Dynamic Port)
	string from_server_std;
		

	
 return 0;
}
