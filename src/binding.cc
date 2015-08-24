#include <node.h>
#include <node_buffer.h>
#include <nan.h>
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


NAN_METHOD(GetInterfaceFriendlyName) {
    NanScope();
    // Expect the {GUID} only
    CLSID guid;
    PWSTR wFriendlyName[IF_MAX_STRING_SIZE * 2];
    LPSTR friendlyName[IF_MAX_STRING_SIZE + 1];
    PWSTR wDeviceName[IF_MAX_STRING_SIZE * 2];
    HRESULT hr = 0;
    NET_LUID InterfaceLuid;

    NanUtf8String deviceName(args[0]->ToString());

    hr = MultiByteToWideChar(CP_UTF8, 0, (*deviceName), -1, (LPWSTR)wDeviceName, IF_MAX_STRING_SIZE * 2);
    if ( hr > 0 ) {
        CLSIDFromString((LPCOLESTR)wDeviceName,&guid);
        hr = ConvertInterfaceGuidToLuid(&guid, &InterfaceLuid);
        if ( NO_ERROR == hr ) {
            hr = ConvertInterfaceLuidToAlias(&InterfaceLuid, (LPWSTR)wFriendlyName, IF_MAX_STRING_SIZE+1);
            if ( NO_ERROR == hr ) {
                hr = WideCharToMultiByte(CP_UTF8, 0, (LPCWSTR)wFriendlyName, -1, (LPSTR)friendlyName, IF_MAX_STRING_SIZE * 2, NULL, NULL);
                if ( hr > 0 ) {
                    NanReturnValue(NanNew<String>((char *)friendlyName));
                    return;
                }
            }
        }
    }
    NanReturnValue(NanNew<Boolean>(0));
}


extern "C" {
  void init(Handle<Object> target) {
    NanScope();

//    target->Set(NanNew<String>("findDevice"),
//            NanNew<FunctionTemplate>(FindDevice)->GetFunction());
    target->Set(NanNew<String>("GetInterfaceFriendlyName"),
            NanNew<FunctionTemplate>(GetInterfaceFriendlyName)->GetFunction());

  }

  NODE_MODULE(WinIpUtils, init);
}
