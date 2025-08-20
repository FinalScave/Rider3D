//
// Created by Scave on 2024/2/23.
//

#ifndef RIDER3D_FILE_H
#define RIDER3D_FILE_H

#include "Define.h"

NS_RIDER_BEGIN

    struct ByteArray {
        UInt64 length;
        char* data;
    };

    struct CharArray {
        UInt64 length;
        char* data;
    };

    struct FileInfo {
        String path;
        String name;
        String extension;
        bool is_asset;
        UInt64 length;
    };

    class FileSession {
        FileInfo GetInfo();

        String ReadAsString();

        CharArray ReadAsChars();

        ByteArray ReadAsBytes();

        void WriteString(const String& content);

        void WriteChars(const CharArray& chars);

        void WriteBytes(const ByteArray& bytes);

        PAIR<UInt32, FileSession*> List();

        FileSession Child(const String& name);

        FileSession Parent();

        bool IsDirectory();

        bool IsFile();

        bool Exists();
    };

    class FileManager {
    public:
        FileSession Asset(const String& path);

        FileSession Absolute(const String& path);

        FileSession AppLocal(const String& path);
    };

NS_RIDER_END

#endif //RIDER3D_FILE_H
