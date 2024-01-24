#pragma once
#include <stdarg.h>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class SVM {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        float kernels[24] = { 0 };
                        float decisions[3] = { 0 };
                        int votes[3] = { 0 };
                        kernels[0] = compute_kernel(x,   0.279296875  , 0.301310043668  , 0.102694399731 );
                        kernels[1] = compute_kernel(x,   0.42578125  , 0.266375545852  , 0.102403321795 );
                        kernels[2] = compute_kernel(x,   0.3046875  , 0.336244541485  , 0.176978891589 );
                        kernels[3] = compute_kernel(x,   0.169921875  , 0.38864628821  , 0.04482950899 );
                        kernels[4] = compute_kernel(x,   0.03515625  , 0.336244541485  , 0.03015286852 );
                        kernels[5] = compute_kernel(x,   0.572265625  , 0.362445414847  , 0.0 );
                        kernels[6] = compute_kernel(x,   0.451171875  , 0.305676855895  , 0.147541443536 );
                        kernels[7] = compute_kernel(x,   0.279296875  , 0.327510917031  , 0.132671920097 );
                        kernels[8] = compute_kernel(x,   0.70703125  , 1.0  , 0.17914619477 );
                        kernels[9] = compute_kernel(x,   0.267578125  , 0.615720524017  , 0.358250305983 );
                        kernels[10] = compute_kernel(x,   0.216796875  , 0.585152838428  , 0.311853184498 );
                        kernels[11] = compute_kernel(x,   0.328125  , 0.524017467249  , 0.334360873514 );
                        kernels[12] = compute_kernel(x,   0.625  , 0.917030567686  , 0.333750661939 );
                        kernels[13] = compute_kernel(x,   0.40625  , 0.650655021834  , 0.345316626161 );
                        kernels[14] = compute_kernel(x,   0.31640625  , 0.580786026201  , 0.286210270492 );
                        kernels[15] = compute_kernel(x,   0.244140625  , 0.650655021834  , 0.360108996412 );
                        kernels[16] = compute_kernel(x,   1.0  , 0.882096069869  , 0.318867110648 );
                        kernels[17] = compute_kernel(x,   0.927734375  , 0.742358078603  , 0.466177094621 );
                        kernels[18] = compute_kernel(x,   0.0  , 0.10480349345  , 0.561843540349 );
                        kernels[19] = compute_kernel(x,   0.0234375  , 0.126637554585  , 0.533675612929 );
                        kernels[20] = compute_kernel(x,   0.279296875  , 0.0  , 0.561843540349 );
                        kernels[21] = compute_kernel(x,   0.0234375  , 0.917030567686  , 0.673954135937 );
                        kernels[22] = compute_kernel(x,   0.927734375  , 0.742358078603  , 0.561843540349 );
                        kernels[23] = compute_kernel(x,   0.9140625  , 0.847161572052  , 0.533675612929 );
                        decisions[0] = 0.160796403885
                        + kernels[0] * 1000.0
                        + kernels[2] * 1000.0
                        + kernels[3] * 1000.0
                        + kernels[4] * 514.899301274112
                        + kernels[5] * 485.100698725888
                        + kernels[6] * 1000.0
                        + kernels[7] * 1000.0
                        + kernels[9] * -1000.0
                        + kernels[10] * -1000.0
                        + kernels[11] * -1000.0
                        + kernels[13] * -1000.0
                        + kernels[14] * -1000.0
                        + kernels[15] * -1000.0
                        ;
                        decisions[1] = -1.391649246216
                        + kernels[0] * 858.516839584948
                        + kernels[1] * 1000.0
                        + kernels[2] * 1000.0
                        + kernels[6] * 1000.0
                        + kernels[7] * 1000.0
                        + kernels[16] * -1000.0
                        + kernels[17] * -858.516839584948
                        + kernels[18] * -1000.0
                        + kernels[19] * -1000.0
                        + kernels[20] * -1000.0
                        ;
                        decisions[2] = -2.063698392684
                        + kernels[8] * 396.291243600239
                        + kernels[9] * 1000.0
                        + kernels[10] * 1000.0
                        + kernels[11] * 1000.0
                        + kernels[12] * 1000.0
                        + kernels[13] * 1000.0
                        + kernels[14] * 1000.0
                        + kernels[15] * 1000.0
                        + kernels[16] * -1000.0
                        + kernels[17] * -1000.0
                        + kernels[18] * -1000.0
                        + kernels[19] * -1000.0
                        + kernels[20] * -799.50193646581
                        + kernels[21] * -1000.0
                        + kernels[22] * -596.78930713443
                        + kernels[23] * -1000.0
                        ;
                        votes[decisions[0] > 0 ? 0 : 1] += 1;
                        votes[decisions[1] > 0 ? 0 : 2] += 1;
                        votes[decisions[2] > 0 ? 1 : 2] += 1;
                        int val = votes[0];
                        int idx = 0;

                        for (int i = 1; i < 3; i++) {
                            if (votes[i] > val) {
                                val = votes[i];
                                idx = i;
                            }
                        }

                        return idx;
                    }

                    /**
                    * Predict readable class name
                    */
                    const char* predictLabel(float *x) {
                        return idxToLabel(predict(x));
                    }

                    /**
                    * Convert class idx to readable name
                    */
                    const char* idxToLabel(uint8_t classIdx) {
                        switch (classIdx) {
                            case 0:
                            return "Bersih";
                            case 1:
                            return "Perlu Diencerkan";
                            case 2:
                            return "Perlu Dikuras";
                            default:
                            return "Houston we have a problem";
                        }
                    }

                protected:
                    /**
                    * Compute kernel between feature vector and support vector.
                    * Kernel type: rbf
                    */
                    float compute_kernel(float *x, ...) {
                        va_list w;
                        va_start(w, 3);
                        float kernel = 0.0;

                        for (uint16_t i = 0; i < 3; i++) {
                            kernel += pow(x[i] - va_arg(w, double), 2);
                        }

                        return exp(-0.001 * kernel);
                    }
                };
            }
        }
    }