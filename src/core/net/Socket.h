//
// Created by Scave on 2024/2/23.
//

#ifndef UNKNOWN3D_SOCKET_H
#define UNKNOWN3D_SOCKET_H

#include "Define.h"

UNKNOWN_NS_BEGIN

    class Socket {
    public:
        explicit Socket(String address, int port);

        void Connect();

        bool IsConnected();

        String ReadString();

    private:
        String address_;
        int port_;
    };

    class ServerSocket {
    public:
        explicit ServerSocket(int port);

        Socket Accept();
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_SOCKET_H
