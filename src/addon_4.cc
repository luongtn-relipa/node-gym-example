#include <napi.h>
#include <cmath>
#include <iostream>
#include <ostream>

int add(int a, int b) {
    return a + b;
}

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return n >= 2;
}

void mainFunction() {
    std::cout << "Running main function" << std::endl;
    int sum = add(3, 4);
    bool prime = isPrime(7);
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Is 7 prime: " << prime << std::endl;
}

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

Napi::Value MainFunctionWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    mainFunction();

    return env.Undefined();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, AddWrapped));
    exports.Set(Napi::String::New(env, "isPrime"), Napi::Function::New(env, IsPrimeWrapped));
    exports.Set(Napi::String::New(env, "mainFunction"), Napi::Function::New(env, MainFunctionWrapped));
    return exports;
}

NODE_API_MODULE(addon4, Init)
