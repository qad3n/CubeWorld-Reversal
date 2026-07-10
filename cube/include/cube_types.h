#ifndef CUBE_TYPES_H
#define CUBE_TYPES_H
#include <stdint.h>

typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned long long    GUID;
typedef pointer32 ImageBaseOffset32;

typedef long long    longlong;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    wchar16;
typedef short    wchar_t;
typedef unsigned short    word;
typedef int __ehstate_t;

typedef longlong __time64_t;

typedef struct _Cancellation_beacon _Cancellation_beacon, *P_Cancellation_beacon;

struct _Cancellation_beacon { /* PlaceHolder Structure */
};

typedef struct _Concurrent_vector_base_v4 _Concurrent_vector_base_v4, *P_Concurrent_vector_base_v4;

struct _Concurrent_vector_base_v4 { /* PlaceHolder Structure */
};

typedef struct _Container_base0 _Container_base0, *P_Container_base0;

struct _Container_base0 { /* PlaceHolder Structure */
};

typedef struct _CONTEXT _CONTEXT, *P_CONTEXT;

typedef ulong DWORD;

typedef struct _FLOATING_SAVE_AREA _FLOATING_SAVE_AREA, *P_FLOATING_SAVE_AREA;

typedef struct _FLOATING_SAVE_AREA FLOATING_SAVE_AREA;

typedef uchar BYTE;

struct _FLOATING_SAVE_AREA {
    DWORD ControlWord;
    DWORD StatusWord;
    DWORD TagWord;
    DWORD ErrorOffset;
    DWORD ErrorSelector;
    DWORD DataOffset;
    DWORD DataSelector;
    BYTE RegisterArea[80];
    DWORD Cr0NpxState;
};

struct _CONTEXT {
    DWORD ContextFlags;
    DWORD Dr0;
    DWORD Dr1;
    DWORD Dr2;
    DWORD Dr3;
    DWORD Dr6;
    DWORD Dr7;
    FLOATING_SAVE_AREA FloatSave;
    DWORD SegGs;
    DWORD SegFs;
    DWORD SegEs;
    DWORD SegDs;
    DWORD Edi;
    DWORD Esi;
    DWORD Ebx;
    DWORD Edx;
    DWORD Ecx;
    DWORD Eax;
    DWORD Ebp;
    DWORD Eip;
    DWORD SegCs;
    DWORD EFlags;
    DWORD Esp;
    DWORD SegSs;
    BYTE ExtendedRegisters[512];
};

typedef struct _Context _Context, *P_Context;

struct _Context { /* PlaceHolder Structure */
};

typedef struct _EXCEPTION_POINTERS _EXCEPTION_POINTERS, *P_EXCEPTION_POINTERS;

typedef struct _EXCEPTION_RECORD _EXCEPTION_RECORD, *P_EXCEPTION_RECORD;

typedef struct _EXCEPTION_RECORD EXCEPTION_RECORD;

typedef EXCEPTION_RECORD *PEXCEPTION_RECORD;

typedef struct _CONTEXT CONTEXT;

typedef CONTEXT *PCONTEXT;

typedef void *PVOID;

typedef ulong ULONG_PTR;

struct _EXCEPTION_RECORD {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    struct _EXCEPTION_RECORD *ExceptionRecord;
    PVOID ExceptionAddress;
    DWORD NumberParameters;
    ULONG_PTR ExceptionInformation[15];
};

struct _EXCEPTION_POINTERS {
    PEXCEPTION_RECORD ExceptionRecord;
    PCONTEXT ContextRecord;
};

typedef struct _FILETIME _FILETIME, *P_FILETIME;

struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
};

typedef enum _GET_FILEEX_INFO_LEVELS {
    GetFileExInfoStandard=0,
    GetFileExMaxInfoLevel=1
} _GET_FILEEX_INFO_LEVELS;

typedef struct _GUID _GUID, *P_GUID;

struct _GUID {
    ulong Data1;
    ushort Data2;
    ushort Data3;
    uchar Data4[8];
};

typedef struct _IMAGE_SECTION_HEADER _IMAGE_SECTION_HEADER, *P_IMAGE_SECTION_HEADER;

typedef union _union_226 _union_226, *P_union_226;

typedef ushort WORD;

union _union_226 {
    DWORD PhysicalAddress;
    DWORD VirtualSize;
};

struct _IMAGE_SECTION_HEADER {
    BYTE Name[8];
    union _union_226 Misc;
    DWORD VirtualAddress;
    DWORD SizeOfRawData;
    DWORD PointerToRawData;
    DWORD PointerToRelocations;
    DWORD PointerToLinenumbers;
    WORD NumberOfRelocations;
    WORD NumberOfLinenumbers;
    DWORD Characteristics;
};

