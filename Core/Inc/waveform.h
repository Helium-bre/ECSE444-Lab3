#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <stdint.h>

/* Highest value for the 12-bit right-aligned DAC (DAC_ALIGN_12B_R). */
#define WAVE_MAX 4095u

/*
 * Return sample number `i` of a wave that repeats every `period` samples.
 * Values range from 0 to WAVE_MAX, ready for HAL_DAC_SetValue(..., DAC_ALIGN_12B_R, ...).
 * `i` can keep counting up forever; it wraps around the period internally.
 *
 * Output frequency = sample rate / period.
 */
uint16_t triangle_wave(uint32_t i, uint32_t period);
uint16_t sawtooth_wave(uint32_t i, uint32_t period);

#endif /* WAVEFORM_H */
