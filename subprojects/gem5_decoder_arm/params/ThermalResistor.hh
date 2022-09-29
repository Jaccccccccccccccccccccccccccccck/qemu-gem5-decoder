/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   build_tools/sim_object_param_struct_hh.py:50
 */

#ifndef __PARAMS__ThermalResistor__
#define __PARAMS__ThermalResistor__

namespace gem5 {
class ThermalResistor;
} // namespace gem5
#include <cstddef>

#include "params/SimObject.hh"

namespace gem5
{
struct ThermalResistorParams
    : public SimObjectParams
{
    gem5::ThermalResistor * create() const;
    double resistance;
};

} // namespace gem5

#endif // __PARAMS__ThermalResistor__