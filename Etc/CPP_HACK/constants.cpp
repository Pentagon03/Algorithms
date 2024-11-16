using ld = long double;
constexpr ld PI = numbers::pi_v<ld>;
constexpr ld E = numbers::e_v<ld>;

template <typename T>
constexpr T inf;

template <>
constexpr int32_t inf<int32_t> = 1'000'000'009;

template <>
constexpr int64_t inf<int64_t> = 1'000'000'000'000'000'009LL;

template<>
constexpr double inf<double> = 1e300;

template<>
constexpr long double inf<long double> = 1e300;