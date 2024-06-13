comment * ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
           Include file for procedures in the MASM32 library
          ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл *


IFNDEF MASM32_INC
MASM32_INC equ <1>

; for both --> arg num, buffer
ArgCl  PROTO :DWORD,:DWORD   ; GUI mode version
ArgClC PROTO :DWORD,:DWORD   ; console mode version

GetCL       PROTO :DWORD,:DWORD ; 128 byte buffer version
getcl_ex    PROTO :DWORD,:DWORD ; unlimited size version

Alloc       PROTO :DWORD
Free        PROTO :DWORD

comment * --------------------------
        numeric and text conversions
        ---------------------------- *
a2dw   PROTO :DWORD
atodw  PROTO :DWORD          ; return value in eax
htodw  PROTO :DWORD          ; return value in eax
dwtoa  PROTO :DWORD,:DWORD   ; value - buffer
dw2a   PROTO :DWORD,:DWORD
dw2hex PROTO :DWORD,:DWORD

ustr2dw PROTO :DWORD
udw2str PROTO :DWORD,:DWORD

GetErrDescription PROTO :DWORD

comment * -----------------------------------
        string and floating point conversions
        ------------------------------------- *
FloatToStr  proto stdcall fpin:QWORD, szDbl:PTR CHAR
FloatToStr2	proto	stdcall fpin:QWORD, szDbl:PTR CHAR
StrToFloat	proto	stdcall szIn:PTR BYTE, fpout:PTR DWORD

comment * ---------------
        search algorithms
        ----------------- *
InString  PROTO :DWORD,:DWORD,:DWORD ; StartPos - lpszString - lpszSubStr
BinSearch PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD      ; classic scanner

; Boyer Moore based algorithms
; ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
BMBinSearch  PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD   ; complete BM
BMHBinsearch PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD   ; horspool variation
SBMBinSearch PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD   ; simplified version
WordCount    PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

comment * ---------------------------
        encryption algorithms for
        "one shot" or "one pass" pads
        ----------------------------- *
XorData PROTO :DWORD,:DWORD,:DWORD,:DWORD
RolData PROTO :DWORD,:DWORD,:DWORD,:DWORD
RorData PROTO :DWORD,:DWORD,:DWORD,:DWORD

StrLen PROTO :DWORD ; Agner Fog's high speed string length algo

comment * ------------------------------------
        zero terminated string procedures have
        been renamed for consistency. Equates
        to the old names are below.
        -------------------------------------- *

    szappend    PROTO :DWORD,:DWORD,:DWORD
    szCatStr    PROTO :DWORD,:DWORD
    szCmp       PROTO :DWORD,:DWORD
    szCmpi      PROTO :DWORD,:DWORD,:DWORD
    Cmpi        PROTO :DWORD,:DWORD
    szCopy      PROTO :DWORD,:DWORD
    szLeft      PROTO :DWORD,:DWORD,:DWORD
    szLen       PROTO :DWORD
    szLower     PROTO :DWORD
    szLtrim     PROTO :DWORD,:DWORD
    szMid       PROTO :DWORD,:DWORD,:DWORD,:DWORD
    szMultiCat  PROTO C :DWORD,:DWORD,:VARARG
    szMonoSpace PROTO :DWORD
    szRemove    PROTO :DWORD,:DWORD,:DWORD
    szRep       PROTO :DWORD,:DWORD,:DWORD,:DWORD
    szRev       PROTO :DWORD,:DWORD
    szRight     PROTO :DWORD,:DWORD,:DWORD
    szRtrim     PROTO :DWORD,:DWORD
    szTrim      PROTO :DWORD
    szUpper     PROTO :DWORD
    szWcnt      PROTO :DWORD,:DWORD

