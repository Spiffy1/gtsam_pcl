/* ----------------------------------------------------------------------------

 * GTSAM Copyright 2010, Georgia Tech Research Corporation,
 * Atlanta, Georgia 30332-0415
 * All Rights Reserved
 * Authors: Frank Dellaert, et al. (see THANKS for the full author list)

 * See LICENSE for the license information

 * -------------------------------------------------------------------------- */

/**
 * @file testSampler
 * @author Alex Cunningham
 */

#include <CppUnitLite/TestHarness.h>

#include <gtsam/linear/Sampler.h>

using namespace gtsam;

const double tol = 1e-5;

/* ************************************************************************* */
TEST(testSampler, basic) {
	Vector sigmas = Vector_(3, 1.0, 0.1, 0.0);
	noiseModel::Diagonal::shared_ptr model = noiseModel::Diagonal::Sigmas(sigmas);
	char seed = 'A';
	Sampler sampler1(model, seed), sampler2(model, 1), sampler3(model, 1);
	EXPECT(assert_equal(sigmas, sampler1.sigmas()));
	EXPECT(assert_equal(sigmas, sampler2.sigmas()));
	EXPECT_LONGS_EQUAL(3, sampler1.dim());
	EXPECT_LONGS_EQUAL(3, sampler2.dim());
	Vector actual1 = sampler1.sample();
	EXPECT_DOUBLES_EQUAL(0.0, actual1(2), tol);
	EXPECT(assert_equal(sampler2.sample(), sampler3.sample(), tol));
}

/* ************************************************************************* */
int main() { TestResult tr; return TestRegistry::runAllTests(tr); }
/* ************************************************************************* */
