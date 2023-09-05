#include <modules/tnm067lab1/utils/scalartocolormapping.h>

namespace inviwo {

void ScalarToColorMapping::clearColors() { baseColors_.clear(); }
void ScalarToColorMapping::addBaseColors(vec4 color) { baseColors_.push_back(color); }

vec4 ScalarToColorMapping::sample(float t) const {
    if (baseColors_.size() == 0) return vec4(t);
    if (baseColors_.size() == 1) return vec4(baseColors_[0]);
    if (t <= 0) return vec4(baseColors_.front());
    if (t >= 1) return vec4(baseColors_.back());

    // TODO: use t to select which two base colors to interpolate in-between
    float t_scaled = t * (baseColors_.size() - 1);
    vec4 start = baseColors_[static_cast<int>(t_scaled)];
    vec4 end = baseColors_[static_cast<int>(t_scaled + 1)];


    // TODO: Interpolate colors in baseColors_ and set dummy color to result
    float interpolateFactor = t_scaled - static_cast<size_t>(t_scaled);
    interpolateFactor = interpolateFactor - std::floor(interpolateFactor);
    vec4 finalColor = (1.0f - interpolateFactor) * start + interpolateFactor * end; // dummy color
       
    return finalColor;
}

}  // namespace inviwo
