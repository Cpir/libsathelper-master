/*
 * firinterpolator.cpp
 *
 *  Created on: 22/12/2016
 *      Author: Lucas Teske
 *      Based on GNU Radio Implementation
 */

#include <dsp/firinterpolator.h>
#include <exceptions/SatHelperException.h>
#include <dsp/interpolator_taps.h>
#include <iostream>

namespace SatHelper {

    MMSEFirInterpolator::MMSEFirInterpolator() {
        filters.resize(NSTEPS + 1);

        for (int i = 0; i < NSTEPS + 1; i++) {
            std::vector<float> t(&taps[i][0], &taps[i][NTAPS]);
            filters[i] = new FirKernel(t);
        }
    }

    MMSEFirInterpolator::~MMSEFirInterpolator() {
        for (int i = 0; i < NSTEPS + 1; i++) {
            delete filters[i];
        }
    }

    unsigned MMSEFirInterpolator::GetNTaps() const {
        return NTAPS;
    }

    unsigned MMSEFirInterpolator::GetNSteps() const {
        return NSTEPS;
    }

    std::complex<float> MMSEFirInterpolator::interpolate(const std::complex<float> input[], float mu) const {
        int imu = (int) rint(mu * NSTEPS);

        if ((imu < 0) || (imu > NSTEPS)) {
            std::cerr << "MMSE Fir Interpolator imu is out of bounds." << std::endl;
            if (imu < 0) {
                imu = 0;
            } else if (imu > NSTEPS) {
                imu = NSTEPS;
            }
        }

        return filters[imu]->filter(input);
    }

} /* namespace SatHelper */
