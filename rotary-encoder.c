#include "rotary-encoder.h"

void rotary_encoder_event(struct rotary_encoder *encoder, uint8_t pin, uint8_t pin_value)
{
    if(pin == pinA)
    {
        if(pin_value != encoder->lastA)
        {
            if(pin_value == encoder->lastB)
            {
                if(encoder->position == 0)
                {
                    encoder->position = ROTARY_ENCODER_MAX;
                }
                else
                {
                    encoder->position--;
                }
                encoder->rotation = CCW;
            }
            else
            {
                encoder->position = (encoder->position+1)%ROTARY_ENCODER_MAX;
                encoder->rotation = CW;
            }
            encoder->lastA = pin_value;
        }
    }
    else if(pin == pinB)
    {
        encoder->lastB = pin_value;
    }
    else
    {
        encoder->sw = pin_value;
    }
}
