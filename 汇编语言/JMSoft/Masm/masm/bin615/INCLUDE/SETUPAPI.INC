  ; ===========================================
  ; setupapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF SETUPAPI_INC
SETUPAPI_INC equ <1>

AcquireSCMLock PROTO :DWORD,:DWORD
AddMiniIconToList PROTO :DWORD,:DWORD
AddTagToGroupOrderListEntry PROTO :DWORD,:DWORD,:DWORD
AppendStringToMultiSz PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AssertFail PROTO :DWORD,:DWORD,:DWORD
CMP_Init_Detection PROTO :DWORD
CMP_RegisterNotification PROTO :DWORD,:DWORD,:DWORD,:DWORD
CMP_Report_LogOn PROTO :DWORD,:DWORD
CMP_UnregisterNotification PROTO :DWORD
CMP_WaitNoPendingInstallEvents PROTO :DWORD
CMP_WaitServicesAvailable PROTO :DWORD
CM_Add_Empty_Log_Conf PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Add_Empty_Log_Conf_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Add_IDA PROTO :DWORD,:DWORD,:DWORD
CM_Add_ID equ <CM_Add_IDA>

CM_Add_IDW PROTO :DWORD,:DWORD,:DWORD
CM_Add_ID_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Add_ID_Ex equ <CM_Add_ID_ExA>

CM_Add_ID_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Add_Range PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Add_Res_Des PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Add_Res_Des_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Connect_MachineA PROTO :DWORD,:DWORD
CM_Connect_Machine equ <CM_Connect_MachineA>

CM_Connect_MachineW PROTO :DWORD,:DWORD
CM_Create_DevNodeA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Create_DevNode equ <CM_Create_DevNodeA>

CM_Create_DevNodeW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Create_DevNode_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Create_DevNode_Ex equ <CM_Create_DevNode_ExA>

CM_Create_DevNode_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Create_Range_List PROTO :DWORD,:DWORD
CM_Delete_Class_Key PROTO :DWORD,:DWORD
CM_Delete_Class_Key_Ex PROTO :DWORD,:DWORD,:DWORD
CM_Delete_DevNode_Key PROTO :DWORD,:DWORD,:DWORD
CM_Delete_DevNode_Key_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Delete_Range PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Detect_Resource_Conflict PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Detect_Resource_Conflict_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Disable_DevNode PROTO :DWORD,:DWORD
CM_Disable_DevNode_Ex PROTO :DWORD,:DWORD,:DWORD
CM_Disconnect_Machine PROTO :DWORD
CM_Dup_Range_List PROTO :DWORD,:DWORD,:DWORD
CM_Enable_DevNode PROTO :DWORD,:DWORD
CM_Enable_DevNode_Ex PROTO :DWORD,:DWORD,:DWORD
CM_Enumerate_Classes PROTO :DWORD,:DWORD,:DWORD
CM_Enumerate_Classes_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Enumerate_EnumeratorsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Enumerate_Enumerators equ <CM_Enumerate_EnumeratorsA>

CM_Enumerate_EnumeratorsW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Enumerate_Enumerators_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Enumerate_Enumerators_Ex equ <CM_Enumerate_Enumerators_ExA>

CM_Enumerate_Enumerators_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Find_Range PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_First_Range PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Free_Log_Conf PROTO :DWORD,:DWORD
CM_Free_Log_Conf_Ex PROTO :DWORD,:DWORD,:DWORD
CM_Free_Log_Conf_Handle PROTO :DWORD
CM_Free_Range_List PROTO :DWORD,:DWORD
CM_Free_Res_Des PROTO :DWORD,:DWORD,:DWORD
CM_Free_Res_Des_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Free_Res_Des_Handle PROTO :DWORD
CM_Free_Resource_Conflict_Handle PROTO :DWORD
CM_Get_Child PROTO :DWORD,:DWORD,:DWORD
CM_Get_Child_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Class_Key_NameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Class_Key_Name equ <CM_Get_Class_Key_NameA>

CM_Get_Class_Key_NameW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Class_Key_Name_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Class_Key_Name_Ex equ <CM_Get_Class_Key_Name_ExA>

CM_Get_Class_Key_Name_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Class_NameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Class_Name equ <CM_Get_Class_NameA>

CM_Get_Class_NameW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Class_Name_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Class_Name_Ex equ <CM_Get_Class_Name_ExA>

CM_Get_Class_Name_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Class_Registry_PropertyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Class_Registry_Property equ <CM_Get_Class_Registry_PropertyA>

CM_Get_Class_Registry_PropertyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Depth PROTO :DWORD,:DWORD,:DWORD
CM_Get_Depth_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_DevNode_Registry_PropertyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_DevNode_Registry_Property equ <CM_Get_DevNode_Registry_PropertyA>

CM_Get_DevNode_Registry_PropertyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_DevNode_Registry_Property_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_DevNode_Registry_Property_Ex equ <CM_Get_DevNode_Registry_Property_ExA>

CM_Get_DevNode_Registry_Property_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_DevNode_Status PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_DevNode_Status_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_IDA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_ID equ <CM_Get_Device_IDA>

CM_Get_Device_IDW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_ID_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_ID_Ex equ <CM_Get_Device_ID_ExA>