typedef struct _iobuf _iobuf, *P_iobuf;

struct _iobuf {
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
};

typedef union _LARGE_INTEGER _LARGE_INTEGER, *P_LARGE_INTEGER;

typedef struct _struct_19 _struct_19, *P_struct_19;

typedef struct _struct_20 _struct_20, *P_struct_20;

typedef double LONGLONG;

typedef long LONG;

struct _struct_20 {
    DWORD LowPart;
    LONG HighPart;
};

struct _struct_19 {
    DWORD LowPart;
    LONG HighPart;
};

union _LARGE_INTEGER {
    struct _struct_19 s;
    struct _struct_20 u;
    LONGLONG QuadPart;
};

typedef struct _LIST_ENTRY _LIST_ENTRY, *P_LIST_ENTRY;

struct _LIST_ENTRY {
    struct _LIST_ENTRY *Flink;
    struct _LIST_ENTRY *Blink;
};

typedef struct _Locimp _Locimp, *P_Locimp;

struct _Locimp { /* PlaceHolder Structure */
};

typedef struct _Lockit _Lockit, *P_Lockit;

struct _Lockit { /* PlaceHolder Structure */
};

typedef int (*_onexit_t)(void);

typedef struct _OSVERSIONINFOA _OSVERSIONINFOA, *P_OSVERSIONINFOA;

typedef char CHAR;

struct _OSVERSIONINFOA {
    DWORD dwOSVersionInfoSize;
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    DWORD dwBuildNumber;
    DWORD dwPlatformId;
    CHAR szCSDVersion[128];
};

typedef struct _OVERLAPPED _OVERLAPPED, *P_OVERLAPPED;

typedef union _union_518 _union_518, *P_union_518;

typedef void *HANDLE;

typedef struct _struct_519 _struct_519, *P_struct_519;

struct _struct_519 {
    DWORD Offset;
    DWORD OffsetHigh;
};

union _union_518 {
    struct _struct_519 s;
    PVOID Pointer;
};

struct _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union _union_518 u;
    HANDLE hEvent;
};

typedef struct _RTL_CRITICAL_SECTION _RTL_CRITICAL_SECTION, *P_RTL_CRITICAL_SECTION;

typedef struct _RTL_CRITICAL_SECTION_DEBUG _RTL_CRITICAL_SECTION_DEBUG, *P_RTL_CRITICAL_SECTION_DEBUG;

typedef struct _RTL_CRITICAL_SECTION_DEBUG *PRTL_CRITICAL_SECTION_DEBUG;

typedef struct _LIST_ENTRY LIST_ENTRY;

struct _RTL_CRITICAL_SECTION {
    PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    ULONG_PTR SpinCount;
};

struct _RTL_CRITICAL_SECTION_DEBUG {
    WORD Type;
    WORD CreatorBackTraceIndex;
    struct _RTL_CRITICAL_SECTION *CriticalSection;
    LIST_ENTRY ProcessLocksList;
    DWORD EntryCount;
    DWORD ContentionCount;
    DWORD Flags;
    WORD CreatorBackTraceIndexHigh;
    WORD SpareWORD;
};

typedef struct _s__RTTIBaseClassDescriptor _s__RTTIBaseClassDescriptor, *P_s__RTTIBaseClassDescriptor;

typedef struct TypeDescriptor TypeDescriptor, *PTypeDescriptor;

typedef struct PMD PMD, *PPMD;

typedef struct _s__RTTIClassHierarchyDescriptor _s__RTTIClassHierarchyDescriptor, *P_s__RTTIClassHierarchyDescriptor;

typedef struct _s__RTTIClassHierarchyDescriptor RTTIClassHierarchyDescriptor;

typedef int ptrdiff_t;

typedef struct _s__RTTIBaseClassDescriptor RTTIBaseClassDescriptor;

struct TypeDescriptor {
    void *pVFTable;
    void *spare;
    char name[0];
};

struct PMD {
    ptrdiff_t mdisp;
    ptrdiff_t pdisp;
    ptrdiff_t vdisp;
};

struct _s__RTTIBaseClassDescriptor {
    struct TypeDescriptor *pTypeDescriptor; /* ref to TypeDescriptor (RTTI 0) for class */
    dword numContainedBases; /* count of extended classes in BaseClassArray (RTTI 2) */
    struct PMD where; /* member displacement structure */
    dword attributes; /* bit flags */
    RTTIClassHierarchyDescriptor *pClassHierarchyDescriptor; /* ref to ClassHierarchyDescriptor (RTTI 3) for class */
};

