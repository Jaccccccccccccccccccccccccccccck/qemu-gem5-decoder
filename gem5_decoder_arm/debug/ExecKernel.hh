/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   build_tools/debugflaghh.py:127
 */

#ifndef __DEBUG_ExecKernel_HH__
#define __DEBUG_ExecKernel_HH__

#include "base/compiler.hh" // For namespace deprecation
#include "base/debug.hh"
namespace gem5
{

GEM5_DEPRECATED_NAMESPACE(Debug, debug);
namespace debug
{

namespace unions
{
inline union ExecKernel
{
    ~ExecKernel() {}
    SimpleFlag ExecKernel = {
        "ExecKernel", "Filter: Trace kernel mode instructions", false
    };
} ExecKernel;
} // namespace unions

inline constexpr const auto& ExecKernel = 
    ::gem5::debug::unions::ExecKernel.ExecKernel;

} // namespace debug
} // namespace gem5

#endif // __DEBUG_ExecKernel_HH__