CM_Get_Device_ID_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_ID_ListA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_ID_List equ <CM_Get_Device_ID_ListA>

CM_Get_Device_ID_ListW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_ID_List_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_ID_List_Ex equ <CM_Get_Device_ID_List_ExA>

CM_Get_Device_ID_List_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_ID_List_SizeA PROTO :DWORD,:DWORD,:DWORD
CM_Get_Device_ID_List_Size equ <CM_Get_Device_ID_List_SizeA>

CM_Get_Device_ID_List_SizeW PROTO :DWORD,:DWORD,:DWORD
CM_Get_Device_ID_List_Size_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_ID_List_Size_Ex equ <CM_Get_Device_ID_List_Size_ExA>

CM_Get_Device_ID_List_Size_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_ID_Size PROTO :DWORD,:DWORD,:DWORD
CM_Get_Device_ID_Size_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_Interface_AliasA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_Interface_Alias equ <CM_Get_Device_Interface_AliasA>

CM_Get_Device_Interface_AliasW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_Interface_Alias_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_Interface_Alias_Ex equ <CM_Get_Device_Interface_Alias_ExA>

CM_Get_Device_Interface_Alias_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_Interface_ListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_Interface_List equ <CM_Get_Device_Interface_ListA>

CM_Get_Device_Interface_ListW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_Interface_List_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_Interface_List_Ex equ <CM_Get_Device_Interface_List_ExA>

CM_Get_Device_Interface_List_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_Interface_List_SizeA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_Interface_List_Size equ <CM_Get_Device_Interface_List_SizeA>

CM_Get_Device_Interface_List_SizeW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_Interface_List_Size_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Device_Interface_List_Size_Ex equ <CM_Get_Device_Interface_List_Size_ExA>

CM_Get_Device_Interface_List_Size_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_First_Log_Conf PROTO :DWORD,:DWORD,:DWORD
CM_Get_First_Log_Conf_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Global_State PROTO :DWORD,:DWORD
CM_Get_Global_State_Ex PROTO :DWORD,:DWORD,:DWORD
CM_Get_HW_Prof_FlagsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_HW_Prof_Flags equ <CM_Get_HW_Prof_FlagsA>

CM_Get_HW_Prof_FlagsW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_HW_Prof_Flags_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_HW_Prof_Flags_Ex equ <CM_Get_HW_Prof_Flags_ExA>

CM_Get_HW_Prof_Flags_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Hardware_Profile_InfoA PROTO :DWORD,:DWORD,:DWORD
CM_Get_Hardware_Profile_Info equ <CM_Get_Hardware_Profile_InfoA>

CM_Get_Hardware_Profile_InfoW PROTO :DWORD,:DWORD,:DWORD
CM_Get_Hardware_Profile_Info_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Hardware_Profile_Info_Ex equ <CM_Get_Hardware_Profile_Info_ExA>

CM_Get_Hardware_Profile_Info_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Log_Conf_Priority PROTO :DWORD,:DWORD,:DWORD
CM_Get_Log_Conf_Priority_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Next_Log_Conf PROTO :DWORD,:DWORD,:DWORD
CM_Get_Next_Log_Conf_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Next_Res_Des PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Next_Res_Des_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Parent PROTO :DWORD,:DWORD,:DWORD
CM_Get_Parent_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Res_Des_Data PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Res_Des_Data_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Res_Des_Data_Size PROTO :DWORD,:DWORD,:DWORD
CM_Get_Res_Des_Data_Size_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Resource_Conflict_Count PROTO :DWORD,:DWORD
CM_Get_Resource_Conflict_DetailsA PROTO :DWORD,:DWORD,:DWORD
CM_Get_Resource_Conflict_Details equ <CM_Get_Resource_Conflict_DetailsA>

CM_Get_Resource_Conflict_DetailsW PROTO :DWORD,:DWORD,:DWORD
CM_Get_Sibling PROTO :DWORD,:DWORD,:DWORD
CM_Get_Sibling_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Get_Version PROTO 
CM_Get_Version_Ex PROTO :DWORD
CM_Intersect_Range_List PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Invert_Range_List PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Is_Dock_Station_Present PROTO :DWORD
CM_Is_Dock_Station_Present_Ex PROTO :DWORD,:DWORD
CM_Locate_DevNodeA PROTO :DWORD,:DWORD,:DWORD
CM_Locate_DevNode equ <CM_Locate_DevNodeA>

CM_Locate_DevNodeW PROTO :DWORD,:DWORD,:DWORD
CM_Locate_DevNode_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Locate_DevNode_Ex equ <CM_Locate_DevNode_ExA>

CM_Locate_DevNode_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Merge_Range_List PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Modify_Res_Des PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Modify_Res_Des_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Move_DevNode PROTO :DWORD,:DWORD,:DWORD
CM_Move_DevNode_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Next_Range PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Open_Class_KeyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Open_Class_Key equ <CM_Open_Class_KeyA>

CM_Open_Class_KeyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Open_Class_Key_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Open_Class_Key_Ex equ <CM_Open_Class_Key_ExA>

CM_Open_Class_Key_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Open_DevNode_Key PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Open_DevNode_Key_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Query_And_Remove_SubTreeA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Query_And_Remove_SubTree equ <CM_Query_And_Remove_SubTreeA>

