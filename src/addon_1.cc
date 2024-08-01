#include <node.h>

void Hello(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();
  args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "Hello from add on 1").ToLocalChecked());
}

void Sum(const v8::FunctionCallbackInfo<v8::Value>& args) {
    v8::Isolate* isolate = args.GetIsolate();

    // Check number of input parameters
    if (args.Length() < 1 || !args[0]->IsArray()) {
        isolate->ThrowException(v8::Exception::TypeError(
            v8::String::NewFromUtf8(isolate, "Argument must be an array", v8::NewStringType::kNormal).ToLocalChecked()));
        return;
    }

    // Get JavaScript array
    v8::Local<v8::Array> inputArray = v8::Local<v8::Array>::Cast(args[0]);
    double sum = 0;

    // Loop array
    for (unsigned int i = 0; i < inputArray->Length(); i++) {
        v8::Local<v8::Value> element = inputArray->Get(isolate->GetCurrentContext(), i).ToLocalChecked();
        if (element->IsNumber()) {
            sum += element->NumberValue(isolate->GetCurrentContext()).FromJust();
        }
    }

    // Return value
    args.GetReturnValue().Set(v8::Number::New(isolate, sum));
}

void Init(v8::Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "hello", Hello);
  NODE_SET_METHOD(exports, "sum", Sum);
}

NODE_MODULE(addon_1, Init)