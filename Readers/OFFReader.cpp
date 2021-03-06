#include "OFFReader.h"
#include "../Utils/Color.h"
#include <fstream>
#include <iostream>
#include <sstream>

Shape *OFFReader::fromFile(std::string path) {
	std::ifstream file(path);
	if (!file.is_open()) {
		throw std::exception();
	}
	std::string line;

	//Reading first line (OFF)
	std::getline(file, line);
	while (line == "OFF" || line[0] == '#') {
		std::getline(file, line);
	}
	std::stringstream stream(line);
	int nbVertices, nbFaces;
	stream >> nbVertices;
	stream >> nbFaces;

	float x, y, z;
	auto shape = new Shape(Color::red);
	for (auto i = 0; i < nbVertices; ++i) {
		std::getline(file, line);
		if (line[0] == '#') {
			i--;
			continue;
		}
		stream = std::stringstream(line);
		stream >> x;
		stream >> y;
		stream >> z;
		shape->addPoint({x, y, z});
	}

	int nbIdx;
	for (auto i = 0; i < nbFaces; ++i) {
		std::getline(file, line);
		if (line[0] == '#') {
			i--;
			continue;
		}
		stream = std::stringstream(line);
		stream >> nbIdx;
		std::vector<int> face;
		int idx;
		for (auto j = 0; j < nbIdx; ++j) {
			stream >> idx;
			face.emplace_back(idx);
		}
		shape->addFace(face);
	}

	return shape;
}
