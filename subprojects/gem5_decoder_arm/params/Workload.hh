/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   build_tools/sim_object_param_struct_hh.py:50
 */

#ifndef __PARAMS__Workload__
#define __PARAMS__Workload__

namespace gem5 {
class Workload;
} // namespace gem5
#include <cstddef>

#include "params/SimObject.hh"

namespace gem5
{
struct WorkloadParams
    : public SimObjectParams
{
    bool wait_for_remote_gdb;
};

} // namespace gem5

#endif // __PARAMS__Workload__