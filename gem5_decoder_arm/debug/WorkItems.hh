/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   build_tools/debugflaghh.py:127
 */

#ifndef __DEBUG_WorkItems_HH__
#define __DEBUG_WorkItems_HH__

#include "base/compiler.hh" // For namespace deprecation
#include "base/debug.hh"
namespace gem5
{

GEM5_DEPRECATED_NAMESPACE(Debug, debug);
namespace debug
{

namespace unions
{
inline union WorkItems
{
    ~WorkItems() {}
    SimpleFlag WorkItems = {
        "WorkItems", "", false
    };
} WorkItems;
} // namespace unions

inline constexpr const auto& WorkItems = 
    ::gem5::debug::unions::WorkItems.WorkItems;

} // namespace debug
} // namespace gem5

#endif // __DEBUG_WorkItems_HH__
