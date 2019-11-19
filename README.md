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
#####[rjdeal@in-csci-rrpc02 RFT]$ make
    javac  src/*.java

#####[rjdeal@in-csci-rrpc02 RFT]$ make clean
    rm -f ./src/Client.class ./src/Utility.class ./src/Server.class

#####[rjdeal@in-csci-rrpc02 RFT]$ make run-server
    java  -cp src Server
    Waiting for connections

#####[rjdeal@in-csci-rrpc01 RFT]$ make run-client
     java  -cp src Client
     Just connected to /10.234.136.56:7555
     
     
     Choose an option:
     1: register
     2: create
     3: list
     4: transfer
     5: summary
     6: subset
     7: delete
     8: close
