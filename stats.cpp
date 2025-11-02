#include "stats.h"
#include <algorithm>
#include <numeric>
#include <cmath>

Statistics::Stats Statistics::ComputeStatistics(const std::vector<float>& input) {
    Statistics::Stats result;
    
    if (input.empty()) {
        result.average = NAN;
        result.max = NAN;
        result.min = NAN;
        return result;
    }
    
    result.min = *std::min_element(input.begin(), input.end());
    result.max = *std::max_element(input.begin(), input.end());
    
    float sum = std::accumulate(input.begin(), input.end(), 0.0f);
    result.average = sum / input.size();
    
    return result;
}