struct _s__RTTIClassHierarchyDescriptor {
    dword signature;
    dword attributes; /* bit flags */
    dword numBaseClasses; /* number of base classes (i.e. rtti1Count) */
    RTTIBaseClassDescriptor **pBaseClassArray; /* ref to BaseClassArray (RTTI 2) */
};

typedef struct _s__RTTICompleteObjectLocator _s__RTTICompleteObjectLocator, *P_s__RTTICompleteObjectLocator;

struct _s__RTTICompleteObjectLocator {
    dword signature;
    dword offset; /* offset of vbtable within class */
    dword cdOffset; /* constructor displacement offset */
    struct TypeDescriptor *pTypeDescriptor; /* ref to TypeDescriptor (RTTI 0) for class */
    RTTIClassHierarchyDescriptor *pClassDescriptor; /* ref to ClassHierarchyDescriptor (RTTI 3) */
};

typedef struct _s_CatchableType _s_CatchableType, *P_s_CatchableType;


/* WARNING! conflicting data type names: /ehdata.h/TypeDescriptor - /TypeDescriptor */

typedef void (*PMFN)(void *);

struct _s_CatchableType {
    uint properties;
    struct TypeDescriptor *pType;
    struct PMD thisDisplacement;
    int sizeOrOffset;
    PMFN copyFunction;
};

typedef struct _s_CatchableTypeArray _s_CatchableTypeArray, *P_s_CatchableTypeArray;

typedef struct _s_CatchableType CatchableType;

struct _s_CatchableTypeArray {
    int nCatchableTypes;
    CatchableType *arrayOfCatchableTypes[0];
};

typedef struct _s_ESTypeList _s_ESTypeList, *P_s_ESTypeList;

typedef struct _s_HandlerType _s_HandlerType, *P_s_HandlerType;

typedef struct _s_HandlerType HandlerType;

struct _s_HandlerType {
    uint adjectives;
    struct TypeDescriptor *pType;
    ptrdiff_t dispCatchObj;
    void *addressOfHandler;
};

struct _s_ESTypeList {
    int nCount;
    HandlerType *pTypeArray;
};

typedef struct _s_FuncInfo _s_FuncInfo, *P_s_FuncInfo;

typedef struct _s_UnwindMapEntry _s_UnwindMapEntry, *P_s_UnwindMapEntry;

typedef struct _s_UnwindMapEntry UnwindMapEntry;

typedef struct _s_TryBlockMapEntry _s_TryBlockMapEntry, *P_s_TryBlockMapEntry;

typedef struct _s_TryBlockMapEntry TryBlockMapEntry;

typedef struct _s_ESTypeList ESTypeList;

struct _s_FuncInfo {
    uint magicNumber_and_bbtFlags;
    __ehstate_t maxState;
    UnwindMapEntry *pUnwindMap;
    uint nTryBlocks;
    TryBlockMapEntry *pTryBlockMap;
    uint nIPMapEntries;
    void *pIPToStateMap;
    ESTypeList *pESTypeList;
    int EHFlags;
};

struct _s_UnwindMapEntry {
    __ehstate_t toState;
    void (*action)(void);
};

struct _s_TryBlockMapEntry {
    __ehstate_t tryLow;
    __ehstate_t tryHigh;
    __ehstate_t catchHigh;
    int nCatches;
    HandlerType *pHandlerArray;
};

typedef struct _s_ThrowInfo _s_ThrowInfo, *P_s_ThrowInfo;

typedef struct _s_CatchableTypeArray CatchableTypeArray;

struct _s_ThrowInfo {
    uint attributes;
    PMFN pmfnUnwind;
    int (*pForwardCompat)(void);
    CatchableTypeArray *pCatchableTypeArray;
};

typedef struct _SECURITY_ATTRIBUTES _SECURITY_ATTRIBUTES, *P_SECURITY_ATTRIBUTES;

typedef void *LPVOID;

typedef int BOOL;

struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
};

typedef struct _Smanip<__int64> _Smanip<__int64>, *P_Smanip<__int64>;

struct _Smanip<__int64> { /* PlaceHolder Structure */
};

typedef struct _SpinWait<1> _SpinWait<1>, *P_SpinWait<1>;

struct _SpinWait<1> { /* PlaceHolder Structure */
};

typedef struct _startupinfo _startupinfo, *P_startupinfo;

struct _startupinfo {
    int newmode;
};

typedef struct _struct_531 _struct_531, *P_struct_531;

