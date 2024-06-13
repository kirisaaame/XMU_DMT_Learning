  ; ===========================================
  ; winspool.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF WINSPOOL_INC
WINSPOOL_INC equ <1>

ADVANCEDSETUPDIALOG PROTO :DWORD,:DWORD,:DWORD,:DWORD
AbortPrinter PROTO :DWORD
AddFormA PROTO :DWORD,:DWORD,:DWORD
AddForm equ <AddFormA>

AddFormW PROTO :DWORD,:DWORD,:DWORD
AddJobA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddJob equ <AddJobA>

AddJobW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AddMonitorA PROTO :DWORD,:DWORD,:DWORD
AddMonitor equ <AddMonitorA>

AddMonitorW PROTO :DWORD,:DWORD,:DWORD
AddPerMachineConnectionA PROTO :DWORD,:DWORD,:DWORD,:DWORD
AddPerMachineConnection equ <AddPerMachineConnectionA>

AddPerMachineConnectionW PROTO :DWORD,:DWORD,:DWORD,:DWORD
AddPortA PROTO :DWORD,:DWORD,:DWORD
AddPort equ <AddPortA>

AddPortExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
AddPortEx equ <AddPortExA>

AddPortExW PROTO :DWORD,:DWORD,:DWORD,:DWORD
AddPortW PROTO :DWORD,:DWORD,:DWORD
AddPrintProcessorA PROTO :DWORD,:DWORD,:DWORD,:DWORD
AddPrintProcessor equ <AddPrintProcessorA>

AddPrintProcessorW PROTO :DWORD,:DWORD,:DWORD,:DWORD
AddPrintProvidorA PROTO :DWORD,:DWORD,:DWORD
AddPrintProvidor equ <AddPrintProvidorA>

AddPrintProvidorW PROTO :DWORD,:DWORD,:DWORD
AddPrinterA PROTO :DWORD,:DWORD,:DWORD
AddPrinter equ <AddPrinterA>

AddPrinterConnectionA PROTO :DWORD
AddPrinterConnection equ <AddPrinterConnectionA>

AddPrinterConnectionW PROTO :DWORD
AddPrinterDriverA PROTO :DWORD,:DWORD,:DWORD
AddPrinterDriver equ <AddPrinterDriverA>

AddPrinterDriverExA PROTO :DWORD,:DWORD,:DWORD,:DWORD
AddPrinterDriverEx equ <AddPrinterDriverExA>

AddPrinterDriverExW PROTO :DWORD,:DWORD,:DWORD,:DWORD
AddPrinterDriverW PROTO :DWORD,:DWORD,:DWORD
AddPrinterW PROTO :DWORD,:DWORD,:DWORD
AdvancedDocumentPropertiesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AdvancedDocumentProperties equ <AdvancedDocumentPropertiesA>

AdvancedDocumentPropertiesW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
AdvancedSetupDialog PROTO :DWORD,:DWORD,:DWORD,:DWORD
ClosePrinter PROTO :DWORD
CloseSpoolFileHandle PROTO :DWORD,:DWORD
ClusterSplClose PROTO :DWORD
ClusterSplIsAlive PROTO :DWORD
ClusterSplOpen PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CommitSpoolData PROTO :DWORD,:DWORD,:DWORD
ConfigurePortA PROTO :DWORD,:DWORD,:DWORD
ConfigurePort equ <ConfigurePortA>

ConfigurePortW PROTO :DWORD,:DWORD,:DWORD
ConnectToPrinterDlg PROTO :DWORD,:DWORD
ConvertAnsiDevModeToUnicodeDevmode PROTO :DWORD,:DWORD,:DWORD,:DWORD
ConvertUnicodeDevModeToAnsiDevmode PROTO :DWORD,:DWORD,:DWORD,:DWORD
CreatePrinterIC PROTO :DWORD,:DWORD
DEVICECAPABILITIES PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DEVICEMODE PROTO :DWORD,:DWORD,:DWORD,:DWORD
DeleteFormA PROTO :DWORD,:DWORD
DeleteForm equ <DeleteFormA>

DeleteFormW PROTO :DWORD,:DWORD
DeleteMonitorA PROTO :DWORD,:DWORD,:DWORD
DeleteMonitor equ <DeleteMonitorA>

