#ifndef ANTPLUS_PROFILEHEARTRATEMONITOR_h
#define ANTPLUS_PROFILEHEARTRATEMONITOR_h

#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <Profiles/HeartRate/DataPages/ANTPLUS_ProfileHeartRateDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

#include "ANT.h"

class ProfileHeartRateMonitor : public BaseSlaveProfile {
public:
    ProfileHeartRateMonitor();
    ProfileHeartRateMonitor(uint16_t deviceNumber);
    ProfileHeartRateMonitor(uint16_t deviceNumber, uint8_t transmissionType);
    void onHeartRateBatteryStatus(void (*func)(HeartRateBatteryStatus&, uintptr_t), uintptr_t data = 0) { _onHeartRateBatteryStatus.set(func, data); }
    void onHeartRateCapabilities(void (*func)(HeartRateCapabilities&, uintptr_t), uintptr_t data = 0) { _onHeartRateCapabilities.set(func, data); }
    void onHeartRateCumulativeOperatingTime(void (*func)(HeartRateCumulativeOperatingTime&, uintptr_t), uintptr_t data = 0) { _onHeartRateCumulativeOperatingTime.set(func, data); }
    void onHeartRateDefault(void (*func)(HeartRateDefault&, uintptr_t), uintptr_t data = 0) { _onHeartRateDefault.set(func, data); }
    void onHeartRateManufacturerInformation(void (*func)(HeartRateManufacturerInformation&, uintptr_t), uintptr_t data = 0) { _onHeartRateManufacturerInformation.set(func, data); }
    void onHeartRatePreviousHeartBeat(void (*func)(HeartRatePreviousHeartBeat&, uintptr_t), uintptr_t data = 0) { _onHeartRatePreviousHeartBeat.set(func, data); }
    void onHeartRateProductInformation(void (*func)(HeartRateProductInformation&, uintptr_t), uintptr_t data = 0) { _onHeartRateProductInformation.set(func, data); }
    void onHeartRateSwimIntervalSummary(void (*func)(HeartRateSwimIntervalSummary&, uintptr_t), uintptr_t data = 0) { _onHeartRateSwimIntervalSummary.set(func, data); }
    void onModeSettings(void (*func)(ModeSettings&, uintptr_t), uintptr_t data = 0) { _onModeSettings.set(func, data); }

    void begin();
    void stop();

    /******************************************
     *LIBRARY INTERNAL ONLY FUNCTIONS BELOW
     ******************************************/
    void onBroadcastData(BroadcastData& msg);
    void onAcknowledgedData(AcknowledgedData& msg);

private:
    void setChannelConfig();
    bool handleBatteryStatus(HeartRateBaseMainDataPage& dataPage);
    bool handleCapabilities(HeartRateBaseMainDataPage& dataPage);
    bool handleCumulativeOperatingTime(HeartRateBaseMainDataPage& dataPage);
    bool handleDefault(HeartRateBaseMainDataPage& dataPage);
    bool handleManufacturerInformation(HeartRateBaseMainDataPage& dataPage);
    bool handlePreviousHeartBeat(HeartRateBaseMainDataPage& dataPage);
    bool handleProductInformation(HeartRateBaseMainDataPage& dataPage);
    bool handleSwimIntervalSummary(HeartRateBaseMainDataPage& dataPage);
    bool handleModeSettings(HeartRateBaseMainDataPage& dataPage);
    Callback<HeartRateBatteryStatus&> _onHeartRateBatteryStatus;
    Callback<HeartRateCapabilities&> _onHeartRateCapabilities;
    Callback<HeartRateCumulativeOperatingTime&> _onHeartRateCumulativeOperatingTime;
    Callback<HeartRateDefault&> _onHeartRateDefault;
    Callback<HeartRateManufacturerInformation&> _onHeartRateManufacturerInformation;
    Callback<HeartRatePreviousHeartBeat&> _onHeartRatePreviousHeartBeat;
    Callback<HeartRateProductInformation&> _onHeartRateProductInformation;
    Callback<HeartRateSwimIntervalSummary&> _onHeartRateSwimIntervalSummary;
    Callback<ModeSettings&> _onModeSettings;
};

#endif // ANTPLUS_PROFILEHEARTRATEMONITOR_h