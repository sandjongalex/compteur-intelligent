#ifndef ALEXTECH_SIMULATION_M09_H
#define ALEXTECH_SIMULATION_M09_H
#include <stdint.h>

// Simulation pedagogique a puissance fixe de 92,2 W.
// 92200 mW * temps (ms) / 3 600 000 000 = Wh.
// L'arithmetique des differences uint32_t gere le rollover de millis()
// si deux appels successifs sont espaces de moins de 49,7 jours.
class SimulateurEnergieM09 {
  uint32_t precedentMs_;
  uint32_t indexWh_;
  uint64_t resteMilliWms_;
public:
  explicit SimulateurEnergieM09(uint32_t initialWh=12345UL)
    : precedentMs_(0), indexWh_(initialWh), resteMilliWms_(0) {}
  uint32_t indexWh(uint32_t ms) {
    const uint32_t deltaMs=ms-precedentMs_;
    precedentMs_=ms;
    resteMilliWms_+=(uint64_t)92200UL*deltaMs;
    const uint64_t deltaWh=resteMilliWms_/3600000000ULL;
    resteMilliWms_%=3600000000ULL;
    if(deltaWh > (uint64_t)UINT32_MAX-indexWh_) {
      indexWh_=UINT32_MAX;
      resteMilliWms_=0;
    } else indexWh_+=(uint32_t)deltaWh;
    return indexWh_;
  }
};
#endif
