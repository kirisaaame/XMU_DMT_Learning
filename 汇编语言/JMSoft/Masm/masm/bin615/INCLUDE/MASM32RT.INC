comment * ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл

    The MASM32 Runtime Library include file.

    Differing from most compilers, MASM does not contain any built in
    run time library so it is difficult for a programmer starting with
    MASM to to get any code up and running without having to learn a lot
    of extra information just to do basic things.
    
    This file simplifies entry into assembler programming by making the
    full capacity of the MASM32 library, macro system and include files
    available to programmers undertaking this quest.

    It specifies the normal conditions for building a 32 bit Windows
    program with the minimum processor type, memory model and the need
    for case sensitive capacity.

    The include files are declared in the correct order so that the
    windows.inc file is always first followed by static libraries and
    import libraries for Windows API functions.

    Where there is a corresponding library for either static or import
    libraries, it is included after the include files.

    NOTE : It is to the advantage of the programmer once they have their
    basic code up and running to properly understand the architecture
    of a MASM executable file so that they can construct their own
    projects to more accurately reflect their own application design.

  ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл *

      .486                                      ; create 32 bit code
      .model flat, stdcall                      ; 32 bit memory model
      option casemap :none                      ; case sensitive 

;     include files
;     ~~~~~~~~~~~~~
      include \masm32\include\windows.inc       ; main windows include file
      include \masm32\include\masm32.inc        ; masm32 library include

    ; -------------------------
    ; Windows API include files
    ; -------------------------
      include \masm32\include\gdi32.inc
      include \masm32\include\user32.inc
      include \masm32\include\kernel32.inc
      include \masm32\include\Comctl32.inc
      include \masm32\include\comdlg32.inc
      include \masm32\include\shell32.inc
      include \masm32\include\oleaut32.inc
      include \masm32\include\ole32.inc
      include \masm32\include\msvcrt.inc

      include \masm32\include\dialogs.inc       ; macro file for dialogs
      include \masm32\macros\macros.asm         ; masm32 macro file

;     libraries
;     ~~~~~~~~~
      includelib \masm32\lib\masm32.lib         ; masm32 static library

    ; ------------------------------------------
    ; import libraries for Windows API functions
    ; ------------------------------------------
      includelib \masm32\lib\gdi32.lib
      includelib \masm32\lib\user32.lib
      includelib \masm32\lib\kernel32.lib
      includelib \masm32\lib\Comctl32.lib
      includelib \masm32\lib\comdlg32.lib
      includelib \masm32\lib\shell32.lib
      includelib \masm32\lib\oleaut32.lib
      includelib \masm32\lib\ole32.lib
      includelib \masm32\lib\msvcrt.lib

; ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл
