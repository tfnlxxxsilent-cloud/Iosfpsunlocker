#include <Geode/Geode.hpp>
#include <cocos2d.h>

using namespace geode::prelude;
using namespace cocos2d;

class $modify(MyCCApplication, CCApplication) {
    void setAnimationInterval(double interval) {
        int targetFps = static_cast<int>(Mod::get()->getSettingValue<int64_t>("target-fps"));

        if (targetFps > 0) {
            CCApplication::setAnimationInterval(1.0 / static_cast<double>(targetFps));
            log::info("Set FPS to {}", targetFps);
        } else {
            CCApplication::setAnimationInterval(interval);
        }
    }
};