comment * ---------------------------------
        the equates for the old names must
        be put after the prototypes for the
        procedures they are mapped to.
        ----------------------------------- *

    lnstr   equ <szLen>
    cmpstr  equ <szCmp>
    cmpsi   equ <szCmpi>
    revstr  equ <szRev>
    lcase   equ <szLower>
    ucase   equ <szUpper>
    ltrim   equ <szLtrim>
    rtrim   equ <szRtrim>
    trim    equ <szTrim>
    lstr    equ <szLeft>
    rstr    equ <szRight>
    midstr  equ <szMid>

; ---------------------------------
; self contained "shell" procedures
; ---------------------------------
shell       PROTO :DWORD                ; failsafe version
shell_ex    PROTO :DWORD,:DWORD         ; version with priority control

StripRangeI PROTO :DWORD,:DWORD,:BYTE,:BYTE
StripRangeX PROTO :DWORD,:DWORD,:BYTE,:BYTE

MemCopy PROTO :DWORD,:DWORD,:DWORD  ; source - dest - length
memfill PROTO :DWORD,:DWORD,:DWORD

GetAppPath   PROTO :DWORD     ; buffer has app path
NameFromPath PROTO :DWORD,:DWORD
GetPathOnly  PROTO :DWORD,:DWORD

exist       PROTO :DWORD
filesize    PROTO :DWORD

FrameCtrl   PROTO :DWORD,:DWORD,:DWORD,:DWORD
FrameWindow PROTO :DWORD,:DWORD,:DWORD,:DWORD
FrameGrp    PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

Frame3D PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
line    PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
circle  PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

DisplayBmp   PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DisplayIcon  PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
VerticalTile PROTO :DWORD,:DWORD,:DWORD
SetBMcolor   PROTO :DWORD,:DWORD

BmpButton    PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

StdOut       PROTO :DWORD
StdErr       PROTO :DWORD
StdIn        PROTO :DWORD,:DWORD
locate       PROTO :DWORD,:DWORD
ClearScreen  PROTO
StripLF      PROTO :DWORD
wait_key     PROTO
ret_key      PROTO

BrowseForFolder PROTO :DWORD,:DWORD,:DWORD,:DWORD
FontDialog      PROTO :DWORD,:DWORD,:DWORD
ColorDialog     PROTO :DWORD,:DWORD,:DWORD
PageSetupDialog PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PrintDialog     PROTO :DWORD,:DWORD,:DWORD

Read_File_In    PROTO :DWORD,:DWORD
ofCallBack      PROTO :DWORD,:DWORD,:DWORD,:DWORD
Write_To_Disk   PROTO :DWORD,:DWORD
sfCallBack      PROTO :DWORD,:DWORD,:DWORD,:DWORD
RichEd1         PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
RichEd2         PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

GetPercent      PROTO :DWORD,:DWORD
IntMul          PROTO :DWORD,:DWORD
IntDiv          PROTO :DWORD,:DWORD
IntSqrt         PROTO :DWORD

nrandom         PROTO :DWORD
nseed           PROTO :DWORD

; ---------------------------------
; prototypes for pre-built dialogs
; ---------------------------------
GetTextInput    PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AboutBox        PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetFile         PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LoadList        PROTO :DWORD,:DWORD
IPtoString      PROTO :DWORD,:DWORD
GetIP           PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

; ----------------------------------------
; Ernie Murphy's image loading procedures
; ----------------------------------------
comment * ---------------------------------------------------------------
With functions BitmapFromMemory, BitmapFromFile and BitmapFromResource
the statements :
        invoke CoInitialize, NULL   ; at the beginning of the source code
        invoke CoUninitialize       ; at the end of the source code
should be included to initialize and uninitiaize COM
        --------------------------------------------------------------- *
BitmapFromFile          PROTO :DWORD
BitmapFromMemory        PROTO :DWORD,:DWORD
BitmapFromPicture       PROTO :DWORD
BitmapFromResource      PROTO :DWORD,:DWORD

; -------------------
; file IO procedures
; -------------------
read_disk_file  PROTO :DWORD,:DWORD,:DWORD
write_disk_file PROTO :DWORD,:DWORD,:DWORD