struct _struct_531 {
    WORD wProcessorArchitecture;
    WORD wReserved;
};

typedef struct _StructuredTaskCollection _StructuredTaskCollection, *P_StructuredTaskCollection;

struct _StructuredTaskCollection { /* PlaceHolder Structure */
};

typedef struct _SYSTEM_INFO _SYSTEM_INFO, *P_SYSTEM_INFO;

typedef union _union_530 _union_530, *P_union_530;

typedef ULONG_PTR DWORD_PTR;

union _union_530 {
    DWORD dwOemId;
    struct _struct_531 s;
};

struct _SYSTEM_INFO {
    union _union_530 u;
    DWORD dwPageSize;
    LPVOID lpMinimumApplicationAddress;
    LPVOID lpMaximumApplicationAddress;
    DWORD_PTR dwActiveProcessorMask;
    DWORD dwNumberOfProcessors;
    DWORD dwProcessorType;
    DWORD dwAllocationGranularity;
    WORD wProcessorLevel;
    WORD wProcessorRevision;
};

typedef struct _SYSTEMTIME _SYSTEMTIME, *P_SYSTEMTIME;

struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
};

typedef enum _TaskCollectionStatus {
} _TaskCollectionStatus;

typedef struct _UnrealizedChore _UnrealizedChore, *P_UnrealizedChore;

struct _UnrealizedChore { /* PlaceHolder Structure */
};

typedef WORD ATOM;

typedef struct bad_cast bad_cast, *Pbad_cast;

struct bad_cast { /* PlaceHolder Structure */
};

typedef struct basic_filebuf<char,std::char_traits<char>_> basic_filebuf<char,std::char_traits<char>_>, *Pbasic_filebuf<char,std::char_traits<char>_>;

struct basic_filebuf<char,std::char_traits<char>_> { /* PlaceHolder Class Structure */
};

typedef struct basic_ios<char,std::char_traits<char>_> basic_ios<char,std::char_traits<char>_>, *Pbasic_ios<char,std::char_traits<char>_>;

struct basic_ios<char,std::char_traits<char>_> { /* PlaceHolder Structure */
};

typedef struct basic_ios<wchar_t,std::char_traits<wchar_t>_> basic_ios<wchar_t,std::char_traits<wchar_t>_>, *Pbasic_ios<wchar_t,std::char_traits<wchar_t>_>;

struct basic_ios<wchar_t,std::char_traits<wchar_t>_> { /* PlaceHolder Structure */
};

typedef struct basic_iostream<char,std::char_traits<char>_> basic_iostream<char,std::char_traits<char>_>, *Pbasic_iostream<char,std::char_traits<char>_>;

struct basic_iostream<char,std::char_traits<char>_> { /* PlaceHolder Structure */
};

typedef struct basic_iostream<wchar_t,std::char_traits<wchar_t>_> basic_iostream<wchar_t,std::char_traits<wchar_t>_>, *Pbasic_iostream<wchar_t,std::char_traits<wchar_t>_>;

struct basic_iostream<wchar_t,std::char_traits<wchar_t>_> { /* PlaceHolder Structure */
};

typedef struct basic_istream<char,std::char_traits<char>_> basic_istream<char,std::char_traits<char>_>, *Pbasic_istream<char,std::char_traits<char>_>;

struct basic_istream<char,std::char_traits<char>_> { /* PlaceHolder Structure */
};

typedef struct basic_istream<char,struct_std::char_traits<char>_> basic_istream<char,struct_std::char_traits<char>_>, *Pbasic_istream<char,struct_std::char_traits<char>_>;

struct basic_istream<char,struct_std::char_traits<char>_> { /* PlaceHolder Structure */
};

typedef struct basic_istream<wchar_t,std::char_traits<wchar_t>_> basic_istream<wchar_t,std::char_traits<wchar_t>_>, *Pbasic_istream<wchar_t,std::char_traits<wchar_t>_>;

struct basic_istream<wchar_t,std::char_traits<wchar_t>_> { /* PlaceHolder Structure */
};

typedef struct basic_istream<wchar_t,struct_std::char_traits<wchar_t>_> basic_istream<wchar_t,struct_std::char_traits<wchar_t>_>, *Pbasic_istream<wchar_t,struct_std::char_traits<wchar_t>_>;

struct basic_istream<wchar_t,struct_std::char_traits<wchar_t>_> { /* PlaceHolder Structure */
};

typedef struct basic_ostream<char,std::char_traits<char>_> basic_ostream<char,std::char_traits<char>_>, *Pbasic_ostream<char,std::char_traits<char>_>;

