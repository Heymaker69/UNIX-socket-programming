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



int main(int argc, char const* argv[]){
	
	//XXX = 574
	
	int server_A_port = 21574;
	int server_B_port = 22574;
	int server_C_port = 23574;
	
	int server_main_port = 24574;
	int client_A_port = 25574;
	int client_B_port = 26574;
	
	char info1_received[256];
	char info2_received[256];
	char info3_received[256];
	
	int server_sock, server_to_client_A_sock, server_to_client_B_sock, main_to_serverA, serverA_to_main, main_to_serverB, serverB_to_main, main_to_serverC, serverC_to_main;
	string what_i_got;
	int operation = 1;
	int counter = 1;
	
	cout << "The main server is up and running." << endl;
	
	
while (true) {

	//Send to BackEnd A UDP
	if ((main_to_serverA = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket failed");
		exit(EXIT_FAILURE);}
		
	struct sockaddr_in server_address_send_serverA;
	server_address_send_serverA.sin_family = AF_INET;
	server_address_send_serverA.sin_port = htons(server_A_port);
	server_address_send_serverA.sin_addr.s_addr = inet_addr("127.0.0.1");
	sendto(main_to_serverA, "1", 1, 0, (struct sockaddr *) &server_address_send_serverA, sizeof(server_address_send_serverA));
	cout << "The main server sent a request to server A." <<endl;
	close(main_to_serverA);
	

	
	//Receive from BackEnd A UDP
	
	char buff[1024];
	string temp_one;
	sockaddr_in client;	
	socklen_t recv_param = sizeof(client);
	
	//cout << "here" << endl;	
	recvfrom(main_to_serverA, buff, 1024, 0,(sockaddr*) &client, &recv_param);
	cout << "The main server received transactions from Server A using UDP over port " << server_A_port << "." << endl;
	
	//cout << buff << "fefe" << endl;
		
		
	


    //Recv from client A TCP (Static Port)
    if ((server_to_client_A_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);}
    
	struct sockaddr_in server_address_CA;
	server_address_CA.sin_family = AF_INET;
	server_address_CA.sin_port = htons(client_A_port);
	server_address_CA.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	bind(server_to_client_A_sock, (struct sockaddr *) &server_address_CA, sizeof(server_address_CA));
	
	if (counter % 2 != 0){
		listen(server_to_client_A_sock, 6);
		++counter;
		};
	int client_A_sock = accept(server_to_client_A_sock, NULL, NULL);
	recv(client_A_sock, &info1_received, sizeof(info1_received), 0);
	
	if (recv(client_A_sock, &info2_received, sizeof(info2_received), 0)){
		//if its a Transfer Coins request
		operation = 2;
		recv(client_A_sock, &info3_received, sizeof(info3_received), 0);
		cout << "The main server received from "  << info1_received << " to transfer " 
		  << info3_received << " coins to " << info2_received <<  " using TCP over port "
		  << client_A_port << "." << endl; 
		}
	else{ //if its a Check Balance request
		cout << "The main server received input=" 
		<< info1_received <<  " from the client using TCP over port " 
		<< client_A_port << "." << endl; 

	}
	close(server_to_client_A_sock);

	//client B TCP
	//Recv from client B TCP (Static Port)
	if ((server_to_client_B_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);}
    
	struct sockaddr_in server_address_CB;
	server_address_CB.sin_family = AF_INET;
	server_address_CB.sin_port = htons(client_B_port);
	server_address_CB.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	bind(server_to_client_B_sock, (struct sockaddr *) &server_address_CB, sizeof(server_address_CB));
	
		
	if (counter % 2 == 0){
	listen(server_to_client_B_sock, 6);
	++counter;
	
	//cout << "socket for client B connected" << endl;
	}
	int client_B_sock = accept(server_to_client_B_sock, NULL, NULL);
	recv(client_B_sock, &info1_received, sizeof(info1_received), 0);

	if (recv(client_B_sock, &info2_received, sizeof(info2_received), 0)){
		//if its a Transfer Coins request
		operation = 2;
		recv(client_B_sock, &info3_received, sizeof(info3_received), 0);
		cout << "The main server received from "  << info1_received << " to transfer " 
		  << info3_received << " coins to " << info2_received <<  " using TCP over port "
		  << client_B_port << "." << endl;
		}
	else { //if its a Check Balance request
		cout << "The main server received input=" 
		<< info1_received <<  " from the client using TCP over port " 
		<< client_B_port << "." << endl; 
		}
	close(server_to_client_B_sock);
	
	/////////////////////////////////////////////////////////////////////////
	
	
	
	

	
	
	
		//Send to BackEnd B UDP
	if ((main_to_serverB = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
		perror("socket failed");
		exit(EXIT_FAILURE);}
		
	struct sockaddr_in server_address_send_serverB;
	server_address_send_serverB.sin_family = AF_INET;
	server_address_send_serverB.sin_port = htons(server_B_port);
	server_address_send_serverB.sin_addr.s_addr = inet_addr("127.0.0.1");
	sendto(main_to_serverB, "1", 1, 0, (struct sockaddr *) &server_address_send_serverB, sizeof(server_address_send_serverB));
	cout << "The main server sent a request to server A." <<endl;
	close(main_to_serverB);
	

	
	//Receive from BackEnd A UDP
	
	char buffB[1024];
	string temp_oneB;
	sockaddr_in clientB;	
	socklen_t recv_paramB = sizeof(clientB);
	
	//cout << "here" << endl;	
	recvfrom(main_to_serverB, buffB, 1024, 0,(sockaddr*) &clientB, &recv_paramB);
	cout << "The main server received transactions from Server A using UDP over port " << server_B_port << "." << endl;
	
	//cout << buff << "fefe" << endl;
	
	
	/*
	//BackEnd C UDP ?
	if ((back_C_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);}
    
	struct sockaddr_in server_address_SC;
	server_address_SC.sin_family = AF_INET;
	server_address_SC.sin_port = htons(server_C_port);
	server_address_SC.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	
	//Main Server UDP ?
	if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("socket failed");
		exit(EXIT_FAILURE);}
    
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(server_main_port);
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    
    
        
       */
 }
 return 0;
}
