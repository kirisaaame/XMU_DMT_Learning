  ; ===========================================
  ; odbcbcp.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF ODBCBCP_INC
ODBCBCP_INC equ <1>

LibMain PROTO :DWORD,:DWORD,:DWORD
SQLLinkedCatalogsA PROTO :DWORD,:DWORD,:DWORD
SQLLinkedCatalogs equ <SQLLinkedCatalogsA>

SQLLinkedCatalogsW PROTO :DWORD,:DWORD,:DWORD
SQLLinkedServers PROTO :DWORD
bcp_batch PROTO :DWORD
bcp_bind PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
bcp_colfmt PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
bcp_collen PROTO :DWORD,:DWORD,:DWORD
bcp_colptr PROTO :DWORD,:DWORD,:DWORD
bcp_columns PROTO :DWORD,:DWORD
bcp_control PROTO :DWORD,:DWORD,:DWORD
bcp_done PROTO :DWORD
bcp_exec PROTO :DWORD,:DWORD
bcp_initA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
bcp_init equ <bcp_initA>

bcp_initW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
bcp_moretext PROTO :DWORD,:DWORD,:DWORD
bcp_readfmtA PROTO :DWORD,:DWORD
bcp_readfmt equ <bcp_readfmtA>

bcp_readfmtW PROTO :DWORD,:DWORD
bcp_sendrow PROTO :DWORD
bcp_writefmtA PROTO :DWORD,:DWORD
bcp_writefmt equ <bcp_writefmtA>

bcp_writefmtW PROTO :DWORD,:DWORD
dbprtypeA PROTO :DWORD
dbprtype equ <dbprtypeA>

dbprtypeW PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file odbcbcp.inc
echo -----------------------------------------
ENDIF
