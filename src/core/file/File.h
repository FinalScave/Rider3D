//
// Created by Scave on 2024/2/23.
//

#ifndef UNKNOWN3D_FILE_H
#define UNKNOWN3D_FILE_H

#include "Define.h"

UNKNOWN_NS_BEGIN

    struct ByteArray {
        UInt64 length;
        Byte* data;
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

UNKNOWN_NS_END

#endif //UNKNOWN3D_FILE_H