struct basic_ostream<char,std::char_traits<char>_> { /* PlaceHolder Structure */
};

typedef struct basic_ostream<char,struct_std::char_traits<char>_> basic_ostream<char,struct_std::char_traits<char>_>, *Pbasic_ostream<char,struct_std::char_traits<char>_>;

struct basic_ostream<char,struct_std::char_traits<char>_> { /* PlaceHolder Structure */
};

typedef struct basic_ostream<wchar_t,std::char_traits<wchar_t>_> basic_ostream<wchar_t,std::char_traits<wchar_t>_>, *Pbasic_ostream<wchar_t,std::char_traits<wchar_t>_>;

struct basic_ostream<wchar_t,std::char_traits<wchar_t>_> { /* PlaceHolder Structure */
};

typedef struct basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>, *Pbasic_ostream<wchar_t,struct_std::char_traits<wchar_t>_>;

struct basic_ostream<wchar_t,struct_std::char_traits<wchar_t>_> { /* PlaceHolder Structure */
};

typedef struct basic_streambuf<char,std::char_traits<char>_> basic_streambuf<char,std::char_traits<char>_>, *Pbasic_streambuf<char,std::char_traits<char>_>;

struct basic_streambuf<char,std::char_traits<char>_> { /* PlaceHolder Structure */
};

typedef struct basic_streambuf<char,struct_std::char_traits<char>_> basic_streambuf<char,struct_std::char_traits<char>_>, *Pbasic_streambuf<char,struct_std::char_traits<char>_>;

struct basic_streambuf<char,struct_std::char_traits<char>_> { /* PlaceHolder Structure */
};

typedef struct basic_streambuf<wchar_t,std::char_traits<wchar_t>_> basic_streambuf<wchar_t,std::char_traits<wchar_t>_>, *Pbasic_streambuf<wchar_t,std::char_traits<wchar_t>_>;

struct basic_streambuf<wchar_t,std::char_traits<wchar_t>_> { /* PlaceHolder Structure */
};

typedef struct basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>, *Pbasic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_>;

struct basic_streambuf<wchar_t,struct_std::char_traits<wchar_t>_> { /* PlaceHolder Structure */
};

typedef struct CLIENT_ID CLIENT_ID, *PCLIENT_ID;

struct CLIENT_ID {
    void *UniqueProcess;
    void *UniqueThread;
};

typedef struct codecvt<char,char,int> codecvt<char,char,int>, *Pcodecvt<char,char,int>;

struct codecvt<char,char,int> { /* PlaceHolder Structure */
};

typedef struct codecvt_base codecvt_base, *Pcodecvt_base;

struct codecvt_base { /* PlaceHolder Structure */
};

typedef enum ConcRT_EventType {
} ConcRT_EventType;

typedef struct CRefTime CRefTime, *PCRefTime;

struct CRefTime { /* PlaceHolder Structure */
};

typedef struct ctype<wchar_t> ctype<wchar_t>, *Pctype<wchar_t>;

struct ctype<wchar_t> { /* PlaceHolder Structure */
};

typedef struct DotNetPdbInfo DotNetPdbInfo, *PDotNetPdbInfo;

struct DotNetPdbInfo {
    char signature[4];
    GUID guid;
    dword age;
    char pdbpath[49];
};

typedef int errno_t;

typedef struct exception exception, *Pexception;

struct exception { /* PlaceHolder Structure */
};

typedef struct _EXCEPTION_POINTERS EXCEPTION_POINTERS;

typedef struct facet facet, *Pfacet;

struct facet { /* PlaceHolder Structure */
};

typedef int (*FARPROC)(void);

typedef struct _iobuf FILE;

typedef enum FILL {
} FILL;

typedef struct fpos<int> fpos<int>, *Pfpos<int>;

struct fpos<int> { /* PlaceHolder Structure */
};

typedef longlong fpos_t;

typedef struct _s_FuncInfo FuncInfo;

typedef enum _GET_FILEEX_INFO_LEVELS GET_FILEEX_INFO_LEVELS;


/* WARNING! conflicting data type names: /guiddef.h/GUID - /GUID */

typedef struct HBRUSH__ HBRUSH__, *PHBRUSH__;

typedef struct HBRUSH__ *HBRUSH;

struct HBRUSH__ {
    int unused;
};

typedef struct HICON__ HICON__, *PHICON__;

typedef struct HICON__ *HICON;

typedef HICON HCURSOR;

struct HICON__ {
    int unused;
};

typedef struct HINSTANCE__ HINSTANCE__, *PHINSTANCE__;

typedef struct HINSTANCE__ *HINSTANCE;

