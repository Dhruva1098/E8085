// Copyright 2024 Dhruva Sharma

#ifndef E8085_HEADERS_FLAG_H_
#define E8085_HEADERS_FLAG_H_

#include <iostream>

class _FLAG_ {
    uint8_t FLAG;

 public:
    _FLAG_() :FLAG(0) {};
    bool get_sign() {
        return unsigned(FLAG << 7);
    }
    void set_flag() {
        FLAG |= 0b10000000;
    }
    void reset_flag() {
        FLAG &= 0b01111111;
    }

    bool get_zero() {
        return unsigned(FLAG << 6);
    }
    void set_zero() {
        FLAG |= 0b01000000;
    }
    void reset_zero() {
        FLAG &= 0b10111111;
    }

    bool get_aux_carry() {
        return unsigned(FLAG << 4);
    }
    void set_aux_carry() {
        FLAG |= 0b00001000;
    }
    void reset_aux_carry() {
        FLAG &= 0b11110111;
    }

    bool get_parity() {
        return unsigned(FLAG << 2);
    }
    void set_parity() {
        FLAG |= 0b00000010;
    }
    void reset_parity() {
        FLAG &= 0b11111101;
    }

    bool get_carry() {
        return unsigned(FLAG << 1);
    }
    void set_carry() {
        FLAG |= 0b00000001;
    }
    void reset_carry() {
        FLAG &= 0b11111110;
    }
};

enum {
    B = 0,
    C,
    D,
    E,
    H,
    L
};

enum {
    A = 0,
    INSTRUCTION,
    ACC
};

#endif  // E8085_HEADERS_FLAG_H_
