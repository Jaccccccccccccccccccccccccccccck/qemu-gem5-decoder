/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   build_tools/sim_object_param_struct_hh.py:50
 */

#ifndef __PARAMS__RedirectPath__
#define __PARAMS__RedirectPath__

namespace gem5 {
class RedirectPath;
} // namespace gem5
#include <cstddef>
#include <string>
#include <vector>
#include <string>

#include "params/SimObject.hh"

namespace gem5
{
struct RedirectPathParams
    : public SimObjectParams
{
    gem5::RedirectPath * create() const;
    std::string app_path;
    std::vector< std::string > host_paths;
};

} // namespace gem5

#endif // __PARAMS__RedirectPath__
