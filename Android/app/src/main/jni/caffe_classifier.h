//
// Created by xue on 19-1-6.
//

#ifndef DROIDPAD_CAFFE_CLASSIFIER_H
#define DROIDPAD_CAFFE_CLASSIFIER_H

#include <caffe/caffe.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <algorithm>
#include <iosfwd>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include <fstream>

using namespace caffe;  // NOLINT(build/namespaces)
using std::string;

/* Pair (label, confidence) representing a prediction. */
typedef std::pair<string, float> Prediction;

class Classifier {
public:
    Classifier() { google::InitGoogleLogging("CaffeClassifier"); }

    bool init(const string &model_file,
              const string &trained_file,
              const string &mean_file,
              const string &label_file);

    std::vector<Prediction> Classify(const cv::Mat &img, int N = 5);

    ~Classifier() { google::ShutdownGoogleLogging(); };
private:
    bool SetMean(const string &mean_file);

    std::vector<float> Predict(const cv::Mat &img);

    //void WrapInputLayer(std::vector<cv::Mat>* input_channels);

    void Preprocess(const cv::Mat &img);

private:
    std::shared_ptr<Net<float> > net_;
    cv::Size input_geometry_;
    int num_channels_;
    cv::Mat mean_;
    std::vector<string> labels_;
    std::vector<cv::Mat> input_channel_;
};


#endif //DROIDPAD_CAFFE_CLASSIFIER_H
