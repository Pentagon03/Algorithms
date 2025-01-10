template<typename T = long double> constexpr T PI = numbers::pi_v<T>;
template<typename T = long double> constexpr T E = numbers::e_v<T>;

// source: dadas08
template<typename T>
struct infinity {
	static constexpr T max_real = std::numeric_limits<T>::max();
	static constexpr T min_real = std::numeric_limits<T>::min();
	static constexpr T max = max_real / 2;
	static constexpr T min = min_real / 2;
};
template<typename T = int> constexpr T INF = infinity<T>::max;