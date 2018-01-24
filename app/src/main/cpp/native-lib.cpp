#include <jni.h>
#include <string>

constexpr auto foo(int bar) noexcept {
    if (const auto k = bar / 3; k < 3) {
        return 44;
    }

    return 33 * bar;
}

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_hckaye_a17test_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    const int32_t i = 3;
    const auto f = [j = std::move(i)](int x) constexpr { return x * j; };
    return env->NewStringUTF(std::to_string(f(3) * foo(34)).c_str());
}

