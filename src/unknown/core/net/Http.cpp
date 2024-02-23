//
// Created by Scave on 2024/2/23.
//

#include "Http.h"

#include <utility>

UNKNOWN_NS_BEGIN

    HttpRequest::HttpRequest(const HttpMethod& method, String url)
            : method(method), url(std::move(url)) {

    }

    HttpResponse::HttpResponse(HttpStatus status,
                               String body,
                               const std::vector<PAIR<String, String>>& headers
    ) : status(status), body(std::move(body)), headers(headers) {}

    String HttpResponse::GetHeader(const String& key) {
        for (const auto& item: headers) {
            if (item.first == key) {
                return item.second;
            }
        }
        return {};
    }

    void Http::SendRequest(const HttpRequest& request) {

    }

    void Http::SendRequestAsync(const HttpRequest& request, std::function<void(HttpResponse)> callback) {

    }

    void Http::CancelRequest(const HttpRequest& request) {

    }

UNKNOWN_NS_END
