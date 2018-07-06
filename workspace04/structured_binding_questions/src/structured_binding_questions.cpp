#include <cassert>
struct base{};
template<typename V>
struct valbase{
	int val;
};
template <typename U, template <typename ...> class ...BS>
struct ops:BS<U>...{};

template <typename U>
struct Eq{
	friend constexpr bool
	operator==(U const &l, U const& r) noexcept {
		//static_assert(is_strong_v<U>,"can only be applied to units");
		auto const &[vl]=l;
		auto const &[vr]=r;
		return vl == vr;
	}
	friend constexpr bool
	operator!=(U const &l, U const& r) noexcept {
		return !(l==r);
	}
};

//struct E:Eq<E>{ // E is incomplete in template instantiation (?)
//	int x{};
//}; // error: cannot decompose class type 'const E': both it and its base class 'const E' have non-static data members auto const &[vl]=l;
// gcc 7.3 bug, clang and gcc 8.1 OK


//struct E:base,Eq<E>{
//	int x{};
//};
struct E:valbase<E>,Eq<E>{

};

int main() {
	E e{};
	assert(e==e);

}
