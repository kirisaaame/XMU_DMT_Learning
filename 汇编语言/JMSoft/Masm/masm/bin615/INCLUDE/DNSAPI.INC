  ; ===========================================
  ; dnsapi.inc copyright MASM32 1998 - 2005
  ; ===========================================

IFNDEF DNSAPI_INC
DNSAPI_INC equ <1>

DnsAcquireContextHandle_A PROTO :DWORD,:DWORD,:DWORD
DnsAcquireContextHandle_ equ <DnsAcquireContextHandle_A>

DnsAcquireContextHandle_UTF8 PROTO :DWORD,:DWORD,:DWORD
DnsAcquireContextHandle_W PROTO :DWORD,:DWORD,:DWORD
DnsAddRecordSet_A PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsAddRecordSet_ equ <DnsAddRecordSet_A>

DnsAddRecordSet_UTF8 PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsAddRecordSet_W PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsAllocateRecord PROTO :DWORD
DnsApiHeapReset PROTO :DWORD,:DWORD,:DWORD
DnsAsyncRegisterHostAddrs_A PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsAsyncRegisterHostAddrs_ equ <DnsAsyncRegisterHostAddrs_A>

DnsAsyncRegisterHostAddrs_UTF8 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsAsyncRegisterHostAddrs_W PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsAsyncRegisterInit PROTO :DWORD
DnsAsyncRegisterTerm PROTO 
DnsCheckNameCollision_A PROTO :DWORD,:DWORD
DnsCheckNameCollision_ equ <DnsCheckNameCollision_A>

DnsCheckNameCollision_UTF8 PROTO :DWORD,:DWORD
DnsCheckNameCollision_W PROTO :DWORD,:DWORD
DnsCopyStringEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsCreateReverseNameStringForIpAddress PROTO :DWORD
DnsCreateStandardDnsNameCopy PROTO :DWORD,:DWORD,:DWORD
DnsCreateStringCopy PROTO :DWORD,:DWORD
DnsDhcpSrvRegisterHostName_W PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsDhcpSrvRegisterInit PROTO 
DnsDhcpSrvRegisterTerm PROTO 
DnsDisableAdapterDomainNameRegistration PROTO :DWORD
DnsDisableBNodeResolverThread PROTO 
DnsDisableDynamicRegistration PROTO :DWORD
DnsDllInit PROTO :DWORD,:DWORD,:DWORD
DnsDowncaseDnsNameLabel PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsEnableAdapterDomainNameRegistration PROTO :DWORD
DnsEnableBNodeResolverThread PROTO 
DnsEnableDynamicRegistration PROTO :DWORD
DnsExtractRecordsFromMessage_UTF8 PROTO :DWORD,:DWORD,:DWORD
DnsExtractRecordsFromMessage_W PROTO :DWORD,:DWORD,:DWORD
DnsFindAuthoritativeZone PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsFlushResolverCache PROTO 
DnsFlushResolverCacheEntry_A PROTO :DWORD
DnsFlushResolverCacheEntry_ equ <DnsFlushResolverCacheEntry_A>

DnsFlushResolverCacheEntry_UTF8 PROTO :DWORD
DnsFlushResolverCacheEntry_W PROTO :DWORD
DnsFreeAdapterInformation PROTO :DWORD
DnsFreeNetworkInformation PROTO :DWORD
DnsFreeSearchInformation PROTO :DWORD
DnsGetBufferLengthForStringCopy PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsGetCacheDataTable PROTO :DWORD
DnsGetHostName_A PROTO 
DnsGetHostName_ equ <DnsGetHostName_A>

DnsGetHostName_UTF8 PROTO 
DnsGetHostName_W PROTO 
DnsGetLastServerUpdateIP PROTO 
DnsGetMaxNumberOfAddressesToRegister PROTO :DWORD
DnsGetNetworkInformation PROTO 
DnsGetPrimaryDomainName_A PROTO 
DnsGetPrimaryDomainName_ equ <DnsGetPrimaryDomainName_A>

DnsGetPrimaryDomainName_UTF8 PROTO 
DnsGetPrimaryDomainName_W PROTO 
DnsGetSearchInformation PROTO 
DnsIpv6AddressToString PROTO :DWORD,:DWORD
DnsIpv6StringToAddress PROTO :DWORD,:DWORD,:DWORD
DnsIsAdapterDomainNameRegistrationEnabled PROTO :DWORD
DnsIsDynamicRegistrationEnabled PROTO :DWORD
DnsIsStringCountValidForTextType PROTO :DWORD,:DWORD
DnsModifyRecordSet_A PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsModifyRecordSet_ equ <DnsModifyRecordSet_A>

