/*
 * Copyright 2011-2023 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#include "bx/bx.h"
#include "bx/file.h"
#include "bx/sort.h"
#include "bgfx/bgfx.h"

#include <time.h>

#if BX_PLATFORM_EMSCRIPTEN
#	include <emscripten.h>
#endif // BX_PLATFORM_EMSCRIPTEN

namespace entry {
    static bx::FileReaderI *s_fileReader = NULL;
    static bx::FileWriterI *s_fileWriter = NULL;

    bx::AllocatorI *getDefaultAllocator();

    bx::AllocatorI *g_allocator = getDefaultAllocator();

    typedef bx::StringT<&g_allocator> String;

    static String s_currentDir;

    /*class FileReader : public bx::FileReader {
        typedef bx::FileReader super;

    public:
        virtual bool open(const bx::FilePath &_filePath, bx::Error *_err) override {
            String filePath(s_currentDir);
            filePath.append(_filePath);
            return super::open(filePath.getPtr(), _err);
        }
    };

    class FileWriter : public bx::FileWriter {
        typedef bx::FileWriter super;

    public:
        virtual bool open(const bx::FilePath &_filePath, bool _append, bx::Error *_err) override {
            String filePath(s_currentDir);
            filePath.append(_filePath);
            return super::open(filePath.getPtr(), _append, _err);
        }
    };*/

    void setCurrentDir(const char *_dir) {
        s_currentDir.set(_dir);
    }

    bx::AllocatorI *getDefaultAllocator() {
        static bx::DefaultAllocator s_allocator;
        return &s_allocator;
    }

    bx::FileReaderI *getFileReader() {
        if (s_fileReader == NULL) {
            s_fileReader = BX_NEW(g_allocator, bx::FileReader);
        }
        return s_fileReader;
    }

    bx::FileWriterI *getFileWriter() {
        if (s_fileWriter == NULL) {
            s_fileWriter = BX_NEW(g_allocator, bx::FileWriter);
        }
        return s_fileWriter;
    }

    bx::AllocatorI *getAllocator() {
        if (NULL == g_allocator) {
            g_allocator = getDefaultAllocator();
        }

        return g_allocator;
    }
} // namespace entry