  ; ===========================================
  ; winscard.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF WINSCARD_INC
WINSCARD_INC equ <1>

SCardAddReaderToGroupA PROTO :DWORD,:DWORD,:DWORD
SCardAddReaderToGroup equ <SCardAddReaderToGroupA>

SCardAddReaderToGroupW PROTO :DWORD,:DWORD,:DWORD
SCardBeginTransaction PROTO :DWORD
SCardCancel PROTO :DWORD
SCardConnectA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardConnect equ <SCardConnectA>

SCardConnectW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardControl PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardDisconnect PROTO :DWORD,:DWORD
SCardEndTransaction PROTO :DWORD,:DWORD
SCardEstablishContext PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardForgetCardTypeA PROTO :DWORD,:DWORD
SCardForgetCardType equ <SCardForgetCardTypeA>

SCardForgetCardTypeW PROTO :DWORD,:DWORD
SCardForgetReaderA PROTO :DWORD,:DWORD
SCardForgetReader equ <SCardForgetReaderA>

SCardForgetReaderGroupA PROTO :DWORD,:DWORD
SCardForgetReaderGroup equ <SCardForgetReaderGroupA>

SCardForgetReaderGroupW PROTO :DWORD,:DWORD
SCardForgetReaderW PROTO :DWORD,:DWORD
SCardFreeMemory PROTO :DWORD,:DWORD
SCardGetAttrib PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardGetCardTypeProviderNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardGetCardTypeProviderName equ <SCardGetCardTypeProviderNameA>

SCardGetCardTypeProviderNameW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardGetProviderIdA PROTO :DWORD,:DWORD,:DWORD
SCardGetProviderId equ <SCardGetProviderIdA>

SCardGetProviderIdW PROTO :DWORD,:DWORD,:DWORD
SCardGetStatusChangeA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardGetStatusChange equ <SCardGetStatusChangeA>

SCardGetStatusChangeW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardIntroduceCardTypeA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardIntroduceCardType equ <SCardIntroduceCardTypeA>

SCardIntroduceCardTypeW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardIntroduceReaderA PROTO :DWORD,:DWORD,:DWORD
SCardIntroduceReader equ <SCardIntroduceReaderA>

SCardIntroduceReaderGroupA PROTO :DWORD,:DWORD
SCardIntroduceReaderGroup equ <SCardIntroduceReaderGroupA>

SCardIntroduceReaderGroupW PROTO :DWORD,:DWORD
SCardIntroduceReaderW PROTO :DWORD,:DWORD,:DWORD
SCardIsValidContext PROTO :DWORD
SCardListCardsA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardListCards equ <SCardListCardsA>

SCardListCardsW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardListInterfacesA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardListInterfaces equ <SCardListInterfacesA>

SCardListInterfacesW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardListReaderGroupsA PROTO :DWORD,:DWORD,:DWORD
SCardListReaderGroups equ <SCardListReaderGroupsA>

SCardListReaderGroupsW PROTO :DWORD,:DWORD,:DWORD
SCardListReadersA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardListReaders equ <SCardListReadersA>

SCardListReadersW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardLocateCardsA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardLocateCards equ <SCardLocateCardsA>

SCardLocateCardsW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardReconnect PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardReleaseContext PROTO :DWORD
SCardRemoveReaderFromGroupA PROTO :DWORD,:DWORD,:DWORD
SCardRemoveReaderFromGroup equ <SCardRemoveReaderFromGroupA>

SCardRemoveReaderFromGroupW PROTO :DWORD,:DWORD,:DWORD
SCardSetAttrib PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardSetCardTypeProviderNameA PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardSetCardTypeProviderName equ <SCardSetCardTypeProviderNameA>

SCardSetCardTypeProviderNameW PROTO :DWORD,:DWORD,:DWORD,:DWORD
SCardState PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardStatusA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardStatus equ <SCardStatusA>

SCardStatusW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
SCardTransmit PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file winscard.inc
echo -----------------------------------------
ENDIF
