#ifndef vcl_config_manual_h_
#define vcl_config_manual_h_

// This file either is or was generated from vcl_config_manual.h.in

// -------------------- manual options

// -- VCL_USE_NATIVE_STL
// Whether to use the compiler's STL.
#define VCL_USE_NATIVE_STL 1


// -- VCL_USE_NATIVE_COMPLEX
// Whether to use the compiler's complex type.
#define VCL_USE_NATIVE_COMPLEX 1
// Used to be set from VCL_USE_NATIVE_STL, which worked fine.
// If you don't use the stl flag's setting you're on your own.
// #define VCL_USE_NATIVE_COMPLEX VCL_USE_NATIVE_STL


// -- VCL_USE_LONG_DOUBLE
// Whether to use long double.
#define VCL_USE_LONG_DOUBLE 1

#endif // vcl_config_manual_h_
