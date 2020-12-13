/*
 * Copyright (c) 2020 - Romulo Fernandes Machado Leitao
 * See LICENSE for details.
 *
 * Romulo Fernandes Machado Leitao <abra185@gmail.com>
 */

#pragma once

#include <yaul.h>

#define DEBUG_FS 0

typedef iso9660_filelist_entry_t* CDFileHandle;

typedef struct {
  uint8_t sector[2048];
  uint32_t fad;
  uint8_t* cursor;
} FilesystemEntryCursor;

int getFileContents(CDFileHandle entry, void *buffer);
void initFileEntryCursor(CDFileHandle entry, FilesystemEntryCursor* cursor);
void lseekFileCursor(CDFileHandle entry, FilesystemEntryCursor* cursor, off_t offset, int whence);
int readFileCursor(FilesystemEntryCursor* fileCursor, void* buffer, uint32_t length);