DnsModifyRecordSet_UTF8 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsModifyRecordSet_W PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsModifyRecordsInSet_A PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsModifyRecordsInSet_ equ <DnsModifyRecordsInSet_A>

DnsModifyRecordsInSet_UTF8 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsModifyRecordsInSet_W PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsNameCompareEx_A PROTO :DWORD,:DWORD,:DWORD
DnsNameCompareEx_ equ <DnsNameCompareEx_A>

DnsNameCompareEx_UTF8 PROTO :DWORD,:DWORD,:DWORD
DnsNameCompareEx_W PROTO :DWORD,:DWORD,:DWORD
DnsNameCompare_A PROTO :DWORD,:DWORD
DnsNameCompare_ equ <DnsNameCompare_A>

DnsNameCompare_W PROTO :DWORD,:DWORD
DnsNameCopy PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsNameCopyAllocate PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsQueryConfig PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsQueryEx PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsQuery_A PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsQuery_ equ <DnsQuery_A>

DnsQuery_UTF8 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsQuery_W PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsRecordBuild_UTF8 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsRecordBuild_W PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsRecordCompare PROTO :DWORD,:DWORD
DnsRecordCopyEx PROTO :DWORD,:DWORD,:DWORD
DnsRecordListFree PROTO :DWORD,:DWORD
DnsRecordSetCompare PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsRecordSetCopyEx PROTO :DWORD,:DWORD,:DWORD
DnsRecordSetDetach PROTO :DWORD
DnsRecordStringForType PROTO :DWORD
DnsRecordStringForWritableType PROTO :DWORD
DnsRecordTypeForName PROTO :DWORD,:DWORD
DnsRelationalCompare_UTF8 PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsRelationalCompare_W PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsReleaseContextHandle PROTO :DWORD
DnsRemoveRegistrations PROTO 
DnsReplaceRecordSetA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsReplaceRecordSet equ <DnsReplaceRecordSetA>

DnsReplaceRecordSetUTF8 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsReplaceRecordSetW PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsReplaceRecordSet_A PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsReplaceRecordSet_ equ <DnsReplaceRecordSet_A>

DnsReplaceRecordSet_UTF8 PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsReplaceRecordSet_W PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsServiceNotificationDeregister_A PROTO :DWORD
DnsServiceNotificationDeregister_ equ <DnsServiceNotificationDeregister_A>

DnsServiceNotificationDeregister_UTF8 PROTO :DWORD
DnsServiceNotificationDeregister_W PROTO :DWORD
DnsServiceNotificationRegister_A PROTO :DWORD,:DWORD
DnsServiceNotificationRegister_ equ <DnsServiceNotificationRegister_A>

DnsServiceNotificationRegister_UTF8 PROTO :DWORD,:DWORD
DnsServiceNotificationRegister_W PROTO :DWORD,:DWORD
DnsSetMaxNumberOfAddressesToRegister PROTO :DWORD,:DWORD
DnsStringCopyAllocateEx PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsUpdate PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsUpdateTest_A PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsUpdateTest_ equ <DnsUpdateTest_A>

DnsUpdateTest_UTF8 PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsUpdateTest_W PROTO :DWORD,:DWORD,:DWORD,:DWORD
DnsValidateName_A PROTO :DWORD,:DWORD
DnsValidateName_ equ <DnsValidateName_A>

DnsValidateName_UTF8 PROTO :DWORD,:DWORD
DnsValidateName_W PROTO :DWORD,:DWORD
DnsValidateUtf8Byte PROTO :DWORD,:DWORD
DnsWinsRecordFlagForString PROTO :DWORD,:DWORD
DnsWinsRecordFlagString PROTO :DWORD,:DWORD
DnsWriteQuestionToBuffer_UTF8 PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsWriteQuestionToBuffer_W PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
DnsWriteReverseNameStringForIpAddress PROTO :DWORD,:DWORD
GetCurrentTimeInSeconds PROTO 

ELSE
echo -----------------------------------------
echo WARNING Duplicate include file dnsapi.inc
echo -----------------------------------------
ENDIF
