# How to Test

## 1. Compile the Programs
Open two terminals and compile both the **server** and **client** programs:

- **In the first terminal (server):**
  ```sh
  gcc server.c -o server

- **In the second terminal (client):**
  ```sh
  gcc client.c -o client

## 2. Start the Server
- **Run the server in the first terminal:**
  ```sh
  ./server

- **The output will display the PID (Process ID) of the server, for example:**
  ```sh
  Server PID: 12345


## 3. Send Signals from the Client
Use the server's PID in the second terminal to send signals:
- **Send SIGUSR1 (prints "Hello World"):**
  ```sh
  ./client <PID> 1

- **Send SIGUSR2 (prints a random number):**
  ```sh
  ./client <PID> 2