struct HINSTANCE__ {
    int unused;
};

typedef HANDLE HLOCAL;

typedef struct HMENU__ HMENU__, *PHMENU__;

typedef struct HMENU__ *HMENU;

struct HMENU__ {
    int unused;
};

typedef HINSTANCE HMODULE;

typedef long HRESULT;

typedef struct HWND__ HWND__, *PHWND__;

typedef struct HWND__ *HWND;

struct HWND__ {
    int unused;
};

typedef struct id id, *Pid;

struct id { /* PlaceHolder Structure */
};

typedef GUID IID;

typedef struct IMAGE_BASE_RELOCATION IMAGE_BASE_RELOCATION, *PIMAGE_BASE_RELOCATION;

struct IMAGE_BASE_RELOCATION {
    dword VirtualAddress;
    dword SizeOfBlock;
};

typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

struct IMAGE_DATA_DIRECTORY {
    ImageBaseOffset32 VirtualAddress;
    dword Size;
};

typedef struct IMAGE_DEBUG_DIRECTORY IMAGE_DEBUG_DIRECTORY, *PIMAGE_DEBUG_DIRECTORY;

struct IMAGE_DEBUG_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    dword Type;
    dword SizeOfData;
    dword AddressOfRawData;
    dword PointerToRawData;
};

typedef struct IMAGE_DOS_HEADER IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

struct IMAGE_DOS_HEADER {
    char e_magic[2]; /* Magic number */
    word e_cblp; /* Bytes of last page */
    word e_cp; /* Pages in file */
    word e_crlc; /* Relocations */
    word e_cparhdr; /* Size of header in paragraphs */
    word e_minalloc; /* Minimum extra paragraphs needed */
    word e_maxalloc; /* Maximum extra paragraphs needed */
    word e_ss; /* Initial (relative) SS value */
    word e_sp; /* Initial SP value */
    word e_csum; /* Checksum */
    word e_ip; /* Initial IP value */
    word e_cs; /* Initial (relative) CS value */
    word e_lfarlc; /* File address of relocation table */
    word e_ovno; /* Overlay number */
    word e_res[4][4]; /* Reserved words */
    word e_oemid; /* OEM identifier (for e_oeminfo) */
    word e_oeminfo; /* OEM information; e_oemid specific */
    word e_res2[10][10]; /* Reserved words */
    dword e_lfanew; /* File address of new exe header */
    byte e_program[64]; /* Actual DOS program */
};

typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

struct IMAGE_FILE_HEADER {
    word Machine; /* 332 */
    word NumberOfSections;
    dword TimeDateStamp;
    dword PointerToSymbolTable;
    dword NumberOfSymbols;
    word SizeOfOptionalHeader;
    word Characteristics;
};

typedef struct IMAGE_LOAD_CONFIG_DIRECTORY32 IMAGE_LOAD_CONFIG_DIRECTORY32, *PIMAGE_LOAD_CONFIG_DIRECTORY32;

struct IMAGE_LOAD_CONFIG_DIRECTORY32 {
    dword Size;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    dword GlobalFlagsClear;
    dword GlobalFlagsSet;
    dword CriticalSectionDefaultTimeout;
    dword DeCommitFreeBlockThreshold;
    dword DeCommitTotalFreeThreshold;
    pointer32 LockPrefixTable;
    dword MaximumAllocationSize;
    dword VirtualMemoryThreshold;
    dword ProcessHeapFlags;
    dword ProcessAffinityMask;
    word CsdVersion;
    word DependentLoadFlags;
    pointer32 EditList;
    pointer32 SecurityCookie;
    pointer32 SEHandlerTable;
    dword SEHandlerCount;
};

typedef struct IMAGE_NT_HEADERS32 IMAGE_NT_HEADERS32, *PIMAGE_NT_HEADERS32;

typedef struct IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;

struct IMAGE_OPTIONAL_HEADER32 {
    word Magic;
    byte MajorLinkerVersion;
    byte MinorLinkerVersion;
    dword SizeOfCode;
    dword SizeOfInitializedData;
    dword SizeOfUninitializedData;
    ImageBaseOffset32 AddressOfEntryPoint;
    ImageBaseOffset32 BaseOfCode;
    ImageBaseOffset32 BaseOfData;
    pointer32 ImageBase;
    dword SectionAlignment;
    dword FileAlignment;
    word MajorOperatingSystemVersion;
    word MinorOperatingSystemVersion;
    word MajorImageVersion;
    word MinorImageVersion;
    word MajorSubsystemVersion;
    word MinorSubsystemVersion;
    dword Win32VersionValue;
    dword SizeOfImage;
    dword SizeOfHeaders;
    dword CheckSum;
    word Subsystem;
    word DllCharacteristics;
    dword SizeOfStackReserve;
    dword SizeOfStackCommit;
    dword SizeOfHeapReserve;
    dword SizeOfHeapCommit;
    dword LoaderFlags;
    dword NumberOfRvaAndSizes;
    struct IMAGE_DATA_DIRECTORY DataDirectory[16];
};

