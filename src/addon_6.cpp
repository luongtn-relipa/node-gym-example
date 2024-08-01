#include <node_api.h>
#include <cassert>

int add(int a, int b);
bool isPrime(int n);

napi_value AddWrapped(napi_env env, napi_callback_info info) {
    size_t argc = 2;
    napi_value args[2];
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    int32_t a, b;
    napi_get_value_int32(env, args[0], &a);
    napi_get_value_int32(env, args[1], &b);

    int result = add(a, b);

    napi_value napi_result;
    napi_create_int32(env, result, &napi_result);

    return napi_result;
}

napi_value IsPrimeWrapped(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_get_cb_info(env, info, &argc, args, nullptr, nullptr);

    int32_t n;
    napi_get_value_int32(env, args[0], &n);

    bool result = isPrime(n);

    napi_value napi_result;
    napi_get_boolean(env, result, &napi_result);

    return napi_result;
}

napi_value Init(napi_env env, napi_value exports) {
    napi_value addFn, isPrimeFn;

    napi_create_function(env, nullptr, 0, AddWrapped, nullptr, &addFn);
    napi_create_function(env, nullptr, 0, IsPrimeWrapped, nullptr, &isPrimeFn);

    napi_set_named_property(env, exports, "add", addFn);
    napi_set_named_property(env, exports, "isPrime", isPrimeFn);

    return exports;
}

NAPI_MODULE(addon6, Init)
