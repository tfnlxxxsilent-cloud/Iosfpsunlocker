#include <Geode/Geode.hpp>
#include <cocos2d.h>

using namespace geode::prelude;
using namespace cocos2d;

class $modify(MyCCApplication, CCApplication) {
    void setAnimationInterval(double interval) {
        auto mod = Mod::get();
        int targetFps = static_cast<int>(mod->getSettingValue<int64_t>("target-fps"));

        if (targetFps > 0) {
            double newInterval = 1.0 / static_cast<double>(targetFps);
            CCApplication::setAnimationInterval(newInterval);
            log::info("FPS Unlocker applied: {} FPS", targetFps);
        } else {
            CCApplication::setAnimationInterval(interval);
            log::info("FPS Unlocker disabled, using default interval");
        }
    }
};