; ------------------------------
; memory mapped file procedures
; ------------------------------
CloseMMF  PROTO :DWORD,:DWORD
CreateMMF PROTO :DWORD,:DWORD,:DWORD,:DWORD

; ----------------
; sort procedures
; ----------------
nrQsortA PROTO :DWORD,:DWORD
nrQsortD PROTO :DWORD,:DWORD

CombSortA PROTO :DWORD,:DWORD
CombSortD PROTO :DWORD,:DWORD

testreg PROTO

HexDump   PROTO :DWORD,:DWORD,:DWORD
AsciiDump PROTO :DWORD,:DWORD,:DWORD

; ------------------------------------------
; ascii and 32 bit long integer conversions
; ------------------------------------------
atol PROTO :DWORD
ltoa PROTO :DWORD,:DWORD

; ----------------------------
; File open and close dialogs
; ----------------------------
OpenFileDialog PROTO :DWORD, :DWORD, :DWORD, :DWORD
SaveFileDialog PROTO :DWORD, :DWORD, :DWORD, :DWORD

; ------------------
; ascii to wide char
; ------------------
a2wc        PROTO :DWORD

; ---------------------------
; array arithmetic procedures
; ---------------------------
arr_add PROTO :DWORD,:DWORD,:DWORD
arr_mul PROTO :DWORD,:DWORD,:DWORD
arr_sub PROTO :DWORD,:DWORD,:DWORD

; -------------------
; create dynamic aray
; -------------------
create_array PROTO :DWORD,:DWORD

; ----------------------------------------------------
; count all bytes in a file and write results to array
; ----------------------------------------------------
byte_count  PROTO :DWORD,:DWORD,:DWORD

