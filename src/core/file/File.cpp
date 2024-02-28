//
// Created by Scave on 2024/2/24.
//

#include "Define.h"
#include "File.h"


NS_RIDER_BEGIN
    FileInfo FileSession::GetInfo() {
        return {};
    }

    String FileSession::ReadAsString() {
        return String();
    }

    FileSession FileManager::Asset(const String& path) {
        FileSession session;
        return session;
    }

    FileSession FileManager::Absolute(const String& path) {
        return FileSession();
    }

    FileSession FileManager::AppLocal(const String& path) {
        return FileSession();
    }

NS_RIDER_END