struct IMAGE_NT_HEADERS32 {
    char Signature[4];
    struct IMAGE_FILE_HEADER FileHeader;
    struct IMAGE_OPTIONAL_HEADER32 OptionalHeader;
};

typedef struct IMAGE_RESOURCE_DATA_ENTRY IMAGE_RESOURCE_DATA_ENTRY, *PIMAGE_RESOURCE_DATA_ENTRY;

struct IMAGE_RESOURCE_DATA_ENTRY {
    dword OffsetToData;
    dword Size;
    dword CodePage;
    dword Reserved;
};

typedef struct IMAGE_RESOURCE_DIRECTORY IMAGE_RESOURCE_DIRECTORY, *PIMAGE_RESOURCE_DIRECTORY;

struct IMAGE_RESOURCE_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    word NumberOfNamedEntries;
    word NumberOfIdEntries;
};

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY IMAGE_RESOURCE_DIRECTORY_ENTRY, *PIMAGE_RESOURCE_DIRECTORY_ENTRY;

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion;

typedef union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion;

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;

typedef struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct, *PIMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct {
    dword NameOffset:31;
    dword NameIsString:1;
};

union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion {
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct;
    dword Name;
    word Id;
};

struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct {
    dword OffsetToDirectory:31;
    dword DataIsDirectory:1;
};

union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion {
    dword OffsetToData;
    struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct;
};

struct IMAGE_RESOURCE_DIRECTORY_ENTRY {
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_NameUnion NameUnion;
    union IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryUnion DirectoryUnion;
};

typedef struct IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

typedef union Misc Misc, *PMisc;

typedef enum SectionFlags {
    IMAGE_SCN_TYPE_NO_PAD=8,
    IMAGE_SCN_RESERVED_0001=16,
    IMAGE_SCN_CNT_CODE=32,
    IMAGE_SCN_CNT_INITIALIZED_DATA=64,
    IMAGE_SCN_CNT_UNINITIALIZED_DATA=128,
    IMAGE_SCN_LNK_OTHER=256,
    IMAGE_SCN_LNK_INFO=512,
    IMAGE_SCN_RESERVED_0040=1024,
    IMAGE_SCN_LNK_REMOVE=2048,
    IMAGE_SCN_LNK_COMDAT=4096,
    IMAGE_SCN_GPREL=32768,
    IMAGE_SCN_MEM_16BIT=131072,
    IMAGE_SCN_MEM_PURGEABLE=131072,
    IMAGE_SCN_MEM_LOCKED=262144,
    IMAGE_SCN_MEM_PRELOAD=524288,
    IMAGE_SCN_ALIGN_1BYTES=1048576,
    IMAGE_SCN_ALIGN_2BYTES=2097152,
    IMAGE_SCN_ALIGN_4BYTES=3145728,
    IMAGE_SCN_ALIGN_8BYTES=4194304,
    IMAGE_SCN_ALIGN_16BYTES=5242880,
    IMAGE_SCN_ALIGN_32BYTES=6291456,
    IMAGE_SCN_ALIGN_64BYTES=7340032,
    IMAGE_SCN_ALIGN_128BYTES=8388608,
    IMAGE_SCN_ALIGN_256BYTES=9437184,
    IMAGE_SCN_ALIGN_512BYTES=10485760,
    IMAGE_SCN_ALIGN_1024BYTES=11534336,
    IMAGE_SCN_ALIGN_2048BYTES=12582912,
    IMAGE_SCN_ALIGN_4096BYTES=13631488,
    IMAGE_SCN_ALIGN_8192BYTES=14680064,
    IMAGE_SCN_LNK_NRELOC_OVFL=16777216,
    IMAGE_SCN_MEM_DISCARDABLE=33554432,
    IMAGE_SCN_MEM_NOT_CACHED=67108864,
    IMAGE_SCN_MEM_NOT_PAGED=134217728,
    IMAGE_SCN_MEM_SHARED=268435456,
    IMAGE_SCN_MEM_EXECUTE=536870912,
    IMAGE_SCN_MEM_READ=1073741824,
    IMAGE_SCN_MEM_WRITE=2147483648
} SectionFlags;

