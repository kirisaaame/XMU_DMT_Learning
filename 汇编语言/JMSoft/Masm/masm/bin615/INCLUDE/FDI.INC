  ; ===========================================
  ; fdi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF FDI_INC
FDI_INC equ <1>

Arith_Close PROTO 
Arith_Decode_Bits PROTO :DWORD
Arith_Init PROTO 
CSUMCompute PROTO :DWORD,:DWORD,:DWORD
DComp_Close PROTO 
DComp_DecompressBlock PROTO :DWORD,:DWORD,:DWORD,:DWORD
DComp_Init PROTO :DWORD
DComp_Reset PROTO 
ErfSetCodes PROTO :DWORD,:DWORD,:DWORD
FDICallEnumerate PROTO :DWORD
FDIGetDataBlock PROTO :DWORD
FDIGetFile PROTO :DWORD
FDIReadCFDATAEntry PROTO :DWORD,:DWORD
FDIReadCFFILEEntry PROTO :DWORD
FDIReadPSZ PROTO :DWORD,:DWORD,:DWORD
GetCount PROTO :DWORD
HuftBuild PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InflateBlock PROTO :DWORD
InflateCodes PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InflateDynamic PROTO :DWORD
InflateFixed PROTO :DWORD
InflateStored PROTO :DWORD,:DWORD
InitFixed PROTO 
InitFolder PROTO :DWORD,:DWORD
Internal_Literal PROTO :DWORD
Internal_Match PROTO :DWORD,:DWORD
LZX_Decode PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LZX_DecodeFree PROTO :DWORD
LZX_DecodeInit PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LZX_DecodeNewGroup PROTO :DWORD
LoginCabinet PROTO :DWORD,:DWORD,:DWORD,:DWORD
Lz_Bump PROTO :DWORD
Lz_Close PROTO 
Lz_Init PROTO :DWORD
Lz_NextToken PROTO 
MDICreateDecompressionGlobal PROTO :DWORD
MDIDecompressGlobal PROTO :DWORD,:DWORD
MDIDestroyDecompressionGlobal PROTO :DWORD
MDIResetDecompressionGlobal PROTO :DWORD
NFM_Decompress PROTO :DWORD,:DWORD
NFM_Prepare PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NFMdeco_create PROTO :DWORD
NFMdeco_destroy PROTO :DWORD,:DWORD
ReadRepTree PROTO :DWORD,:DWORD,:DWORD,:DWORD
Remove_Symbol PROTO :DWORD,:DWORD
Rtl_Free PROTO :DWORD
Rtl_Malloc PROTO :DWORD
SeekFolder PROTO :DWORD,:DWORD
SetDecompressionType PROTO :DWORD,:DWORD
SwitchToNewCab PROTO :DWORD
allocate_decompression_memory PROTO :DWORD
copy_data_to_output PROTO :DWORD,:DWORD,:DWORD
decode_aligned_offset_block PROTO :DWORD,:DWORD,:DWORD
decode_block PROTO :DWORD,:DWORD,:DWORD,:DWORD
decode_data PROTO :DWORD,:DWORD
decode_uncompressed_block PROTO :DWORD,:DWORD,:DWORD
decode_verbatim_block PROTO :DWORD,:DWORD,:DWORD
decoder_misc_init PROTO :DWORD
decoder_translate_e8 PROTO :DWORD,:DWORD,:DWORD
doCabinetInfoNotify PROTO :DWORD
fast_decode_aligned_offset_block PROTO :DWORD,:DWORD,:DWORD
fast_decode_verbatim_block PROTO :DWORD,:DWORD,:DWORD
fillbuf PROTO :DWORD,:DWORD
free_decompression_memory PROTO :DWORD
getbits PROTO :DWORD,:DWORD
handle_beginning_of_uncompressed_block PROTO :DWORD
init_decoder_input PROTO :DWORD
init_decoder_translation PROTO :DWORD
initialise_decoder_bitbuf PROTO :DWORD
make_table PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
make_table_8bit PROTO :DWORD,:DWORD,:DWORD
read_aligned_offset_tree PROTO :DWORD
read_main_and_secondary_trees PROTO :DWORD
reset_decoder_trees PROTO :DWORD
special_decode_aligned_block PROTO :DWORD,:DWORD,:DWORD
special_decode_verbatim_block PROTO :DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file fdi.inc
echo -----------------------------------------
ENDIF
