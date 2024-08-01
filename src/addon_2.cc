#include <napi.h>

Napi::String Hello(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    return Napi::String::New(env, "Hello from add on 2");
}

Napi::Value Sum(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1 || !info[0].IsArray()) {
        Napi::TypeError::New(env, "Argument must be an array").ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::Array inputArray = info[0].As<Napi::Array>();
    double sum = 0;

    for (uint32_t i = 0; i < inputArray.Length(); i++) {
        Napi::Value element = inputArray[i];
        if (element.IsNumber()) {
            sum += element.As<Napi::Number>().DoubleValue();
        }
    }

    return Napi::Number::New(env, sum);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, Hello));
    exports.Set(Napi::String::New(env, "sum"), Napi::Function::New(env, Sum));
    return exports;
}

NODE_API_MODULE(addon_2, Init)