DeleteMonitorW PROTO :DWORD,:DWORD,:DWORD
DeletePerMachineConnectionA PROTO :DWORD,:DWORD
DeletePerMachineConnection equ <DeletePerMachineConnectionA>

DeletePerMachineConnectionW PROTO :DWORD,:DWORD
DeletePortA PROTO :DWORD,:DWORD,:DWORD
DeletePort equ <DeletePortA>

DeletePortW PROTO :DWORD,:DWORD,:DWORD
DeletePrintProcessorA PROTO :DWORD,:DWORD,:DWORD
DeletePrintProcessor equ <DeletePrintProcessorA>

DeletePrintProcessorW PROTO :DWORD,:DWORD,:DWORD
DeletePrintProvidorA PROTO :DWORD,:DWORD,:DWORD
DeletePrintProvidor equ <DeletePrintProvidorA>

DeletePrintProvidorW PROTO :DWORD,:DWORD,:DWORD
DeletePrinter PROTO :DWORD
DeletePrinterConnectionA PROTO :DWORD
DeletePrinterConnection equ <DeletePrinterConnectionA>

DeletePrinterConnectionW PROTO :DWORD
DeletePrinterDataA PROTO :DWORD,:DWORD
DeletePrinterData equ <DeletePrinterDataA>

DeletePrinterDataExA PROTO :DWORD,:DWORD,:DWORD
DeletePrinterDataEx equ <DeletePrinterDataExA>

DeletePrinterDataExW PROTO :DWORD,:DWORD,:DWORD
DeletePrinterDataW PROTO :DWORD,:DWORD
DeletePrinterDriverA PROTO :DWORD,:DWORD,:DWORD
DeletePrinterDriver equ <DeletePrinterDriverA>

DeletePrinterDriverExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DeletePrinterDriverEx equ <DeletePrinterDriverExA>

DeletePrinterDriverExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DeletePrinterDriverW PROTO :DWORD,:DWORD,:DWORD
DeletePrinterIC PROTO :DWORD
DeletePrinterKeyA PROTO :DWORD,:DWORD
DeletePrinterKey equ <DeletePrinterKeyA>

DeletePrinterKeyW PROTO :DWORD,:DWORD
DevQueryPrint PROTO :DWORD,:DWORD,:DWORD
DevQueryPrintEx PROTO :DWORD
DeviceCapabilitiesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DeviceCapabilities equ <DeviceCapabilitiesA>

DeviceCapabilitiesW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DeviceMode PROTO :DWORD,:DWORD,:DWORD,:DWORD
DevicePropertySheets PROTO :DWORD,:DWORD
DocumentEvent PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DocumentPropertiesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DocumentProperties equ <DocumentPropertiesA>

DocumentPropertiesW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DocumentPropertySheets PROTO :DWORD,:DWORD
EXTDEVICEMODE PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EndDocPrinter PROTO :DWORD
EndPagePrinter PROTO :DWORD
EnumFormsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumForms equ <EnumFormsA>

EnumFormsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumJobsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumJobs equ <EnumJobsA>

EnumJobsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumMonitorsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumMonitors equ <EnumMonitorsA>

EnumMonitorsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPerMachineConnectionsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPerMachineConnections equ <EnumPerMachineConnectionsA>

EnumPerMachineConnectionsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPortsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPorts equ <EnumPortsA>

EnumPortsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrintProcessorDatatypesA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrintProcessorDatatypes equ <EnumPrintProcessorDatatypesA>

EnumPrintProcessorDatatypesW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrintProcessorsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrintProcessors equ <EnumPrintProcessorsA>

EnumPrintProcessorsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrinterDataA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrinterData equ <EnumPrinterDataA>

EnumPrinterDataExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrinterDataEx equ <EnumPrinterDataExA>

EnumPrinterDataExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrinterDataW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrinterDriversA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrinterDrivers equ <EnumPrinterDriversA>

EnumPrinterDriversW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrinterKeyA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrinterKey equ <EnumPrinterKeyA>

EnumPrinterKeyW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrinterPropertySheets PROTO :DWORD,:DWORD,:DWORD,:DWORD
EnumPrintersA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
EnumPrinters equ <EnumPrintersA>

