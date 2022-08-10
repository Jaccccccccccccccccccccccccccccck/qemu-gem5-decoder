/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/workspace/gem5/build/ARM/SConscript:781
 */

#include "base/compiler.hh"
#include "enums/OpClass.hh"

namespace gem5
{

GEM5_DEPRECATED_NAMESPACE(Enums, enums);
namespace enums
{
    const char *OpClassStrings[Num_OpClass] =
    {
        "No_OpClass",
        "IntAlu",
        "IntMult",
        "IntDiv",
        "FloatAdd",
        "FloatCmp",
        "FloatCvt",
        "FloatMult",
        "FloatMultAcc",
        "FloatDiv",
        "FloatMisc",
        "FloatSqrt",
        "SimdAdd",
        "SimdAddAcc",
        "SimdAlu",
        "SimdCmp",
        "SimdCvt",
        "SimdMisc",
        "SimdMult",
        "SimdMultAcc",
        "SimdShift",
        "SimdShiftAcc",
        "SimdDiv",
        "SimdSqrt",
        "SimdFloatAdd",
        "SimdFloatAlu",
        "SimdFloatCmp",
        "SimdFloatCvt",
        "SimdFloatDiv",
        "SimdFloatMisc",
        "SimdFloatMult",
        "SimdFloatMultAcc",
        "SimdFloatSqrt",
        "SimdReduceAdd",
        "SimdReduceAlu",
        "SimdReduceCmp",
        "SimdFloatReduceAdd",
        "SimdFloatReduceCmp",
        "SimdAes",
        "SimdAesMix",
        "SimdSha1Hash",
        "SimdSha1Hash2",
        "SimdSha256Hash",
        "SimdSha256Hash2",
        "SimdShaSigma2",
        "SimdShaSigma3",
        "SimdPredAlu",
        "MemRead",
        "MemWrite",
        "FloatMemRead",
        "FloatMemWrite",
        "IprAccess",
        "InstPrefetch",
    };
} // namespace enums
} // namespace gem5
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("enum_OpClass");

py::enum_<enums::OpClass>(m, "enum_OpClass")
        .value("No_OpClass", enums::No_OpClass)
        .value("IntAlu", enums::IntAlu)
        .value("IntMult", enums::IntMult)
        .value("IntDiv", enums::IntDiv)
        .value("FloatAdd", enums::FloatAdd)
        .value("FloatCmp", enums::FloatCmp)
        .value("FloatCvt", enums::FloatCvt)
        .value("FloatMult", enums::FloatMult)
        .value("FloatMultAcc", enums::FloatMultAcc)
        .value("FloatDiv", enums::FloatDiv)
        .value("FloatMisc", enums::FloatMisc)
        .value("FloatSqrt", enums::FloatSqrt)
        .value("SimdAdd", enums::SimdAdd)
        .value("SimdAddAcc", enums::SimdAddAcc)
        .value("SimdAlu", enums::SimdAlu)
        .value("SimdCmp", enums::SimdCmp)
        .value("SimdCvt", enums::SimdCvt)
        .value("SimdMisc", enums::SimdMisc)
        .value("SimdMult", enums::SimdMult)
        .value("SimdMultAcc", enums::SimdMultAcc)
        .value("SimdShift", enums::SimdShift)
        .value("SimdShiftAcc", enums::SimdShiftAcc)
        .value("SimdDiv", enums::SimdDiv)
        .value("SimdSqrt", enums::SimdSqrt)
        .value("SimdFloatAdd", enums::SimdFloatAdd)
        .value("SimdFloatAlu", enums::SimdFloatAlu)
        .value("SimdFloatCmp", enums::SimdFloatCmp)
        .value("SimdFloatCvt", enums::SimdFloatCvt)
        .value("SimdFloatDiv", enums::SimdFloatDiv)
        .value("SimdFloatMisc", enums::SimdFloatMisc)
        .value("SimdFloatMult", enums::SimdFloatMult)
        .value("SimdFloatMultAcc", enums::SimdFloatMultAcc)
        .value("SimdFloatSqrt", enums::SimdFloatSqrt)
        .value("SimdReduceAdd", enums::SimdReduceAdd)
        .value("SimdReduceAlu", enums::SimdReduceAlu)
        .value("SimdReduceCmp", enums::SimdReduceCmp)
        .value("SimdFloatReduceAdd", enums::SimdFloatReduceAdd)
        .value("SimdFloatReduceCmp", enums::SimdFloatReduceCmp)
        .value("SimdAes", enums::SimdAes)
        .value("SimdAesMix", enums::SimdAesMix)
        .value("SimdSha1Hash", enums::SimdSha1Hash)
        .value("SimdSha1Hash2", enums::SimdSha1Hash2)
        .value("SimdSha256Hash", enums::SimdSha256Hash)
        .value("SimdSha256Hash2", enums::SimdSha256Hash2)
        .value("SimdShaSigma2", enums::SimdShaSigma2)
        .value("SimdShaSigma3", enums::SimdShaSigma3)
        .value("SimdPredAlu", enums::SimdPredAlu)
        .value("MemRead", enums::MemRead)
        .value("MemWrite", enums::MemWrite)
        .value("FloatMemRead", enums::FloatMemRead)
        .value("FloatMemWrite", enums::FloatMemWrite)
        .value("IprAccess", enums::IprAccess)
        .value("InstPrefetch", enums::InstPrefetch)
        .value("Num_OpClass", enums::Num_OpClass)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_OpClass", module_init);

} // namespace gem5
