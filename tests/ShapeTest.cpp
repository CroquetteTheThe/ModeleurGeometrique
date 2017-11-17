#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Shapes/Shape.h"
#include "../Utils/Color.h"

using testing::Eq;

namespace {

	class ShapeTest : public testing::Test {
	public:
		Shape *obj;

		ShapeTest() {
			obj = new Shape(Color::red);
		}
	};

	TEST_F(ShapeTest, nameOfTheTest1) {
		ASSERT_EQ("", "");
	}
}