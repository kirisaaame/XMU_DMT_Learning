  ; ===========================================
  ; fci.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF FCI_INC
FCI_INC equ <1>

AddFileToFolder PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddFolderToCabinet PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CSUMCompute PROTO :DWORD,:DWORD,:DWORD
CabDestroy PROTO :DWORD,:DWORD
CrTempFiles PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateCab PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ErfSetCodes PROTO :DWORD,:DWORD,:DWORD
FlushCab PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FolderDestroy PROTO :DWORD,:DWORD
FolderFlush PROTO :DWORD,:DWORD,:DWORD
FolderInit PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InitCFHEADER PROTO :DWORD
LZX_Encode PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LZX_EncodeFlush PROTO :DWORD
LZX_EncodeFree PROTO :DWORD
LZX_EncodeInit PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
LZX_EncodeNewGroup PROTO :DWORD
LZX_GetInputData PROTO :DWORD,:DWORD,:DWORD
MCICompressGlobal PROTO :DWORD,:DWORD
MCICreateCompressionGlobal PROTO :DWORD
MCIDestroyCompressionGlobal PROTO :DWORD
MCIResetCompressionGlobal PROTO :DWORD
NFMcomp_create PROTO :DWORD
NFMcomp_destroy PROTO :DWORD,:DWORD
NFMcompress PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
NFMcompress_init PROTO :DWORD,:DWORD,:DWORD
NukeTempFiles PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ReadCFDATAEntry PROTO :DWORD,:DWORD,:DWORD,:DWORD
ReadCFFILEEntry PROTO :DWORD,:DWORD,:DWORD
ReadPSZ PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetCompressionType PROTO :DWORD,:DWORD
WriteCFDATABlock PROTO :DWORD,:DWORD,:DWORD
WriteCount PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WritePsz PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WritePszTmp PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
WriteRepTree PROTO :DWORD,:DWORD,:DWORD,:DWORD
bi_init PROTO :DWORD
bi_reverse PROTO :DWORD,:DWORD
bi_windup PROTO :DWORD
binary_search_findmatch PROTO :DWORD,:DWORD
binary_search_remove_node PROTO :DWORD,:DWORD,:DWORD
block_end PROTO :DWORD,:DWORD
build_bl_tree PROTO :DWORD
build_tree PROTO :DWORD,:DWORD
comp_alloc_compress_memory PROTO :DWORD
comp_free_compress_memory PROTO :DWORD
comp_read_input PROTO :DWORD,:DWORD,:DWORD
compress_block PROTO :DWORD,:DWORD,:DWORD
copy_block PROTO :DWORD,:DWORD,:DWORD,:DWORD
count_len PROTO :DWORD,:DWORD
create_ones_table PROTO :DWORD
create_slot_lookup_table PROTO :DWORD
create_trees PROTO :DWORD,:DWORD
ct_init PROTO :DWORD
ct_tally PROTO :DWORD,:DWORD,:DWORD
deflate PROTO :DWORD
do_block_output PROTO :DWORD,:DWORD,:DWORD
downheap PROTO :DWORD,:DWORD
encode_aligned_block PROTO :DWORD,:DWORD
encode_aligned_tree PROTO :DWORD
encode_trees PROTO :DWORD
encode_uncompressed_block PROTO :DWORD,:DWORD,:DWORD
encode_verbatim_block PROTO :DWORD,:DWORD
encoder_start PROTO :DWORD
encoder_translate_e8 PROTO :DWORD,:DWORD,:DWORD
estimate_buffer_contents PROTO :DWORD
estimate_compressed_block_size PROTO :DWORD
filecopy PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
fix_tree_cost_estimates PROTO :DWORD
flush_all_pending_blocks PROTO :DWORD
flush_block PROTO :DWORD,:DWORD,:DWORD,:DWORD
flush_output_bit_buffer PROTO :DWORD
free_compressed_output_buffer PROTO :DWORD
gen_bitlen PROTO :DWORD,:DWORD
gen_codes PROTO :DWORD,:DWORD,:DWORD
get_aligned_stats PROTO :DWORD,:DWORD
get_block_stats PROTO :DWORD,:DWORD,:DWORD,:DWORD
get_distances_from_literals PROTO :DWORD,:DWORD
get_final_repeated_offset_states PROTO :DWORD,:DWORD
init_block PROTO :DWORD
init_compressed_output_buffer PROTO :DWORD
init_compression_memory PROTO :DWORD
lm_init PROTO :DWORD
lm_init_clear_tables PROTO :DWORD
lm_init_use_tables PROTO :DWORD
longest_match PROTO :DWORD,:DWORD
make_code PROTO :DWORD,:DWORD,:DWORD,:DWORD
make_len PROTO :DWORD,:DWORD
make_tree2 PROTO :DWORD,:DWORD,:DWORD,:DWORD
make_tree PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
opt_encode_top PROTO :DWORD,:DWORD
output_bits PROTO :DWORD,:DWORD,:DWORD
output_block PROTO :DWORD
perform_flush_output_callback PROTO :DWORD
pqdownheap PROTO :DWORD,:DWORD,:DWORD
prevent_far_matches PROTO :DWORD
quick_insert_bsearch_findmatch PROTO :DWORD,:DWORD,:DWORD
read_input_data PROTO :DWORD,:DWORD,:DWORD
redo_first_block PROTO :DWORD,:DWORD
reset_translation PROTO :DWORD
return_difference PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
scan_tree PROTO :DWORD,:DWORD,:DWORD
send_all_trees PROTO :DWORD,:DWORD,:DWORD,:DWORD
send_bits PROTO :DWORD,:DWORD,:DWORD
send_tree PROTO :DWORD,:DWORD,:DWORD
split_block PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
tally_aligned_bits PROTO :DWORD,:DWORD
tally_frequency PROTO :DWORD,:DWORD,:DWORD,:DWORD
update_cumulative_block_stats PROTO :DWORD,:DWORD,:DWORD,:DWORD
update_tree_estimates PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file fci.inc
echo -----------------------------------------
ENDIF
