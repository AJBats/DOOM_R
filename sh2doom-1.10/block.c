
#include "block.h"

int getFileContents(iso9660_filelist_entry_t* entry, void *buffer)
{
    FilesystemEntryCursor tmpFileCursor;
    tmpFileCursor.cursor = NULL;
    tmpFileCursor.fad = entry->starting_fad;
    return readFileCursor(&tmpFileCursor, buffer, entry->size);
}

void initFileEntryCursor(iso9660_filelist_entry_t* entry, FilesystemEntryCursor *cursor)
{
    assert(entry != NULL);
    assert(cursor != NULL);

    memset(cursor, 0, sizeof(*cursor));
    cursor->fad = entry->starting_fad;
}

#define DEBUG_READ_FILE_CURSOR 0
int readFileCursor(FilesystemEntryCursor *fileCursor, void *buffer, uint32_t length)
{
    assert(fileCursor != NULL);
    assert(buffer != NULL);

    uint8_t* dstBuffer = (uint8_t *)buffer;
    uint32_t missingBytes = length;

#if DEBUG_READ_FILE_CURSOR == 1
    clearscreen();
    dbgio_printf("missingBytes %lu\n", missingBytes);
    dbgio_printf("readingFAD %lu\n", fileCursor->fad);
    dbgio_printf("aliasCursor %p\n", fileCursor->cursor);
    getinput();
#endif

    if (fileCursor->cursor)
    {
        uint32_t remainingBuffer = fileCursor->cursor - fileCursor->sector;
        remainingBuffer = sizeof(fileCursor->sector) - remainingBuffer;

#if DEBUG_READ_FILE_CURSOR == 1
        dbgio_printf("(If0) remainingBuffer %p %p %lu\n", fileCursor->cursor, fileCursor->sector, remainingBuffer);
        getinput();
#endif

        if (missingBytes <= remainingBuffer)
        {
#if DEBUG_READ_FILE_CURSOR == 1
            dbgio_printf("(If1) dstBuffer %p\n", dstBuffer);
            dbgio_printf("(If1) aliasCursor %p\n", fileCursor->cursor);
            dbgio_printf("(If1) missingBytes %lu\n", missingBytes);
            getinput();
#endif
            memcpy(dstBuffer, fileCursor->cursor, missingBytes);
            fileCursor->cursor += missingBytes;
            return 0;
        }
        else
        {
#if DEBUG_READ_FILE_CURSOR == 1
            dbgio_printf("(If2) dstBuffer %p\n", dstBuffer);
            dbgio_printf("(If2) aliasCursor %p\n", fileCursor->cursor);
            dbgio_printf("(If2) missingBytes %lu\n", missingBytes);
            getinput();
#endif
            // if remainingBuffer is 0, then this memcopy does nothing
            // and we prepare for a normal read from a fresh sector.
            memcpy(dstBuffer, fileCursor->cursor, remainingBuffer);
            dstBuffer += remainingBuffer;
            missingBytes -= remainingBuffer;
            fileCursor->cursor = NULL;

            // Jump to next fad.
            fileCursor->fad++;
        }
    }

    while (missingBytes > 0)
    {
        //int ret = cd_block_read_data(LBA2FAD(fileCursor->lba), 2048, fileCursor->sector.data);
        int ret = cd_block_sector_read(fileCursor->fad, fileCursor->sector);
        if (ret != 0)
            return ret;

        if (missingBytes > 2048)
        {
            memcpy(dstBuffer, fileCursor->sector, 2048);
            dstBuffer += 2048;
            missingBytes -= 2048;
            fileCursor->cursor = NULL;

            // Jump to next fad.
            fileCursor->fad++;
        }
        else
        {
            memcpy(dstBuffer, fileCursor->sector, missingBytes);
            fileCursor->cursor = fileCursor->sector + missingBytes;
            missingBytes = 0;
        }
    }

    return 0;
}
