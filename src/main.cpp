#include <Geode/Geode.hpp>
#include <Geode/modify/CCApplication.hpp>

using namespace geode::prelude;

class $modify(CCApplication) {
    void setAnimationInterval(double interval) {
        int targetFps = Mod::get()->getSettingValue<int64_t>("target-fps");
        
        if (targetFps > 0) {
            CCApplication::setAnimationInterval(1.0 / targetFps);
        } else {
            CCApplication::setAnimationInterval(interval);
        }
    }
};
