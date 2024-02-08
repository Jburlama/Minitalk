# Minitalk

The purpose of this project is to code a small data exchange program using UNIX signals.

• The server is started first and prompts its PID.

• The client takes two parameters

    -The server PID.
    -The string to send.

• The client sends a string passed as a parameter to the server. Once the string has been received, the server prints it.

## usage

```
make
```
We can use the make command to compile both the server and the client.

```
./server
```
Use the command './server' to start the server.

```
./client [server pid] [string]
```

To send a string from the client to the server, execute the command above in your client program.
