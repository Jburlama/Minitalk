![image](https://github.com/user-attachments/assets/fbc7fa62-7cb7-4e70-bae7-4aab7a908aae)



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
----------------------


**Minitalk** must conform to the [42 Norm](https://cdn.intra.42.fr/pdf/pdf/96987/en.norm.pdf).

**Install** [norminette](https://github.com/42School/norminette).




https://github.com/user-attachments/assets/f7b61c6d-f14d-458a-9ce5-c3985199d91e



