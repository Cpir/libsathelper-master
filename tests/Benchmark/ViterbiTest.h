/*
 * ViterbiTest.h
 *
 *  Created on: 05/01/2017
 *      Author: Lucas Teske
 */

#ifndef TESTS_VITERBITEST_H_
#define TESTS_VITERBITEST_H_

#include "BaseBenchmark.h"

namespace SatHelper {

    class ViterbiTest: public BaseBenchmark {
    public:
        std::string TestName() const override { return std::string("Viterbi Test"); }
        bool RunTest() override;
    };

} /* namespace SatHelper */

#endif /* TESTS_VITERBITEST_H_ */
