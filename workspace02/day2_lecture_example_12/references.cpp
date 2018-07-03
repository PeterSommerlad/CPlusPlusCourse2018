
int main() {
	int i{42};
	int & ri{i};           // must initialize ref
	int const & cri{i};    // const alias
	int const & cr{6 * 7}; // extend lifetime of 6*7
	ri = 43;               // changes i, ri only an alias
	//--cri;               // doesn't work -> const
}
