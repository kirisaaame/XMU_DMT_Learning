.386p
.model flat,stdcall
option casemap:none
include		windows.inc
include		gdi32.inc
includelib	gdi32.lib
include		user32.inc
includelib	user32.lib
include		kernel32.inc
includelib	kernel32.lib

WinMain proto :DWORD,:DWORD,:DWORD,:DWORD
LISTITEM STRUCT 
      db 8 dup (0)
LISTITEM ENDS
.data
ClassName               db "ListBoxClass",0
TitleName                db "列表框控件子窗口",0
ButtonClassName     db "BUTTON",0
ListClassName         db "LISTBOX",0
PushButtonText       db "确定",0
List1                       LISTITEM          <"北京市">,<"天津">,<"南京市">,<"沈阳市">,<"广州市">,<"西安市">,<"成都">,<"上海市">,<"武汉">
LISTNUM=($-List1)/sizeof LISTITEM
List2       db ".\*.exe",0
CrlF       db 13,10,0
Prompt   db "您删除了以下城市名",0

.data?
hInstance               HINSTANCE ?
hwndButtonPush    HWND ?
hwndList1             HWND ?
hwndList2             HWND ?
Buffer                   db 20 dup(?)
Dustbin                 db 100 dup (0)
.const
ID_BUTTON_PUSH     equ 1
ID_LIST1                    equ 2
ID_LIST2                   equ 3
.code
start:
   invoke GetModuleHandle, NULL
   mov    hInstance,eax
   invoke WinMain, NULL,NULL,NULL, SW_SHOWDEFAULT
   invoke ExitProcess,eax

WinMain proc hInst:HINSTANCE,hPrevInst:HINSTANCE,CmdLine:LPSTR,CmdShow:DWORD
  LOCAL wc:WNDCLASSEX
   LOCAL msg:MSG
   LOCAL hwnd:HWND
   mov   wc.cbSize,SIZEOF WNDCLASSEX
   mov   wc.style, CS_HREDRAW or CS_VREDRAW or CS_DBLCLKS
   mov   wc.lpfnWndProc, OFFSET WndProc
   mov   wc.cbClsExtra,NULL
   mov   wc.cbWndExtra,NULL
   mov   eax, hInstance
   mov   wc.hInstance,eax
   invoke GetStockObject,WHITE_BRUSH 
   mov   wc.hbrBackground,eax
   mov   wc.lpszMenuName,NULL
   mov   wc.lpszClassName,OFFSET ClassName
   invoke LoadIcon,NULL,IDI_ASTERISK
   mov   wc.hIcon,eax
   mov   wc.hIconSm,0
   invoke LoadCursor,NULL,IDC_HAND
   mov   wc.hCursor,eax
   invoke RegisterClassEx, addr wc
   invoke CreateWindowEx,WS_EX_CLIENTEDGE+WS_EX_APPWINDOW,addr ClassName,\
      addr TitleName,WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,400,300,\
      NULL,NULL,hInst,NULL
   mov   hwnd,eax
   invoke ShowWindow,hwnd,CmdShow
   invoke UpdateWindow,hwnd
   .while TRUE
      invoke GetMessage, addr msg,NULL,0,0
      .BREAK .if (!eax)
      invoke TranslateMessage,addr msg
      invoke DispatchMessage, addr msg
   .endw
   mov eax,msg.wParam
   ret
WinMain endp

WndProc proc hWnd:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM
   .if uMsg==WM_DESTROY
      invoke PostQuitMessage,NULL
   .elseif uMsg==WM_CREATE 
      invoke CreateWindowEx,WS_EX_CLIENTEDGE, ADDR ListClassName,addr TitleName,\
          WS_VISIBLE  or WS_CHILD or LBS_SORT   OR LBS_EXTENDEDSEL or   LBS_STANDARD or LBS_NOTIFY ,\
          20,40,100,100,hWnd,ID_LIST1,hInstance,NULL  
      mov hwndList1,eax                 
      mov ecx,LISTNUM
      push esi
      lea esi,List1 
loopadd:
         push ecx 
         invoke SendMessage,hwndList1,LB_ADDSTRING,NULL,esi
         add esi,sizeof LISTITEM
         pop ecx
      loop loopadd
      pop esi
      invoke CreateWindowEx,WS_EX_CLIENTEDGE, ADDR ListClassName,addr TitleName,\
         WS_VISIBLE  or WS_CHILD or LBS_SORT  or LBS_EXTENDEDSEL or WS_HSCROLL or  LBS_MULTICOLUMN or LBS_NOTIFY ,\
         180,40,180,100,hWnd,ID_LIST2,hInstance,NULL  
      mov hwndList2,eax   
      invoke SendMessage,hwndList2,LB_DIR,DDL_DIRECTORY or DDL_DRIVES,addr List2
      .if eax==0 
         invoke MessageBox,NULL,addr ListClassName,addr TitleName,MB_OK
      .endif
      invoke CreateWindowEx,NULL, ADDR ButtonClassName,addr PushButtonText,\
         WS_VISIBLE or WS_CHILD  or  BS_DEFPUSHBUTTON or BS_VCENTER, 120,190,80,20,hWnd,ID_BUTTON_PUSH,hInstance,NULL
      mov hwndButtonPush,eax              
   .elseif uMsg==WM_COMMAND
      mov eax,wParam
      .if lParam
         .if ax==ID_LIST1
            shr eax,16
            .if ax==LBN_DBLCLK
               invoke SendMessage,hwndList1,LB_GETCURSEL,0,0
               push eax
               invoke SendMessage,hwndList1,LB_GETTEXT,eax,addr Buffer  
               invoke lstrcat,addr Dustbin,addr Buffer
               invoke lstrcat,addr Dustbin,addr CrlF
               pop eax                    
               invoke SendMessage,hwndList1,LB_DELETESTRING,eax,0
            .endif
         .elseif ax==ID_LIST2
            shr eax,16
            .if ax==LBN_DBLCLK
               invoke SendMessage,hwndList2,LB_GETCURSEL,0,0                  
               invoke SendMessage,hwndList2,LB_GETTEXT,eax,addr Buffer
               invoke WinExec,addr Buffer,SW_SHOW
            .endif   
         .elseif ax==ID_BUTTON_PUSH 
            shr eax,16     
            .if ax==BN_CLICKED
               invoke MessageBox,hWnd,addr Dustbin,addr Prompt,MB_OK                 
            .endif
         .endif                        
      .endif
   .else
      invoke DefWindowProc,hWnd,uMsg,wParam,lParam
      ret
   .endif
   xor    eax,eax
   ret
WndProc endp
end start


