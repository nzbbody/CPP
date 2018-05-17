#ifndef UTILS_H_
#define UTILS_H_

#include "dhnetsdk.h"
#include <string>


void PrintDevice(const DEVICE_NET_INFO& device);

std::string GetIPV6(const char* const ip);

#endif