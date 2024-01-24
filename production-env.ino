#include "classifier_svm.h"
#include "Pipeline.h"
Eloquent::ML::Port::SVM clf;

void setup() {
    Serial.begin(9600);
}

void loop() {
    float features[3] = {22.76,7.8,100.00};

    if (!pipeline.transform(features))
        return;

    Serial.println("Predicted label (you should see 'bersih'): ");
    //Serial.println(clf.predictLabel(features));
    Serial.println(clf.predictLabel(pipeline.X));
    delay(1000);
}