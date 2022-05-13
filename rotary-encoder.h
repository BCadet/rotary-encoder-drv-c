#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

#include <stdint.h>

#define ROTARY_ENCODER_MIN 0
#define ROTARY_ENCODER_MAX 255

#define pinA 0
#define pinB 1
#define SW 2

enum rotation_type {
    CW,
    CCW,
};

struct rotary_encoder {
    uint8_t lastA;
    uint8_t lastB;

    enum rotation_type rotation;
    uint8_t position;
    uint8_t sw;
};

void rotary_encoder_event(struct rotary_encoder *encoder, uint8_t pin, uint8_t pin_value);

#endif /* ROTARY_ENCODER_H */
