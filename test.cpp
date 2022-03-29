#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Generator.h"
#include <vector>

TEST_CASE("Factorials are computed", "[factorial]") {
	REQUIRE(Factorial(1) == 1);
	REQUIRE(Factorial(2) == 2);
	REQUIRE(Factorial(3) == 6);
	REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE("Check iterative generator correctness", "[generator]") {
	Generator g(36);
	vector<vector<int>> tests = {
		{2, 2, 3, 3},
		{2, 2, 9},
		{2, 3, 6},
		{2, 18},
		{3, 3, 4},
		{3, 12},
		{4, 9},
		{6, 6},
		{36}
	};
	g.GenerateAll();
	REQUIRE(g.GetCount() == tests.size());
	auto cnt = g.GetCount();
	for (int i = 0; i < cnt; i++) {
		const auto& result = g.GetResult(i);
		for (const auto& t : result) {
			REQUIRE(t <= 36);
			REQUIRE(t > 0);
		}
	}
	int i = 0;
	for (const auto& test : tests) {
		if (i >= cnt) break;
		auto res = g.GetResult(i);
		REQUIRE(res == test);
		i++;
	}
}

TEST_CASE("Check recursive generator correctness", "[generator]") {
	Generator g(36);
	vector<vector<int>> tests = {
		{2, 2, 3, 3},
		{2, 2, 9},
		{2, 3, 6},
		{2, 18},
		{3, 3, 4},
		{3, 12},
		{4, 9},
		{6, 6},
		{36}
	};
	g.GenerateRec();
	REQUIRE(g.GetCount() == tests.size());
	auto cnt = g.GetCount();
	for (int i = 0; i < cnt; i++) {
		const auto& result = g.GetResult(i);
		for (const auto& t : result) {
			REQUIRE(t <= 36);
			REQUIRE(t > 0);
		}
	}
	int i = 0;
	for (const auto& test : tests) {
		if (i >= cnt) break;
		auto res = g.GetResult(i);
		REQUIRE(res == test);
		i++;
	}
}

TEST_CASE("Check vector elements", "[vector]") {
	vector<vector<int>> v;
	v.push_back({ 1,2,3 });
	v.push_back(v[0]);
	

	
	const vector<int> vec = { 1, 2, 3 };
	REQUIRE(v[1] == vec);

	//v[0][1] = 0;
	REQUIRE(v[0] == vec);


	REQUIRE(v.size() == 2);

	v.resize(3);
	v[2].resize(3);
	fill(v[2].begin(), v[2].end(), 7);

	const vector<int> vec2 = { 7, 7, 7 };
	REQUIRE(v[2] == vec2);
	
	REQUIRE(*find(v[1].cbegin(), v[1].cend(), 2) == 2);
	REQUIRE( find(v[1].cbegin(), v[1].cend(), 27) == v[1].cend());


}
