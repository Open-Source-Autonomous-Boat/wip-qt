import 'package:flutter/material.dart';
import 'package:logging/logging.dart';
import 'package:osab/db/db.dart';
import 'package:osab/material/styles/text.dart';
import 'package:uuid/uuid.dart';
import 'dart:async';

class _LocationCard extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Card(
        child: Column(children: [
      ListTile(
        leading: const Icon(Icons.location_city),
        title: TextStyles.cardText("Location"),
        subtitle: const Text("Washington DC"),
      ),
      ButtonBar(
        children: [
          TextButton(onPressed: (() => {}), child: const Text("Open Settings"))
        ],
      )
    ]));
  }
}

class _DeviceCard extends StatefulWidget {
  @override
  State<StatefulWidget> createState() => _DeviceCardState();
}

class _DeviceCardState extends State<_DeviceCard> {
  late Future<String> mName;
  late Future<String> mID;
  var mDeviceQuery = ["Change Name", "Set Name"];
  int mDeviceIndex = 0;

  @override
  void initState() {
    super.initState();
    mID = _getDeviceID();
    mName = _getDeviceName();
  }

  @override
  void dispose() {
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Card(
        child: Column(children: [
      ExpansionTile(
        leading: const Icon(Icons.devices),
        title: TextStyles.cardText("Device"),
        subtitle: const Text("CONNECTED"),
        children: [
          FutureBuilder(
              future: mName,
              builder: ((context, AsyncSnapshot<String> snapshot) {
                String name = (snapshot.hasData &&
                        snapshot.connectionState == ConnectionState.done)
                    ? snapshot.data!
                    : "Unknown Name";
                return ListTile(
                  title: const Text("Device Name"),
                  subtitle: Text(name),
                );
              })),
          ListTile(
            title: const Text("UUID"),
            subtitle: Text(const Uuid().v1()),
          ),
          const ListTile(
            title: Text("Date Added"),
          )
        ],
      ),
      ButtonBar(
        children: [
          TextButton(onPressed: (() => {}), child: const Text("Disconnect"))
        ],
      )
    ]));
  }

  Future<String> _getDeviceName() async {
    var name = DeviceData()
        .from(await (await DBInstances.devices()).getItem(await mID));
    return (name.isEmpty) ? "0" : name.first.name;
  }

  Future<String> _getDeviceID() async {
    List<OSABDataValues> data =
        OSABData().from(await (await DBInstances.osab()).getItem("devid"));
    return (data.isEmpty || data.first.value == "null")
        ? "0"
        : data.first.value ?? "0";
  }

  void _setDeviceName(String aName) {
    if (aName.isEmpty) {
      return;
    }
    //DBInstances.osab().then((value) {
    //  value.set(OSABDataValues(id: "devname", value: aName).asMap());
    //});
    DBInstances.devices().then((value) => {
          value.set(DeviceDataValues(id: int.tryParse("0") ?? -1, name: aName)
              .asMap())
        });
  }
}

class _GreetingCard extends StatefulWidget {
  @override
  State<StatefulWidget> createState() => _GreetingCardState();
}

class _GreetingCardState extends State<_GreetingCard> {
  late final Future<String> mName;

  @override
  void initState() {
    super.initState();
    mName = _getUserName();
  }

  @override
  Widget build(BuildContext context) {
    return Expanded(
        flex: 1,
        child: Padding(
          padding: const EdgeInsets.all(10),
          child: FutureBuilder<String>(
            future: mName,
            builder: (context, snapshot) {
              if (snapshot.hasData) {
                return Card(
                  child: SizedBox.expand(
                      child: Stack(children: [
                    Center(
                      child: TextStyles.cardText(snapshot.data!),
                    )
                  ])),
                );
              } else {
                return Card(
                  child: SizedBox.expand(
                    child: TextStyles.cardText("FAILED TO GET USER NAME!"),
                  ),
                );
              }
            },
          ),
        ));
  }

  static Future<String> _getUserName() async {
    String? data = OSABData()
        .from(await (await DBInstances.osab()).getItem("name"))
        .first
        .value;
    return data ?? "[Unknown UserName]";
  }
}

class DashBoardCards {
  static var list = [
    Padding(padding: const EdgeInsets.all(10), child: _DeviceCard()),
    Padding(padding: const EdgeInsets.all(10), child: _LocationCard()),
  ];
  static Widget greetingCard() => _GreetingCard();
}
