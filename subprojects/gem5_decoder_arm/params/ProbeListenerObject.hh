/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   build_tools/sim_object_param_struct_hh.py:50
 */

#ifndef __PARAMS__ProbeListenerObject__
#define __PARAMS__ProbeListenerObject__

namespace gem5 {
class ProbeListenerObject;
} // namespace gem5
#include <cstddef>
#include "params/SimObject.hh"

#include "params/SimObject.hh"

namespace gem5
{
struct ProbeListenerObjectParams
    : public SimObjectParams
{
    gem5::ProbeListenerObject * create() const;
    gem5::SimObject * manager;
};

} // namespace gem5

#endif // __PARAMS__ProbeListenerObject__