EnumPrintersW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ExtDeviceMode PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
FindClosePrinterChangeNotification PROTO :DWORD
FindFirstPrinterChangeNotification PROTO :DWORD,:DWORD,:DWORD,:DWORD
FindNextPrinterChangeNotification PROTO :DWORD,:DWORD,:DWORD,:DWORD
FlushPrinter PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
ForceUnloadDriver PROTO :DWORD
FreePrinterNotifyInfo PROTO :DWORD
GetDefaultPrinterA PROTO :DWORD,:DWORD
GetDefaultPrinter equ <GetDefaultPrinterA>

GetDefaultPrinterW PROTO :DWORD,:DWORD
GetFormA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetForm equ <GetFormA>

GetFormW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetJobA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetJob equ <GetJobA>

GetJobW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrintProcessorDirectoryA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrintProcessorDirectory equ <GetPrintProcessorDirectoryA>

GetPrintProcessorDirectoryW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrinterA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrinter equ <GetPrinterA>

GetPrinterDataA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrinterData equ <GetPrinterDataA>

GetPrinterDataExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrinterDataEx equ <GetPrinterDataExA>

GetPrinterDataExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrinterDataW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrinterDriverA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrinterDriver equ <GetPrinterDriverA>

GetPrinterDriverDirectoryA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrinterDriverDirectory equ <GetPrinterDriverDirectoryA>

GetPrinterDriverDirectoryW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrinterDriverW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetPrinterW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
GetSpoolFileHandle PROTO :DWORD
InitializeDll PROTO :DWORD,:DWORD,:DWORD
LoadPrinterDriver PROTO :DWORD
OpenPrinterA PROTO :DWORD,:DWORD,:DWORD
OpenPrinter equ <OpenPrinterA>

OpenPrinterW PROTO :DWORD,:DWORD,:DWORD
PlayGdiScriptOnPrinterIC PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PrinterMessageBoxA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PrinterMessageBox equ <PrinterMessageBoxA>

PrinterMessageBoxW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PrinterProperties PROTO :DWORD,:DWORD
PublishPrinterA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
PublishPrinter equ <PublishPrinterA>

PublishPrinterW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
QueryColorProfile PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
QueryRemoteFonts PROTO :DWORD,:DWORD,:DWORD
QuerySpoolMode PROTO :DWORD,:DWORD,:DWORD
ReadPrinter PROTO :DWORD,:DWORD,:DWORD,:DWORD
RefCntLoadDriver PROTO :DWORD,:DWORD,:DWORD,:DWORD
RefCntUnloadDriver PROTO :DWORD,:DWORD
ResetPrinterA PROTO :DWORD,:DWORD
ResetPrinter equ <ResetPrinterA>

ResetPrinterW PROTO :DWORD,:DWORD
ScheduleJob PROTO :DWORD,:DWORD
SeekPrinter PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetAllocFailCount PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetDefaultPrinterA PROTO :DWORD
SetDefaultPrinter equ <SetDefaultPrinterA>

SetDefaultPrinterW PROTO :DWORD
SetFormA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetForm equ <SetFormA>

SetFormW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetJobA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetJob equ <SetJobA>

SetJobW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetPortA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetPort equ <SetPortA>

SetPortW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetPrinterA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SetPrinter equ <SetPrinterA>

SetPrinterDataA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetPrinterData equ <SetPrinterDataA>

SetPrinterDataExA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetPrinterDataEx equ <SetPrinterDataExA>

SetPrinterDataExW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetPrinterDataW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SetPrinterW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SplDriverUnloadComplete PROTO :DWORD
SplReadPrinter PROTO :DWORD,:DWORD,:DWORD
SpoolerDevQueryPrintW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SpoolerInit PROTO 
SpoolerPrinterEvent PROTO :DWORD,:DWORD,:DWORD,:DWORD
StartDocDlgA PROTO :DWORD,:DWORD
StartDocDlg equ <StartDocDlgA>

StartDocDlgW PROTO :DWORD,:DWORD
StartDocPrinterA PROTO :DWORD,:DWORD,:DWORD
StartDocPrinter equ <StartDocPrinterA>

StartDocPrinterW PROTO :DWORD,:DWORD,:DWORD
StartPagePrinter PROTO :DWORD
WaitForPrinterChange PROTO :DWORD,:DWORD
WritePrinter PROTO :DWORD,:DWORD,:DWORD,:DWORD
XcvDataW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file winspool.inc
echo -----------------------------------------
ENDIF
