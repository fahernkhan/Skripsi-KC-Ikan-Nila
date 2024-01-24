#ifndef UUID2394018014640
#define UUID2394018014640

#include <cstring>


namespace WaterPipeline {

    
        #ifndef UUID2393994300336
#define UUID2393994300336

/**
  * MinMaxScaler(low=0, high=1)
 */
class Step0 {
    public:

        /**
         * Transform input vector
         */
        bool transform(float *x) {
            
    for (uint16_t i = 0; i < 3; i++) {
        x[i] = (x[i] - offset[i]) * scale[i] + 0;

        if (x[i] < 0) x[i] = 0;
        else if (x[i] > 1) x[i] = 1;
    }

    return true;


            return true;
        }

    protected:
        
    float offset[3] = {25.93000000000f, 6.56000000000f, 127.88000000000f};
    float scale[3] = {0.24937655860f, 0.32362459547f, 0.00036716246f};

};



#endif
    

     /**
      * Pipeline:
 * ---------
 *  > MinMaxScaler(low=0, high=1)
     */
    class Pipeline {
        public:
            static const uint16_t NUM_INPUTS = 3;
            static const uint16_t NUM_OUTPUTS = 3;
            static const uint16_t WORKING_SIZE = 3;
            float X[3];

            /**
             * Apply pipeline to input vector
             */
            template<typename T>
            bool transform(T *x) {
                for (uint16_t i = 0; i < 3; i++)
                    this->X[i] = x[i];

                size_t start = micros();
                bool isOk =
                
                     step0.transform(X, X)
                ;

                latency = micros() - start;

                return isOk;
            }

            /**
             * Debug output feature vector
             */
            template<typename PrinterInterface>
            void debugTo(PrinterInterface &printer, uint8_t precision=5) {
                printer.print(X[0], precision);

                for (uint16_t i = 1; i < 3; i++) {
                    printer.print(", ");
                    printer.print(X[i], precision);
                }

                printer.print('\n');
            }

            /**
 * Get latency in micros
 */
uint32_t latencyInMicros() {
    return latency;
}

/**
 * Get latency in millis
 */
uint16_t latencyInMillis() {
    return latency / 1000;
}

        protected:
            float latency;
            
                WaterPipeline::Step0 step0;
            
    };
}


static WaterPipeline::Pipeline pipeline;


#endif