#include <vector>

struct Coordinate{};
struct POI{
	Coordinate coordinate;
};

POI createPOI(Coordinate) {
	return {};
}

auto allPOIs() {
	Coordinate location{};
	POI const & migros = createPOI(location);
	//...
	return std::vector{migros};
}

int main() {
	auto pois = allPOIs();
	//...
}
