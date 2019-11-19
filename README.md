#Distributed-Computing-Project-2 (File Transfer)
From the directory this README is in the following commands can be used


#NOTE TO THE TA: Multiple clients work at a time (for bonus points)
https://github.com/killmequickdeal/RPCGEN

####make 
    Build the .o files and executables for all necessary files
####make clean 
    Clean up .o files, executables, etc
####make cleanall
    Cleans up EVERYTHING, so it can be rebuild with rpcgen. Please be cautious of this.
####Running the server-side
    ./add_server
####Running the client-side
    ./add_client {server_ip}

Examples:
--
#####[rjdeal@in-csci-rrpc03 RPC]$ make
g++ -g -D_REENTRANT  -c -o add_clnt.o add_clnt.c
g++ -g -D_REENTRANT  -c -o add_client.o add_client.c
g++ -g -D_REENTRANT  -c -o add_xdr.o add_xdr.c
g++ -g -D_REENTRANT   -o add_client  add_clnt.o add_client.o add_xdr.o -lnsl -lpthread
g++ -g -D_REENTRANT  -c -o add_svc.o add_svc.c
g++ -g -D_REENTRANT  -c -o add_server.o add_server.c
g++ -g -D_REENTRANT   -o add_server  add_svc.o add_server.o add_xdr.o -lnsl -lpthread
[rjdeal@in-csci-rrpc03 RPC]$

#####[rjdeal@in-csci-rrpc03 RPC]$ make clean
rm -f core  add_clnt.o add_client.o add_xdr.o  add_svc.o add_server.o add_xdr.o add_client add_server
[rjdeal@in-csci-rrpc03 RPC]$

#####[rjdeal@in-csci-rrpc03 RPC]$ ./add_server


#####[rjdeal@tesla RPC]$ ./add_client 10.234.136.57

Original string: Encryption Test
Reversed, Encrypted string: ?8.k%$"?;29(%

Current Date and Time: Tue Nov 19 00:30:58 2019


Sorted list results:
1 3 5 8

Current files in directory:
.
..
add_server.c
add_client.c
add_server.o
outcomes.txt
add.x
add_svc.c
add.h
.nfs000000000d77b5e0000003a5
add_clnt.o
add_xdr.o
add_svc.o
add_server
add_xdr.c
add_clnt.c
Makefile
DealA3.zip
add_client.o
add_client

Matrix Multiply Results:
28 13 39 67
[rjdeal@tesla RPC]$
