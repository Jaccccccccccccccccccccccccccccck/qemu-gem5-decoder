#ifndef DECODERWRAPPER_CPP_INCLUDED
#define DECODERWRAPPER_CPP_INCLUDED

#include <iostream>

#include "arch/arm/decoder.hh"

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

void decode_opcode(uint32_t inst, char* res) {
    uint64_t _inst = inst | 1L << 34; // set bit 34 of inst = 1, bit 34 of inst is a extra flag for aarch64 of ExtMachInst; 
    gem5::StaticInst *a = gem5::ArmISA::Decoder::decodeInst(_inst).get();
    string opcode = a->getName();
    opcode.copy(res, opcode.length());
}

#ifdef __cplusplus
}
#endif

#endif /* DECODERWRAPPER_CPP_INCLUDED */