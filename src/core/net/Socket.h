//
// Created by Scave on 2024/2/23.
//

#ifndef RIDER3D_SOCKET_H
#define RIDER3D_SOCKET_H

#include "Define.h"

NS_RIDER_BEGIN

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

NS_RIDER_END

#endif //RIDER3D_SOCKET_H
