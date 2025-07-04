#ifndef OS_CORE_H
#define OS_CORE_H

// External Includes
//=============================================================================

#include <fcntl.h>
#include <errno.h>

// Types
//=============================================================================

typedef I32 Os_File;

// File Property
// ============================================================================

typedef U32 FilePropertyFlags;
enum
{
    FilePropertyFlag_IsFolder = (1 << 0),
};

typedef struct Os_FileProperties Os_FileProperties;
struct Os_FileProperties
{
    U64 size;
    DenseTime modified;
    DenseTime created;
    FilePropertyFlags flags;
};

// Access Flags
// ============================================================================

typedef U32 Os_AccessFlags;
enum
{
    OS_AccessFlag_Read        = (1<<0),
    OS_AccessFlag_Write       = (1<<1),
    OS_AccessFlag_Execute     = (1<<2),
    OS_AccessFlag_Append      = (1<<3),
    OS_AccessFlag_ShareRead   = (1<<4),
    OS_AccessFlag_ShareWrite  = (1<<5),
    OS_AccessFlag_Inherited   = (1<<6),
};

// Memory Allocation
//=============================================================================

internal void *os_memory_create(U64 size);
internal I32 os_memory_commit(void *ptr, U64 size);
internal void os_memory_decommit(void *ptr, U64 size);
internal void *os_memory_alloc(U64 size);
internal void os_memory_free(void *ptr, U64 size);

// File System
//=============================================================================

internal Os_File os_file_open(Str8 path, Os_AccessFlags flags);
internal void os_file_close(Os_File file);
internal U64 os_file_read(Os_File file, Rng1U64 rng, void *out_data);
internal U64 os_file_write(Os_File file, Rng1U64 rng, void *data);
internal Os_FileProperties os_file_properties(Os_File file);
internal bool os_dir_make(Str8 path);

// Exit
//=============================================================================

internal void os_exit(I32 exit_code);

// Time
//=============================================================================

internal U32 os_now_unix(void);
internal void os_sleep_ms(U32 msec);

// Program Entry Points
//=============================================================================

internal void entry_point(char *argv[]);

#endif // OS_CORE_H
