#include <node.h>
#include <node_buffer.h>
#include <nan.h>
#include <pcap.h>
#include <stdlib.h>
#include <string.h>
#include <Objbase.h>
#include <Netioapi.h>
#include <Iphlpapi.h>


#if _MSC_VER == 1500
#define NTDDI_VERSION NTDDI_WIN2K
#define _WIN32_WINNT _WIN32_WINNT_WIN2K
#endif

using namespace node;
using namespace v8;


NAN_METHOD(GetFriendlyName) {
    NanScope();
    // Expect the {GUID} only
    CLSID guid;
    PWSTR wFriendlyName[IF_MAX_STRING_SIZE * 2];
    LPSTR friendlyName[IF_MAX_STRING_SIZE + 1];
    PWSTR wDeviceName[IF_MAX_STRING_SIZE * 2];

    NanUtf8String deviceName(args[0]->ToString());

    hr = MultiByteToWideChar(CP_UTF8, 0, (*deviceName), -1, (LPWSTR)wDeviceName, IF_MAX_STRING_SIZE * 2);
    hr = CLSIDFromString((LPCOLESTR)wDeviceName,&guid);
    NET_LUID InterfaceLuid;

    hr = ConvertInterfaceGuidToLuid(&guid, &InterfaceLuid);
    hr = ConvertInterfaceLuidToAlias(&InterfaceLuid, (LPWSTR)wFriendlyName, IF_MAX_STRING_SIZE+1);
    WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)wFriendlyName, -1, (LPSTR)friendlyName, IF_MAX_STRING_SIZE * 2, NULL, NULL);
    NanReturnValue(NanNew<String>((char *)friendlyName));
}


extern "C" {
  void init(Handle<Object> target) {
    NanScope();

//    target->Set(NanNew<String>("findDevice"),
//            NanNew<FunctionTemplate>(FindDevice)->GetFunction());
    target->Set(NanNew<String>("GetFriendlyName"),
            NanNew<FunctionTemplate>(GetFriendlyName)->GetFunction());

  }

  NODE_MODULE(WinIpUtils, init);
}
