#pragma once
#include <span>

namespace dsp {

class Filter {
public:
    void Init(float sample_rate);
    void Process(std::span<float> block);
    float ProcessSingle(float x);
    void MakeHighShelf(float db_gain, float freq, float s);
    void MakeHighPass(float pitch);
    void MakeDownSample(int dicimate);
    void MakeLowpassDirect(float omega);
    void MakeLowpass(float freq, float Q);
    void ResetLatch();
private:
    float sample_rate_{};
    float b0_{};
    float b1_{};
    float b2_{};
    float a1_{};
    float a2_{};
    float latch1_{};
    float latch2_{};
};

}