CM_Query_And_Remove_SubTreeW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Query_And_Remove_SubTree_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Query_And_Remove_SubTree_Ex equ <CM_Query_And_Remove_SubTree_ExA>

CM_Query_And_Remove_SubTree_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Query_Arbitrator_Free_Data PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Query_Arbitrator_Free_Data_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Query_Arbitrator_Free_Size PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Query_Arbitrator_Free_Size_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Query_Remove_SubTree PROTO :DWORD,:DWORD
CM_Query_Remove_SubTree_Ex PROTO :DWORD,:DWORD,:DWORD
CM_Query_Resource_Conflict_List PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Reenumerate_DevNode PROTO :DWORD,:DWORD
CM_Reenumerate_DevNode_Ex PROTO :DWORD,:DWORD,:DWORD
CM_Register_Device_Driver PROTO :DWORD,:DWORD
CM_Register_Device_Driver_Ex PROTO :DWORD,:DWORD,:DWORD
CM_Register_Device_InterfaceA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Register_Device_Interface equ <CM_Register_Device_InterfaceA>

CM_Register_Device_InterfaceW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Register_Device_Interface_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Register_Device_Interface_Ex equ <CM_Register_Device_Interface_ExA>

CM_Register_Device_Interface_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Remove_SubTree PROTO :DWORD,:DWORD
CM_Remove_SubTree_Ex PROTO :DWORD,:DWORD,:DWORD
CM_Request_Device_EjectA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Request_Device_Eject equ <CM_Request_Device_EjectA>

CM_Request_Device_EjectW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Request_Device_Eject_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Request_Device_Eject_Ex equ <CM_Request_Device_Eject_ExA>

CM_Request_Device_Eject_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Request_Eject_PC PROTO 
CM_Request_Eject_PC_Ex PROTO :DWORD
CM_Run_Detection PROTO :DWORD
CM_Run_Detection_Ex PROTO :DWORD,:DWORD
CM_Set_Class_Registry_PropertyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Set_Class_Registry_Property equ <CM_Set_Class_Registry_PropertyA>

CM_Set_Class_Registry_PropertyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Set_DevNode_Problem PROTO :DWORD,:DWORD,:DWORD
CM_Set_DevNode_Problem_Ex PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Set_DevNode_Registry_PropertyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Set_DevNode_Registry_Property equ <CM_Set_DevNode_Registry_PropertyA>

CM_Set_DevNode_Registry_PropertyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Set_DevNode_Registry_Property_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Set_DevNode_Registry_Property_Ex equ <CM_Set_DevNode_Registry_Property_ExA>

CM_Set_DevNode_Registry_Property_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Set_HW_Prof PROTO :DWORD,:DWORD
CM_Set_HW_Prof_Ex PROTO :DWORD,:DWORD,:DWORD
CM_Set_HW_Prof_FlagsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Set_HW_Prof_Flags equ <CM_Set_HW_Prof_FlagsA>

CM_Set_HW_Prof_FlagsW PROTO :DWORD,:DWORD,:DWORD,:DWORD
CM_Set_HW_Prof_Flags_ExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Set_HW_Prof_Flags_Ex equ <CM_Set_HW_Prof_Flags_ExA>

CM_Set_HW_Prof_Flags_ExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Setup_DevNode PROTO :DWORD,:DWORD
CM_Setup_DevNode_Ex PROTO :DWORD,:DWORD,:DWORD
CM_Test_Range_Available PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CM_Uninstall_DevNode PROTO :DWORD,:DWORD
CM_Uninstall_DevNode_Ex PROTO :DWORD,:DWORD,:DWORD
CM_Unregister_Device_InterfaceA PROTO :DWORD,:DWORD
CM_Unregister_Device_Interface equ <CM_Unregister_Device_InterfaceA>

CM_Unregister_Device_InterfaceW PROTO :DWORD,:DWORD
CM_Unregister_Device_Interface_ExA PROTO :DWORD,:DWORD,:DWORD
CM_Unregister_Device_Interface_Ex equ <CM_Unregister_Device_Interface_ExA>

CM_Unregister_Device_Interface_ExW PROTO :DWORD,:DWORD,:DWORD
CaptureAndConvertAnsiArg PROTO :DWORD,:DWORD
CaptureStringArg PROTO :DWORD,:DWORD
CenterWindowRelativeToParent PROTO :DWORD
ConcatenatePaths PROTO :DWORD,:DWORD,:DWORD,:DWORD
DelayedMove PROTO :DWORD,:DWORD
DelimStringToMultiSz PROTO :DWORD,:DWORD,:DWORD
DestroyTextFileReadBuffer PROTO :DWORD
DoInstallActionWithParams PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DoesUserHavePrivilege PROTO :DWORD
DuplicateString PROTO :DWORD
EnablePrivilege PROTO :DWORD,:DWORD
ExtensionPropSheetPageProc PROTO :DWORD,:DWORD,:DWORD
FileExists PROTO :DWORD,:DWORD
FreeStringArray PROTO :DWORD,:DWORD
GetCurrentDriverSigningPolicy PROTO :DWORD
GetSetFileTimestamp PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetVersionInfoFromImage PROTO :DWORD,:DWORD,:DWORD
HandleFailedVerification PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
InfIsFromOemLocation PROTO :DWORD,:DWORD
InstallCatalog PROTO :DWORD,:DWORD,:DWORD
InstallHinfSectionA PROTO :DWORD,:DWORD,:DWORD,:DWORD
InstallHinfSection equ <InstallHinfSectionA>

