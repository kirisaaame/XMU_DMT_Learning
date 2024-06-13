comment "written by drizz <1of00@gmx.net>"

; CIPHERS
; =======

DESSetKey PROTO pKey:PTR BYTE
DESSetKeyEnc PROTO pKey:PTR BYTE
DESSetKeyDec PROTO pKey:PTR BYTE
DESEncrypt PROTO pBlockIn:PTR BYTE,pBlockOut:PTR BYTE
DESDecrypt PROTO pBlockIn:PTR BYTE,pBlockOut:PTR BYTE
TwofishInit PROTO :DWORD,:DWORD
TwofishEncrypt PROTO :DWORD,:DWORD
TwofishDecrypt PROTO :DWORD,:DWORD
RC2Init proto :DWORD,:DWORD
RC2Encrypt proto :DWORD,:DWORD
RC2Decrypt proto :DWORD,:DWORD
RC4Init proto :DWORD,:DWORD
RC4Encrypt proto :DWORD,:DWORD
RC4Decrypt equ <RC4Encrypt>
RC5Init       PROTO :DWORD
RC5Encrypt    PROTO :DWORD,:DWORD
RC5Decrypt    PROTO :DWORD,:DWORD
RC6Init       PROTO :DWORD,:DWORD
RC6Encrypt    PROTO :DWORD,:DWORD
RC6Decrypt    PROTO :DWORD,:DWORD
XTEAInit	proto :DWORD,:DWORD
XTEAEncrypt	proto :DWORD,:DWORD
XTEADecrypt	proto :DWORD,:DWORD
RijndaelInit proto :DWORD,:DWORD
RijndaelEncrypt	proto :DWORD,:DWORD 
RijndaelDecrypt	proto :DWORD,:DWORD
ThreeWayInit    proto :DWORD
ThreeWayEncrypt proto :DWORD,:DWORD
ThreeWayDecrypt proto :DWORD,:DWORD
TEAInit	proto :DWORD
TEAEncrypt	proto :DWORD,:DWORD
TEADecrypt	proto :DWORD,:DWORD
BlowfishInit proto :DWORD,:DWORD
BlowfishEncrypt	proto :DWORD,:DWORD 
BlowfishDecrypt	proto :DWORD,:DWORD

; CHECKSUMS
; =========

INIT_CRC32 equ 0
INIT_CRC16 equ 0
INIT_ADLER32 equ 1
CRC32 proto lpBuffer:DWORD,dwBufLen:DWORD,dwCRC:DWORD; init dwCRC = 0
; for RCRC32 Data must be Readable/Writeable
RCRC32 proto pData:dword,dwDataLen:dword,dwOffset:dword,dwWantCrc:dword; reverse CRC32
CRC16 proto lpBuffer:DWORD,dwBufLen:DWORD,dwCRC:DWORD; init dwCRC = 0
Adler32 proto lpBuffer:DWORD,dwBufLen:DWORD,dwAdler:DWORD; init dwAdler = 1

; HASHES
; ======

MD5Init proto
MD5Update proto :DWORD,:DWORD
MD5Final proto
MD5_DIGESTSIZE equ 128
MD4Init proto
MD4Update proto :DWORD,:DWORD
MD4Final proto
MD4_DIGESTSIZE equ 128
MD2Init proto
MD2Update proto :dword, :dword
MD2Final proto
MD2_DIGESTSIZE equ 128
RMD128Init proto
RMD128Update proto :dword,:dword
RMD128Final proto
RMD128_DIGESTSIZE equ 128
RMD160Init proto
RMD160Update proto :dword,:dword
RMD160Final proto
RMD160_DIGESTSIZE equ 160
RMD256Init proto
RMD256Update proto :dword,:dword
RMD256Final proto
RMD256_DIGESTSIZE equ 256
RMD320Init proto
RMD320Update proto :dword,:dword
RMD320Final proto
RMD320_DIGESTSIZE equ 320
SHA0Init proto
SHA0Update proto :dword,:dword
SHA0Final proto
SHA0_DIGESTSIZE equ 160
SHA1Init proto
SHA1Update proto :dword,:dword
SHA1Final proto
SHA1_DIGESTSIZE equ 160
SHA256Init proto
SHA256Update proto :dword,:dword
SHA256Final proto
SHA256_DIGESTSIZE equ 256
SHA384Init proto
SHA384Update proto :dword,:dword
SHA384Final proto
SHA384_DIGESTSIZE equ 384
SHA512Init proto
SHA512Update proto :dword,:dword
SHA512Final proto
SHA512_DIGESTSIZE equ 512
WhirlpoolInit proto
WhirlpoolUpdate proto :dword,:dword
WhirlpoolFinal proto
WHIRLPOOL_DIGESTSIZE equ 512
TigerInit proto
TigerUpdate proto :dword,:dword
TigerFinal proto
TIGER_DIGESTSIZE equ 192
HavalInit proto :dword,:dword ; variable digest & passes !!!
HavalUpdate proto :dword,:dword
HavalFinal proto


; TEXT UTILS
; ==========

HexEncode proto pBuff:dword,dwLen:dword,pOutBuff:dword ; sizeof pOutBuff must be (dwLen)*2+2
HexDecode proto pHexStr:dword,pOutBuffer:dword; sizeof pOutBuff must be StrLen(pHexStr)/2+1
Base64Encode proto pInputData:DWORD,dwDataLen:DWORD,pOutputStr:DWORD; returns b64 string len
Base64Decode proto pInputStr:DWORD,pOutputData:DWORD; result = length
Base2Decode proto pInputStr:dword,pOutputData:dword; result = length
Base2Encode proto pInputData:dword,dwDataLen:dword,pOutputData:dword; result = length