/*
 * Copyright (c) 2020 - Romulo Fernandes Machado Leitao
 * See LICENSE for details.
 *
 * Romulo Fernandes Machado Leitao <abra185@gmail.com>
 */

#pragma once

#include <yaul.h>

#define DEBUG_FS 0

typedef struct {
  uint8_t sector[2048];
  uint32_t fad;
  uint8_t* cursor;
} FilesystemEntryCursor;

/**
 * Return file contents from the specified entry.
 * @param entry A file entry in the header table.
 * @param buffer File contents will be returned in this buffer.
 *
 * @return 0 If reading was successful.
 */
extern int getFileContents(iso9660_filelist_entry_t *entry, void *buffer);

extern void initFileEntryCursor(iso9660_filelist_entry_t* entry, FilesystemEntryCursor* cursor);

/**
 * Return file contents from the specified entry.
 * @param entry A file entry in the header table.
 * @param buffer File contents will be returned in this buffer.
 *
 * @return 0 If reading was successful.
 */
extern int readFileCursor(FilesystemEntryCursor* fileCursor, void* buffer, uint32_t length);



