//
// Created by Scave on 2024/2/23.
//

#include "Socket.h"

UNKNOWN_NS_BEGIN
    Socket::Socket(String address, int port) : address_(std::move(address)), port_(port) {
    }

    void Socket::Connect() {

    }

    bool Socket::IsConnected() {
        return false;
    }

    String Socket::ReadString() {
        return String();
    }

    ServerSocket::ServerSocket(int port) {

    }

    Socket ServerSocket::Accept() {
        return Socket{"", 0};
    }
UNKNOWN_NS_END
