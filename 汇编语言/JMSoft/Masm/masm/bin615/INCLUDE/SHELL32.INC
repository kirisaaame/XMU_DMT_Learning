  ; ===========================================
  ; shell32.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF SHELL32_INC
SHELL32_INC equ <1>

CheckEscapesA PROTO :DWORD,:DWORD
CheckEscapes equ <CheckEscapesA>

CheckEscapesW PROTO :DWORD,:DWORD
CommandLineToArgvW PROTO :DWORD,:DWORD
DoEnvironmentSubstA PROTO :DWORD,:DWORD
DoEnvironmentSubst equ <DoEnvironmentSubstA>

DoEnvironmentSubstW PROTO :DWORD,:DWORD
DragAcceptFiles PROTO :DWORD,:DWORD
DragFinish PROTO :DWORD
DragQueryFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD
DragQueryFile equ <DragQueryFileA>

DragQueryFileAorW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DragQueryFileW PROTO :DWORD,:DWORD,:DWORD,:DWORD
DragQueryPoint PROTO :DWORD,:DWORD
DuplicateIcon PROTO :DWORD,:DWORD
ExtractAssociatedIconA PROTO :DWORD,:DWORD,:DWORD
ExtractAssociatedIcon equ <ExtractAssociatedIconA>

ExtractAssociatedIconExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ExtractAssociatedIconEx equ <ExtractAssociatedIconExA>

ExtractAssociatedIconExW PROTO :DWORD,:DWORD,:DWORD,:DWORD
ExtractAssociatedIconW PROTO :DWORD,:DWORD,:DWORD
ExtractIconA PROTO :DWORD,:DWORD,:DWORD
ExtractIcon equ <ExtractIconA>

ExtractIconExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ExtractIconEx equ <ExtractIconExA>

ExtractIconExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ExtractIconResInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ExtractIconResInfo equ <ExtractIconResInfoA>

ExtractIconResInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ExtractIconW PROTO :DWORD,:DWORD,:DWORD
ExtractVersionResource16W PROTO :DWORD,:DWORD
FindExeDlgProc PROTO :DWORD,:DWORD,:DWORD,:DWORD
FindExecutableA PROTO :DWORD,:DWORD,:DWORD
FindExecutable equ <FindExecutableA>

FindExecutableW PROTO :DWORD,:DWORD,:DWORD
FreeIconList PROTO :DWORD,:DWORD
InternalExtractIconListA PROTO :DWORD,:DWORD,:DWORD
InternalExtractIconList equ <InternalExtractIconListA>

InternalExtractIconListW PROTO :DWORD,:DWORD,:DWORD
RealShellExecuteA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RealShellExecute equ <RealShellExecuteA>

RealShellExecuteExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RealShellExecuteEx equ <RealShellExecuteExA>

RealShellExecuteExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RealShellExecuteW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RegenerateUserEnvironment PROTO :DWORD,:DWORD
SHAddToRecentDocs PROTO :DWORD,:DWORD
SHAppBarMessage PROTO :DWORD,:DWORD
SHBindToParent PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHBrowseForFolderA PROTO :DWORD
SHBrowseForFolder equ <SHBrowseForFolderA>

SHBrowseForFolderW PROTO :DWORD
SHChangeNotify PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHChangeNotifySuspendResume PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHCreateDirectoryExA PROTO :DWORD,:DWORD,:DWORD
SHCreateDirectoryEx equ <SHCreateDirectoryExA>

SHCreateDirectoryExW PROTO :DWORD,:DWORD,:DWORD
SHCreateProcessAsUserW PROTO :DWORD
SHEmptyRecycleBinA PROTO :DWORD,:DWORD,:DWORD
SHEmptyRecycleBin equ <SHEmptyRecycleBinA>

SHEmptyRecycleBinW PROTO :DWORD,:DWORD,:DWORD
SHExtractIconsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHFileOperationA PROTO :DWORD
SHFileOperation equ <SHFileOperationA>

SHFileOperationW PROTO :DWORD
SHFormatDrive PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHFreeNameMappings PROTO :DWORD
SHGetDataFromIDListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHGetDataFromIDList equ <SHGetDataFromIDListA>

SHGetDataFromIDListW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHGetDesktopFolder PROTO :DWORD
SHGetDiskFreeSpaceA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHGetDiskFreeSpace equ <SHGetDiskFreeSpaceA>

SHGetDiskFreeSpaceExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHGetDiskFreeSpaceEx equ <SHGetDiskFreeSpaceExA>

SHGetDiskFreeSpaceExW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHGetFileInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHGetFileInfo equ <SHGetFileInfoA>

SHGetFileInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHGetFolderLocation PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHGetFolderPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHGetFolderPath equ <SHGetFolderPathA>

SHGetFolderPathW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHGetIconOverlayIndexA PROTO :DWORD,:DWORD
SHGetIconOverlayIndex equ <SHGetIconOverlayIndexA>

SHGetIconOverlayIndexW PROTO :DWORD,:DWORD
SHGetInstanceExplorer PROTO :DWORD
SHGetMalloc PROTO :DWORD
SHGetNewLinkInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHGetNewLinkInfo equ <SHGetNewLinkInfoA>

SHGetNewLinkInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHGetPathFromIDListA PROTO :DWORD,:DWORD
SHGetPathFromIDList equ <SHGetPathFromIDListA>

SHGetPathFromIDListW PROTO :DWORD,:DWORD
SHGetSettings PROTO :DWORD,:DWORD
SHGetSpecialFolderLocation PROTO :DWORD,:DWORD,:DWORD
SHGetSpecialFolderPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHGetSpecialFolderPath equ <SHGetSpecialFolderPathA>

SHGetSpecialFolderPathW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHInvokePrinterCommandA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHInvokePrinterCommand equ <SHInvokePrinterCommandA>

SHInvokePrinterCommandW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SHIsFileAvailableOffline PROTO :DWORD,:DWORD
SHLoadInProc PROTO :DWORD
SHLoadNonloadedIconOverlayIdentifiers PROTO 
SHPathPrepareForWriteA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHPathPrepareForWrite equ <SHPathPrepareForWriteA>

SHPathPrepareForWriteW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SHQueryRecycleBinA PROTO :DWORD,:DWORD
SHQueryRecycleBin equ <SHQueryRecycleBinA>

SHQueryRecycleBinW PROTO :DWORD,:DWORD
SHUpdateRecycleBinIcon PROTO 
SheChangeDirA PROTO :DWORD
SheChangeDir equ <SheChangeDirA>

SheChangeDirExA PROTO :DWORD
SheChangeDirEx equ <SheChangeDirExA>

SheChangeDirExW PROTO :DWORD
SheChangeDirW PROTO :DWORD
SheConvertPathW PROTO :DWORD,:DWORD,:DWORD
SheFullPathA PROTO :DWORD,:DWORD,:DWORD
SheFullPath equ <SheFullPathA>

SheFullPathW PROTO :DWORD,:DWORD,:DWORD
SheGetCurDrive PROTO 
SheGetDirA PROTO :DWORD,:DWORD
SheGetDir equ <SheGetDirA>

SheGetDirExW PROTO :DWORD,:DWORD,:DWORD
SheGetDirW PROTO :DWORD,:DWORD
SheGetPathOffsetW PROTO :DWORD
SheRemoveQuotesA PROTO :DWORD
SheRemoveQuotes equ <SheRemoveQuotesA>

SheRemoveQuotesW PROTO :DWORD
SheSetCurDrive PROTO :DWORD
SheShortenPathA PROTO :DWORD,:DWORD
SheShortenPath equ <SheShortenPathA>

SheShortenPathW PROTO :DWORD,:DWORD
ShellAboutA PROTO :DWORD,:DWORD,:DWORD,:DWORD
ShellAbout equ <ShellAboutA>

ShellAboutW PROTO :DWORD,:DWORD,:DWORD,:DWORD
ShellExecuteA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ShellExecute equ <ShellExecuteA>

ShellExecuteExA PROTO :DWORD
ShellExecuteEx equ <ShellExecuteExA>

ShellExecuteExW PROTO :DWORD
ShellExecuteW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ShellHookProc PROTO :DWORD,:DWORD,:DWORD
Shell_NotifyIconA PROTO :DWORD,:DWORD
Shell_NotifyIcon equ <Shell_NotifyIconA>

Shell_NotifyIconW PROTO :DWORD,:DWORD
WOWShellExecute PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
_WOWShellExecute PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file shell32.inc
echo -----------------------------------------
ENDIF
