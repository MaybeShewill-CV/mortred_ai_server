/************************************************
* Copyright MaybeShewill-CV. All Rights Reserved.
* Author: MaybeShewill-CV
* File: classification_task.h
* Date: 22-6-14
************************************************/

#ifndef MM_AI_SERVER_CLASSIFICATION_TASK_H
#define MM_AI_SERVER_CLASSIFICATION_TASK_H

#include "factory/base_factory.h"
#include "factory/register_marco.h"
#include "models/base_model.h"
#include "models/classification/mobilenetv2.h"
#include "models/classification/resnet.h"
#include "models/classification/densenet.h"

namespace morted {
namespace factory {

using morted::factory::ModelFactory;
using morted::models::BaseAiModel;

namespace classification {
using morted::models::classification::MobileNetv2;
using morted::models::classification::ResNet;
using morted::models::classification::DenseNet;

/***
 * create mobilenetv2 image classification
 * @tparam INPUT
 * @tparam OUTPUT
 * @param detector_name
 * @return
 */
template<typename INPUT, typename OUTPUT>
static std::unique_ptr<BaseAiModel<INPUT, OUTPUT> > create_mobilenetv2_classifier(
    const std::string& classifier_name) {
    REGISTER_AI_MODEL(MobileNetv2, classifier_name, INPUT, OUTPUT)
    return ModelFactory<BaseAiModel<INPUT, OUTPUT> >::get_instance().get_model(classifier_name);
}

/***
 * create resnet image classification
 * @tparam INPUT
 * @tparam OUTPUT
 * @param detector_name
 * @return
 */
template<typename INPUT, typename OUTPUT>
static std::unique_ptr<BaseAiModel<INPUT, OUTPUT> > create_resnet_classifier(
    const std::string& classifier_name) {
    REGISTER_AI_MODEL(ResNet, classifier_name, INPUT, OUTPUT)
    return ModelFactory<BaseAiModel<INPUT, OUTPUT> >::get_instance().get_model(classifier_name);
}

/***
 * create densenet image classification
 * @tparam INPUT
 * @tparam OUTPUT
 * @param detector_name
 * @return
 */
template<typename INPUT, typename OUTPUT>
static std::unique_ptr<BaseAiModel<INPUT, OUTPUT> > create_densenet_classifier(
    const std::string& classifier_name) {
    REGISTER_AI_MODEL(DenseNet, classifier_name, INPUT, OUTPUT)
    return ModelFactory<BaseAiModel<INPUT, OUTPUT> >::get_instance().get_model(classifier_name);
}

}
}
}

#endif //MM_AI_SERVER_CLASSIFICATION_TASK_H