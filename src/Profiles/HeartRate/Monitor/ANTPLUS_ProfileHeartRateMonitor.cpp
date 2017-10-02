#include <Profiles/HeartRate/Monitor/ANTPLUS_ProfileHeartRateMonitor.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <CommonDataPages/RX/ANTPLUS_ModeSettings.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>

ProfileHeartRateMonitor::ProfileHeartRateMonitor() : BaseSlaveProfile() {
    setChannelConfig();
}

ProfileHeartRateMonitor::ProfileHeartRateMonitor(uint16_t deviceNumber) : BaseSlaveProfile(deviceNumber) {
    setChannelConfig();
}

ProfileHeartRateMonitor::ProfileHeartRateMonitor(uint16_t deviceNumber, uint8_t transmissionType) : BaseSlaveProfile(deviceNumber, transmissionType) {
    setChannelConfig();
}

void ProfileHeartRateMonitor::onBroadcastData(BroadcastData& msg) {
    HeartRateBaseMainDataPage dp = HeartRateBaseMainDataPage(msg);
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    BaseProfile::onBroadcastData(msg);

    switch (dataPage) {
    case ANTPLUS_HEARTRATE_DATAPAGE_DEFAULT_NUMBER:
        called = handleDefault(dp);
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_NUMBER:
        called = handleCumulativeOperatingTime(dp);
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER:
        called = handleManufacturerInformation(dp);
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_NUMBER:
        called = handleProductInformation(dp);
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_NUMBER:
        called = handlePreviousHeartBeat(dp);
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_NUMBER:
        called = handleSwimIntervalSummary(dp);
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_NUMBER:
        called = handleBatteryStatus(dp);
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_NUMBER:
        called = handleCapabilities(dp);
        break;
    case ANTPLUS_COMMON_DATAPAGE_MODESETTINGS_NUMBER:
        called = handleModeSettings(dp);
        break;
    }

    if (!called) {
        callOnOtherDataPage(msg);
    }
}

void ProfileHeartRateMonitor::onAcknowledgedData(AcknowledgedData& msg) {
    // TODO
}

void ProfileHeartRateMonitor::begin() {
    pushChannelConfig();
    openChannel();
}

void ProfileHeartRateMonitor::stop() {
    closeChannel();
}

void ProfileHeartRateMonitor::setChannelConfig() {
    setChannelType(ANTPLUS_HEARTRATE_CHANNELTYPE);
    setDeviceType(ANTPLUS_HEARTRATE_DEVICETYPE);
    setChannelPeriod(ANTPLUS_HEARTRATE_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_HEARTRATE_SEARCHTIMEOUT);
}

bool ProfileHeartRateMonitor::handleBatteryStatus(HeartRateBaseMainDataPage& dataPage) {
    HeartRateBatteryStatus dp = HeartRateBatteryStatus(dataPage);
    return _onHeartRateBatteryStatus.call(dp);
}

bool ProfileHeartRateMonitor::handleCumulativeOperatingTime(HeartRateBaseMainDataPage& dataPage) {
    HeartRateCumulativeOperatingTime dp = HeartRateCumulativeOperatingTime(dataPage);
    return _onHeartRateCumulativeOperatingTime.call(dp);
}

bool ProfileHeartRateMonitor::handleDefault(HeartRateBaseMainDataPage& dataPage) {
    HeartRateDefault dp = HeartRateDefault(dataPage);
    return _onHeartRateDefault.call(dp);
}

bool ProfileHeartRateMonitor::handleManufacturerInformation(HeartRateBaseMainDataPage& dataPage) {
    HeartRateManufacturerInformation dp = HeartRateManufacturerInformation(dataPage);
    return _onHeartRateManufacturerInformation.call(dp);
}

bool ProfileHeartRateMonitor::handlePreviousHeartBeat(HeartRateBaseMainDataPage& dataPage) {
    HeartRatePreviousHeartBeat dp = HeartRatePreviousHeartBeat(dataPage);
    return _onHeartRatePreviousHeartBeat.call(dp);
}

bool ProfileHeartRateMonitor::handleProductInformation(HeartRateBaseMainDataPage& dataPage) {
    HeartRateProductInformation dp = HeartRateProductInformation(dataPage);
    return _onHeartRateProductInformation.call(dp);
}

bool ProfileHeartRateMonitor::handleSwimIntervalSummary(HeartRateBaseMainDataPage& dataPage) {
    HeartRateSwimIntervalSummary dp = HeartRateSwimIntervalSummary(dataPage);
    return _onHeartRateSwimIntervalSummary.call(dp);
}

bool ProfileHeartRateMonitor::handleCapabilities(HeartRateBaseMainDataPage& dataPage) {
    HeartRateCapabilities dp = HeartRateCapabilities(dataPage);
    return _onHeartRateCapabilities.call(dp);
}

bool ProfileHeartRateMonitor::handleModeSettings(HeartRateBaseMainDataPage& dataPage) {
    ModeSettings dp = ModeSettings(dataPage);
    return _onModeSettings.call(dp);
}
