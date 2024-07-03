// Copyright 2024 Dhruva Sharma

#ifndef E8085_HEADERS_FLAG_H_
#define E8085_HEADERS_FLAG_H_

class _FLAG_ {
    uint8_t FLAG;

 public:
    _FLAG_() :FLAG(0) {};
    bool get_sign() {
        return unsigned(FLAG << 7);
    }
    void set_sign() {
        FLAG |= 0x80;
    }
    void reset_sign() {
        FLAG &= 0x7F;
    }

    bool get_zero() {
        return unsigned(FLAG << 6);
    }
    void set_zero() {
        FLAG |= 0x40;
    }
    void reset_zero() {
        FLAG &= 0xBF;
    }

    bool get_aux_carry() {
        return unsigned(FLAG << 4);
    }
    void set_aux_carry() {
        FLAG |= 0x08;
    }
    void reset_aux_carry() {
        FLAG &= 0xF7;
    }

    bool get_parity() {
        return unsigned(FLAG << 2);
    }
    void set_parity() {
        FLAG |= 0x02;
    }
    void reset_parity() {
        FLAG &= 0xFD;
    }

    bool get_carry() {
        return unsigned(FLAG << 1);
    }
    void set_carry() {
        FLAG |= 0x01;
    }
    void reset_carry() {
        FLAG &= 0xFE;
    }
};


#endif  // E8085_HEADERS_FLAG_H_
