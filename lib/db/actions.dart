import 'package:osab/db/db.dart';

class DBActions {
  static Future<String> getFavoriteDevice() async {
    DBClass db = await DBInstances.osab();
    List<OSABDataValues> data = OSABData().from(await db.getItem("devid"));
    if (data.isEmpty) {
      return "0";
    }
    String firstValue = data.first.value ?? "0";
    if (firstValue != "null") {
      return firstValue;
    }
    return "0";
  }

  static Future<void> setFavoriteDevice(String device) async {
    DBClass db = await DBInstances.osab();
    await db.set(OSABDataValues(id: "devid", value: device).asMap());
  }

  static Future<DeviceDataValues?> getDevice(String id) async {
    DBClass db = await DBInstances.devices();
    var data = await db.getItem(id);
    if (data == null) {
      return null;
    }
    return DeviceData().from(data).first;
  }

  static Future<void> setDevice(
      {required String name, String? uuid, int? id}) async {
    DBClass db = await DBInstances.devices();
    id ??= await db.getCount() + 1;
    DeviceDataValues data = DeviceDataValues(id: id, name: name, uuid: uuid);
    db.set(data.asMap());
  }

  static Future<DeviceDataValues?> getDeviceFavValue() async {
    return await DBActions.getDevice(await DBActions.getFavoriteDevice());
  }

  static Future<void> rmDeviceId(String id) async {
    DBClass db = await DBInstances.devices();
    await db.rmItem(id);
  }

  static Future<void> resetFavoriteDevice(String currentID) async {
    DBClass osabDB = await DBInstances.osab();
    DBClass deviceDB = await DBInstances.devices();
    List<OSABDataValues> devID = OSABData().from(await osabDB.getItem("devid"));
    if (devID.isEmpty) {
      return;
    }
    final String? devIDValue = devID.first.value;
    if (devIDValue != "null" && devIDValue == currentID) {
      osabDB.set(OSABDataValues(id: "devid", value: "0").asMap());
    }
    List<DeviceDataValues> devices = DeviceData().from(await deviceDB.get());
    if (devices.isNotEmpty) {
      DBActions.setFavoriteDevice(devices.first.id.toString());
    } else {
      DBActions.setFavoriteDevice("0");
    }
  }
}
