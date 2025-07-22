// Test code to force backlight ON
#include <zephyr/device.h>
#include <zephyr/drivers/pwm.h>
#include <zephyr/kernel.h>

void force_backlight_on(void) {
    const struct device *pwm_dev = DEVICE_DT_GET(DT_NODELABEL(pwm1));
    if (device_is_ready(pwm_dev)) {
        // Force 100% brightness
        pwm_set_cycles(pwm_dev, 0, 1000, 1000, 0);
    }
}