
A) Abdullah Alenezi

B) A58469809

C) In this assignment I worked on connecting two clients to a main server and connect that main server to three back-end servers to exchange information between the clients to the main server and the backend servers to the main server and vice versa.
I tried completing the optional part as I added the option to it in the Client files.

D) My code files are: 

clientA.cpp  //source code for client A
clientB.cpp  //source code for client B
serverA.cpp  //Back end server A that contains the transactions
serverB.cpp  //Back end server B that contains the transactions
serverC.cpp  //Back end server C that contains the transactions
serverM.cpp  //Main server that connects send and receive information from 			clients and back end servers.
Makefile     	//Creates Executables to run in the terminal
README.txt (this file) //Contains project information and resources.

E) The format of all the messages exchanged was string.

G) The project does send the information for Clients A and B respectivly in order. However, I was not able to send multiple calls of A and B in the same server session.


H) I did not directly copy and pasted a specific code, however I used some resources including youtube videos and stackoverflow to further understand some C/C++ concepts, these videos and articles include:
 
-send() / recv() functionality for TCP: https://forums.codeguru.com/showthread.php?434034-recv()-buffer-as-string

-Converting string to const char *: https://www.techiedelight.com/convert-std-string-const-char-cpp/

-using sendto() for UDP network: https://stackoverflow.com/questions/19535978/c-using-sendto-with-a-basic-string

-int to string conversion: https://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c

-TCP and UDP servers: https://www.geeksforgeeks.org/tcp-and-udp-server-using-select/

-UDP Server-Client Implementation: https://www.geeksforgeeks.org/udp-server-client-implementation-c/

-UDP programming in C: https://www.youtube.com/watch?v=Emuw71lozdA

-simple UDP client server Program: https://www.youtube.com/watch?v=lUyaV4haBUE

-fork functionality: https://stackoverflow.com/questions/13669474/multiclient-server-using-fork

-Vectors: https://www.youtube.com/watch?v=Da_PPyjOUrE