; -----------------------------------------------------
; load list box with formatted drive and volume strings
; -----------------------------------------------------
load_drives PROTO :DWORD

  ; -------------------------------------
  ; C style character testing procedures.
  ; -------------------------------------
    isalpha  PROTO :BYTE
    isupper  PROTO :BYTE
    islower  PROTO :BYTE
    isnumber PROTO :BYTE
    isalphanum PROTO :BYTE

  ; ---------------------------------
  ; hybrid quick / cisort string sort
  ; ---------------------------------
    assort   PROTO :DWORD,:DWORD,:DWORD
    dssort   PROTO :DWORD,:DWORD,:DWORD

  ; --------------------------------------------------
  ; high speed quick sort with recursion depth limiter
  ; This algorithm is used by the above hybrid.
  ; --------------------------------------------------
    asqsort  PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
    dsqsort  PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD

  ; -----------------------------------------------------
  ; comb / insertion sort hybrid used by the above hybrid.
  ; -----------------------------------------------------
    acisort PROTO :DWORD,:DWORD
    dcisort PROTO :DWORD,:DWORD

  ; -----------------------------------
  ; insertion sort for the above hybrid
  ; -----------------------------------
    aissort PROTO :DWORD,:DWORD
    dissort PROTO :DWORD,:DWORD
                                                                                                        
  ; ----------------------------------------------
  ; high safety margin comb / cocktail shaker sort
  ; ----------------------------------------------
    ccsorta  PROTO :DWORD,:DWORD
    ccsortd  PROTO :DWORD,:DWORD

  ; -----------------
  ; Quick string sort
  ; -----------------
    qssorta  PROTO :DWORD,:DWORD,:DWORD
    qssortd  PROTO :DWORD,:DWORD,:DWORD

  ; -----------------
  ; Shell string sort
  ; -----------------
    ssorta   PROTO :DWORD,:DWORD,:DWORD
    ssortd   PROTO :DWORD,:DWORD,:DWORD

  ; ----------------
  ; Comb string sort
  ; ----------------
    cstsorta PROTO :DWORD,:DWORD
    cstsortd PROTO :DWORD,:DWORD

  ; -----------------------
  ; traditional bubble sort
  ; -----------------------
    bstsorta PROTO :DWORD,:DWORD,:DWORD
    bstsortd PROTO :DWORD,:DWORD,:DWORD

  ; -----------------------------------------------
  ; read and write lines of text to and from memory
  ; -----------------------------------------------
    readline   PROTO :DWORD,:DWORD,:DWORD
    writeline  PROTO :DWORD,:DWORD,:DWORD,:DWORD
    tstline    PROTO :DWORD
    parse_line PROTO :DWORD,:DWORD
    lfcnt      PROTO :DWORD

  ; -------------------------
  ; UNICODE string procedures
  ; -------------------------
    ucCatStr  PROTO :DWORD,:DWORD
    ucCopy    PROTO :DWORD,:DWORD
    ucCmp     PROTO :DWORD,:DWORD
    ucLen     PROTO :DWORD
    ucLeft    PROTO :DWORD,:DWORD,:DWORD
    ucMid     PROTO :DWORD,:DWORD,:DWORD,:DWORD
    ucRight   PROTO :DWORD,:DWORD,:DWORD
    ucLtrim   PROTO :DWORD,:DWORD
    ucRtrim   PROTO :DWORD,:DWORD
    ucLower   PROTO :DWORD
    ucUpper   PROTO :DWORD
    ucRev     PROTO :DWORD,:DWORD
    ucMultiCat PROTO C :DWORD,:DWORD,:VARARG
    ucFind    PROTO :DWORD,:DWORD,:DWORD
    ucOpenFileDialog PROTO :DWORD,:DWORD,:DWORD,:DWORD
    ucSaveFileDialog PROTO :DWORD,:DWORD,:DWORD,:DWORD

  ; ------------------
  ; whole word replace
  ; ------------------
    wordreplace PROTO :DWORD,:DWORD,:DWORD,:DWORD

  ; ------------------------------
  ; extended performance functions
  ; ------------------------------
    atodw_ex      PROTO :DWORD
    byt2bin_ex    PROTO :BYTE,:DWORD
    wrd2bin_ex    PROTO :WORD,:DWORD
    dw2bin_ex     PROTO :DWORD,:DWORD
    bin2byte_ex   PROTO :DWORD
    dw2hex_ex     PROTO :DWORD,:DWORD
    hexflip32     PROTO :DWORD

  ; -----------------------------------
  ; high speed binary / hex conversions
  ; -----------------------------------
    bin2hex       PROTO :DWORD,:DWORD,:DWORD
    hex2bin       PROTO :DWORD,:DWORD

  ; --------------------------
  ; additional shell functions
  ; --------------------------
    wshell        PROTO :DWORD

  ; -------------------------------------
  ; compare memory blocks of known length
  ; -------------------------------------
    cmpmem PROTO :DWORD,:DWORD,:DWORD

  ; ---------------------------------------------------------
  ; structure and prototype for running a synchronous process
  ; ---------------------------------------------------------
    RUN_SYNCH_PROCESS_EX STRUCT
      priority dd ?       ; priority setting
      timeout  dd ?       ; timeout interval
      rvcreate dd ?       ; CreateProcess() return value
      exitcode dd ?       ; GetExitCodeProcess() exit code
      rvwait   dd ?       ; WaitForSingleObjectEx() return value
    RUN_SYNCH_PROCESS_EX ENDS

    run_synch_process_ex PROTO :DWORD,:DWORD

  ; -----------------------------------------------
  ; return the font handle from a CreateFont() call
  ; -----------------------------------------------
    RetFontHandle PROTO :DWORD,:DWORD,:DWORD

    ArgByNumber PROTO :DWORD,:DWORD,:DWORD,:DWORD
    get_ml      PROTO :DWORD,:DWORD,:DWORD
    decomment   PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file masm32.inc
echo -----------------------------------------
ENDIF
