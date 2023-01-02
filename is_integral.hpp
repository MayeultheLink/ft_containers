#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft {

	template<class T>
	struct is_integral {
		static const bool value = false;
	};

	template<>
	struct is_integral<bool> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const bool> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile bool> {
		static const bool value = true;
	};

	template<>
	struct is_integral<char> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const char> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile char> {
		static const bool value = true;
	};

	template<>
	struct is_integral<char16_t> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const char16_t> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile char16_t> {
		static const bool value = true;
	};

	template<>
	struct is_integral<char32_t> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const char32_t> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile char32_t> {
		static const bool value = true;
	};

	template<>
	struct is_integral<wchar_t> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const wchar_t> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile wchar_t> {
		static const bool value = true;
	};

	template<>
	struct is_integral<signed char> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const signed char> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile signed char> {
		static const bool value = true;
	};

	template<>
	struct is_integral<short int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const short int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile short int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<long int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const long int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile long int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<long long int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const long long int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile long long int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned char> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const unsigned char> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile unsigned char> {
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned short int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const unsigned short int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile unsigned short int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const unsigned int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile unsigned int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned long int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const unsigned long int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile unsigned long int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<unsigned long long int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<const unsigned long long int> {
		static const bool value = true;
	};

	template<>
	struct is_integral<volatile unsigned long long int> {
		static const bool value = true;
	};

}

#endif
