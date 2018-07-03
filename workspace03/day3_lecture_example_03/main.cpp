

template<typename T>
void accessTMembers() {
	typename T::MemberType m{};
	T::StaticMemberFunction();
	T::StaticMemberVariable;

	typename T::template MemberTemplate<int> mInt{};
	T::template StaticMemberFunctionTemplate<int>();
	T::template StaticMemberVariableTemplate<int>;
}


struct Argument {
	struct MemberType{};

	static void StaticMemberFunction() {}

	static int StaticMemberVariable;

	template<typename T>
	struct MemberTemplate{};

	template<typename T>
	static T StaticMemberFunctionTemplate() {
		return T{};
	}

	template<typename T>
	static T StaticMemberVariableTemplate;
};


int main() {
	accessTMembers<Argument>();

}
