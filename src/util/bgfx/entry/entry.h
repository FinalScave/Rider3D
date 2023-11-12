/*
 * Copyright 2011-2023 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#ifndef ENTRY_H_HEADER_GUARD
#define ENTRY_H_HEADER_GUARD

#include "bgfx/bgfx.h"
#include "bx/bx.h"
#include "bx/filepath.h"
#include "bx/string.h"

namespace bx { struct FileReaderI; struct FileWriterI; struct AllocatorI; }

namespace entry
{

	///
	bx::FileReaderI* getFileReader();

	///
	bx::FileWriterI* getFileWriter();

	///
	bx::AllocatorI*  getAllocator();

	///
	void setCurrentDir(const char* _dir);

} // namespace entry

#endif // ENTRY_H_HEADER_GUARD
