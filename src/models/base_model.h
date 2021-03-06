/************************************************
* Copyright MaybeShewill-CV. All Rights Reserved.
* Author: MaybeShewill-CV
* File: base_model.h
* Date: 22-6-2
************************************************/

#ifndef MMAISERVER_BASE_MODEL_H
#define MMAISERVER_BASE_MODEL_H

#include "toml/toml.hpp"

#include "common/status_code.h"

namespace jinq {
namespace models {

template<typename INPUT, typename OUTPUT>
class BaseAiModel {
public:
    /***
    *
    */
    virtual ~BaseAiModel() = default;

    /***
     * 构造函数
     * @param config
     */
    BaseAiModel() = default;

    /***
    * 赋值构造函数
    * @param transformer
    */
    BaseAiModel(const BaseAiModel& BaseAiModel) = default;

    /***
     * 复制构造函数
     * @param transformer
     * @return
     */
    BaseAiModel& operator=(const BaseAiModel& transformer) = default;

    /***
     *
     * @param cfg
     * @return
     */
    virtual jinq::common::StatusCode init(const decltype(toml::parse(""))& cfg) = 0;

    /***
     *
     * @param input
     * @param output
     * @return
     */
    virtual jinq::common::StatusCode run(const INPUT& in, OUTPUT& out) = 0;

    /***
     *
     * @return
     */
    virtual bool is_successfully_initialized() const = 0;
};
}
}


#endif //MMAISERVER_BASE_MODEL_H
