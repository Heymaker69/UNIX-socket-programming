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
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


int main(void){
	//XXX = 574
	int server_A_port = 21574;
	int server_B_port = 22574;
	int server_C_port = 23574;
	
	int server_main_port = 24574;
	int client_A_port = 25574;
	int client_B_port = 26574;
	
	cout << "The ServerB is up and running using UDP on port " << server_A_port << "." << endl;
	
	//receive message from main server
	int main_to_serverC;
	string info_received;
	
	if ((main_to_serverC = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket failed");
		exit(EXIT_FAILURE);}
		
	struct sockaddr_in server_address_send_serverC;
	server_address_send_serverC.sin_family = AF_INET;
	server_address_send_serverC.sin_port = htons(server_C_port);
	server_address_send_serverC.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	bind(main_to_serverC, (struct sockaddr *) &server_address_send_serverC, sizeof(server_address_send_serverC));
	
	
	//cout << "infooo is " << info_received << endl;
	string operation;
	char buffC[1024];
	sockaddr_in clientC;	
	socklen_t recv_paramC = sizeof(clientC);	
										
	recvfrom(main_to_serverC, buffC, 1, 0,(sockaddr*) &clientC, &recv_paramC);
	cout << "The ServerC received a request from the Main Server." << endl;
	close(main_to_serverC);
	
	
	
	
	//send messages to main server
	string wordC = "this is being sent from A to Main";
	sendto(main_to_serverC, wordC.data(), sizeof(wordC), 0, (struct sockaddr *) &server_address_send_serverC, sizeof(server_address_send_serverC));
	cout << "The ServerC finished sending the response to the Main Server." << endl;
	//cout << word.data() << "   ayooo" << endl;	
	
	
	
	
	
	
////////////////////////////////////////////////////////////////////////////////////////

	ifstream block3("block3.txt");
	vector<vector<string>> block3_lines;
	string std_block3_line;
	
	if (block3.is_open()){
		while(getline(block3, std_block3_line)){
			vector<string> temp_line_vec;
			stringstream ss(std_block3_line);
			string temp_str;
			while(getline(ss, temp_str, ' ')){
				temp_line_vec.push_back(temp_str);
				}
			block3_lines.push_back(temp_line_vec);
			}}
			block3.close();

	for(auto line : block3_lines){
		
		
		for(auto word : line) {
			
			cout << word << " ";
			
			}
		cout << endl;
		
		}
	
	//////////////////////////////////////////////////////

	


	return 0;
}
