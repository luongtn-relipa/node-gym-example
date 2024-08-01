#include <napi.h>
#include "test.h"

Napi::Number AddWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::TypeError::New(env, "Number arguments expected").ThrowAsJavaScriptException();
    }

    int arg0 = info[0].As<Napi::Number>().Int32Value();
    int arg1 = info[1].As<Napi::Number>().Int32Value();
    int result = add(arg0, arg1);

    return Napi::Number::New(env, result);
}

Napi::Boolean IsPrimeWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (!info[0].IsNumber()) {
        Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    }

    int n = info[0].As<Napi::Number>().Int32Value();
    bool result = isPrime(n);

    return Napi::Boolean::New(env, result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, AddWrapped));
    exports.Set(Napi::String::New(env, "isPrime"), Napi::Function::New(env, IsPrimeWrapped));
    return exports;
}

NODE_API_MODULE(addon, Init)
