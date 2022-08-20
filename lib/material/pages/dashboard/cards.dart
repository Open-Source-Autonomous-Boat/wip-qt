import 'package:flutter/material.dart';
import 'package:osab/db/actions.dart';
import 'package:osab/db/db.dart';

class _DeviceCard extends StatefulWidget {
  @override
  State<StatefulWidget> createState() => _DeviceCardState();
}

class _DeviceCardState extends State<_DeviceCard> {
  late Future<DeviceDataValues?> deviceData;
  @override
  void initState() {
    deviceData = DBActions.getDeviceFavValue();
  }

  @override
  void dispose() {
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    ListTile waitTile = const ListTile(
        leading: Icon(Icons.waving_hand),
        title: Text("Waiting for data to load...."),
        subtitle: Text("Might wanna submit a report on this one :("));
    ListTile errorTile = const ListTile(
        leading: Icon(Icons.error),
        title: Text("Failed to recieve favorite device id"),
        subtitle: Text("Please submit bug report :)"));
    return Card(
        child: FutureBuilder(
            future: deviceData,
            builder: (BuildContext context,
                AsyncSnapshot<DeviceDataValues?> snapshot) {
              switch (snapshot.connectionState) {
                case ConnectionState.active:
                case ConnectionState.waiting:
                  return waitTile;
                case ConnectionState.none:
                  return errorTile;
                case ConnectionState.done:
                  {
                    if (!snapshot.hasData || snapshot.data == null) {
                      return const ListTile(
                          leading: Icon(Icons.warning),
                          title: Text("No device available!"),
                          subtitle: Text("Please add new device :)"));
                    }
                    DeviceDataValues data = snapshot.data!;
                    return ExpansionTile(
                        leading: const Icon(Icons.device_hub),
                        title: Text(data.name),
                        subtitle: Text("ID: ${data.id.toString()}"),
                        children: <Widget>[
                          if (data.uuid != null)
                            ListTile(
                                leading: const Icon(Icons.perm_identity),
                                title: const Text("UUID"),
                                subtitle: Text(data.uuid!)),
                        ]);
                  }
              }
            }));
  }
}

class DashBoardCards {
  static var list = [
    Padding(padding: const EdgeInsets.all(10), child: _DeviceCard()),
  ];
}