InstallHinfSectionW PROTO :DWORD,:DWORD,:DWORD,:DWORD
InstallStop PROTO :DWORD
InstallStopEx PROTO :DWORD,:DWORD,:DWORD
IsUserAdmin PROTO 
LookUpStringInTable PROTO :DWORD,:DWORD,:DWORD
MemoryInitialize PROTO :DWORD
MultiByteToUnicode PROTO :DWORD,:DWORD
MultiSzFromSearchControl PROTO :DWORD,:DWORD,:DWORD,:DWORD
MyFree PROTO :DWORD
MyGetFileTitle PROTO :DWORD
MyMalloc PROTO :DWORD
MyRealloc PROTO :DWORD,:DWORD
OpenAndMapFileForRead PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
OutOfMemory PROTO :DWORD
QueryMultiSzValueToArray PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
QueryRegistryValue PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ReadAsciiOrUnicodeTextFile PROTO :DWORD,:DWORD
RegistryDelnode PROTO :DWORD,:DWORD
RetreiveFileSecurity PROTO :DWORD,:DWORD
RetrieveServiceConfig PROTO :DWORD,:DWORD
SearchForInfFile PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetArrayToMultiSzValue PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupAddInstallSectionToDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupAddInstallSectionToDiskSpaceList equ <SetupAddInstallSectionToDiskSpaceListA>

SetupAddInstallSectionToDiskSpaceListW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupAddSectionToDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupAddSectionToDiskSpaceList equ <SetupAddSectionToDiskSpaceListA>

SetupAddSectionToDiskSpaceListW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupAddToDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupAddToDiskSpaceList equ <SetupAddToDiskSpaceListA>

SetupAddToDiskSpaceListW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupAddToSourceListA PROTO :DWORD,:DWORD
SetupAddToSourceList equ <SetupAddToSourceListA>

SetupAddToSourceListW PROTO :DWORD,:DWORD
SetupAdjustDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupAdjustDiskSpaceList equ <SetupAdjustDiskSpaceListA>

SetupAdjustDiskSpaceListW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupBackupErrorA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupBackupError equ <SetupBackupErrorA>

SetupBackupErrorW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupCancelTemporarySourceList PROTO 
SetupCloseFileQueue PROTO :DWORD
SetupCloseInfFile PROTO :DWORD
SetupCloseLog PROTO 
SetupCommitFileQueueA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupCommitFileQueue equ <SetupCommitFileQueueA>

SetupCommitFileQueueW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupCopyErrorA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupCopyError equ <SetupCopyErrorA>

SetupCopyErrorW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupCopyOEMInfA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupCopyOEMInf equ <SetupCopyOEMInfA>

SetupCopyOEMInfW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupCreateDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD
SetupCreateDiskSpaceList equ <SetupCreateDiskSpaceListA>

SetupCreateDiskSpaceListW PROTO :DWORD,:DWORD,:DWORD
SetupDecompressOrCopyFileA PROTO :DWORD,:DWORD,:DWORD
SetupDecompressOrCopyFile equ <SetupDecompressOrCopyFileA>

SetupDecompressOrCopyFileW PROTO :DWORD,:DWORD,:DWORD
SetupDefaultQueueCallbackA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDefaultQueueCallback equ <SetupDefaultQueueCallbackA>

SetupDefaultQueueCallbackW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDeleteErrorA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDeleteError equ <SetupDeleteErrorA>

SetupDeleteErrorW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDestroyDiskSpaceList PROTO :DWORD
SetupDiAskForOEMDisk PROTO :DWORD,:DWORD
SetupDiBuildClassInfoList PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiBuildClassInfoListExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiBuildClassInfoListEx equ <SetupDiBuildClassInfoListExA>

SetupDiBuildClassInfoListExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiBuildDriverInfoList PROTO :DWORD,:DWORD,:DWORD
SetupDiCallClassInstaller PROTO :DWORD,:DWORD,:DWORD
SetupDiCancelDriverInfoSearch PROTO :DWORD
SetupDiChangeState PROTO :DWORD,:DWORD
SetupDiClassGuidsFromNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiClassGuidsFromName equ <SetupDiClassGuidsFromNameA>

SetupDiClassGuidsFromNameExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiClassGuidsFromNameEx equ <SetupDiClassGuidsFromNameExA>

SetupDiClassGuidsFromNameExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiClassGuidsFromNameW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiClassNameFromGuidA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiClassNameFromGuid equ <SetupDiClassNameFromGuidA>

SetupDiClassNameFromGuidExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiClassNameFromGuidEx equ <SetupDiClassNameFromGuidExA>

SetupDiClassNameFromGuidExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiClassNameFromGuidW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiCreateDevRegKeyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiCreateDevRegKey equ <SetupDiCreateDevRegKeyA>

SetupDiCreateDevRegKeyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiCreateDeviceInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiCreateDeviceInfo equ <SetupDiCreateDeviceInfoA>

