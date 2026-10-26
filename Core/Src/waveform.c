#include "waveform.h"

/* Rises from 0 to WAVE_MAX over the first half of the period, then falls back to 0. */
uint16_t triangle_wave(uint32_t i, uint32_t period)
{
  if (period < 2)
    return 0;

  uint32_t phase = i % period;
  uint32_t half = period / 2;

  if (phase < half)
    return (uint16_t)(phase * WAVE_MAX / half);
  else
    return (uint16_t)((period - phase) * WAVE_MAX / (period - half));
}

/* Rises from 0 to WAVE_MAX over the period, then drops straight back to 0. */
uint16_t sawtooth_wave(uint32_t i, uint32_t period)
{
  if (period < 2)
    return 0;

  uint32_t phase = i % period;
  return (uint16_t)(phase * WAVE_MAX / (period - 1));
}
