#include <napi.h>

int add(int a, int b);
bool isPrime(int n);

Napi::Number AddWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    int a = info[0].As<Napi::Number>().Int32Value();
    int b = info[1].As<Napi::Number>().Int32Value();
    int result = add(a, b);

    return Napi::Number::New(env, result);
}

Napi::Boolean IsPrimeWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

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