SetupDiCreateDeviceInfoList PROTO :DWORD,:DWORD
SetupDiCreateDeviceInfoListExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiCreateDeviceInfoListEx equ <SetupDiCreateDeviceInfoListExA>

SetupDiCreateDeviceInfoListExW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiCreateDeviceInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiCreateDeviceInterfaceA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiCreateDeviceInterface equ <SetupDiCreateDeviceInterfaceA>

SetupDiCreateDeviceInterfaceRegKeyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiCreateDeviceInterfaceRegKey equ <SetupDiCreateDeviceInterfaceRegKeyA>

SetupDiCreateDeviceInterfaceRegKeyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiCreateDeviceInterfaceW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiDeleteDevRegKey PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiDeleteDeviceInfo PROTO :DWORD,:DWORD
SetupDiDeleteDeviceInterfaceData PROTO :DWORD,:DWORD
SetupDiDeleteDeviceInterfaceRegKey PROTO :DWORD,:DWORD,:DWORD
SetupDiDestroyClassImageList PROTO :DWORD
SetupDiDestroyDeviceInfoList PROTO :DWORD
SetupDiDestroyDriverInfoList PROTO :DWORD,:DWORD,:DWORD
SetupDiDrawMiniIcon PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiEnumDeviceInfo PROTO :DWORD,:DWORD,:DWORD
SetupDiEnumDeviceInterfaces PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiEnumDriverInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiEnumDriverInfo equ <SetupDiEnumDriverInfoA>

SetupDiEnumDriverInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetActualSectionToInstallA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetActualSectionToInstall equ <SetupDiGetActualSectionToInstallA>

SetupDiGetActualSectionToInstallW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassBitmapIndex PROTO :DWORD,:DWORD
SetupDiGetClassDescriptionA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassDescription equ <SetupDiGetClassDescriptionA>

SetupDiGetClassDescriptionExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassDescriptionEx equ <SetupDiGetClassDescriptionExA>

SetupDiGetClassDescriptionExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassDescriptionW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassDevPropertySheetsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassDevPropertySheets equ <SetupDiGetClassDevPropertySheetsA>

SetupDiGetClassDevPropertySheetsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassDevsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassDevs equ <SetupDiGetClassDevsA>

SetupDiGetClassDevsExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassDevsEx equ <SetupDiGetClassDevsExA>

SetupDiGetClassDevsExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassDevsW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassImageIndex PROTO :DWORD,:DWORD,:DWORD
SetupDiGetClassImageList PROTO :DWORD
SetupDiGetClassImageListExA PROTO :DWORD,:DWORD,:DWORD
SetupDiGetClassImageListEx equ <SetupDiGetClassImageListExA>

SetupDiGetClassImageListExW PROTO :DWORD,:DWORD,:DWORD
SetupDiGetClassInstallParamsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetClassInstallParams equ <SetupDiGetClassInstallParamsA>

SetupDiGetClassInstallParamsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDeviceInfoListClass PROTO :DWORD,:DWORD
SetupDiGetDeviceInfoListDetailA PROTO :DWORD,:DWORD
SetupDiGetDeviceInfoListDetail equ <SetupDiGetDeviceInfoListDetailA>

SetupDiGetDeviceInfoListDetailW PROTO :DWORD,:DWORD
SetupDiGetDeviceInstallParamsA PROTO :DWORD,:DWORD,:DWORD
SetupDiGetDeviceInstallParams equ <SetupDiGetDeviceInstallParamsA>

SetupDiGetDeviceInstallParamsW PROTO :DWORD,:DWORD,:DWORD
SetupDiGetDeviceInstanceIdA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDeviceInstanceId equ <SetupDiGetDeviceInstanceIdA>

SetupDiGetDeviceInstanceIdW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDeviceInterfaceAlias PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDeviceInterfaceDetailA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDeviceInterfaceDetail equ <SetupDiGetDeviceInterfaceDetailA>

SetupDiGetDeviceInterfaceDetailW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDeviceRegistryPropertyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDeviceRegistryProperty equ <SetupDiGetDeviceRegistryPropertyA>

SetupDiGetDeviceRegistryPropertyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDriverInfoDetailA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDriverInfoDetail equ <SetupDiGetDriverInfoDetailA>

SetupDiGetDriverInfoDetailW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDriverInstallParamsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetDriverInstallParams equ <SetupDiGetDriverInstallParamsA>

SetupDiGetDriverInstallParamsW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetHwProfileFriendlyNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetHwProfileFriendlyName equ <SetupDiGetHwProfileFriendlyNameA>

SetupDiGetHwProfileFriendlyNameExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetHwProfileFriendlyNameEx equ <SetupDiGetHwProfileFriendlyNameExA>

SetupDiGetHwProfileFriendlyNameExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetHwProfileFriendlyNameW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetHwProfileList PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetHwProfileListExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetHwProfileListEx equ <SetupDiGetHwProfileListExA>

SetupDiGetHwProfileListExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetINFClassA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetINFClass equ <SetupDiGetINFClassA>

SetupDiGetINFClassW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiGetSelectedDevice PROTO :DWORD,:DWORD
SetupDiGetSelectedDriverA PROTO :DWORD,:DWORD,:DWORD
SetupDiGetSelectedDriver equ <SetupDiGetSelectedDriverA>

