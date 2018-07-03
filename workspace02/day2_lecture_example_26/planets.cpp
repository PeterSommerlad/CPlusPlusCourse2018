#include <vector>

struct Thing {

};

struct Planet {
  //gigantic type with data on heap
  std::vector<Thing> thingsOnPlanet{};
};

Planet createMars() {
	return {"Mars"};
}

std::vector<Planet> createPlanetsOfSolarSystem() {
  std::vector<Planet> planets{};
  Planet earth{};
  planets.push_back(earth);        //copying a whole planet takes time
  planets.push_back(createMars()); //creates a mars temporary; copy that too?
  return planets;                  //copy everything once more?!
}
