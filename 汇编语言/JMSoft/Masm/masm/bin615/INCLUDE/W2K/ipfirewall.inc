comment ^
Module Name:
    ipfirewall.inc

Abstract:
    Header file for IP firewall hook clients.

Author:
    Four-F (four-f@mail.ru)

Last update:
	06-July-2004
^

INVALID_IF_INDEX	equ 0ffffffffh	; The invalid inteface index.

LOCAL_IF_INDEX		equ 0			; Local inteface index.

DEST_LOCAL      equ 0		; Destination is local.
DEST_BCAST      equ 1		; Destination is net or local bcast.
DEST_SN_BCAST   equ 3		; A subnet bcast.
DEST_MCAST      equ 5		; A local mcast.
DEST_REMOTE     equ 8		; Destination is remote.
DEST_REM_BCAST  equ 11		; Destination is a remote broadcast
DEST_REM_MCAST  equ 13		; Destination is a remote mcast.
DEST_INVALID    equ 0ffh	; Invalid destination

DEST_PROMIS     equ 32		; Dest is promiscuous(32=0x20)

DEST_BCAST_BIT  equ 1
DEST_OFFNET_BIT equ 10h		; Destination is offnet -
							; used only by upper layer callers.
DEST_MCAST_BIT  equ 5

;#define DD_IP_DEVICE_NAME   L"\\Device\\Ip"

FSCTL_IP_BASE	equ FILE_DEVICE_NETWORK

IFNDEF CTL_CODE
CTL_CODE MACRO DeviceType:=<0>, Function:=<0>, Method:=<0>, Access:=<0>
	EXITM %(((DeviceType) SHL 16) OR ((Access) SHL 14) OR ((Function) SHL 2) OR (Method))
ENDM
ENDIF

IOCTL_IP_SET_FIREWALL_HOOK	equ CTL_CODE(FSCTL_IP_BASE, 12, METHOD_BUFFERED, FILE_WRITE_ACCESS)