SetupDiGetSelectedDriverW PROTO :DWORD,:DWORD,:DWORD
SetupDiGetWizardPage PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiInstallClassA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiInstallClass equ <SetupDiInstallClassA>

SetupDiInstallClassExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiInstallClassEx equ <SetupDiInstallClassExA>

SetupDiInstallClassExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiInstallClassW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiInstallDevice PROTO :DWORD,:DWORD
SetupDiInstallDeviceInterfaces PROTO :DWORD,:DWORD
SetupDiInstallDriverFiles PROTO :DWORD,:DWORD
SetupDiLoadClassIcon PROTO :DWORD,:DWORD,:DWORD
SetupDiMoveDuplicateDevice PROTO :DWORD,:DWORD
SetupDiOpenClassRegKey PROTO :DWORD,:DWORD
SetupDiOpenClassRegKeyExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiOpenClassRegKeyEx equ <SetupDiOpenClassRegKeyExA>

SetupDiOpenClassRegKeyExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiOpenDevRegKey PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiOpenDeviceInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiOpenDeviceInfo equ <SetupDiOpenDeviceInfoA>

SetupDiOpenDeviceInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiOpenDeviceInterfaceA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiOpenDeviceInterface equ <SetupDiOpenDeviceInterfaceA>

SetupDiOpenDeviceInterfaceRegKey PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiOpenDeviceInterfaceW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiRegisterCoDeviceInstallers PROTO :DWORD,:DWORD
SetupDiRegisterDeviceInfo PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiRemoveDevice PROTO :DWORD,:DWORD
SetupDiRemoveDeviceInterface PROTO :DWORD,:DWORD
SetupDiSelectBestCompatDrv PROTO :DWORD,:DWORD
SetupDiSelectDevice PROTO :DWORD,:DWORD
SetupDiSelectOEMDrv PROTO :DWORD,:DWORD,:DWORD
SetupDiSetClassInstallParamsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiSetClassInstallParams equ <SetupDiSetClassInstallParamsA>

SetupDiSetClassInstallParamsW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiSetDeviceInstallParamsA PROTO :DWORD,:DWORD,:DWORD
SetupDiSetDeviceInstallParams equ <SetupDiSetDeviceInstallParamsA>

SetupDiSetDeviceInstallParamsW PROTO :DWORD,:DWORD,:DWORD
SetupDiSetDeviceRegistryPropertyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiSetDeviceRegistryProperty equ <SetupDiSetDeviceRegistryPropertyA>

SetupDiSetDeviceRegistryPropertyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupDiSetDriverInstallParamsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiSetDriverInstallParams equ <SetupDiSetDriverInstallParamsA>

SetupDiSetDriverInstallParamsW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDiSetSelectedDevice PROTO :DWORD,:DWORD
SetupDiSetSelectedDriverA PROTO :DWORD,:DWORD,:DWORD
SetupDiSetSelectedDriver equ <SetupDiSetSelectedDriverA>

SetupDiSetSelectedDriverW PROTO :DWORD,:DWORD,:DWORD
SetupDiUnremoveDevice PROTO :DWORD,:DWORD
SetupDuplicateDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupDuplicateDiskSpaceList equ <SetupDuplicateDiskSpaceListA>

SetupDuplicateDiskSpaceListW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupFindFirstLineA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupFindFirstLine equ <SetupFindFirstLineA>

SetupFindFirstLineW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupFindNextLine PROTO :DWORD,:DWORD
SetupFindNextMatchLineA PROTO :DWORD,:DWORD,:DWORD
SetupFindNextMatchLine equ <SetupFindNextMatchLineA>

SetupFindNextMatchLineW PROTO :DWORD,:DWORD,:DWORD
SetupFreeSourceListA PROTO :DWORD,:DWORD
SetupFreeSourceList equ <SetupFreeSourceListA>

SetupFreeSourceListW PROTO :DWORD,:DWORD
SetupGetBackupInformationA PROTO :DWORD,:DWORD
SetupGetBackupInformation equ <SetupGetBackupInformationA>

SetupGetBackupInformationW PROTO :DWORD,:DWORD
SetupGetBinaryField PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetFieldCount PROTO :DWORD
SetupGetFileCompressionInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetFileCompressionInfo equ <SetupGetFileCompressionInfoA>

SetupGetFileCompressionInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetInfFileListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetInfFileList equ <SetupGetInfFileListA>

SetupGetInfFileListW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetInfInformationA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetInfInformation equ <SetupGetInfInformationA>

SetupGetInfInformationW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetInfSections PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupGetIntField PROTO :DWORD,:DWORD,:DWORD
SetupGetLineByIndexA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupGetLineByIndex equ <SetupGetLineByIndexA>

SetupGetLineByIndexW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupGetLineCountA PROTO :DWORD,:DWORD
SetupGetLineCount equ <SetupGetLineCountA>

SetupGetLineCountW PROTO :DWORD,:DWORD
SetupGetLineTextA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetLineText equ <SetupGetLineTextA>

SetupGetLineTextW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetMultiSzFieldA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetMultiSzField equ <SetupGetMultiSzFieldA>

