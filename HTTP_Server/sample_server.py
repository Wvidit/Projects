import socket

HOST = "localhost"
PORT = 8080

#AF_INET = ipv4 , SOCK_STREAM = TCP
main_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

main_socket.bind(( HOST, PORT))

main_socket.listen(5)

print("Server is running")

while True:
    client_socket, client_address = main_socket.accept()

    print(f"Connecting to {client_address}")

    request = client_socket.recv(1024).decode()
    print(f"Request received from:\n", request)

    response = """ 
        \HTTP\1.1 200 OK
        Content-Type: text/html

        <title>It's running</title>
        """
    client_socket.sendall(response.encode())

    client_socket.close()
