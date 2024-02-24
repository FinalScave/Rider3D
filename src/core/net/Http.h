//
// Created by Scave on 2024/2/23.
//

#ifndef UNKNOWN3D_HTTP_H
#define UNKNOWN3D_HTTP_H

#include <vector>
#include <functional>
#include "Define.h"

UNKNOWN_NS_BEGIN

    struct HttpMethod {
        enum Enum {
            Get = 0,
            Post,
            Put,
            Delete
        };
    };

    struct HttpStatus {
        enum Enum {
            Continue = 100,
            SwitchingProtocols = 101,
            Processing = 102,
            Ok = 200,
            Created = 201,
            Accepted = 202,
            NoContent = 203,
            ResetContent = 205,
            PartialContent = 206,
            MultiStatus = 207,
            MultiChoice = 300,
            UseProxy = 305,
            BadRequest = 400,
            Unauthorized = 401,
            PaymentRequired = 402,
            Forbidden = 403,
            NotFound = 404,
            MethodNotAllowed = 405,
            RequestTimeout = 408,
            Conflict = 409,
            Gone = 410,
            MethodFailure = 420,
            InternalServerError = 500,
            BadGateway = 502,
            GatewayTimeout = 504,
        };
    };

    struct HttpRequest {
        HttpRequest(const HttpMethod::Enum& method, String url);

        HttpMethod::Enum method;
        String url;
        std::vector<PAIR<String, String>> headers;
        String content;
        UInt32 timeout{};
        bool follow_redirects{};
    };

    struct HttpResponse {
        HttpResponse(
                HttpStatus status,
                String body,
                const std::vector<PAIR<String, String>>& headers
        );

        HttpStatus status;
        String body;
        std::vector<PAIR<String, String>> headers;

        String GetHeader(const String& key);
    };

    class Http {
    public:
        void SendRequest(const HttpRequest& request);

        void SendRequestAsync(const HttpRequest& request, std::function<void(HttpResponse)> callback);

        void CancelRequest(const HttpRequest& request);
    };

UNKNOWN_NS_END

#endif //UNKNOWN3D_HTTP_H