SetupGetMultiSzFieldW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetSourceFileLocationA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetSourceFileLocation equ <SetupGetSourceFileLocationA>

SetupGetSourceFileLocationW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetSourceFileSizeA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetSourceFileSize equ <SetupGetSourceFileSizeA>

SetupGetSourceFileSizeW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetSourceInfoA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetSourceInfo equ <SetupGetSourceInfoA>

SetupGetSourceInfoW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetStringFieldA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetStringField equ <SetupGetStringFieldA>

SetupGetStringFieldW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetTargetPathA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupGetTargetPath equ <SetupGetTargetPathA>

SetupGetTargetPathW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInitDefaultQueueCallback PROTO :DWORD
SetupInitDefaultQueueCallbackEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInitializeFileLogA PROTO :DWORD,:DWORD
SetupInitializeFileLog equ <SetupInitializeFileLogA>

SetupInitializeFileLogW PROTO :DWORD,:DWORD
SetupInstallFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInstallFile equ <SetupInstallFileA>

SetupInstallFileExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInstallFileEx equ <SetupInstallFileExA>

SetupInstallFileExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInstallFileW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInstallFilesFromInfSectionA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInstallFilesFromInfSection equ <SetupInstallFilesFromInfSectionA>

SetupInstallFilesFromInfSectionW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInstallFromInfSectionA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInstallFromInfSection equ <SetupInstallFromInfSectionA>

SetupInstallFromInfSectionW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInstallServicesFromInfSectionA PROTO :DWORD,:DWORD,:DWORD
SetupInstallServicesFromInfSection equ <SetupInstallServicesFromInfSectionA>

SetupInstallServicesFromInfSectionExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInstallServicesFromInfSectionEx equ <SetupInstallServicesFromInfSectionExA>

SetupInstallServicesFromInfSectionExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupInstallServicesFromInfSectionW PROTO :DWORD,:DWORD,:DWORD
SetupIterateCabinetA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupIterateCabinet equ <SetupIterateCabinetA>

SetupIterateCabinetW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupLogErrorA PROTO :DWORD,:DWORD
SetupLogError equ <SetupLogErrorA>

SetupLogErrorW PROTO :DWORD,:DWORD
SetupLogFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupLogFile equ <SetupLogFileA>

SetupLogFileW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupOpenAppendInfFileA PROTO :DWORD,:DWORD,:DWORD
SetupOpenAppendInfFile equ <SetupOpenAppendInfFileA>

SetupOpenAppendInfFileW PROTO :DWORD,:DWORD,:DWORD
SetupOpenFileQueue PROTO 
SetupOpenInfFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupOpenInfFile equ <SetupOpenInfFileA>

SetupOpenInfFileW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupOpenLog PROTO :DWORD
SetupOpenMasterInf PROTO 
SetupPromptForDiskA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupPromptForDisk equ <SetupPromptForDiskA>

SetupPromptForDiskW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupPromptReboot PROTO :DWORD,:DWORD,:DWORD
SetupQueryDrivesInDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupQueryDrivesInDiskSpaceList equ <SetupQueryDrivesInDiskSpaceListA>

SetupQueryDrivesInDiskSpaceListW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupQueryFileLogA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueryFileLog equ <SetupQueryFileLogA>

SetupQueryFileLogW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueryInfFileInformationA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueryInfFileInformation equ <SetupQueryInfFileInformationA>

SetupQueryInfFileInformationW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueryInfOriginalFileInformationA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupQueryInfOriginalFileInformation equ <SetupQueryInfOriginalFileInformationA>

SetupQueryInfOriginalFileInformationW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupQueryInfVersionInformationA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueryInfVersionInformation equ <SetupQueryInfVersionInformationA>

SetupQueryInfVersionInformationW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQuerySourceListA PROTO :DWORD,:DWORD,:DWORD
SetupQuerySourceList equ <SetupQuerySourceListA>

SetupQuerySourceListW PROTO :DWORD,:DWORD,:DWORD
SetupQuerySpaceRequiredOnDriveA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQuerySpaceRequiredOnDrive equ <SetupQuerySpaceRequiredOnDriveA>

SetupQuerySpaceRequiredOnDriveW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueueCopyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueueCopy equ <SetupQueueCopyA>

SetupQueueCopyIndirectA PROTO :DWORD
SetupQueueCopyIndirect equ <SetupQueueCopyIndirectA>

SetupQueueCopyIndirectW PROTO :DWORD
SetupQueueCopySectionA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueueCopySection equ <SetupQueueCopySectionA>

SetupQueueCopySectionW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueueCopyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueueDefaultCopyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueueDefaultCopy equ <SetupQueueDefaultCopyA>

SetupQueueDefaultCopyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueueDeleteA PROTO :DWORD,:DWORD,:DWORD
SetupQueueDelete equ <SetupQueueDeleteA>

SetupQueueDeleteSectionA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupQueueDeleteSection equ <SetupQueueDeleteSectionA>

SetupQueueDeleteSectionW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupQueueDeleteW PROTO :DWORD,:DWORD,:DWORD
SetupQueueRenameA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupQueueRename equ <SetupQueueRenameA>

SetupQueueRenameSectionA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupQueueRenameSection equ <SetupQueueRenameSectionA>

