#ifndef DECODERWRAPPER_CPP_INCLUDED
#define DECODERWRAPPER_CPP_INCLUDED

#include <iostream>

#include "arch/arm/decoder.hh"

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

void decode(int inst) {
    long long int _inst = inst | 1L << 34; // set bit 34 of inst = 1, bit 34 of inst is a extra flag for aarch64 of ExtMachInst; 
    gem5::StaticInst *a = gem5::ArmISA::Decoder::decodeInst(inst).get();
    cout << a->getName() << endl;
}

#ifdef __cplusplus
}
#endif

#endif /* DECODERWRAPPER_CPP_INCLUDED */