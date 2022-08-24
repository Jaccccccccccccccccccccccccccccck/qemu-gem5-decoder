/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   build_tools/sim_object_param_struct_hh.py:50
 */

#ifndef __PARAMS__BaseGic__
#define __PARAMS__BaseGic__

namespace gem5 {
class BaseGic;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/Platform.hh"

#include "params/PioDevice.hh"

namespace gem5
{
struct BaseGicParams
    : public PioDeviceParams
{
    uint32_t gicc_iidr;
    uint32_t gicd_iidr;
    uint32_t gicd_pidr;
    uint32_t gicv_iidr;
    gem5::Platform * platform;
};

} // namespace gem5

#endif // __PARAMS__BaseGic__