SetupQueueRenameSectionW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetupQueueRenameW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupRemoveFileLogEntryA PROTO :DWORD,:DWORD,:DWORD
SetupRemoveFileLogEntry equ <SetupRemoveFileLogEntryA>

SetupRemoveFileLogEntryW PROTO :DWORD,:DWORD,:DWORD
SetupRemoveFromDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupRemoveFromDiskSpaceList equ <SetupRemoveFromDiskSpaceListA>

SetupRemoveFromDiskSpaceListW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupRemoveFromSourceListA PROTO :DWORD,:DWORD
SetupRemoveFromSourceList equ <SetupRemoveFromSourceListA>

SetupRemoveFromSourceListW PROTO :DWORD,:DWORD
SetupRemoveInstallSectionFromDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupRemoveInstallSectionFromDiskSpaceList equ <SetupRemoveInstallSectionFromDiskSpaceListA>

SetupRemoveInstallSectionFromDiskSpaceListW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupRemoveSectionFromDiskSpaceListA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupRemoveSectionFromDiskSpaceList equ <SetupRemoveSectionFromDiskSpaceListA>

SetupRemoveSectionFromDiskSpaceListW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupRenameErrorA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupRenameError equ <SetupRenameErrorA>

SetupRenameErrorW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupScanFileQueueA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupScanFileQueue equ <SetupScanFileQueueA>

SetupScanFileQueueW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupSetDirectoryIdA PROTO :DWORD,:DWORD,:DWORD
SetupSetDirectoryId equ <SetupSetDirectoryIdA>

SetupSetDirectoryIdExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupSetDirectoryIdEx equ <SetupSetDirectoryIdExA>

SetupSetDirectoryIdExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetupSetDirectoryIdW PROTO :DWORD,:DWORD,:DWORD
SetupSetFileQueueAlternatePlatformA PROTO :DWORD,:DWORD,:DWORD
SetupSetFileQueueAlternatePlatform equ <SetupSetFileQueueAlternatePlatformA>

SetupSetFileQueueAlternatePlatformW PROTO :DWORD,:DWORD,:DWORD
SetupSetPlatformPathOverrideA PROTO :DWORD
SetupSetPlatformPathOverride equ <SetupSetPlatformPathOverrideA>

SetupSetPlatformPathOverrideW PROTO :DWORD
SetupSetSourceListA PROTO :DWORD,:DWORD,:DWORD
SetupSetSourceList equ <SetupSetSourceListA>

SetupSetSourceListW PROTO :DWORD,:DWORD,:DWORD
SetupTermDefaultQueueCallback PROTO :DWORD
SetupTerminateFileLog PROTO :DWORD
ShouldDeviceBeExcluded PROTO :DWORD,:DWORD,:DWORD
StampFileSecurity PROTO :DWORD,:DWORD
StringTableAddString PROTO :DWORD,:DWORD,:DWORD
StringTableAddStringEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StringTableDestroy PROTO :DWORD
StringTableDuplicate PROTO :DWORD
StringTableEnum PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StringTableGetExtraData PROTO :DWORD,:DWORD,:DWORD,:DWORD
StringTableInitialize PROTO 
StringTableInitializeEx PROTO :DWORD,:DWORD
StringTableLookUpString PROTO :DWORD,:DWORD,:DWORD
StringTableLookUpStringEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
StringTableSetExtraData PROTO :DWORD,:DWORD,:DWORD,:DWORD
StringTableStringFromId PROTO :DWORD,:DWORD
StringTableStringFromIdEx PROTO :DWORD,:DWORD,:DWORD,:DWORD
StringTableTrim PROTO :DWORD
TakeOwnershipOfFile PROTO :DWORD
UnicodeToMultiByte PROTO :DWORD,:DWORD
UnmapAndCloseFile PROTO :DWORD,:DWORD,:DWORD
VerifyCatalogFile PROTO :DWORD
VerifyFile PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
pSetupAccessRunOnceNodeList PROTO 
pSetupDestroyRunOnceNodeList PROTO 
pSetupDiGetDeviceInfoContext PROTO :DWORD,:DWORD,:DWORD
pSetupDiSetDeviceInfoContext PROTO :DWORD,:DWORD,:DWORD
pSetupDirectoryIdToPath PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
pSetupGetField PROTO :DWORD,:DWORD
pSetupGetGlobalFlags PROTO 
pSetupGetOsLoaderDriveAndPath PROTO :DWORD,:DWORD,:DWORD,:DWORD
pSetupGetQueueFlags PROTO :DWORD
pSetupGetVersionDatum PROTO :DWORD,:DWORD
pSetupGuidFromString PROTO :DWORD,:DWORD
pSetupIsGuidNull PROTO :DWORD
pSetupMakeSurePathExists PROTO :DWORD
pSetupSetGlobalFlags PROTO :DWORD
pSetupSetQueueFlags PROTO :DWORD,:DWORD
pSetupSetSystemSourcePath PROTO :DWORD,:DWORD
pSetupStringFromGuid PROTO :DWORD,:DWORD,:DWORD
pSetupVerifyQueuedCatalogs PROTO :DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file setupapi.inc
echo -----------------------------------------
ENDIF
