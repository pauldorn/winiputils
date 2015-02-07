#include <node.h>
#include <node_buffer.h>
#include <v8.h>
#include <stdlib.h>
#include <string.h>

using namespace node;
using namespace v8;

/*
static void Initialize(Handle<Object> target) {
      HandleScope scope;

      Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
      Local<String> name = String::NewSymbol("Cap");

      Pcap_constructor = Persistent<FunctionTemplate>::New(tpl);
      Pcap_constructor->InstanceTemplate()->SetInternalFieldCount(1);
      Pcap_constructor->SetClassName(name);

      NODE_SET_PROTOTYPE_METHOD(Pcap_constructor, "send", Send);
      NODE_SET_PROTOTYPE_METHOD(Pcap_constructor, "open", Open);
      NODE_SET_PROTOTYPE_METHOD(Pcap_constructor, "close", Close);
#ifdef _WIN32
      NODE_SET_PROTOTYPE_METHOD(Pcap_constructor, "setMinBytes", WIN_SetMin);
#endif

      emit_symbol = NODE_PSYMBOL("emit");
      packet_symbol = NODE_PSYMBOL("packet");
      close_symbol = NODE_PSYMBOL("close");

      target->Set(name, Pcap_constructor->GetFunction());
    }
};
    */

extern "C" {
  void init(Handle<Object> target) {
    HandleScope scope;
/*
    Pcap::Initialize(target);
    target->Set(String::NewSymbol("findDevice"),
                FunctionTemplate::New(FindDevice)->GetFunction());
    target->Set(String::NewSymbol("deviceList"),
                FunctionTemplate::New(ListDevices)->GetFunction());

*/
  }

  NODE_MODULE(winiputils, init);
}