union Misc {
    dword PhysicalAddress;
    dword VirtualSize;
};

struct IMAGE_SECTION_HEADER {
    char Name[8];
    union Misc Misc;
    ImageBaseOffset32 VirtualAddress;
    dword SizeOfRawData;
    dword PointerToRawData;
    dword PointerToRelocations;
    dword PointerToLinenumbers;
    word NumberOfRelocations;
    word NumberOfLinenumbers;
    enum SectionFlags Characteristics;
};

typedef struct ios_base ios_base, *Pios_base;

struct ios_base { /* PlaceHolder Structure */
};

typedef struct IUnknown IUnknown, *PIUnknown;

typedef struct IUnknownVtbl IUnknownVtbl, *PIUnknownVtbl;

typedef DWORD ULONG;

struct IUnknownVtbl {
    HRESULT (*QueryInterface)(struct IUnknown *, IID *, void **);
    ULONG (*AddRef)(struct IUnknown *);
    ULONG (*Release)(struct IUnknown *);
};

struct IUnknown {
    struct IUnknownVtbl *lpVtbl;
};

typedef union _LARGE_INTEGER LARGE_INTEGER;

typedef struct locale locale, *Plocale;

struct locale { /* PlaceHolder Structure */
};

typedef long LONG_PTR;

typedef LONG_PTR LPARAM;

typedef BOOL *LPBOOL;

typedef struct _RTL_CRITICAL_SECTION *PRTL_CRITICAL_SECTION;

typedef PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;

typedef CHAR *LPCSTR;

typedef void *LPCVOID;

typedef wchar_t WCHAR;

typedef WCHAR *LPCWSTR;

typedef DWORD *LPDWORD;

typedef struct _FILETIME *LPFILETIME;

typedef struct tagMSG tagMSG, *PtagMSG;

typedef struct tagMSG *LPMSG;

typedef uint UINT;

typedef uint UINT_PTR;

typedef UINT_PTR WPARAM;

typedef struct tagPOINT tagPOINT, *PtagPOINT;

typedef struct tagPOINT POINT;

struct tagPOINT {
    LONG x;
    LONG y;
};

struct tagMSG {
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
};

typedef struct _OSVERSIONINFOA *LPOSVERSIONINFOA;

typedef struct _OVERLAPPED *LPOVERLAPPED;

typedef struct tagPOINT *LPPOINT;

typedef struct tagRECT tagRECT, *PtagRECT;

typedef struct tagRECT *LPRECT;

struct tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
};

typedef struct _SECURITY_ATTRIBUTES *LPSECURITY_ATTRIBUTES;

typedef CHAR *LPSTR;

typedef struct _SYSTEM_INFO *LPSYSTEM_INFO;

typedef struct _SYSTEMTIME *LPSYSTEMTIME;

typedef LONG (*PTOP_LEVEL_EXCEPTION_FILTER)(struct _EXCEPTION_POINTERS *);

typedef PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

typedef struct IUnknown *LPUNKNOWN;

typedef WCHAR *LPWSTR;

typedef LONG_PTR LRESULT;

typedef struct missing_wait missing_wait, *Pmissing_wait;

struct missing_wait { /* PlaceHolder Structure */
};

typedef UINT MMRESULT;

typedef struct tagMSG MSG;

typedef struct pair<unsigned___int64,unsigned___int64> pair<unsigned___int64,unsigned___int64>, *Ppair<unsigned___int64,unsigned___int64>;

struct pair<unsigned___int64,unsigned___int64> { /* PlaceHolder Structure */
};

typedef BYTE *PBYTE;

typedef struct _IMAGE_SECTION_HEADER *PIMAGE_SECTION_HEADER;

typedef LONG *PLONG;

typedef uint size_t;

typedef size_t rsize_t;

typedef struct _s__RTTICompleteObjectLocator RTTICompleteObjectLocator;

typedef ULONG_PTR SIZE_T;

typedef struct _SYSTEMTIME SYSTEMTIME;

typedef struct tagWNDCLASSW tagWNDCLASSW, *PtagWNDCLASSW;

typedef LRESULT (*WNDPROC)(HWND, UINT, WPARAM, LPARAM);

struct tagWNDCLASSW {
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
};

typedef struct _s_ThrowInfo ThrowInfo;

typedef struct tm tm, *Ptm;

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

typedef struct type_info type_info, *Ptype_info;

struct type_info { /* PlaceHolder Structure */
};

typedef uint uintptr_t;

typedef char *va_list;

typedef struct tagWNDCLASSW WNDCLASSW;


#endif
