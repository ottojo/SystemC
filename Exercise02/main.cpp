#include <iostream>
#include <fmt/core.h>

template<typename T>
concept Unsigned = std::is_unsigned_v<T>;

// Returns value of LSB
constexpr bool lsb(Unsigned auto a) {
    return (a & 1U) != 0;
}

// Perform right shift of l and r where LSB of l is shifted into MSB of r
constexpr void rightshift(uint8_t &l, uint8_t &r) {
    r >>= 1U;
    r |= unsigned(lsb(l)) << 7U;
    l >>= 1U;
}

// Sets bit at location to specified state (LSB is loc 0)
constexpr void setBit(Unsigned auto &dest, unsigned int loc, bool state) {
    if (state) {
        dest |= 1U << loc;
    } else {
        dest &= ~(1U << loc);
    }
}

class Multiplier {
        uint8_t P;
        uint8_t A;
        uint8_t B;
        bool C;

        void printState() const {
            fmt::print("C: {:#1b}  P: {:#010b}  A: {:#010b}  B: {:#010b}\n", C, P, A, B);
        }

    public:
        uint16_t multiply(uint8_t inA, uint8_t inB) {
            // 1.
            A = inA;
            B = inB;
            P = 0;
            C = false;

            fmt::print("Initial: ");
            printState();

            for (int i = 0; i < 8; i++) {
                // 2.
                if (lsb(A)) {
                    // P += B
                    // C <- Carry
                    uint16_t Pt = P;
                    Pt += B;
                    // Check carry
                    C = (Pt & 0x100U) != 0;
                    P = Pt & 0xFFU;
                } else {
                    C = false;
                }

                // 3.
                rightshift(P, A);
                setBit(P, 7, C);

                printState();
            }

            return (unsigned(P) << 8U) | A;
        }
};

int main() {
    Multiplier m{};
    for (uint8_t a = 0; a < 255; a++) {
        for (uint8_t b = 0; b < 255; b++) {
            uint16_t result = m.multiply(a, b);
            uint16_t correctResult = a * b;
            if (result != correctResult) {
                std::cout << "Failed:" << static_cast<int>(a) << "x" << static_cast<int>(b) << std::endl;
                fmt::print("Expected: {:#018b}\n", correctResult);
                fmt::print("Got:      {:#018b}\n", result);

                fmt::print("Error:    {:#018b}\n", result ^ correctResult);
                exit(1);
            }
        }
    }
}
