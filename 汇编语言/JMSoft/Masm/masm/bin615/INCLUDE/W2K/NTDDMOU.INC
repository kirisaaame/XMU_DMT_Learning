
comment ^
Module Name:
    ntddmou.inc

Abstract:
    This is the include file that defines all constants and types for
    accessing the mouse device.

Author:
    Four-F (four-f@mail.ru)

Last updated:
	08-July-2004
^

IFNDEF CTL_CODE
CTL_CODE MACRO DeviceType:=<0>, Function:=<0>, Method:=<0>, Access:=<0>
	EXITM %(((DeviceType) SHL 16) OR ((Access) SHL 14) OR ((Function) SHL 2) OR (Method))
ENDM
ENDIF

IFNDEF _NTDDMOU_
_NTDDMOU_ equ 1

;
; Device Name - this string is the name of the device.  It is the name
; that should be passed to NtOpenFile when accessing the device.
;
; Note:  For devices that support multiple units, it should be suffixed
;        with the Ascii representation of the unit number.
;

;#define DD_MOUSE_DEVICE_NAME    "\\Device\\PointerClass"
;#define DD_MOUSE_DEVICE_NAME_U L"\\Device\\PointerClass"

;
; NtDeviceIoControlFile IoControlCode values for this device.
;
; Warning:  Remember that the low two bits of the code specify how the
;           buffers are passed to the driver!
;

IOCTL_MOUSE_QUERY_ATTRIBUTES equ CTL_CODE(FILE_DEVICE_MOUSE, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_MOUSE_INSERT_DATA      equ CTL_CODE(FILE_DEVICE_MOUSE, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)

; Define the mouse button state indicators.

MOUSE_LEFT_BUTTON_DOWN   equ 0001  ; Left Button changed to down.
MOUSE_LEFT_BUTTON_UP     equ 0002  ; Left Button changed to up.
MOUSE_RIGHT_BUTTON_DOWN  equ 0004  ; Right Button changed to down.
MOUSE_RIGHT_BUTTON_UP    equ 0008  ; Right Button changed to up.
MOUSE_MIDDLE_BUTTON_DOWN equ 0010h ; Middle Button changed to down.
MOUSE_MIDDLE_BUTTON_UP   equ 0020h ; Middle Button changed to up.

MOUSE_BUTTON_1_DOWN     equ MOUSE_LEFT_BUTTON_DOWN
MOUSE_BUTTON_1_UP       equ MOUSE_LEFT_BUTTON_UP
MOUSE_BUTTON_2_DOWN     equ MOUSE_RIGHT_BUTTON_DOWN
MOUSE_BUTTON_2_UP       equ MOUSE_RIGHT_BUTTON_UP
MOUSE_BUTTON_3_DOWN     equ MOUSE_MIDDLE_BUTTON_DOWN
MOUSE_BUTTON_3_UP       equ MOUSE_MIDDLE_BUTTON_UP

MOUSE_BUTTON_4_DOWN     equ 0040h
MOUSE_BUTTON_4_UP       equ 0080h
MOUSE_BUTTON_5_DOWN     equ 0100h
MOUSE_BUTTON_5_UP       equ 0200h

MOUSE_WHEEL             equ 0400h

; Define the mouse indicator flags.

MOUSE_MOVE_RELATIVE         equ 0
MOUSE_MOVE_ABSOLUTE         equ 1
MOUSE_VIRTUAL_DESKTOP       equ 2  ; the coordinates are mapped to the virtual desktop
MOUSE_ATTRIBUTES_CHANGED    equ 4  ; requery for mouse attributes

; Define the mouse identifier types.

MOUSE_INPORT_HARDWARE       equ 0001
MOUSE_I8042_HARDWARE        equ 0002
MOUSE_SERIAL_HARDWARE       equ 0004
BALLPOINT_I8042_HARDWARE    equ 0008
BALLPOINT_SERIAL_HARDWARE   equ 0010h
WHEELMOUSE_I8042_HARDWARE   equ 0020h
WHEELMOUSE_SERIAL_HARDWARE  equ 0040h
MOUSE_HID_HARDWARE          equ 0080h
WHEELMOUSE_HID_HARDWARE     equ 0100h

MOUSE_ERROR_VALUE_BASE        equ 20000

ENDIF ; _NTDDMOU_

