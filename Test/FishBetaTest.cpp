/**
 * @file FishBetaTest.cpp
 * @author Quinton Strausbaugh
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Aquarium.h>
#include <FishBeta.h>

using namespace std;

TEST(FishBetaTest, Construct) {
    Aquarium aquarium;
    FishBeta fishbeta(&aquarium);
}

TEST(FishBetaTest, NullTest) {
    Aquarium aquarium;
    shared_ptr<FishBeta> fishy = make_shared<FishBeta>(&aquarium);

    ASSERT_EQ(fishy->HitTest(100, 200), false) <<
                                                   L"Testing empty image";

    ASSERT_FALSE(aquarium.HitTest(100, 200) == fishy) <<
                                                     L"Testing fish at 100, 200";
}